/********************************************************************************
*					Tangram Library - version 10.0.0							*
*********************************************************************************
* Copyright (C) 2002-2019 by Tangram Team.   All Rights Reserved.				*
*
* THIS SOURCE FILE IS THE PROPERTY OF TANGRAM TEAM AND IS NOT TO
* BE RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED
* WRITTEN CONSENT OF TANGRAM TEAM.
*
* THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS
* OUTLINED IN THE GPL LICENSE AGREEMENT.TANGRAM TEAM
* GRANTS TO YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE
* THIS SOFTWARE ON A SINGLE COMPUTER.
*
* CONTACT INFORMATION:
* mailto:tangramteam@outlook.com
* https://www.tangramteam.com
*
*
********************************************************************************/

// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "dllmain.h"
#include "TangramCoreEvents.cpp"
#include <shellapi.h>
#include <shlobj.h>

ITangram* GetTangram()
{
	if (::GetModuleHandle(_T("TangramCore.dll")) == nullptr)
	{
		HMODULE hModule = ::LoadLibrary(L"tangramcore.dll");
		if (hModule == nullptr) {
			TCHAR m_szBuffer[MAX_PATH];
			if (SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, 0, m_szBuffer) ==
				S_OK) {
				ATL::CString m_strProgramFilePath = ATL::CString(m_szBuffer);
				m_strProgramFilePath += _T("\\Tangram\\Tangramcore.dll");
				if (::PathFileExists(m_strProgramFilePath)) {
					hModule = ::LoadLibrary(m_strProgramFilePath);
				}
			}
		}
		if (hModule) {
			typedef CTangramImpl* (__stdcall * GetTangramImpl)(ITangram**);
			GetTangramImpl _pTangramImplFunction;
			_pTangramImplFunction = (GetTangramImpl)GetProcAddress(hModule, "GetTangramImpl");
			if (_pTangramImplFunction != NULL) {
				theApp.m_pTangramImpl = _pTangramImplFunction(&theApp.m_pTangram);
				if(theApp.m_pTangramImpl->m_nAppType==0)
					theApp.m_pTangramImpl->m_nAppType = 4000;
				theApp.m_pTangramImpl->m_pTangramDelegate = ((ITangramDelegate*)&theApp);
				theApp.m_pTangramImpl->m_pTangramAppProxy = ((ITangramAppProxy*)&theApp);
			}
		}
	}
	return theApp.m_pTangram;
}

CTangramCLRApp::CTangramCLRApp()
{
	ATLTRACE(_T("Loading CTangramCLRApp :%p\n"), this);
	m_pTangram = nullptr;
	m_pVSExtender = nullptr;
	m_dwThreadID = ::GetCurrentThreadId();
	TCHAR file[MAX_PATH];
	GetModuleFileName(::GetModuleHandle(nullptr), file, MAX_PATH * sizeof(TCHAR));
	m_strAppPath = CString(file);
	int nPos = m_strAppPath.ReverseFind('\\');
	m_strAppPath = m_strAppPath.Left(nPos + 1);
}

CTangramCLRApp::~CTangramCLRApp()
{
	ATLTRACE(_T("Release CTangramCLRApp :%p\n"), this);
}

void CTangramCLRApp::InitTangramApp(bool bCrashReporting)
{
	if (m_bBrowserModeInit)
		return;
	HMODULE hModule = ::GetModuleHandle(L"chromert.dll");
	if(hModule==nullptr)
		hModule = ::LoadLibrary(L"chromert.dll");
	if (hModule) {
		typedef int(__stdcall * _InitApp)(bool bSupportCrashReporting);
		_InitApp _pInitAppFunction;
		_pInitAppFunction = (_InitApp)GetProcAddress(hModule, "InitApp");
		if (_pInitAppFunction != NULL) {
			m_bBrowserModeInit = true;
			theApp.BeginBrowserSession();
			_pInitAppFunction(bCrashReporting);
			theApp.EndBrowserSession();
		}
	}
}

void CTangramCLRApp::ExitJVM()
{
	if (m_pJVMenv)
	{
		try
		{
			OutputDebugString(
				_T("\n\n***************For CLR Developer***************\n")
				_T("***************Exit Eclipse JVM from CLR***************\n\n")
			);
			if (m_pTangramImpl && m_pTangramImpl->m_mapTangramWindowProvider.size())
			{
				while (m_pTangramImpl->m_mapTangramWindowProvider.size())
					m_pTangramImpl->m_mapTangramWindowProvider.erase(m_pTangramImpl->m_mapTangramWindowProvider.begin());
			}
			m_pJVMenv->CallStaticVoidMethod(systemClass, exitMethod, 0);
		}
		catch (...)
		{
		}
		if (m_pJVMenv->ExceptionOccurred()) {
			m_pJVMenv->ExceptionDescribe();
			m_pJVMenv->ExceptionClear();
		}
	}
}

