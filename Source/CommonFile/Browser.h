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
* http://www.tangramteam.com
*
*
********************************************************************************/

#pragma once
#include "ExDispID.h"

IHTMLDocument2* GetDocInterface(HWND hWnd);
IWebBrowser2*	GetWebBrowser2(HWND hWnd);

extern _ATL_FUNC_INFO StatusTextChange;
extern _ATL_FUNC_INFO ProgressChange;
extern _ATL_FUNC_INFO CommandStateChange;
extern _ATL_FUNC_INFO DownloadBegin;
extern _ATL_FUNC_INFO DownloadComplete;
extern _ATL_FUNC_INFO TitleChange;
extern _ATL_FUNC_INFO PropertyChange;
extern _ATL_FUNC_INFO BeforeNavigate2;
extern _ATL_FUNC_INFO NewWindow2;
extern _ATL_FUNC_INFO NavigateComplete2;
extern _ATL_FUNC_INFO DocumentComplete;
//extern _ATL_FUNC_INFO OnQuit;
//extern _ATL_FUNC_INFO OnVisible;
//extern _ATL_FUNC_INFO OnToolBar;
//extern _ATL_FUNC_INFO OnMenuBar;
//extern _ATL_FUNC_INFO OnStatusBar;
//extern _ATL_FUNC_INFO OnFullScreen;
//extern _ATL_FUNC_INFO OnTheaterMode;
extern _ATL_FUNC_INFO WindowSetResizable;
extern _ATL_FUNC_INFO WindowSetLeft;
extern _ATL_FUNC_INFO WindowSetTop;
extern _ATL_FUNC_INFO WindowSetWidth;
extern _ATL_FUNC_INFO WindowSetHeight;
extern _ATL_FUNC_INFO WindowClosing;
extern _ATL_FUNC_INFO ClientToHostWindow;
extern _ATL_FUNC_INFO SetSecureLockIcon;
extern _ATL_FUNC_INFO FileDownload;
extern _ATL_FUNC_INFO NavigateError;
extern _ATL_FUNC_INFO PrintTemplateInstantiation;
extern _ATL_FUNC_INFO PrintTemplateTeardown;
extern _ATL_FUNC_INFO UpdatePageStatus;
extern _ATL_FUNC_INFO PrivacyImpactedStateChange;
extern _ATL_FUNC_INFO NewWindow3;
extern _ATL_FUNC_INFO SetPhishingFilterStatus;
extern _ATL_FUNC_INFO WindowStateChanged;
extern _ATL_FUNC_INFO NewProcess;
extern _ATL_FUNC_INFO ThirdPartyUrlBlocked;
extern _ATL_FUNC_INFO RedirectXDomainBlocked;
extern _ATL_FUNC_INFO BeforeScriptExecute;
extern _ATL_FUNC_INFO WebWorkerStarted;
extern _ATL_FUNC_INFO WebWorkerFinsihed;

