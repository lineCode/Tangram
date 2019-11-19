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
* OUTLINED IN THE TANGRAM LICENSE AGREEMENT.TANGRAM TEAM
* GRANTS TO YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE
* THIS SOFTWARE ON A SINGLE COMPUTER.
*
* CONTACT INFORMATION:
* mailto:tangramteam@outlook.com
* https://www.tangramteam.com
*
********************************************************************************/


#pragma once
#include "XZip.h"
namespace Utilities
{
	class CComponentInstaller
	{
	public:
		CComponentInstaller(void);
		~CComponentInstaller(void);

		CString m_strHostFile;
		//压缩一个文件
		BOOL Zip(LPCTSTR lpszZipArchive, LPCTSTR lpszSrcFile);
		//解压压缩包内的文件
		void VerifyZip(HZIP hz, LPCTSTR lpszFile, LPCTSTR lpszPath);
		//进行文件比较
		BOOL Compare(LPCTSTR lpszFile1, LPCTSTR lpszFile2, BOOL *pbResult);
		//解压压缩包内的文件，支持一个文件,并以strName命名,strName带路径
		BOOL UnZip(CString strZip, CString strName);
		//解压压缩包内的文件，支持多个文件，并不改名
		BOOL UnMultiZip(CString strZip, CString strPath);
		BOOL UnMultiZip2(CString strZip, CString strPath);
		BOOL InstallComponent(CString strXml);

		BOOL RegComDll(const CString& strDllLib);
		BOOL UnRegComDll(const CString& strDllLib);
		BOOL SetDirectory(CString strFile);
	};
}