CString CTangramCLRApp::GetLibPathFromAssemblyQualifiedName(CString strAssemblyQualifiedName)
{
	BOOL bLocalAssembly = false;
	strAssemblyQualifiedName.MakeLower();
	CString strPath = _T("");
	CString strLib = _T("");
	CString strObjName = _T("");
	CString strVersion = _T("");
	CString strPublickeytoken = _T("");
	int nPos = strAssemblyQualifiedName.Find(_T("publickeytoken"));
	if (nPos == -1)
	{
		bLocalAssembly = true;
		nPos = strAssemblyQualifiedName.Find(_T(","));
		if (nPos != -1)
		{
			strObjName = strAssemblyQualifiedName.Left(nPos);
			strLib = strAssemblyQualifiedName.Mid(nPos + 1);
			strLib.Trim();
			strObjName.Trim();
			if (strLib == _T("tangramclr")|| strLib == _T("tangram"))
			{
				return strObjName + _T("|") + strLib + _T("|");
			}
		}
	}
	else
	{
		strPublickeytoken = strAssemblyQualifiedName.Mid(nPos + 15);
		if (strPublickeytoken == _T("null"))
		{
			bLocalAssembly = true;
			nPos = strAssemblyQualifiedName.Find(_T("version"));
			if (nPos != -1)
			{
				strLib = strAssemblyQualifiedName.Left(nPos);
				nPos = strLib.ReverseFind(',');
				strLib = strLib.Left(nPos);
				nPos = strLib.Find(',');
				strObjName = strLib.Left(nPos);
				strLib = strLib.Mid(nPos + 1);
				strLib.Trim();
			}
		}
		else
		{
			nPos = strAssemblyQualifiedName.Find(_T("version"));
			if (nPos != -1)
			{
				strVersion = strAssemblyQualifiedName.Mid(nPos + 8);
				strLib = strAssemblyQualifiedName.Left(nPos);
				nPos = strLib.ReverseFind(',');
				strLib = strLib.Left(nPos);
				nPos = strVersion.Find(',');
				strVersion = strVersion.Left(nPos);
				nPos = strLib.Find(',');
				strObjName = strLib.Left(nPos);
				strLib = strLib.Mid(nPos + 1);
				strLib.Trim();
				TCHAR m_szBuffer[MAX_PATH];
				HRESULT hr = SHGetFolderPath(NULL, CSIDL_WINDOWS, NULL, 0, m_szBuffer);
				strPath.Format(_T("%s\\Microsoft.NET\\assembly\\GAC_MSIL\\%s\\v4.0_%s__%s\\%s.dll"), m_szBuffer, strLib, strVersion, strPublickeytoken,strLib);
				if (::PathFileExists(strPath))
					return strObjName + _T("|") + strLib + _T("|") + strPath;
				else
				{
#ifdef _WIN64
					strPath.Format(_T("%s\\Microsoft.NET\\assembly\\GAC_%d\\%s\\v4.0_%s__%s\\%s.dll"), m_szBuffer, 64, strLib, strVersion, strPublickeytoken, strLib);
#else
					strPath.Format(_T("%s\\Microsoft.NET\\assembly\\GAC_%d\\%s\\v4.0_%s__%s\\%s.dll"), m_szBuffer, 32, strLib, strVersion, strPublickeytoken, strLib);
#endif
					if (::PathFileExists(strPath))
						return strObjName + _T("|") + strLib + _T("|") + strPath;
				}
			}
		}
	}
	if (strLib != _T(""))
	{
		if (strLib.CompareNoCase(theApp.m_pTangramImpl->m_strExeName) == 0)
		{
			strPath = m_strAppPath + strLib + _T(".exe");
		}
		else
			strPath = m_strAppPath + strLib + _T(".dll");
		if (::PathFileExists(strPath))
			return strObjName + _T("|") + strLib + _T("|") + strPath;
		else
		{
			HANDLE hFind; // file handle
			WIN32_FIND_DATA FindFileData;

			hFind = FindFirstFile(m_strAppPath + _T("*.*"), &FindFileData); // find the first file
			if (hFind == INVALID_HANDLE_VALUE)
			{
				return false;
			}

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
						CString strPath = m_strAppPath + FindFileData.cFileName + _T("\\");
						CString strPath2 = strPath + strLib + _T(".dll");
						if (::PathFileExists(strPath2))
							return strObjName + _T("|") + strLib + _T("|") + strPath2;
						CString strRet = _GetLibPathFromAssemblyQualifiedName(strPath, strLib + _T(".dll"));
						if (strRet != _T(""))
							return strObjName + _T("|") + strLib + _T("|") + strRet;
					}

				}//FindNextFile
				else
				{
					if (theApp.m_pTangramImpl)
					{
						strPath = theApp.m_pTangramImpl->m_strAppCommonFormsPath + strLib + _T(".dll");
						if (::PathFileExists(strPath))
						{
							return strObjName + _T("|") + strLib + _T("|") + strPath;
						}
						strPath = L"C:\\Program Files (x86)\\Syncfusion\\Essential Studio\\Windows\\16.4.0.42\\Assemblies\\4.6\\";
						strPath = strPath + strLib + _T(".dll");
						if (::PathFileExists(strPath))
						{
							return strObjName + _T("|") + strLib + _T("|") + strPath;
						}
					}
					if (GetLastError() == ERROR_NO_MORE_FILES) // no more files there
						bSearch = false;
					else {
						// some error occured, close the handle and return false
						FindClose(hFind);
						return _T("");
					}
				}
			}//while

			// Find .shared directory
			CString strSharedPath = theApp.m_pTangramImpl->m_strAppDataPath;// OLE2T(pVal.bstrVal);
			hFind = FindFirstFile(strSharedPath + _T(".shared\\*.*"), &FindFileData); // find the first file
			if (hFind == INVALID_HANDLE_VALUE)
			{
				return false;
			}

			bSearch = true;
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
						CString strPath = m_strAppPath + FindFileData.cFileName + _T("\\");
						CString strPath2 = strPath + strLib + _T(".dll");
						if (::PathFileExists(strPath2))
							return strObjName + _T("|") + strLib + _T("|") + strPath2;
						CString strRet = _GetLibPathFromAssemblyQualifiedName(strPath, strLib + _T(".dll"));
						if (strRet != _T(""))
							return strObjName + _T("|") + strLib + _T("|") + strRet;
					}

				}//FindNextFile
				else
				{
					if (GetLastError() == ERROR_NO_MORE_FILES) // no more files there
						bSearch = false;
					else {
						// some error occured, close the handle and return false
						FindClose(hFind);
						return _T("");
					}
				}
			}//while

			// End Find .shared directory

			FindClose(hFind); // closing file handle
		}
	}

	return _T("");
}

