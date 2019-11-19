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
namespace Utilities
{
	class CDownLoadObj
	{
	public:
		CDownLoadObj();
		~CDownLoadObj();

		CString m_strFileURL;
		CString m_strFilePath;
		CString m_strActionXml;
		BOOL InerDownloadAFile();
		BOOL OnDownLoadSuccess(int fileid);
		BOOL DownLoadFile(CString strURL, CString strTarget);
	private:
		ULONG crc32Table[256];			//CRC±í
		CString m_strMac;

		void InitCRC32Table();
		int GetCRC32(CString& csData, DWORD dwSize);
		ULONG Reflect(ULONG ref, char ch);
		CString OpenFile(CString &filePath);
		DWORD ExecCmd(const CString cmd, const BOOL setCurrentDirectory);
	};
}
