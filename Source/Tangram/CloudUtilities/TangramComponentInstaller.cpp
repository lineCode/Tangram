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


#include "..\stdafx.h"
#include "..\TangramApp.h"
#include "..\TangramCore.h"
#include "XZip.h"
#include "XUnzip.h"
#include "TangramComponentInstaller.h"

#define COMPARE_BUF_SIZE (64*1024)
#define TEXT_LINE    _T("This is line %5d\r\n")
#define TEXT_LINE1   _T("This is line     1\r\n")
#define IsValidFileHandle(x)	((x) && ((x) != INVALID_HANDLE_VALUE))

namespace Utilities
{
	CComponentInstaller::CComponentInstaller(void)
	{
		m_strHostFile = _T("");
	}

	CComponentInstaller::~CComponentInstaller(void)
	{
	}

	BOOL CComponentInstaller::UnZip(CString strZip, CString dbName)
	{
		ZIPENTRYW ze;
		memset(&ze, 0, sizeof(ze));

		HZIP hz = OpenZip(strZip.GetBuffer(), 0, ZIP_FILENAME);
		if (hz)
		{
			ZRESULT zr = GetZipItem(hz, -1, &ze);
			if (zr == ZR_OK)
			{
				int numitems = ze.index;
				if (numitems == 1)
				{
					GetZipItem(hz, 0, &ze);
					VerifyZip(hz, ze.name, dbName);
					CloseZip(hz);
					return true;
				}
			}
		}
		return false;
	}

