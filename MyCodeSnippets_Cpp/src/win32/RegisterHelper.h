#pragma once

#include <windows.h>

struct CRegisterAccessor
{
	CRegisterAccessor(HKEY hKey, LPCTSTR lpSubKey)
	{
		m_status = RegOpenKeyEx(hKey, lpSubKey, 0, KEY_READ, &m_hKey);
	}
	~CRegisterAccessor()
	{
		if (m_status == ERROR_SUCCESS)
		{
			RegCloseKey(m_hKey);
		}
	}

	bool QueryDWORDValue(WCHAR const *szRegName, DWORD &dwRegValue)
	{
		if (m_status == ERROR_SUCCESS)
		{
			DWORD dwType = REG_DWORD;
			DWORD valueSize = sizeof(DWORD);
			DWORD status = RegQueryValueEx(m_hKey, szRegName, 0, &dwType, reinterpret_cast<BYTE*>(&dwRegValue), &valueSize);
			if (status == ERROR_SUCCESS)
			{
				return true;
			}
		}

		return false;
	}

private:
	LONG m_status;
	HKEY m_hKey;
};