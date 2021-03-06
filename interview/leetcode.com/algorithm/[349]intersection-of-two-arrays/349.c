/*
 *  Source: https://leetcode.com/problems/intersection-of-two-arrays/
 *  Author: matthew6886(mxu.public@outlook.com)
 *  Date: 2016-11-19

    349. Intersection of Two Arrays   QuestionEditorial Solution  My Submissions
    Total Accepted: 59697
    Total Submissions: 132297
    Difficulty: Easy
    Contributors: Admin
    Given two arrays, write a function to compute their intersection.

    Example:
    Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

    Note:
    Each element in the result must be unique.
    The result can be in any order.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#ifundef HASHSIZE
#define HASHSIZE 1024
#endif
#ifundef MAX
#define MAX(val1, val2) (val1 > val2 ? val1 : val2)
#endif

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *ret;
    int hash[HASHSIZE] = { 0 };

    if (!nums1 || !nums2)
        return NULL;

    *returnSize = 0;
    ret = calloc(MAX(nums1Size, nums2Size), sizeof(*nums1));

    for (int i = 0; i < nums1Size; ++i)
        hash[nums1[i]] = 1;
    
    for (int i = 0; i < nums2Size; ++i)
        if (hash[nums2[i]] == 1)
            hash[nums2[i]] = 2;
    
    for (int i = 0; i < HASHSIZE; ++i)
        if (hash[i] == 2)
            ret[(*returnSize)++] = i;

    return ret;
}