	BOOL CComponentInstaller::InstallComponent(CString strXml)
	{
		CTangramXmlParse m_Parse;
		if (m_Parse.LoadXml(strXml))
		{
			if (m_strHostFile == _T(""))
				m_strHostFile = m_Parse.attr(_T("FileName"), _T(""));
			if (m_strHostFile != _T(""))
			{
				m_strHostFile = g_pTangram->m_strAppDataPath + m_strHostFile;
				if (::PathFileExists(m_strHostFile))
				{
					BOOL bModifyed = false;
					CString strVal = _T("");
					CString strCfgFile = _T("");
					CString strFilePath = _T("");
					CTangramXmlParse m_Parse2;
					CTangramXmlParse* pAssemblyBindingNode = nullptr;
					ZIPENTRYW ze;
					memset(&ze, 0, sizeof(ze));
					HZIP hz = OpenZip(m_strHostFile.GetBuffer(), 0, ZIP_FILENAME);
					if (hz)
					{
						ZRESULT zr = GetZipItem(hz, -1, &ze);
						if (zr == ZR_OK)
						{
							int numitems = ze.index;
							for (int i = 0; i < numitems; i++)
							{
								GetZipItem(hz, i, &ze);
								CString strName = ze.name;
								strFilePath = m_strHostFile + ze.name;
								ZRESULT zr = 0;
								ZIPENTRYW zeNiew;
								memset(&ze, 0, sizeof(zeNiew));
								int index = -1;
								zr = FindZipItem(hz, strFilePath, true, &index, &zeNiew);
								int nPos = strName.Find(_T("/"));
								int nIndex = 0;
								strName = strName.Left(nPos);
								strFilePath = _T("");
								if (strName == _T(""))
								{
									strFilePath = g_pTangram->m_strAppPath + ze.name;
								}
								else if (strName.CompareNoCase(_T("Templates")) == 0)
								{
									CString	m_strModulePath = _T("");
									HMODULE hModule = NULL;
#ifndef _WIN64
									hModule = ::GetModuleHandle(_T("TangramPackage.dll"));
									if (hModule)
									{
										GetModuleFileName(hModule, g_pTangram->m_szBuffer, MAX_PATH * sizeof(TCHAR));
										m_strModulePath = CString(g_pTangram->m_szBuffer);
										nPos = m_strModulePath.ReverseFind('\\');
										m_strModulePath = m_strModulePath.Left(nPos + 1);
									}
#endif								strFilePath = theApp.m_strModulePath + ze.name;
								}
								else if (strName.CompareNoCase(_T("COMDll")) == 0)
								{
									nIndex = 1;
									strFilePath = g_pTangram->m_strAppPath + _T("TangramCOMAssemblies\\") + strName;
								}
								else if (strName.CompareNoCase(_T("CommonCLRDll")) == 0)
								{
									nIndex = 1;
									strFilePath = g_pTangram->m_strProgramFilePath + _T("Tangram\\TangramCOMAssemblies\\") + strName;
								}
								else if (strName.CompareNoCase(_T("CLRDll")) == 0)
								{
									nIndex = 2;
									strFilePath = g_pTangram->m_strAppPath + _T("TangramAssemblies\\") + strName;
								}
								else if (strName.CompareNoCase(_T("CommonCOMDll")) == 0)
								{
									nIndex = 4;
									strFilePath = g_pTangram->m_strProgramFilePath + _T("Tangram\\TangramAssemblies\\") + strName;
								}
								else if (strName.CompareNoCase(_T("msi")) == 0)
								{
									nIndex = 3;
									strFilePath = g_pTangram->m_strAppDataPath + _T("TangramMSI\\") + strName;
								}

								TCHAR targetname[MAX_PATH];
								_tcscpy_s(targetname, strFilePath);
								::DeleteFile(targetname);
								zr = UnzipItem(hz, index, targetname, 0, ZIP_FILENAME);
								if (zr == ZR_OK)
								{
									switch (nIndex)
									{
									case 0:
									{

									}
									break;
									case 1:
										if (::PathFileExists(strFilePath))
										{
											RegComDll(strFilePath);
										}
										break;
									case 2:
										if (::PathFileExists(strFilePath))
										{
											nPos = strName.ReverseFind('/');
											if (nPos != -1)
											{
												CString strProbingPath = _T("TangramAssemblies\\") + strName.Left(nPos);
												if (pAssemblyBindingNode == nullptr)
												{
													TCHAR szFile[MAX_PATH] = { 0 };
													::GetModuleFileName(NULL, szFile, MAX_PATH);
													strCfgFile = CString(szFile) + _T(".config");
													if (m_Parse2.LoadFile(strCfgFile))
														pAssemblyBindingNode = m_Parse2[_T("runtime")][_T("assemblyBinding")].GetChild(_T("probing"));
												}

												if (pAssemblyBindingNode)
												{
													if (strVal == _T(""))
														strVal = pAssemblyBindingNode->attr(_T("privatePath"), _T(""));
													CString _strval = strVal;
													_strval.MakeLower();
													CString strKey = _T(";") + strProbingPath + _T(";");
													strKey.MakeLower();
													if (_strval.Find(strKey) == -1)
													{
														nPos = strVal.Find(_T(";"));
														CString s = strVal.Left(nPos + 1);
														s += strProbingPath;
														s += _T(";");
														s += strVal.Mid(nPos);
														s.Replace(_T(";;"), _T(";"));
														bModifyed = true;
														strVal = s;
													}
												}
											}
										}
										break;
									case 3:
										break;
									}
								}
							}
							if (bModifyed&&pAssemblyBindingNode)
							{
								pAssemblyBindingNode->put_attr(_T("privatePath"), strVal);
								m_Parse2.SaveFile(strCfgFile);
							}
							CloseZip(hz);
							return true;
						}
						return false;
					}
				}
				else
				{
					return false;
				}
			}
		}
		return false;
	}

	BOOL CComponentInstaller::UnMultiZip(CString strZip, CString strPath)
	{
		if (::PathIsDirectory(strPath) == false)
		{
			if (::SHCreateDirectoryEx(NULL, strPath, NULL))
				return false;
		}

		ZIPENTRYW ze;
		memset(&ze, 0, sizeof(ze));
		CString strFilePath = _T("");
		HZIP hz = OpenZip(strZip.GetBuffer(), 0, ZIP_FILENAME);
		if (hz)
		{
			ZRESULT zr = GetZipItem(hz, -1, &ze);
			if (zr == ZR_OK)
			{
				int numitems = ze.index;
				for (int i = 0; i < numitems; i++)
				{
					GetZipItem(hz, i, &ze);
					strFilePath = strPath + ze.name;
					VerifyZip(hz, ze.name, strFilePath);
				}
				CloseZip(hz);
				return true;
			}
		}
		return false;
	}