class CWebbrowserEvent : public IDispEventSimpleImpl< 1, CWebbrowserEvent, &__uuidof(DWebBrowserEvents2)>
{
public:
	CWebbrowserEvent();
	//virtual void __stdcall OnStatusTextChange(BSTR Text){};
	//virtual void __stdcall OnProgressChange(long Progress, long ProgressMax){}
	//virtual void __stdcall OnCommandStateChange(long Command, VARIANT_BOOL Enable){}
	//virtual void __stdcall OnDownloadBegin(){}
	//virtual void __stdcall OnDownloadComplete(){}
	//virtual void __stdcall OnTitleChange(BSTR Text){}
	//virtual void __stdcall OnPropertyChange(BSTR szProperty){}
	//virtual void __stdcall OnBeforeNavigate2(IDispatch* pDisp, VARIANT* URL, VARIANT* Flags, VARIANT* TargetFrameName, VARIANT* PostData, VARIANT* Headers, VARIANT_BOOL* Cancel){}
	//virtual void __stdcall OnNewWindow2(IDispatch** ppDisp, VARIANT_BOOL* Cancel){}
	virtual void __stdcall OnNavigateComplete2(IDispatch* pDisp, VARIANT* URL){}
	virtual void __stdcall OnDocumentComplete(IDispatch* pDisp, VARIANT* URL){}
	//virtual void __stdcall OnOnQuit(){}
	//virtual void __stdcall OnOnVisible(VARIANT_BOOL Visible){}
	//virtual void __stdcall OnOnToolBar(VARIANT_BOOL ToolBar){}
	//virtual void __stdcall OnOnMenuBar(VARIANT_BOOL MenuBar){}
	//virtual void __stdcall OnOnStatusBar(VARIANT_BOOL StatusBar){}
	//virtual void __stdcall OnOnFullScreen(VARIANT_BOOL FullScreen){}
	//virtual void __stdcall OnOnTheaterMode(VARIANT_BOOL TheaterMode){}
	//virtual void __stdcall OnWindowSetResizable(VARIANT_BOOL Resizable){}
	//virtual void __stdcall OnWindowSetLeft(long Left){}
	//virtual void __stdcall OnWindowSetTop(long Top){}
	//virtual void __stdcall OnWindowSetWidth(long Width){}
	//virtual void __stdcall OnWindowSetHeight(long Height){}
	//virtual void __stdcall OnWindowClosing(VARIANT_BOOL IsChildWindow, VARIANT_BOOL* Cancel){}
	//virtual void __stdcall OnClientToHostWindow(long* CX, long* CY){}
	//virtual void __stdcall OnSetSecureLockIcon(long SecureLockIcon){}
	//virtual void __stdcall OnFileDownload(VARIANT_BOOL ActiveDocument, VARIANT_BOOL* Cancel){}
	//virtual void __stdcall OnNavigateError(IDispatch* pDisp, VARIANT* URL, VARIANT* Frame, VARIANT* StatusCode, VARIANT_BOOL* Cancel){}
	//virtual void __stdcall OnPrintTemplateInstantiation(IDispatch* pDisp){}
	//virtual void __stdcall OnPrintTemplateTeardown(IDispatch* pDisp){}
	//virtual void __stdcall OnUpdatePageStatus(IDispatch* pDisp, VARIANT* nPage, VARIANT* fDone){}
	//virtual void __stdcall OnPrivacyImpactedStateChange(VARIANT_BOOL bImpacted){}
	//virtual void __stdcall OnNewWindow3(IDispatch** ppDisp, VARIANT_BOOL* Cancel, ULONG dwFlags, BSTR bstrUrlContext, BSTR bstrUrl){}
	//virtual void __stdcall OnSetPhishingFilterStatus(long PhishingFilterStatus){}
	//virtual void __stdcall OnWindowStateChanged(ULONG dwWindowStateFlags, ULONG dwValidFlagsMask){}
	//virtual void __stdcall OnNewProcess(long lCauseFlag, IDispatch* pWB2, VARIANT_BOOL* Cancel){}
	//virtual void __stdcall OnThirdPartyUrlBlocked(VARIANT* URL, ULONG dwCount){}
	//virtual void __stdcall OnRedirectXDomainBlocked(IDispatch* pDisp, VARIANT* StartURL, VARIANT* RedirectURL, VARIANT* Frame, VARIANT* StatusCode){}
	//virtual void __stdcall OnBeforeScriptExecute(IDispatch* pDispWindow){}
	//virtual void __stdcall OnWebWorkerStarted(ULONG dwUniqueID, BSTR bstrWorkerLabel){}
	//virtual void __stdcall OnWebWorkerFinsihed(ULONG dwUniqueID){}
	BEGIN_SINK_MAP(CWebbrowserEvent)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000066, OnStatusTextChange, &StatusTextChange)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x0000006c, OnProgressChange, &ProgressChange)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000069, OnCommandStateChange, &CommandStateChange)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x0000006a, OnDownloadBegin, &DownloadBegin)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000068, OnDownloadComplete, &DownloadComplete)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000071, OnTitleChange, &TitleChange)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000070, OnPropertyChange, &PropertyChange)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x000000fa, OnBeforeNavigate2, &BeforeNavigate2)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x000000fb, OnNewWindow2, &NewWindow2)
		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x000000fc, OnNavigateComplete2, &NavigateComplete2)
		SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000103, OnDocumentComplete, &DocumentComplete)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x000000fd, OnQuit, &OnQuit)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x000000fe, OnVisible, &OnVisible)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x000000ff, OnToolBar, &OnToolBar)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000100, OnMenuBar, &OnMenuBar)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000101, OnStatusBar, &OnStatusBar)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000102, OnFullScreen, &OnFullScreen)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000104, OnTheaterMode, &OnTheaterMode)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000106, OnWindowSetResizable, &WindowSetResizable)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000108, OnWindowSetLeft, &WindowSetLeft)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000109, OnWindowSetTop, &WindowSetTop)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x0000010a, OnWindowSetWidth, &WindowSetWidth)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x0000010b, OnWindowSetHeight, &WindowSetHeight)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000107, OnWindowClosing, &WindowClosing)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x0000010c, OnClientToHostWindow, &ClientToHostWindow)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x0000010d, OnSetSecureLockIcon, &SetSecureLockIcon)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x0000010e, OnFileDownload, &FileDownload)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x0000010f, OnNavigateError, &NavigateError)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x000000e1, OnPrintTemplateInstantiation, &PrintTemplateInstantiation)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x000000e2, OnPrintTemplateTeardown, &PrintTemplateTeardown)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x000000e3, OnUpdatePageStatus, &UpdatePageStatus)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000110, OnPrivacyImpactedStateChange, &PrivacyImpactedStateChange)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000111, OnNewWindow3, &NewWindow3)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x0000011a, OnSetPhishingFilterStatus, &SetPhishingFilterStatus)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x0000011b, OnWindowStateChanged, &WindowStateChanged)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x0000011c, OnNewProcess, &NewProcess)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x0000011d, OnThirdPartyUrlBlocked, &ThirdPartyUrlBlocked)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x0000011e, OnRedirectXDomainBlocked, &RedirectXDomainBlocked)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000122, OnBeforeScriptExecute, &BeforeScriptExecute)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000120, OnWebWorkerStarted, &WebWorkerStarted)
		//SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(DWebBrowserEvents2), /*dispid =*/ 0x00000121, OnWebWorkerFinsihed, &WebWorkerFinsihed)
	END_SINK_MAP()
};
