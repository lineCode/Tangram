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

#include "StdAfx.h"
#include "dllmain.h"
#include "TangramObj.h"
#include "TangramProxy.h"

namespace TangramCLR
{
	TangramProxy::TangramProxy(void)
	{
		m_pCurrentNode = nullptr;
		theAppProxy.m_pTangramProxy = this;
	}

	int TangramProxy::TangramInit(String^ strInit)
	{
		CString strInfo = strInit;
		if (strInfo != _T(""))
		{
			__int64 nPointer = _wtoi64(strInfo);
			if (nPointer)
			{
				theApp.m_pTangramImpl = (CTangramImpl*)nPointer;
				theApp.m_pTangramImpl->m_pCLRProxy = &theAppProxy;
				//theApp.m_pTangramImpl->m_pCLRProxy = &theAppProxy;
				theApp.m_pTangramImpl->m_pTangramCLRAppProxy = static_cast<ITangramAppProxy*>(&theApp);
				//20180817
				if (theApp.m_pTangram == nullptr)
				{
					HMODULE hModule = ::GetModuleHandle(_T("TangramCore.dll"));
					if (hModule) {
						typedef ITangram*(__stdcall * GetTangram)();
						GetTangram _pTangramFunction;
						_pTangramFunction = (GetTangram)GetProcAddress(hModule, "GetTangram");
						if (_pTangramFunction != NULL) {
							theApp.m_pTangram = _pTangramFunction();
						}
					}
				}
			}
		}
		return 0;
	};

	void TangramProxy::Obj_HandleCreated(Object^ sender, EventArgs^ e)
	{
		Control^ pCtrl = (Control^)sender;
		HWND hWnd = (HWND)pCtrl->Handle.ToInt64();
		if (m_pCurrentNode)
		{
			LONGLONG h = 0;
			m_pCurrentNode->get_Handle(&h);
			ICompositor* pCompositor = nullptr;
			m_pCurrentNode->get_Compositor(&pCompositor);
			pCompositor->get_HWND(&h);
			if (::IsWindow((HWND)h))
			{
				CtrlInfo m_CtrlInfo;
				m_CtrlInfo.m_pCtrlDisp = nullptr;
				//IntPtr nDisp;
				try
				{
					IUnknown* pUnk = (IUnknown*)Marshal::GetIDispatchForObject(pCtrl).ToPointer();
					CComQIPtr<IDispatch> pDisp(pUnk);
					if (pDisp)
						m_CtrlInfo.m_pCtrlDisp = pDisp.p;
				}
				catch (InvalidCastException^ e)
				{
					String^ s = e->Message;
				}
				finally
				{
					if (m_CtrlInfo.m_pCtrlDisp)
					{
						m_CtrlInfo.m_hWnd = (HWND)pCtrl->Handle.ToInt64();
						m_CtrlInfo.m_strName = STRING2BSTR(pCtrl->Name);
						ICompositorManager* pCompositorManager = nullptr;
						m_pCurrentNode->get_CompositorManager(&pCompositorManager);
						m_CtrlInfo.m_pCompositorManager = pCompositorManager;
						m_CtrlInfo.m_pNode = m_pCurrentNode;
						::SendMessage((HWND)h, WM_TANGRAMMSG, (WPARAM)&m_CtrlInfo, 2048);
					}
				}
			}
		}

		Control^ pParentCtrl = pCtrl->Parent;
		if (pParentCtrl != nullptr)
		{
			if (pCtrl->Dock == DockStyle::Fill)
			{
				m_pCurrentNode->put_DockObj(STRING2BSTR(pCtrl->Name), (LONGLONG)pCtrl->Handle.ToInt64());
			}
		}

		Control::ControlCollection^ pControls = pCtrl->Controls;
		for each (Control^ _pCtrl in pControls)
		{
			Obj_HandleCreated(_pCtrl, e);
		}
	}

	void TangramProxy::OnHandleDestroyed(Object ^sender, EventArgs ^e)
	{
		Control^ pCtrl = ((Control^)sender);
		HWND hWnd = (HWND)pCtrl->Handle.ToInt64();
	}
}