	BOOL CComponentInstaller::UnMultiZip2(CString strZip, CString strPath)
	{
		if (::PathIsDirectory(strPath) == false)
		{
			if (::SHCreateDirectoryEx(NULL, strPath, NULL))
				return false;
		}

		ZIPENTRYW ze;
		memset(&ze, 0, sizeof(ze));
		CString strFilePath = _T("");
		HZIP hz = OpenZip(strZip.GetBuffer(), 0, ZIP_FILENAME);
		if (hz)
		{
			ZRESULT zr = GetZipItem(hz, -1, &ze);
			if (zr == ZR_OK)
			{
				int numitems = ze.index;
				for (int i = 0; i < numitems; i++)
				{
					GetZipItem(hz, i, &ze);
					CString strName = ze.name;
					int nPos = strName.Find(_T("/"));
					if (nPos == -1)
					{
						nPos = strName.Find(_T("\\"));
					}
					if (nPos != -1)
						strName = strName.Mid(nPos + 1);
					//strFilePath = strPath + strName;
					strFilePath = strPath + ze.name;
					VerifyZip(hz, ze.name, strFilePath);
					SetFileAttributes(strFilePath, FILE_ATTRIBUTE_NORMAL);
				}
				CloseZip(hz);
				return true;
			}
		}
		return false;
	}

	//BOOL CComponentInstaller::UnMultiZip3(CString strZip, CString strPath)
	//{
	//	if (::PathIsDirectory(strPath) == false)
	//	{
	//		if (::SHCreateDirectoryEx(NULL, strPath, NULL))
	//			return false;
	//	}

	//	ZIPENTRYW ze;
	//	memset(&ze, 0, sizeof(ze));
	//	CString strFilePath = _T("");
	//	HZIP hz = OpenZip(strZip.GetBuffer(), 0, ZIP_FILENAME);
	//	if (hz)
	//	{
	//		ZRESULT zr = GetZipItem(hz, -1, &ze);
	//		if (zr == ZR_OK)
	//		{
	//			int numitems = ze.index;
	//			for (int i = 0; i < numitems; i++)
	//			{
	//				GetZipItem(hz, i, &ze);
	//				CString strName = ze.name;
	//				int nPos = strName.Find(_T("/"));
	//				if (nPos == -1)
	//				{
	//					nPos = strName.Find(_T("\\"));
	//				}
	//				if (nPos != -1)
	//					strName = strName.Mid(nPos + 1);
	//				strFilePath = strPath + strName;
	//				VerifyZip(hz, ze.name, strFilePath);
	//				SetFileAttributes(strFilePath, FILE_ATTRIBUTE_NORMAL);
	//				if (::PathFileExists(strFilePath))
	//				{
	//					g_pTangram->ImportTangramDocTemplate(strFilePath);
	//				}
	//			}
	//			CloseZip(hz);
	//			return true;
	//		}
	//	}
	//	return false;
	//}

	BOOL CComponentInstaller::Zip(LPCTSTR lpszZipArchive, LPCTSTR lpszSrcFile)
	{
		BOOL bResult = true;

		_ASSERTE(lpszZipArchive);
		_ASSERTE(lpszZipArchive[0] != _T('\0'));

		if (!lpszZipArchive || lpszZipArchive[0] == _T('\0'))
			return false;

		_ASSERTE(lpszSrcFile);
		_ASSERTE(lpszSrcFile[0] != _T('\0'));

		if (!lpszSrcFile || lpszSrcFile[0] == _T('\0'))
			return false;

		// does zip source file exist?
		if (_taccess(lpszSrcFile, 04) != 0)
		{
			ATLTRACE(_T("WARNING: zip source file '%s' cannot be found, operation aborted\n"),
				lpszSrcFile);
			return false;
		}

		// use only the file name for zip file entry
		TCHAR * cp = (TCHAR *)_tcsrchr(lpszSrcFile, _T('\\'));
		if (cp == nullptr)
			cp = (TCHAR *)lpszSrcFile;
		else
			cp++;

		HZIP hz = Utilities::CreateZip((void *)lpszZipArchive, 0, ZIP_FILENAME);

		if (hz)
		{
			ZRESULT zr = Utilities::ZipAdd(hz, cp, (void *)lpszSrcFile, 0, ZIP_FILENAME);

			CloseZip(hz);

			// did add work?
			if (zr == ZR_OK)
			{
				ATLTRACE(_T("added '%s' to zip file '%s'\n"),
					lpszSrcFile, lpszZipArchive);

				bResult = true;
			}
			else
			{
				ATLTRACE(_T("WARNING: failed to add zip source file '%s'\n"),
					lpszSrcFile);
				bResult = false;
			}
		}
		else
		{
			ATLTRACE(_T("ERROR: failed to create zip file '%s'\n"),
				lpszZipArchive);
			bResult = false;
		}

		return bResult;
	}

