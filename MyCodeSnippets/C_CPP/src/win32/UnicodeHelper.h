#pragma once

#include <Windows.h>

inline wchar_t* AnsiToUnicode(const char *str)
{
	wchar_t* buffer = nullptr;

	if (str)
	{
		size_t nu = strlen(str);
		size_t n = (size_t) ::MultiByteToWideChar(CP_ACP, 0, (const char *) str, int(nu), NULL, 0);

		buffer = 0;
		buffer = new wchar_t[n];
		memset(buffer, 0, n);

		int bytes = ::MultiByteToWideChar(CP_ACP, 0, (const char *) str, -1, buffer, int(n + 1));
		if (!bytes)
		{
			delete [] buffer;
			buffer = nullptr;
		}
	}

	return buffer;
}

inline char* UnicodeToAnsi(const wchar_t *str)
{
	char* buffer = nullptr;

	if (str)
	{
		size_t nu = wcslen(str);
		size_t n = ::WideCharToMultiByte(CP_ACP, 0, str, int(nu), nullptr, 0, 0, 0);

		buffer = 0;
		buffer = new char[n];
		memset(buffer, 0, n);

		int bytes = ::WideCharToMultiByte(CP_ACP, 0, str, int(nu), buffer, int(n), 0, 0);
		if (!bytes)
		{
			delete [] buffer;
			buffer = nullptr;
		}
	}

	return buffer;
}

/*
** Convert a UTF-8 string to microsoft unicode (UTF-16?).
**
** Space to hold the returned string is obtained from malloc.
*/
static wchar_t *utf8ToUnicode(const char *zFilename) {
	int nChar;
	wchar_t *zWideFilename;

	nChar = ::MultiByteToWideChar(CP_UTF8, 0, zFilename, -1, NULL, 0);
	zWideFilename = malloc(nChar*sizeof(zWideFilename[0]));
	if (zWideFilename == 0) {
		return 0;
	}
	nChar = ::MultiByteToWideChar(CP_UTF8, 0, zFilename, -1, zWideFilename, nChar);
	if (nChar == 0) {
		free(zWideFilename);
		zWideFilename = 0;
	}
	return zWideFilename;
}

/*
** Convert microsoft unicode to UTF-8.  Space to hold the returned string is
** obtained from malloc().
*/
static char *unicodeToUtf8(const wchar_t *zWideFilename) {
	int nByte;
	char *zFilename;

	nByte = ::WideCharToMultiByte(CP_UTF8, 0, zWideFilename, -1, 0, 0, 0, 0);
	zFilename = malloc(nByte);
	if (zFilename == 0) {
		return 0;
	}
	nByte = ::WideCharToMultiByte(CP_UTF8, 0, zWideFilename, -1, zFilename, nByte,
		0, 0);
	if (nByte == 0) {
		free(zFilename);
		zFilename = 0;
	}
	return zFilename;
}
