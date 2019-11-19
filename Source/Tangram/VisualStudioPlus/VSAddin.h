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

#ifndef _WIN64
#pragma once
#include "dte.h"
#include "dte80.h"
#include "tangram.h"
#include "vcpkg.h"
#include "../TangramCore.h"
#include "../VisualStudioPlus/DTEEvent.h"
#include "../OfficePlus/OfficeAddin.h"

using namespace VxDTE;
using namespace VisualStudioPlus::VSEvents;
class CTangramListView;
namespace VisualStudioPlus
{
#define VCCLASS_WindowImpl				0x00000001;
#define VCCLASS_ComObjectRootBase		0x00000002;
#define VCCLASS_ComObjectRootEx			0x00000004;
#define VCCLASS_ComControl				0x00000008;
#define VCCLASS_IDispEventSimpleImpl	0x00000010;

	class CVSDocument;
	class CTangramVSTabCtrl;
	class CVSClassObjectInfo
	{
	public:
		CVSClassObjectInfo();
		~CVSClassObjectInfo();

		BOOL	m_bVCClass;
		DWORD	m_dwATLInfo;
		CString m_strBaseClassName;
		CodeType*	m_pCodeType;
		VCCodeClass* m_pVCClass;

		CString GetName();
		CString GetFullName();
	};

	class CVSToolPaneWnd :
		public CWindowImpl<CVSToolPaneWnd, CWindow>
	{
	public:
		CVSToolPaneWnd(void);
		CTangramVSTabCtrl* m_pTabCtrl;
		BEGIN_MSG_MAP(CVSToolPaneWnd)
			NOTIFY_HANDLER(1000, TCN_SELCHANGE, OnTcnSelchangeTab)
		END_MSG_MAP()
		void OnFinalMessage(HWND hWnd);

		LRESULT OnTcnSelchangeTab(int /*idCtrl*/, LPNMHDR pNMHDR, BOOL& /*bHandled*/);
	};

	class CTangramVSListCtrl : public CListCtrl
	{
	public:
		CTangramVSListCtrl();
		virtual ~CTangramVSListCtrl();
	protected:
		virtual void PostNcDestroy();
		DECLARE_MESSAGE_MAP()
	public:
	};

	class CTangramVSTabCtrl : public CTabCtrl
	{
	public:
		CTangramVSTabCtrl();
		virtual ~CTangramVSTabCtrl();

		CTangramVSListCtrl* m_pVSListCtrl;
		int RefreshTabCtrl(CVSDocument* pDoc);
	protected:
		virtual void PostNcDestroy();
		afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
		DECLARE_MESSAGE_MAP()
	public:
		void RePosition();
	};

	class ATL_NO_VTABLE CVSDocument : 
		public CComObjectRootBase,
		public CDTEDocumentEvents,
		public CDTETextEditorEvents,
		public CDTETextDocumentKeyPressEvents,
		public IDispatchImpl<IVSDocument, &IID_IVSDocument, &LIBID_Tangram, /*wMajor =*/ 1, /*wMinor =*/ 0>
	{
	public:
		CVSDocument();
		virtual ~CVSDocument();

		CString									m_strName;
		CString									m_strPath;
		CString									m_strPath2;
		VxDTE::Document*						m_pDocument;
		TextDocument*							m_pTextDoc;
		DocumentEvents*							m_pDocEvent;
		TextDocumentKeyPressEvents*				m_pTextDocumentKeyPressEvents;
		CComPtr<VxDTE::Project>					m_pPrj;
		map<CString, CVSClassObjectInfo*>		m_mapClass;
		void __stdcall OnDocumentClosing(VxDTE::Document* Document);
		//void __stdcall OnAfterKeyPress(BSTR Keypress, VxDTE::TextSelection * Selection, VARIANT_BOOL InStatementCompletion);

		BEGIN_COM_MAP(CVSDocument)
			COM_INTERFACE_ENTRY(IVSDocument)
			COM_INTERFACE_ENTRY(IDispatch)
		END_COM_MAP()
		void Lock() {}
		void Unlock() {}
	protected:
		ULONG InternalAddRef() { return 1; }
		ULONG InternalRelease() { return 1; }

		STDMETHOD(get_Count)(long* pCount);
		STDMETHOD(get_VSClass)(VARIANT vIndex, IDispatch **ppNode);
		STDMETHOD(get__NewEnum)(IUnknown** ppVal);
	};