void CTangramCLRApp::BeginBrowserSession()
{

}

void CTangramCLRApp::EndBrowserSession()
{

}

CString CTangramCLRApp::_GetLibPathFromAssemblyQualifiedName(CString strDir, CString strLibName)
{
	CString strPath = strDir + strLibName;
	if (::PathFileExists(strPath))
		return strPath;
	HANDLE hFind; // file handle
	WIN32_FIND_DATA FindFileData;

	hFind = FindFirstFile(strDir + _T("*.*"), &FindFileData); // find the first file
	if (hFind == INVALID_HANDLE_VALUE)
	{
		return false;
	}

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
				CString strPath = strDir + FindFileData.cFileName + _T("\\");
				CString strRet = _GetLibPathFromAssemblyQualifiedName(strPath, strLibName);
				if (strRet != _T(""))
					return strRet;
			}

		}//FindNextFile
		else
		{
			if (GetLastError() == ERROR_NO_MORE_FILES) // no more files there
				bSearch = false;
			else {
				// some error occured, close the handle and return false
				FindClose(hFind);
				return false;
			}
		}
	}//while

	FindClose(hFind); // closing file handle
	return _T("");
}

#include <wincrypt.h>

int CTangramCLRApp::CalculateByteMD5(BYTE* pBuffer, int BufferSize, CString &MD5)
{
	HCRYPTPROV hProv;
	// Acquire a cryptographic provider context handle.
	if (CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, 0))
	{
		HCRYPTHASH hHash;
		// Create the hash object.
		if (CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash))
		{
			// Compute the cryptographic hash of the buffer.
			if (CryptHashData(hHash, pBuffer, BufferSize, 0))
			{
				DWORD dwCount = 16;
				unsigned char digest[16];
				CryptGetHashParam(hHash, HP_HASHVAL, digest, &dwCount, 0);

				if (hHash)
					CryptDestroyHash(hHash);

				// Release the provider handle.
				if (hProv)
					CryptReleaseContext(hProv, 0);

				unsigned char b;
				char c;
				char *Value = new char[1024];
				int k = 0;
				for (int i = 0; i < 16; i++)
				{
					b = digest[i];
					for (int j = 4; j >= 0; j -= 4)
					{
						c = ((char)(b >> j) & 0x0F);
						if (c < 10) c += '0';
						else c = ('a' + (c - 10));
						Value[k] = c;
						k++;
					}
				}
				Value[k] = '\0';
				MD5 = CString(Value);
				delete Value;
			}
		}
	}

	return 1;
}

CTangramNodeEvent::CTangramNodeEvent()
{
	m_pWndNode				= nullptr;
	m_pTangramNodeCLREvent	= nullptr;
}

CTangramNodeEvent::~CTangramNodeEvent()
{
	if (m_pTangramNodeCLREvent)
	{
		//LONGLONG nValue = (LONGLONG)m_pWndNode;
		DispEventUnadvise(m_pWndNode);
	}
}

using namespace ATL;
