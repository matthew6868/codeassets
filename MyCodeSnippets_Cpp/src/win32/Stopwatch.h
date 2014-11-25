#pragma once

#include <windows.h>
#include <stdio.h>
#include <memory>

struct CStopwatch
{
	static CStopwatch* StartNew()
	{
		return new CStopwatch();
	}

	void Reset(void)
	{
		LARGE_INTEGER qwTime;
		QueryPerformanceCounter(&qwTime);
		m_llStartTime = qwTime.QuadPart;
	}

	LONGLONG ElapsedMillseconds(void)
	{
		LARGE_INTEGER qwTime;
		QueryPerformanceCounter(&qwTime);

		return static_cast<LONGLONG>(((qwTime.QuadPart - m_llStartTime) * 1000.0) / m_llFrequency);
	}

	LONGLONG ElapsedTicks(void)
	{
		LARGE_INTEGER qwTime;
		QueryPerformanceCounter(&qwTime);

		return qwTime.QuadPart - m_llStartTime;
	}

private:
	CStopwatch()
	{
		LARGE_INTEGER qwTicksPerSec;
		QueryPerformanceFrequency(&qwTicksPerSec);
		m_llFrequency = qwTicksPerSec.QuadPart;

		LARGE_INTEGER qwTime;
		QueryPerformanceCounter(&qwTime);
		m_llStartTime = qwTime.QuadPart;
	}


private:
	LONGLONG m_llFrequency;
	LONGLONG m_llStartTime;
};

struct CDumpStopwatch
{
	CDumpStopwatch()
	{
		m_spStopwatch.reset(CStopwatch::StartNew());
	}
	~CDumpStopwatch()
	{
		char szLog[256];
		sprintf_s(szLog, sizeof(szLog) / sizeof(szLog[0]), "{mxu}elapsed time : %I64d in millseconds", m_spStopwatch->ElapsedMillseconds());
		OutputDebugStringA(szLog);

		m_spStopwatch.reset();
	}

private:
	std::shared_ptr<CStopwatch> m_spStopwatch;
};