	class CVSAddin :
		public CTangram,
		public CDTEWindowVisibilityEvents
	{
	public:
		CVSAddin();
		virtual ~CVSAddin();

		CString										m_strBaseClasses;
		_DTE*										m_pDTE;

		VxDTE::Window*								m_pToolBoxWnd;
		OutputWindowPane*							m_pOutputWindowPane;

		map<CString, CVSDocument*>					m_mapVSDoc;
		CImageList									m_PrjImageList;
		CTangramListView*							m_pTangramListView;
		CTangramVSTabCtrl*							m_pTangramVSTabCtrl;

		map<int, TangramProjectInfo*>				m_mapTangramProjectInfo;
		map<CString, CString>						m_mapClassInfo;

		void ClearOutputPane();
		void OnInitInstance();
		void PutTextToOutputPane(BSTR bstrMsg);

		BEGIN_COM_MAP(CVSAddin)
			COM_INTERFACE_ENTRY(ITangram)
			COM_INTERFACE_ENTRY(IDispatch)
			COM_INTERFACE_ENTRY(IConnectionPointContainer)
		END_COM_MAP()

		void TangramToolTabCtrlCreated(HWND hTabCtrl);
		void CreateCommonDesignerToolBar();

		void GetClassesFromNameSpace(VCCodeNamespace* pVCCodeNamespace, CVSDocument*);
		void ProcessCodeInfo(VxDTE::CodeElement *pCodeElement, CVSDocument*);
		CString GetBaseClassInfo(CodeType* pCodeType, CString strBaseClasses, CString strLastBaseName);
		void GetAtlObjInfo(CVSClassObjectInfo*);

		STDMETHOD(get_AppKeyValue)(BSTR bstrKey, VARIANT* pVal);
		STDMETHOD(put_AppKeyValue)(BSTR bstrKey, VARIANT newVal);
	private:
		void TangramInit();

		void _GetAtlObjInfo(CVSClassObjectInfo*, CodeElement*);
		CString FillClassInfo(CTangramXmlParse*);
		void DotNetControlCreated(MSG* lpMsg);
	};


	class ATL_NO_VTABLE CVSExtender :
		public CComObjectRootEx<CComSingleThreadModel>,
		public IDispatchImpl<IVSExtender, &IID_IVSExtender, &LIBID_Tangram, /*wMajor =*/ 1, /*wMinor =*/ 0>
	{
	public:
		CVSExtender(void);
		~CVSExtender(void);
		CVSAddin* m_pAddin;
		BEGIN_COM_MAP(CVSExtender)
			COM_INTERFACE_ENTRY(IVSExtender)
			COM_INTERFACE_ENTRY(IDispatch)
		END_COM_MAP()
	protected:
	public:
		STDMETHOD(Close)();
		STDMETHOD(get_ActiveWorkBenchWindow)(BSTR bstrID, IWorkBenchWindow** pVal);
		STDMETHOD(get_DesignNode)(IWndNode** pVal);
		STDMETHOD(get_CurrentDesignNode)(IWndNode** pVal);
		STDMETHOD(put_CurrentDesignNode)(IWndNode* newVal);
		STDMETHOD(get_DesignRootNode)(IWndNode** pVal);
		STDMETHOD(put_DesignRootNode)(IWndNode* newVal);
		STDMETHOD(get_TangramCLRProject)(BSTR bstrPrjPath, VARIANT_BOOL* pVal);
		STDMETHOD(put_TangramCLRProject)(BSTR bstrPrjPath, VARIANT_BOOL newVal);
		STDMETHOD(get_CurrentSelectedPrj)(BSTR* pVal);
		STDMETHOD(ExtendXmlUI)(BSTR bstrKey, BSTR bstrXml, IWndNode** ppNode);
	};
}
#endif


