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

// TangramCLRProxy.h : Declaration of the CTangramCLRProxy

#pragma once

#include "TangramBase.h"       
#include "TangramProxy.h"
#include "ChromeWebBrowser.h"
#include "resource.h"       // main symbols

using namespace System::Reflection;
using namespace TangramCLR;

class CTangramWPFObjWrapper;

class CTangramCLRProxy : public ITangramCLRImpl
{
public: 
	CTangramCLRProxy();
	virtual~CTangramCLRProxy();

	bool												m_bHostApp;
	bool												m_bInitApp = false;
	gcroot<String^>										m_strExtendableTypes;
	map<CString, gcroot<Assembly^>>						m_mapAssembly;
	map<HWND, gcroot<Form^>>							m_mapDesigningForm;
	map<HWND, CompositorInfo*>							m_mapCompositorInfo;
	map<HWND, CTangramWPFObjWrapper*>					m_mapWpfControlWrapper;
	map<IChromeWebBrowser*, gcroot<ChromeWebBrowser^>>	m_mapChromeWebBrowser;

	gcroot<Form^>										m_pCurrentPForm;
	gcroot<PropertyGrid^>								m_pPropertyGrid;
	gcroot<TangramCLR::TangramProxy^>					m_pTangramProxy;
	Object^ _getObject(Object^ key);
	bool _insertObject(Object^ key, Object^ val);
	bool _removeObject(Object^ key);

	template<typename T1, typename T2>
	T2^ _createObject(T1* punk)
	{
		T2^ pRetObj = nullptr;

		if (punk != NULL)
		{
			LONGLONG l = (LONGLONG)punk;
			pRetObj = (T2^)_getObject(l);

			if (pRetObj == nullptr)
			{
				pRetObj = gcnew T2(punk);
				_insertObject(l, pRetObj);
			}
		}
		return pRetObj;
	}
	void ExportCLRObjInfo(CString strPath);
	void ExportAllCLRObjInfo(CString _strPath);
	IDispatch* CreateCLRObj(CString bstrObjID);
	IDispatch* CreateFormAsMdiChild(BSTR bstrObjID, IDispatch* pMdiParent);
	void TangramAction(BSTR bstrXml, IWndNode* pNode);
private:
	map<HWND, gcroot<Form^>>				m_mapForm;
	gcroot<Hashtable^>						m_htObjects;
	gcroot<Object^>							m_pTangramObj;
	gcroot<Assembly^>						m_pSystemAssembly;
	gcroot<EventHandler^>					m_pOnLoad;
	gcroot<EventHandler^>					m_pOnMdiChildActivate;
	gcroot<EventHandler^>					m_pOnCtrlVisible;

	virtual void OnCLRHostExit();
	CTangramWPFObj* CreateWPFControl(IWndNode* pNode, HWND hPWnd, UINT nID);
	HRESULT ActiveCLRMethod(BSTR bstrObjID, BSTR bstrMethod, BSTR bstrParam, BSTR bstrData);
	HRESULT ActiveCLRMethod(IDispatch* pCLRObj, BSTR bstrMethod, BSTR bstrParam, BSTR bstrData);
	HRESULT ProcessCtrlMsg(HWND hCtrl, bool bShiftKey);
	BOOL ProcessFormMsg(HWND hFormWnd, LPMSG lpMsg, int nMouseButton);
	IDispatch* TangramCreateObject(BSTR bstrObjID, HWND hParent, IWndNode* pHostNode);
	int IsWinForm(HWND hWnd);
	int IsSpecifiedType(IUnknown* pUnknown, BSTR bstrName);
	IDispatch* GetCLRControl(IDispatch* CtrlDisp, BSTR bstrNames);
	BSTR GetCtrlName(IDispatch* pCtrl);
	HWND GetMDIClientHandle(IDispatch* pMDICtrl);
	IDispatch* GetCtrlByName(IDispatch* CtrlDisp, BSTR bstrName, bool bFindInChild);
	HWND GetCtrlHandle(IDispatch* pCtrl);
	BSTR GetCtrlType(IDispatch* pCtrl);
	IDispatch* GetCtrlFromHandle(HWND hWnd);
	HWND IsCtrlCanNavigate(IDispatch* ctrl);
	void ReleaseTangramObj(IDispatch*);
	BSTR GetCtrlValueByName(IDispatch* CtrlDisp, BSTR bstrName, bool bFindInChild);
	void SetCtrlValueByName(IDispatch* CtrlDisp, BSTR bstrName, bool bFindInChild, BSTR strVal);
	HRESULT NavigateURL(IWndNode* pNode, CString strURL, IDispatch* dispObjforScript);
	Control^ GetCanSelect(Control^ ctrl, bool direct);
	void AttachVSPropertyWnd(HWND);
	void SelectObj(IDispatch*);

	HWND GetHwnd(HWND parent, int x, int y, int width, int height);
	void OnDestroyChromeBrowser(IChromeWebBrowser*);

	void* Extend(CString strKey, CString strData, CString strFeatures);
	bool IsSupportDesigner();
	HICON GetAppIcon(int nIndex);

	void WindowCreated(LPCTSTR strClassName, LPCTSTR strName, HWND hPWnd, HWND hWnd);
	void WindowDestroy(HWND hWnd);
	void SelectNode(IWndNode* );
	Object^ InitTangramCtrl(Form^ pForm, Control^ pCtrl, bool bSave, CTangramXmlParse* pParse);
	Object^ InitTangramNode(IWndNode* pNode, Control^ pCtrl, bool bSave, CTangramXmlParse* pParse);
	void SetObjectProperty(IDispatch* pObj, BSTR bstrPropertyName, BSTR bstrPropertyValue);

