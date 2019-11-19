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
#include "../OfficeAddin.h"
#include "ExcelPlusEvents.h"
using namespace OfficePlus;
using namespace OfficePlus::ExcelPlus::ExcelPlusEvent;

namespace OfficePlus
{
	namespace ExcelPlus
	{
		class CExcelObject;
		class CExcelAddin;
		class CExcelWorkBook;
		class CExcelWorkSheet;
		typedef map<HWND, CExcelObject*> ExcelWorkBookWndMap;
		typedef ExcelWorkBookWndMap::iterator ExcelWorkBookWndMapIT;

		class CExcelWorkBook : 
			public COfficeDocument,
			public CExcelWorkbookEvents,
			public map<_Worksheet*, CExcelWorkSheet*>
		{
		public:
			CExcelWorkBook(void);
			~CExcelWorkBook(void);
			BOOL						m_bCreating;
			CString						m_strDefaultSheetXml;
			_Workbook*					m_pWorkBook;
			ExcelWorkBookWndMap			m_mapExcelWorkBookWnd;

			CWndNode*					m_pSheetNode;
			map<CString, CString>		m_mapWorkSheetInfo;

			void InitWorkBook();
			//void ModifySheetForTangram(IDispatch* Sh, CString strSheetXml, CString strTaskPaneXml);
			//void AddPropertyToSheet()
		private:
			void __stdcall OnNewSheet(IDispatch* Sh);
			void __stdcall OnSheetActivate(IDispatch* Sh);
			void __stdcall OnSheetBeforeDelete(IDispatch* Sh);
			void __stdcall OnBeforeSave(VARIANT_BOOL SaveAsUI, VARIANT_BOOL* Cancel);
		};

		class CExcelWorkSheet : public map<CString, CString>
		{
		public:
			CExcelWorkSheet(void);
			~CExcelWorkSheet(void);
			CString m_strKey;
			CString m_strSheetName;
			_Worksheet* m_pSheet;
			map<CString, CWndNode*> m_mapNodeMap;
		};
	}
}
