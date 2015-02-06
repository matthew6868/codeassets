#include "stdafx.h"

#include <stdio.h>
#include <tchar.h>


#ifdef WIN32

#include <Windows.h>
#include "win32/RegisterHelper.h"
#include "win32/LogDebug.h"

int main_windows(int argc, _TCHAR* argv [])
{
	CRegisterAccessor ra(nullptr, nullptr);

	LogToDebugViewA("haha");
	LogToDebugViewW(L"heihei");

	return 0;
}

#endif

int _tmain(int argc, _TCHAR* argv [])
{
#ifdef WIN32
	return main_windows(argc, argv);
#else

	return 0;
#endif
}