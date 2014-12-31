#ifndef __aligned_allocated_h__
#define __aligned_allocated_h__

#include <memory>

#define ALIGNMENT_MAX 1024

#ifdef _DEBUG
int g_total_mem = 0;
#endif

typedef struct {
	void *base;
	int size;
	int size_aligned;
	int log2_alignment;
} malloc_aligned_header_t;


inline void * malloc_aligned(int num_bytes, unsigned int alignment)
{
	int log2_alignment = 0;
	int num_bytes_additional = 0;
	int num_bytes_malloc = 0;
	uint8_t * ptr_aligned = NULL;
	void * base = NULL;
	malloc_aligned_header_t * pheader = NULL;

	if (num_bytes <= 0)
		return NULL;

	if (alignment > 0)
		alignment -= 1;

	if (alignment > ALIGNMENT_MAX)
		alignment = ALIGNMENT_MAX;

	while (alignment)
	{
		alignment >>= 1;
		log2_alignment++;
	}

	num_bytes_additional = (int)sizeof(malloc_aligned_header_t) + (1 << log2_alignment) - 1;
	num_bytes_malloc = num_bytes + num_bytes_additional;

	base = malloc(num_bytes_malloc);
	if (!base)
		return NULL;

#ifdef _DEBUG
	g_total_mem += num_bytes_malloc;
#endif

	ptr_aligned = (uint8_t*) base + sizeof(malloc_aligned_header_t);
	ptr_aligned = ptr_aligned + (((uint8_t*) NULL - ptr_aligned) & ((1 << log2_alignment) - 1));

	pheader = (malloc_aligned_header_t*) (ptr_aligned - sizeof(malloc_aligned_header_t));
	pheader->log2_alignment = log2_alignment;
	pheader->size_aligned = num_bytes;
	pheader->base = base;
	pheader->size = num_bytes_malloc;

	return ptr_aligned;
}


inline int free_aligned(void *ptr_aligned)
{
	void * base = NULL;
	malloc_aligned_header_t * pheader = NULL;

	if (ptr_aligned == NULL)
		return 0;

	pheader = (malloc_aligned_header_t*) ((uint8_t*) ptr_aligned - sizeof(malloc_aligned_header_t));

#ifdef _DEBUG
	g_total_mem -= pheader->size;
#endif

	base = pheader->base;
	free(base);

#ifdef _DEBUG
	return g_total_mem;
#else

	return 0;

#endif
}

#endif