	static void OnLoad(Object ^sender, EventArgs ^e);
	static void OnMdiChildActivate(Object ^sender, EventArgs ^e);
	static void OnApplicationExit(Object ^sender, EventArgs ^e);
	static void OnVisibleChanged(Object ^sender, EventArgs ^e);
	static void OnAfterSelect(Object ^sender, TreeViewEventArgs ^e);
	static void OnItemSelectionChanged(Object ^sender, ListViewItemSelectionChangedEventArgs ^e);
	static void OnSelectedObjectsChanged(Object ^sender, EventArgs ^e);
	static void OnControlAdded(Object ^sender, ControlEventArgs ^e);
	static void OnControlRemoved(Object ^sender, ControlEventArgs ^e);
	static void OnHandleDestroyed(Object ^sender, EventArgs ^e);
	static void OnClick(Object ^sender, EventArgs ^e);
};

class CTangramWPFObjWrapper : public CTangramWPFObj
{
	friend CTangramCLRProxy;
	static HWND FindNextTabStop(HWND wnd, bool forward)
	{
		HWND nextstop = NULL;
		HWND nextwnd = wnd;
		do
		{
			// get the next/previous window in the z-order
			nextwnd = ::GetWindow(nextwnd, forward ? GW_HWNDNEXT : GW_HWNDPREV);

			// if we are at the end of the z-order, start from the top/bottom
			if (nextwnd == NULL)
				nextwnd = ::GetWindow(wnd, forward ? GW_HWNDFIRST : GW_HWNDLAST);

			// if we returned to the same control then we iterated the entire z-order
			if (nextwnd == wnd)
				break;

			// get the window style and check the WS_TABSTOP style
			DWORD style = (DWORD)::GetWindowLongPtr(nextwnd, GWL_STYLE);
			if ((style & WS_TABSTOP) == WS_TABSTOP)
				nextstop = nextwnd;
		} while (nextstop == NULL);

		return nextstop;
	}

	static IntPtr ChildHwndSourceHook(
		IntPtr hwnd,
		int msg,
		IntPtr wParam,
		IntPtr lParam,
		bool% handled)
	{
		if (msg == WM_GETDLGCODE)
		{
			handled = true;
			return System::IntPtr(DLGC_WANTCHARS | DLGC_WANTTAB | DLGC_WANTARROWS | DLGC_WANTALLKEYS);
		}
		else if (msg == WM_CHAR)
		{
			if (wParam.ToInt32() == VK_TAB)
			{
				handled = true;
				HWND nextTabStop = FindNextTabStop((HWND)hwnd.ToPointer(),
					(GetKeyState(VK_SHIFT) & 0x8000) != 0x8000);
				if (nextTabStop)
					::SetFocus(nextTabStop);
			}
		}

		return System::IntPtr::Zero;
	}

public:
	CTangramWPFObjWrapper(void)
	{
		m_hwndWPF = nullptr;
	}

	~CTangramWPFObjWrapper(void);

	template <typename T>
	T^ Control()
	{
		System::Windows::UIElement^ obj = m_pUIElement;
		return dynamic_cast<T^>(obj);
	}

	gcroot<System::Windows::FrameworkElement^> m_pUIElement;
	gcroot<System::Windows::Interop::HwndSource^> m_pSource;
	CTangramWPFObj* CreateControl(Type^ type, HWND parent, DWORD style, int x, int y, int width, int height);

	BOOL IsVisible();
	void InvalidateVisual();
	void Focusable(BOOL bFocus);
	void ShowVisual(BOOL bShow);
	//static void OnLoaded(Object ^sender, System::Windows::RoutedEventArgs ^e);
	//static void OnUnloaded(Object ^sender, System::Windows::RoutedEventArgs ^e);
	//static void OnMouseEnter(Object ^sender, System::Windows::Input::MouseEventArgs ^e);
	//static void OnSizeChanged(Object ^sender, System::Windows::SizeChangedEventArgs ^e);
	//static void OnIsVisibleChanged(Object ^sender, System::Windows::DependencyPropertyChangedEventArgs e);
};

extern _ATL_FUNC_INFO Initialize;
extern _ATL_FUNC_INFO Destroy;
extern _ATL_FUNC_INFO TabChange;
extern _ATL_FUNC_INFO IPCMsg2;

class CCompositorManagerClrEvent : public IDispEventSimpleImpl</*nID =*/ 1, CCompositorManagerClrEvent, &__uuidof(_ITangramObjEvents)>
{
public:
	CCompositorManagerClrEvent();
	virtual ~CCompositorManagerClrEvent();

	gcroot<Object^> m_pCompositorManager;

	void __stdcall  OnDestroy();
	void __stdcall  OnTabChange(IWndNode* sender, int nActivePage,int nOldPage);
	void __stdcall  OnInitialize(IDispatch* pHtmlWnd, BSTR bstrUrl);
	void __stdcall  OnIPCMsg(ICompositor* sender, BSTR bstrType, BSTR bstrContent, BSTR bstrFeature);
	BEGIN_SINK_MAP(CCompositorManagerClrEvent)
		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_ITangramObjEvents), /*dispid =*/ 0x00000001, OnInitialize, &Initialize)
		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_ITangramObjEvents), /*dispid =*/ 0x00000006, OnDestroy, &Destroy)
		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_ITangramObjEvents), /*dispid =*/ 0x00000009, OnTabChange, &TabChange)
		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(_ITangramObjEvents), /*dispid =*/ 0x0000000d, OnIPCMsg, &IPCMsg2)
	END_SINK_MAP()
};

