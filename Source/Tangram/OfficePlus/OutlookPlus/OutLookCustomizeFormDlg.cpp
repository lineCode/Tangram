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

// TangramOutLookCustomizeFormDlg.cpp : COutLookCustomizeFormDlg implementation
#include "../../stdafx.h"
#include "../../TangramApp.h"
#include "../../Compositor.h"
#include "OutLookAddin.h"
#include "OutLookCustomizeFormDlg.h"

// COutLookCustomizeFormDlg
namespace OfficePlus
{
	namespace OutLookPlus
	{
		COutLookCustomizeFormDlg::COutLookCustomizeFormDlg()
			: m_strName(_T(""))
		{
			m_pOutLookInspector = NULL;
		}

		COutLookCustomizeFormDlg::~COutLookCustomizeFormDlg()
		{
		}

		LRESULT COutLookCustomizeFormDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
		{
			CAxDialogImpl<COutLookCustomizeFormDlg>::OnInitDialog(uMsg, wParam, lParam, bHandled);
			bHandled = true;
			return 1;  
		}

		LRESULT COutLookCustomizeFormDlg::OnClickedOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
		{
			if (m_pOutLookInspector)
			{
				OutLook::Pages* pPages = NULL;
				m_pOutLookInspector->m_pInspector->get_ModifiedFormPages((IDispatch**)&pPages);
				HWND hwnd = ::GetDlgItem(m_hWnd, IDC_EDIT_OUTLOOKPAGE);
				::GetWindowText(hwnd, g_pTangram->m_szBuffer, 255);
				m_strName = CString(g_pTangram->m_szBuffer);
				m_strName.Trim();
				if (m_strName != _T(""))
				{
					CComPtr<IDispatch> pItem;
					pPages->Item(CComVariant(L""), &pItem);
					if (pItem)
					{
						::MessageBox(m_hWnd, _T("Page is exists, please input a new name!"), _T("Customize OutLook Form"), MB_OK);
						return 0;
					}
					else
					{
						pPages->Add(CComVariant(m_strName), &pItem);
						if (pItem)
						{
							BSTR bstrName = m_strName.AllocSysString();
							m_pOutLookInspector->m_pInspector->ShowFormPage(bstrName);
							CComQIPtr<IOleWindow> pWnd(pItem);
							if (pWnd)
							{
								HWND hWnd = 0;
								pWnd->GetWindow(&hWnd);
								if (hWnd)
								{
									COutLookPageWnd* pOutLookPageWnd = new COutLookPageWnd();
									pOutLookPageWnd->m_pOutLookInspector = m_pOutLookInspector;
									pOutLookPageWnd->m_hFrameWnd = ::GetParent(hWnd);
									HWND hParent = ::GetParent(pOutLookPageWnd->m_hFrameWnd);
									::ShowWindow(hParent, SW_HIDE);
									pOutLookPageWnd->m_strName = m_strName;
									CString strXml = _T("");
									CString strName = m_strName;
									strName.Replace(_T(" "),_T("_"));
									strXml.Format(_T("<%s><window><node name=\"Start\" /></window></%s>"), strName, strName);
									pOutLookPageWnd->m_strXml =strXml;
									CComQIPtr<MSForm::_UserForm> pForm(pItem);
									pOutLookPageWnd->m_pForm = pForm.p;
									pOutLookPageWnd->m_pForm->AddRef();
									pOutLookPageWnd->SubclassWindow(hParent);
									m_pOutLookInspector->m_mapOutLookPage[m_strName] = pOutLookPageWnd;
									pOutLookPageWnd->DesignPage();
								}
								m_pOutLookInspector->m_pInspector->SetCurrentFormPage(bstrName);
								::SysFreeString(bstrName);
							}
						}
					}
				}
				else
				{
					return 0;
				}
			}
			EndDialog(wID);
			return 0;
		}

		LRESULT COutLookCustomizeFormDlg::OnClickedCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
		{
			EndDialog(wID);
			return 0;
		}
	}
}