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

#include "stdafx.h"
#include "dllmain.h"
#include "tangramobj.h"
#include "DefaultNTPCtrl.h"

namespace TangramCLR {
	System::Void DefaultNTPCtrl::BtnNewPage_Click(System::Object^ sender, System::EventArgs^ e) {
		TangramCLR::Tangram::CreateBrowser(System::IntPtr::Zero, L"https://www.tangram.dev/cloud/newtangrampage.html|");
	}

	System::Void DefaultNTPCtrl::BtnTangramSite_Click(System::Object^ sender, System::EventArgs^ e) {
		TangramCLR::Tangram::CreateBrowser(System::IntPtr::Zero, L"https://www.tangram.dev|");
	}

	System::Void DefaultNTPCtrl::LoadNode(TreeNode^ pNode, CTangramXmlParse* pParse)
	{
		if (pParse)
		{
			int nCount = pParse->GetCount();
			for (int i = 0; i < nCount; i++)
			{
				CTangramXmlParse* _pParse = pParse->GetChild(i);
				if (_pParse)
				{
					CString name = _pParse->name();
					if (name == _T("tangramxml"))
					{
						HWND hWnd = (HWND)this->TangramTreeView->Handle.ToPointer();
						if (hostnode)
						{
							CompositorManager^ pCompositorManager = hostnode->CompositorManager;

							ICompositor* pCompositor = nullptr;
							hostnode->m_pWndNode->get_Compositor(&pCompositor);
							CComBSTR bstrName("");
							pCompositor->get_Name(&bstrName);
							String^ name = pNode->Name + L".";
							name += TangramTreeView->Name;
							name += L"." + BSTR2STRING(bstrName);
							BSTR strName = STRING2BSTR(name->ToLower());
							Compositor^ _pCompositor = pCompositorManager->CreateCompositor(TangramTreeView->Handle, name);
							_pCompositor->Open(L"default", BSTR2STRING(_pParse->xml()));
						}
					}
					else
					{
						bool isTreeNode = _pParse->attrBool(_T("treenode"), false);
						if (isTreeNode)
						{
							TreeNode^ pChildNode = pNode->Nodes->Add(BSTR2STRING(_pParse->text()));
							if (pChildNode)
							{
								CString strTagName = name + _T("_tag");
								CTangramXmlParse* pChild2 = pParse->GetChild(strTagName);
								if (pChild2)
								{
									pChildNode->Tag = BSTR2STRING(pChild2->xml());
								}
								LoadNode(pChildNode, pParse->GetChild(i));
							}
						}
					}
				}
			}
		}
	}

	System::Void DefaultNTPCtrl::DefaultNTPCtrl_Load(System::Object^ sender, System::EventArgs^ e) {
		hostnode = TangramCLR::Tangram::CreatingNode;
		CString strXml = _T("");
		if (theApp.m_pTangramImpl)
		{
			auto it = theApp.m_pTangramImpl->m_mapValInfo.find(_T("ntpdata"));
			if (theApp.m_pTangramImpl->m_strNtpDataXml!=_T(""))
				strXml = theApp.m_pTangramImpl->m_strNtpDataXml;
			else
				strXml = theApp.m_pTangramImpl->m_strAppPath + _T("defaultntpdata.xml");
		}
		CTangramXmlParse m_Parse;
		if (m_Parse.LoadXml(strXml)|| m_Parse.LoadFile(strXml))
		{
			if (TangramTreeView->Nodes->Count == 0)
			{
				LoadNode(TangramTreeView->Nodes->Add(BSTR2STRING(m_Parse.text())), &m_Parse);
			}
		}
		this->TangramTreeView->ExpandAll();
	}

	System::Void DefaultNTPCtrl::TangramTreeView_NodeMouseDoubleClick(System::Object^ sender, System::Windows::Forms::TreeNodeMouseClickEventArgs^ e) {
		if (e->Node->Tag)
		{
			String^ strTag = e->Node->Tag->ToString();
			if (hostnode)
			{
				WndNode^ pHostNode = hostnode->HostNode;
				if (pHostNode == nullptr)
				{
					if (bindnode == nullptr)
					{
						String^ name = hostnode->Attribute[L"bindnode"];
						if (String::IsNullOrEmpty(name) == false)
						{
							WndNodeCollection^ pCol = nullptr;
							hostnode->RootNode->GetNodes(name, bindnode, pCol);
							if (pCol)
							{
								delete pCol;
							}
						}
					}
					if (bindnode != nullptr)
						pHostNode = bindnode;
				}
				if (pHostNode)
				{
					CString strXml = strTag;
					CTangramXmlParse m_Parse;
					if (m_Parse.LoadXml(strXml))
					{
						CString strAction = m_Parse.attr(_T("action"),_T(""));
						if (strAction != _T(""))
						{
							CTangramXmlParse* pChild = m_Parse.GetChild(strAction);
							if (pChild)
							{
								if(strAction==_T("doubleclick"))
									pHostNode->Open(BSTR2STRING(m_Parse.name()), BSTR2STRING(pChild->xml()));
								else if (strAction == _T("openurl"))
								{
									TangramCLR::Tangram::CreateBrowser(System::IntPtr::Zero, BSTR2STRING(pChild->attr(_T("url"),_T("")) + _T("|")));
								}
							}

						}
							
					}
				}
			}
		}
	}

	System::Void DefaultNTPCtrl::TangramTreeView_NodeMouseClick(System::Object^ sender, System::Windows::Forms::TreeNodeMouseClickEventArgs^ e) {
	}

	System::Void DefaultNTPCtrl::TangramTreeView_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {
		if (e->Node->Tag)
		{
			String^ strTag = e->Node->Tag->ToString();
			if (hostnode)
			{
				WndNode^ pHostNode = hostnode->HostNode;
				if (pHostNode == nullptr)
				{
					if (bindnode == nullptr)
					{
						String^ name = hostnode->Attribute[L"bindnode"];
						if (String::IsNullOrEmpty(name) == false)
						{
							WndNodeCollection^ pCol = nullptr;
							hostnode->RootNode->GetNodes(name, bindnode, pCol);
							if (pCol)
								delete pCol;
						}
					}
					if (bindnode != nullptr)
						pHostNode = bindnode;
				}
				if (pHostNode)
				{
					CString strXml = strTag;
					CTangramXmlParse m_Parse;
					if (m_Parse.LoadXml(strXml))
					{
						CTangramXmlParse* pChild = m_Parse.GetChild(_T("afterselected"));
						if(pChild)
							pHostNode->Open(BSTR2STRING(m_Parse.name()), BSTR2STRING(pChild->xml()));
					}
				}
			}
		}
	}
}