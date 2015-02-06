#pragma once

#include <windows.h>


void LogToDebugViewA(char* const format, ...)
{
	char szLog[1024] = { 0 };

	va_list args;
	va_start(args, format);
	vsprintf_s(szLog, sizeof(szLog) / sizeof(szLog[0]), format, args);
	va_end(args);

	OutputDebugStringA(szLog);
}

void LogToDebugViewW(wchar_t* const format, ...)
{
	wchar_t szLog[1024] = { 0 };

	va_list args;
	va_start(args, format);
	vswprintf_s(szLog, sizeof(szLog) / sizeof(szLog[0]), format, args);
	va_end(args);

	OutputDebugStringW(szLog);
}