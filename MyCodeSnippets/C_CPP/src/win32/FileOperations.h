#pragma once

class CDumpFileHelper
{
public:
	CDumpFileHelper(TCHAR const *pszFileName) :
		m_hFile(INVALID_HANDLE_VALUE)
	{
		this->OpenFile(pszFileName);
	}

	~CDumpFileHelper()
	{
		if (m_hFile != INVALID_HANDLE_VALUE) {
			::CloseHandle(m_hFile);
			m_hFile = INVALID_HANDLE_VALUE;
		}
	}

	bool ReadFile(LPVOID lpBuffer, DWORD dwNumberOfBytesToRead)
	{
		if (m_hFile != INVALID_HANDLE_VALUE) {
			DWORD dwBytesRead = 0;
			if (::ReadFile(m_hFile, lpBuffer, dwNumberOfBytesToRead, &dwBytesRead, NULL))
				return false;

			if (dwBytesRead != dwNumberOfBytesToRead)
				return false;

			return true;
		}

		return false;
	}

	bool WriteFile(LPCVOID lpBuffer, DWORD dwNumberOfBytesToWrite)	
	{
		if (m_hFile != INVALID_HANDLE_VALUE) {
			DWORD dwBytesWritten = 0;
			if (!::WriteFile(m_hFile, lpBuffer, dwNumberOfBytesToWrite, &dwBytesWritten, NULL)) {
				return false;
			}

			if (dwBytesWritten != dwNumberOfBytesToWrite)
				return false;

			return true;
		}

		return false;
	}

	bool Append(LPCVOID lpBuffer, DWORD dwNumberOfBytesToWrite)
	{
		if (m_hFile != INVALID_HANDLE_VALUE) {

			if (::SetFilePointer(m_hFile, 0, NULL, FILE_END) == INVALID_SET_FILE_POINTER)
				return false;

			DWORD dwBytesWritten = 0;
			if (!::WriteFile(m_hFile, lpBuffer, dwNumberOfBytesToWrite, &dwBytesWritten, NULL)) {
				return false;
			}

			if (dwBytesWritten != dwNumberOfBytesToWrite)
				return false;

			return true;
		}

		return false;
	}

private:
	bool OpenFile(TCHAR const *pszFileName)
	{
		if (pszFileName)
		{
			m_hFile = ::CreateFile(pszFileName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		}

		return m_hFile != INVALID_HANDLE_VALUE;
	}
private:
	HANDLE m_hFile;
};