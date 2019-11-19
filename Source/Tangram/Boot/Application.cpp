#include "../stdafx.h"
#include "Application.h"

#include "RuntimeDelegate.h"

namespace Boot
{
	CString m_strWorkingPath;
	CString m_strExecutablePath;

	map<CString, CString> m_mapConfigurations;
	map<CString, RuntimeDelegate*> m_mapRuntimeDelegates;

	void Application::Ready()
	{
		TCHAR m_szBuffer[256];
		TCHAR szDriver[MAX_PATH] = { 0 };
		TCHAR szDir[MAX_PATH] = { 0 };
		TCHAR szExt[MAX_PATH] = { 0 };
		TCHAR szFile2[MAX_PATH] = { 0 };
		::GetModuleFileName(NULL, m_szBuffer, MAX_PATH);
		DWORD m_dwThreadID = ::GetCurrentThreadId();

		_tsplitpath_s(m_szBuffer, szDriver, szDir, szFile2, szExt);
		m_strWorkingPath = szDriver;
		m_strWorkingPath += szDir;
	}

	CString Application::GetConfiguration(CString strKey)
	{
		auto it = m_mapConfigurations.find(strKey);
		if (it != m_mapConfigurations.end())
		{
			return it->second;
		}
		return _T("");
	}

	void Application::PutConfiguration(CString strKey, CString strValue)
	{
		m_mapConfigurations[strKey] = strValue;
	}

	CString Application::GetWorkingPath()
	{
		return m_strWorkingPath;
	}

	CString Application::GetExecutablePath()
	{
		return m_strExecutablePath;
	}

	void Application::AddRuntimeDelegate(RuntimeDelegate* pRuntimeDelegate)
	{
		if (pRuntimeDelegate != nullptr)
		{
			m_mapRuntimeDelegates[pRuntimeDelegate->GetName()] = pRuntimeDelegate;
		}
	}
}