	///////////////////////////////////////////////////////////////////////////////
	// VerifyZip
	void CComponentInstaller::VerifyZip(HZIP hz, LPCTSTR lpszFile, LPCTSTR lpszPath)
	{
		ZIPENTRYW ze;
		memset(&ze, 0, sizeof(ze));
		int index = -1;
		ZRESULT zr = 0;

		zr = FindZipItem(hz, lpszFile, true, &index, &ze);

		TCHAR targetname[MAX_PATH];
		_tcscpy_s(targetname, lpszPath);
		// delete target file if it exists
		::DeleteFile(targetname);

		zr = UnzipItem(hz, index, targetname, 0, ZIP_FILENAME);
		if (zr == ZR_OK)
		{
		}
	}

	BOOL CComponentInstaller::Compare(LPCTSTR lpszFile1, LPCTSTR lpszFile2, BOOL *pbResult)
	{
		_ASSERTE(pbResult);
		if (!pbResult)
			return false;

		*pbResult = false;

		BOOL bCompare = false;		// true = files identical
		// false = files not identical
		BOOL bOp = true;			// true = no API failures, compare completed
		// false = file or memory API failed

		_ASSERTE(lpszFile1);
		_ASSERTE(lpszFile1[0] != _T('\0'));

		if (!lpszFile1 || lpszFile1[0] == _T('\0'))
			return false;

		_ASSERTE(lpszFile2);
		_ASSERTE(lpszFile2[0] != _T('\0'));

		if (!lpszFile2 || lpszFile2[0] == _T('\0'))
			return false;

		HANDLE hFile1 = NULL, hFile2 = NULL;

		ATLTRACE(_T("opening '%s'"), lpszFile1);

		// open file 1
		hFile1 = ::CreateFile(lpszFile1, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		if (hFile1 == INVALID_HANDLE_VALUE)
		{
			ATLTRACE(_T("ERROR: %s failed\n"), _T("CreateFile"));
			return false;
		}

		ATLTRACE(_T("opening '%s'"), lpszFile2);

		// open file 2
		hFile2 = ::CreateFile(lpszFile2,
			GENERIC_READ,
			FILE_SHARE_READ | FILE_SHARE_WRITE,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL);

		if (hFile2 == INVALID_HANDLE_VALUE)
		{
			ATLTRACE(_T("ERROR: %s failed\n"), _T("CreateFile"));
			::CloseHandle(hFile1);
			return false;
		}

		DWORD dwFileSize1 = ::GetFileSize(hFile1, NULL);
		DWORD dwFileSize2 = ::GetFileSize(hFile2, NULL);

		if ((dwFileSize1 != INVALID_FILE_SIZE) && (dwFileSize2 != INVALID_FILE_SIZE))
		{
			// continue if file sizes match
			if (dwFileSize1 == dwFileSize2)
			{
				BYTE * pBuf1 = new BYTE[COMPARE_BUF_SIZE];
				_ASSERTE(pBuf1);

				BYTE * pBuf2 = new BYTE[COMPARE_BUF_SIZE];
				_ASSERTE(pBuf2);

				if (pBuf1 && pBuf2)
				{
					while (dwFileSize1)
					{
						DWORD dwBytesRead1 = 0;
						BOOL bRet1 = ::ReadFile(hFile1,
							(LPVOID)pBuf1,
							COMPARE_BUF_SIZE,
							&dwBytesRead1,
							NULL);

						if (!bRet1)
						{
							ATLTRACE(_T("ERROR: %s failed\n"), _T("ReadFile"));
							bOp = false;
							break;
						}

						DWORD dwBytesRead2 = 0;
						BOOL bRet2 = ::ReadFile(hFile2, (LPVOID)pBuf2, COMPARE_BUF_SIZE, &dwBytesRead2, NULL);

						if (!bRet2)
						{
							ATLTRACE(_T("ERROR: %s failed\n"), _T("ReadFile"));
							bOp = false;
							break;
						}

						if (dwBytesRead1 != dwBytesRead2)
						{
							ATLTRACE(_T("Compare failed ==> file Read sizes different\n"));
							break;
						}

						if (dwBytesRead1 == 0)
						{
							// Read ok, but nothing read
							ATLTRACE(_T("Read %s ==> EOF reached.\n"), lpszFile1);
							bCompare = true;
							break;
						}

						if (dwBytesRead2 == 0)
						{
							// Read ok, but nothing read
							ATLTRACE(_T("Read %s ==> EOF reached.\n"), lpszFile2);
							bCompare = true;
							break;
						}

						// do contents match?
						int nCmp = memcmp(pBuf1, pBuf2, dwBytesRead1);
						if (nCmp != 0)
						{
							ATLTRACE(_T("Compare failed ==> file contents different\n"));
							break;
						}

						dwFileSize1 -= dwBytesRead1;

					} // while (dwFileSize1)

					if (dwFileSize1 == 0)
						bCompare = true;

					if (pBuf1)
						delete[] pBuf1;
					if (pBuf2)
						delete[] pBuf2;
				}
				else
				{
					// memory allocation failed
					ATLTRACE(_T("ERROR: memory allocation failure\n"));
					bOp = false;
				}
			}
			else
			{
				ATLTRACE(_T("Compare failed ==> file sizes different\n"));
			}
		}
		else
		{
			// GetFileSize failed
			ATLTRACE(_T("ERROR: %s failed\n"), _T("GetFileSize"));
			bOp = false;
		}

		if (IsValidFileHandle(hFile1))
			::CloseHandle(hFile1);
		if (IsValidFileHandle(hFile2))
			::CloseHandle(hFile2);
		*pbResult = bCompare;
		return bOp;
	}

	BOOL CComponentInstaller::SetDirectory(CString strFile)
	{
		TCHAR sDirve[_MAX_DRIVE];
		TCHAR sDir[_MAX_DIR];
		TCHAR sFname[_MAX_FNAME];
		TCHAR sExt[_MAX_EXT];
		_tsplitpath_s(strFile, sDirve, sDir, sFname, sExt);
		CString filename = (CString(sDirve) + CString(sDir));
		return SetCurrentDirectory(filename);
	}

	BOOL CComponentInstaller::RegComDll(const CString& strDllPath)
	{
		typedef int (CALLBACK* REGISTERFUNCTION)(void);
		BOOL bRet = false;
		REGISTERFUNCTION RegisterServerFunction = NULL;
		HINSTANCE handle = NULL;
		SetDirectory(strDllPath);
		handle = LoadLibraryEx(strDllPath, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
		if (handle != NULL)
		{
			RegisterServerFunction = (REGISTERFUNCTION)::GetProcAddress(handle, "DllRegisterServer");
			if (RegisterServerFunction != NULL)
			{
				bRet = (RegisterServerFunction() == S_OK);
			}
			FreeLibrary(handle);
		}
		return bRet;
	}

	BOOL CComponentInstaller::UnRegComDll(const CString& strDllPath)
	{
		typedef int (CALLBACK* UNREGISTERFUNCTION)(void);
		BOOL bRet = false;
		UNREGISTERFUNCTION UnregisterServerFunction = NULL;
		HINSTANCE handle = NULL;
		SetDirectory(strDllPath);
		handle = LoadLibrary(strDllPath);
		if (handle != NULL)
		{
			UnregisterServerFunction = (UNREGISTERFUNCTION)::GetProcAddress(handle, "DllUnregisterServer");
			if (UnregisterServerFunction != NULL)
			{
				bRet = (UnregisterServerFunction() == S_OK);
			}
			FreeLibrary(handle);
		}
		else
		{
			ATLTRACE("LoadLibrary FAILUR!Reason is %d", ::GetLastError());
		}

		return bRet;
	}
}