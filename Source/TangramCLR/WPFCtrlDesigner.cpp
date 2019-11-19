#include "stdafx.h"
#include "TangramBase.h"
#include "WPFCtrlDesigner.h"
#include "TangramClrProxy.h"

extern CTangramCLRProxy theAppProxy;

using namespace System::Runtime::InteropServices;

namespace TangramDesigner
{
	System::Void WPFCtrlDesigner::WPFCtrlDesigner_Load(System::Object^  sender, System::EventArgs^  e)
	{
		CString filePath = Application::ExecutablePath->ToLower();
		int nPos = filePath.ReverseFind('.');
		CString strLib = filePath.Left(nPos).MakeLower();
		CString strAssemblys = _T("");
		CString _strCurAssembly = m_strCurAssembly;
		if (_strCurAssembly != strLib)
		{
			String^ _strLib = BSTR2STRING(filePath);
			String^ strAssemblyLib = L"";
			if (!m_pTangramAssemblyDic->TryGetValue(_strLib, strAssemblyLib))
			{
				strLib = filePath.MakeLower();
				Assembly^ m_pDotNetAssembly = nullptr;
				String^ strCtls = L"";
				try
				{
					m_pDotNetAssembly = Assembly::LoadFile(Application::ExecutablePath->ToLower());
					if (m_pDotNetAssembly == nullptr)
						return;
				}
				catch (ArgumentNullException^ e)
				{
					Debug::WriteLine(L"Tangram WPFCtrlDesigner_Load: " + e->Message);
				}
				catch (ArgumentException^ e)
				{
					Debug::WriteLine(L"Tangram WPFCtrlDesigner_Load: " + e->Message);
				}
				catch (FileNotFoundException^ e)
				{
					Debug::WriteLine(L"Tangram WPFCtrlDesigner_Load: " + e->Message);
				}
				catch (FileLoadException^ e)
				{
					Debug::WriteLine(L"Tangram WPFCtrlDesigner_Load: " + e->Message);
				}
				catch (BadImageFormatException^ e)
				{
					Debug::WriteLine(L"Tangram WPFCtrlDesigner_Load: " + e->Message);
				}
				finally
				{
					if (m_pDotNetAssembly != nullptr)
					{
						cli::array<Type^>^ pArray = m_pDotNetAssembly->GetExportedTypes();
						for each (Type^ type in pArray)
						{
							if (type->IsSubclassOf(System::Windows::FrameworkElement::typeid))
							{
								strCtls += type->AssemblyQualifiedName;
								strCtls += L"|";
							}
						}
					}
				}
				if (m_pDotNetAssembly == nullptr)
				{
					return;
				}
				CString strCtrls = strCtls;
				if (strCtrls != _T("")) {
					m_strCurAssembly = BSTR2STRING(strLib);
					strAssemblys = strCtrls;
					m_strCurAssemblys = BSTR2STRING(strAssemblys);
					m_pTangramAssemblyDic->Add(_strLib, m_strCurAssemblys);
				}
				else
				{
					strAssemblys = _T("");
					//::MessageBox(NULL, _T("Please Select a Valided WPF Component Library"), _T("Tangram Designer"), MB_ICONWARNING);
					return;
				}

			}
			_strCurAssembly = strLib;
			if (strAssemblys != _T(""))
			{
				comboBoxCLRCtrl->Items->Clear();
				nPos = strAssemblys.Find(_T("|"));
				while (nPos != -1)
				{
					CString strID = strAssemblys.Left(nPos);
					strAssemblys = strAssemblys.Mid(nPos + 1);
					nPos = strAssemblys.Find(_T("|"));
					comboBoxCLRCtrl->Items->Add(BSTR2STRING(strID));
				}
				comboBoxCLRCtrl->SelectedIndex = 0;
			}
		}
	}

	System::Void WPFCtrlDesigner::btnCreate_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBoxCLRCtrl->SelectedItem == nullptr)
			return;
		IWndNode* pDesignerNode = NULL;
		CComPtr<ITangram> pTangram;
		pTangram.CoCreateInstance(CComBSTR(L"tangram.tangram.1"));
		pTangram->get_DesignNode(&pDesignerNode);
		if (pDesignerNode == NULL)
			return;
		CString strID = comboBoxCLRCtrl->SelectedItem->ToString();
		if (strID != _T(""))
		{
			pDesignerNode->put_Attribute(CComBSTR("id"), CComBSTR("WPFCtrl"));
			pDesignerNode->put_Attribute(CComBSTR("cnnid"), CComBSTR(strID));
			LONGLONG h = 0;
			pDesignerNode->get_Handle(&h);
			if (::IsWindow((HWND)h))
				::SendMessage((HWND)h, WM_TANGRAMMSG, (WPARAM)0, (LPARAM)strID.GetBuffer());
		}

		//CString strID = comboBoxCLRCtrl->SelectedItem->ToString();
		//CString strObjID = strID;
		//ViewType nType = ViewType::BlankView;
		//pDesignerNode->get_NodeType(&nType);
		//if (nType != ViewType::BlankView)
		//	return;
		//IWndNode* pRootNode = NULL;
		//pDesignerNode->get_RootNode(&pRootNode);
		//LONGLONG hRoot = 0;
		//pRootNode->get_Handle(&hRoot);
		//HWND _hwnd = (HWND)hRoot;
		//LONGLONG h = 0;
		//HWND hWnd = NULL;
		//HWND hPWnd = NULL;
		//
		//strID = _T("");
		//CString strVal = _T("");
		//int nPages = 0;

		//String^ _strObjID = comboBoxCLRCtrl->SelectedItem->ToString();
		//
		//strObjID = _strObjID;
		//strID = L"wpfctrl";
		//CTangramXmlParse m_Parse;
		//BOOL b = m_Parse.LoadXml(_T("<splitter><window></window></splitter>"));
		//if (b)
		//{
		//	CComBSTR bstrName(L"");
		//	pDesignerNode->get_Name(&bstrName);
		//	CTangramXmlParse* pWndNode = m_Parse.GetChild(_T("window"));
		//	pDesignerNode->get_Handle(&h);
		//	RECT rc;
		//	::GetClientRect((HWND)h, &rc);
		//	CString strNewName = OLE2T(bstrName);
		//	CTangramXmlParse* pNewNode = pWndNode->AddTabNode(strNewName, strObjID, strID, _T(""), nPages);
		//	CString str = m_Parse.xml();
		//	IWndNode* pParent = NULL;
		//	pDesignerNode->get_ParentNode(&pParent);

		//	ViewType m_type;
		//	if (pParent)
		//	{
		//		pParent->get_NodeType(&m_type);
		//		switch (m_type)
		//		{
		//		case ViewType::Splitter:
		//		{
		//			pParent->get_Handle(&h);
		//		}
		//		break;
		//		default:
		//			pDesignerNode->get_Handle(&h);
		//			break;
		//		}
		//	}
		//	else
		//	{
		//		pDesignerNode->get_Handle(&h);
		//	}

		//	hPWnd = (HWND)h;
		//	if(::IsWindow(hPWnd))
		//		::SendMessage(hPWnd, WM_TANGRAMMSG, (WPARAM)pNewNode, (LPARAM)str.GetBuffer()/*pNode*/);
		//}

	}
}