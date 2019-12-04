#include "../stdafx.h"
#include "CLRRuntimeDelegate.h"

#include "Application.h"
#include "../TangramCore.h"

typedef HRESULT(__stdcall* TangramCLRCreateInstance)(REFCLSID clsid, REFIID riid, LPVOID* ppInterface);

extern CTangram* g_pTangram;

namespace Boot
{
	CLRRuntimeDelegate::CLRRuntimeDelegate()
	{
		m_pCLRProxy = nullptr;
		m_pClrHost = nullptr;
	}

	CString CLRRuntimeDelegate::GetName()
	{
		return _T("CLR");
	}

	void CLRRuntimeDelegate::Start()
	{
		if (m_pCLRProxy == nullptr && m_pClrHost == nullptr)
		{
			HMODULE	hMscoreeLib = LoadLibrary(TEXT("mscoree.dll"));
			if (hMscoreeLib)
			{
				TangramCLRCreateInstance CLRCreateInstance = (TangramCLRCreateInstance)GetProcAddress(hMscoreeLib, "CLRCreateInstance");
				if (CLRCreateInstance)
				{
					HRESULT hrStart = 0;
					ICLRMetaHost* m_pMetaHost = NULL;
					hrStart = CLRCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, (LPVOID*)& m_pMetaHost);
					CString strVer = _T("v4.0.30319");
					ICLRRuntimeInfo* lpRuntimeInfo = nullptr;
					hrStart = m_pMetaHost->GetRuntime(strVer.AllocSysString(), IID_ICLRRuntimeInfo, (LPVOID*)& lpRuntimeInfo);
					if (FAILED(hrStart))
						return;
					hrStart = lpRuntimeInfo->GetInterface(CLSID_CLRRuntimeHost, IID_ICLRRuntimeHost, (LPVOID*)& m_pClrHost);
					if (FAILED(hrStart))
						return;

					hrStart = m_pClrHost->Start();
					if (FAILED(hrStart))
					{
						return;
					}
					if (hrStart == S_FALSE)
					{
						m_bStarted = true;
					}
					else
						m_bEnableProcessFormTabKey = true;

					CString strPath = _T("");

					HANDLE hFind; // file handle
					WIN32_FIND_DATA FindFileData;

					hFind = FindFirstFile(Application::GetWorkingPath() + _T("Tangram_CLR_Rt.dll"), &FindFileData); // find the first file
					if (hFind != INVALID_HANDLE_VALUE)
					{
						bool bSearch = true;
						while (bSearch) // until we finds an entry
						{
							if (FindNextFile(hFind, &FindFileData))
							{
								// Don't care about . and ..
								//if(IsDots(FindFileData.cFileName))
								if ((_tcscmp(FindFileData.cFileName, _T(".")) == 0) ||
									(_tcscmp(FindFileData.cFileName, _T("..")) == 0))
									continue;

								// We have found a directory
								if ((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
								{
									CString strPath = Application::GetWorkingPath() + FindFileData.cFileName + _T("\\");
									strPath += _T("Tangram_CLR_Rt.dll");
									if (::PathFileExists(strPath))
									{
										break;
									}
								}

							}//FindNextFile
						}//while
					}

					if (strPath == _T(""))
					{
						int nVer = 0;
#ifdef _WIN64
						nVer = 64;
#else
						nVer = 32;
#endif
						strPath.Format(_T("%s\\Microsoft.NET\\assembly\\GAC_%d\\Tangram_CLR_Rt\\v4.0_1.0.1992.1963__1bcc94f26a4807a7\\Tangram_CLR_RT.dll"), g_pTangram->m_szBuffer, nVer);
					}

					CTangramImpl* pTangramProxyBase = static_cast<CTangramImpl*>(g_pTangram);
					CString strInfo = _T("");
					strInfo.Format(_T("%I64d"), (__int64)pTangramProxyBase);
					DWORD dwRetCode = 0;
					hrStart = m_pClrHost->ExecuteInDefaultAppDomain(
						strPath,
						_T("TangramCLR.TangramProxy"),
						_T("TangramInit"),
						CComBSTR(strInfo),
						&dwRetCode);
					m_pMetaHost->Release();
					m_pMetaHost = nullptr;
					FreeLibrary(hMscoreeLib);
					if (hrStart != S_OK)
						return;
				}
			}
		}
		m_bStarted = true;
	}
}