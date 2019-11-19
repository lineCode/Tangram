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
#include "MSWord.h"
#include "WordPlusEvents.h"
using namespace Word;
using namespace OfficePlus::WordPlus::WordPlusEvent;

namespace OfficePlus
{
	namespace WordPlus
	{
		class CWordObject;
		class CWordAddin;
		class CWordDocument : 
			public CWordDocumentEvents,
			public COfficeDocument,
			public map<HWND, CWordObject*>
		{
		public:
			CWordDocument(void);
			~CWordDocument(void);
			_Document*				m_pDoc;
			map<CString, CString>	m_mapDocUIInfo;

			void __stdcall OnClose();
			void InitDocument();
		};

		class CWordObject :
			public COfficeObject
		{
		public:
			CWordObject(void);

			BOOL					m_bDesignState;
			BOOL					m_bDesignTaskPane;

			CWordDocument*			m_pWordPlusDoc;
			void OnObjDestory();
		};
	}
}
