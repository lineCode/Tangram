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
* http://www.tangramteam.com/
*
********************************************************************************/

//#include "StdAfx.h"
#include "TangramXmlParse.h"
CTangramXmlParse::CTangramXmlParse(void)
{
	Initialize();
	elem = NULL;	
	m_pParentParse = NULL;
}

CTangramXmlParse::~CTangramXmlParse(void)
{
	Clear();
	//if (m_pUnknown) 
	//{
	//	m_pUnknown->Release();
	//	m_pUnknown = NULL;
	//}
	elem = NULL;
}


void CTangramXmlParse::_CTangramXmlParse(CComPtr<IXMLDOMElement> _elem)
{
	Initialize();
	elem = _elem;
	//m_pUnknown = NULL;
	//elem->QueryInterface(IID_IUnknown,(void**)&m_pUnknown);

	CComPtr<IXMLDOMNodeList> pList = NULL;
	if (_elem->get_childNodes(&pList) == S_OK)
	{
		_CTangramXmlParse(pList);
	}
}

void CTangramXmlParse::_CTangramXmlParse(CComPtr<IXMLDOMNode> _node)
{
	CComPtr<IXMLDOMElement> pElem = NULL;
	if (_node->QueryInterface<IXMLDOMElement>(&pElem) == S_OK)
	{		
		_CTangramXmlParse(pElem);		
	}
}

void CTangramXmlParse::ModifyNameAttrByFix(CString strNameFix)
{
	if (strNameFix != _T(""))
	{
		CComVariant var;
		CComBSTR bstrAttrName(L"name");
		CComBSTR bstrNAME(L"Name");
		HRESULT hr = elem->getAttribute(bstrNAME, &var);
		CString strNAME = OLE2T(var.bstrVal);
		hr = elem->getAttribute(bstrAttrName, &var);
		if (var.vt == VT_BSTR)
		{
			CString strName = OLE2T(var.bstrVal);
			CComBSTR bstrName = CComBSTR(strNameFix);
			CString _strName = OLE2T(var.bstrVal);
			if(_strName==_T(""))
				bstrName += strNAME;
			else
				bstrName += var.bstrVal;
			var.bstrVal = bstrName;
			hr = elem->setAttribute(bstrAttrName, var);
		}
		if (hr != S_OK)
		{
			::VariantClear(&var);
			CString _strName = strNameFix + strNAME;
			var.vt = VT_BSTR;
			var.bstrVal = _strName.AllocSysString();
			hr = elem->setAttribute(bstrAttrName, var);
		}
		::VariantClear(&var);
		//::SysFreeString(bstrAttrName);
		int nCount = GetCount();
		for (int i = 0; i < nCount; i++)
		{
			GetChild(i)->ModifyNameAttrByFix(strNameFix);
		}
	}
}

CTangramXmlParse* CTangramXmlParse::AddNode(CTangramXmlParse* pParse, CString strNameFix)
{
	if (pParse)
	{
		if (strNameFix != _T(""))
		{
			pParse->ModifyNameAttrByFix(strNameFix);
		}
		CComPtr<IXMLDOMElement> pElem = pParse->GetElement();
		CComPtr<IXMLDOMDocument> pDoc;
		elem->get_ownerDocument(&pDoc);
		if (pDoc)
		{
			CComPtr<IXMLDOMNode> pNode;
			HRESULT hr = elem->appendChild(pElem,&pNode);
			if (hr == S_OK)
			{
				CTangramXmlParse* pTangramXmlParse = new CTangramXmlParse(pNode);
				m_aChildElements.push_back(pTangramXmlParse);
				return pTangramXmlParse;
			}
		}
	}
	return NULL;
}

CTangramXmlParse* CTangramXmlParse::AddTabNode(CString strName, CString strCnnID,CString strObjID, CString strStyle, int nPages)
{
	strName.Trim();
	if (strName == _T(""))
		return NULL;
	strCnnID.Trim().MakeLower();
	strStyle.Trim().MakeLower();
	if (strCnnID == _T(""))
		strCnnID = _T("TangramTabbedWnd.TabbedComponent.1");
	if (strCnnID == _T("TangramTabbedWnd.TabbedComponent.1"))
	{
		if (strStyle == _T(""))
			strStyle = _T("19");
	}
	CTangramXmlParse* pNode = AddNode(_T("node"));
	pNode->put_attr(_T("id"), strObjID);
	pNode->put_attr(_T("name"), strName);
	pNode->put_attr(_T("cnnid"), strCnnID);
	pNode->put_attr(_T("tabstyle"), strStyle);
	if (nPages)
	{
		CString strVal = _T("");
		for (int i = 0; i < nPages; i++)
		{
			CTangramXmlParse* _pNode = pNode->AddNode(_T("node"));
			strVal.Format(_T("%s_Page%d"), strName, i);
			_pNode->put_attr(_T("name"), strVal);
			_pNode->put_attr(_T("caption"), strVal);
		}
	}
	return pNode;
}

CTangramXmlParse* CTangramXmlParse::AddSplitterNode(int nRows, int nCols, CString strName, int nWidth, int nHeight)
{
	strName.Trim();
	if (strName == _T(""))
		return NULL;
	nRows = nRows % 16;
	nCols = nCols % 16;
	if (nWidth*nHeight&&nRows*nCols>1)
	{
		CTangramXmlParse* pNode = AddNode(_T("node"));
		int _nWidth = nWidth / nCols;
		int _nHeight = nHeight / nRows;
		CString strRows = _T("");
		CString strCols = _T("");
		if (pNode)
		{
			pNode->put_attr(_T("id"), CString(_T("splitter")));
			pNode->put_attr(_T("name"), strName);
			CString strVal = _T("");
			strVal.Format(_T("%d"), nRows);
			pNode->put_attr(_T("rows"), strVal);
			strVal.Format(_T("%d"), nCols);
			pNode->put_attr(_T("cols"), strVal);
			strVal.Format(_T("%d,"), _nWidth);
			CString	strVal2 = _T("");
			CString	strVal3 = _T("");
			strVal2.Format(_T("%d,"), _nHeight);
			for (int i = 0; i < nCols; i++)
			{
				if (i < nCols - 1)
				{
					strRows += strVal;
				}
				for (int j = 0; j < nRows; j++)
				{
					if (i == 0 && j < nRows - 1)
					{
						strCols += strVal2;
					}
					CTangramXmlParse* _pNode = pNode->AddNode(_T("node"));
					strVal3.Format(_T("%s_View%02d%02d"), strName, i, j);
					_pNode->put_attr(_T("name"), strVal3);
				}
			}
			pNode->put_attr(_T("width"), strRows);
			pNode->put_attr(_T("height"), strCols);
			return pNode;
		}
	}

	return NULL;
}

BOOL CTangramXmlParse::ModifyNode(int nRow, int nCol, CString strName, CString strXml)
{
	int nIndex = 0;
	CString strID = this->attr(_T("id"), _T(""));
	if (strID == _T(""))
		return FALSE;
	int nCount = GetCount();
	if (nCount == 0)
		return FALSE;
	nRow = nRow % 16;
	nCol = nCol % 16;
	int nRows = attrInt(_T("rows"), 0);
	int nCols = attrInt(_T("cols"), 0);
	if (nRow >= nRows || nCol>nCols)
		return FALSE;

	nIndex = nRow*nCols + nCol;
	CTangramXmlParse* pChild = GetChild(nIndex);

	CTangramXmlParse m_Parse;
	if (m_Parse.LoadXml(strXml) || m_Parse.LoadFile(strXml))
	{
		CTangramXmlParse* pWindow = m_Parse.GetChild(_T("window"));
		if (pWindow)
		{
			CTangramXmlParse* pNode = pWindow->GetChild(_T("node"));
			if (pNode)
			{
				if (ReplaceNode(pChild, pNode, strName))
					return TRUE;
			}
		}
	}
	return FALSE;
}

CTangramXmlParse* CTangramXmlParse::ReplaceNode(CTangramXmlParse* pOldParse, CTangramXmlParse* pNewParse, CString strNameFix)
{
	int nCount = GetCount();
	for (int i = 0; i < nCount; i++)
	{
		CTangramXmlParse* pChild = GetChild(i);
		if (pChild == pOldParse)
		{
			if (strNameFix != _T(""))
			{
				pNewParse->ModifyNameAttrByFix(strNameFix);
			}
			CString strCapOld = pOldParse->attr(_T("caption"), _T(""));
			CComPtr<IXMLDOMElement> pElem = pOldParse->GetElement();
			CComPtr<IXMLDOMElement> pNewElem = pNewParse->GetElement();
			CComPtr<IXMLDOMNode> pOutNode;
			HRESULT hr = elem->replaceChild(pNewElem, pElem, &pOutNode);
			CComPtr<IXMLDOMNodeList> pList = NULL;
			if (elem->get_childNodes(&pList) == S_OK)
			{
				CComPtr<IXMLDOMNode> pNode;
				pList->get_item(i,&pNode);
				CComPtr<IXMLDOMElement> pElem = NULL;
				if (pNode->QueryInterface<IXMLDOMElement>(&pElem) == S_OK)
				{
					CTangramXmlParse* pOldChild = pChild;
					pChild = new CTangramXmlParse(pElem);
					pChild->m_pParentParse = this;
					m_aChildElements[i] = pChild;
					delete pOldChild;
					CString strCap = pChild->attr(_T("caption"), _T(""));
					if (strCap == _T("") && strCapOld != _T(""))
						pChild->put_attr(_T("caption"), strCapOld);
					return pChild;
				}
			}
			break;
		}
	}
	return NULL;
}

void CTangramXmlParse::_CTangramXmlParse(CComPtr<IXMLDOMNodeList> _nlist)
{
	long nLen = 0;
	_nlist->get_length(&nLen);
	for(long i = 0; i<nLen; i++)
	{
		CComPtr<IXMLDOMNode> pNode = NULL;
		CComPtr<IXMLDOMElement> pElem = NULL;
		if (_nlist->get_item(i,&pNode) == S_OK)
		{
			if (pNode->QueryInterface<IXMLDOMElement>(&pElem) == S_OK)
			{
				//m_aChildElements.Add(new CTangramXmlParse(pElem));
				CTangramXmlParse* pChild = new CTangramXmlParse(pElem);
				pChild->m_pParentParse = this;
				m_aChildElements.push_back(pChild);
			}
		}
	}
}

CTangramXmlParse* CTangramXmlParse::GetChild(int nIndex)
{
	if (nIndex<0 || nIndex>= GetCount()) 
		return NULL;
	return m_aChildElements[nIndex];
}

CTangramXmlParse* CTangramXmlParse::GetChild(CString strName)
{
	for(int i = 0; i<GetCount(); i++)
	{
		if (m_aChildElements[i]->name().CompareNoCase(strName) == 0)
			return m_aChildElements[i];
	}
	return NULL;
}

CTangramXmlParse& CTangramXmlParse::operator[](CString strName)
{
	CTangramXmlParse* pXml = GetChild(strName);
	if (pXml != NULL) return *pXml;
	//ASSERT(FALSE);//don't have the node.
	return *this;
}

CTangramXmlParse& CTangramXmlParse::operator[](int nIndex)
{
	CTangramXmlParse* pXml = GetChild(nIndex);
	if (pXml != NULL) return *pXml;
	//ASSERT(FALSE);//index is overflow
	return *this;	
}

CTangramXmlParse* CTangramXmlParse::FindItem(LPCTSTR strItemname)
{
	CTangramXmlParse* pItem = NULL;

	//if (name().CompareNoCase(strItemname) == 0)
	//{
	//	pItem = this;
	//}

	if (pItem == NULL)
	{
		for(int i = 0; i<GetCount(); i++)
		{
			CTangramXmlParse* pI = GetChild(i);
			if (pI->name().CompareNoCase(strItemname) == 0)
			{
				pItem = pI;
				break;
			}		
		}
	}

	if (pItem == NULL)
	{
		for(int i = 0; i<GetCount(); i++)
		{
			CTangramXmlParse* pX = GetChild(i)->FindItem(strItemname);
			
			if (pX != NULL)
			{
				pItem = pX;
				break;
			}
		}
	}
	return pItem;
}

CTangramXmlParse* CTangramXmlParse::FindItemByName(LPCTSTR strItemname)
{
	CTangramXmlParse* pItem = NULL;

	//if (name().CompareNoCase(strItemname) == 0)
	//{
	//	pItem = this;
	//}

	if (pItem == NULL)
	{
		for(int i = 0; i<GetCount(); i++)
		{
			CTangramXmlParse* pI = GetChild(i);
			CString strName = pI->attr(_T("name"), _T(""));
			if (strName.CompareNoCase(strItemname) == 0)
			{
				pItem = pI;
				break;
			}		
		}
	}

	if (pItem == NULL)
	{
		for(int i = 0; i<GetCount(); i++)
		{
			CTangramXmlParse* pX = GetChild(i)->FindItemByName(strItemname);
			
			if (pX != NULL)
			{
				pItem = pX;
				break;
			}
		}
	}
	return pItem;
}

bool CTangramXmlParse::operator==(CTangramXmlParse& nItem)
{
	IUnknown* pUn1 = NULL;
	elem->QueryInterface(IID_IUnknown,(void**)&pUn1);

	IUnknown* pUn2 = NULL;
	nItem.elem->QueryInterface(IID_IUnknown,(void**)&pUn2);

	bool bRet = (pUn2 == pUn1);

	pUn1->Release();
	pUn2->Release();

	return bRet;
}

void CTangramXmlParse::Initialize()
{
	m_strFile = _T("");
	m_bCanSave = false;
}

CTangramXmlParse* CTangramXmlParse::_FindParseByEle(CTangramXmlParse* _pParent, IUnknown* pEle)
{
	IUnknown* pUn1 = NULL;
	_pParent->elem->QueryInterface(IID_IUnknown,(void**)&pUn1);
	if (pUn1 == pEle)
	{
		pUn1->Release();
		return _pParent;
	}
	pUn1->Release();

	int c = (int)_pParent->GetCount();

	for(int i = 0; i<c; i++)
	{
		CTangramXmlParse* pValue = _FindParseByEle(_pParent->m_aChildElements[i], pEle);
		if (pValue != NULL) return pValue;
	}
	return NULL;
}



CTangramXmlParse* CTangramXmlParse::GetParseByElement(IXMLDOMElement* pEle)
{
	if (elem == NULL) return NULL;
	CTangramXmlParse* pParse = NULL;
	IUnknown* pUnk = NULL;

	if (pEle->QueryInterface(IID_IUnknown,(void**)&pUnk) == S_OK)
	{
		pParse = _FindParseByEle(this,pUnk);
		pUnk->Release(); 
	}
	return pParse;
}

CTangramXmlParse* CTangramXmlParse::AddNode(CString name)
{
	CComPtr<IXMLDOMDocument> pDoc = NULL;
	CComPtr<IXMLDOMElement> pElement = NULL;
	if (elem->get_ownerDocument(&pDoc) == S_OK)
	{			
		pDoc->createElement(CComBSTR(name),&pElement);
		if (pElement != NULL)
		{
			if (elem->appendChild(pElement,NULL) == S_OK)
			{
				CTangramXmlParse* pTangramXmlParse = new CTangramXmlParse(pElement);
				m_aChildElements.push_back(pTangramXmlParse);
				return pTangramXmlParse;
			}
		}
	}
	return NULL;
}

HRESULT CTangramXmlParse::RemoveNode(CString name)
{
	CTangramXmlParse* pNode = GetChild(name);
	return RemoveNode(pNode);
}

HRESULT CTangramXmlParse::RemoveNode(CTangramXmlParse* pNode)
{
	if (pNode == NULL) return E_FAIL;
	
	HRESULT hr = elem->removeChild(pNode->elem,NULL);
	if (hr == S_OK)
	{
		//for(int i = 0; i<GetCount(); i++)
		//{
		//	if (m_aChildElements[i] == pNode)
		//	{
		//		m_aChildElements.RemoveAt(i);
		//		//m_aChildElements.erase(m_aChildElements.at(i));
		//		delete pNode;
		//		break;
		//	}
		//}

		vector<CTangramXmlParse*>::iterator it;
		//for(int i = 0; i<GetCount(); i++)
		for(it = m_aChildElements.begin(); it != m_aChildElements.end(); it++)
		{
			if (*it == pNode)
			{
				//m_aChildElements.RemoveAt(i);
				m_aChildElements.erase(it);
				delete pNode;
				break;
			}
		}
	}
	return hr;
}

HRESULT CTangramXmlParse::RemoveNode(int index)
{
	if (index>=GetCount()) return -1;
	CTangramXmlParse* pNode = m_aChildElements[index];
	return RemoveNode(pNode);	
}

HRESULT CTangramXmlParse::RemoveSubNodes()
{
	for(int i = GetCount(); i>=0; i--)
		RemoveNode(i);
	return S_OK;
}

bool CTangramXmlParse::put_text(CString text)
{		
	CComPtr<IXMLDOMNodeList> pSubNodeList;
	elem->get_childNodes(&pSubNodeList);
	long sublen;
	bool bFound = false;
	pSubNodeList->get_length(&sublen);
	for(long j = 0; j<sublen; j++)
	{			
		CComPtr<IXMLDOMNode> pChildNode = NULL;
		if (pSubNodeList->get_item(j,&pChildNode) == S_OK)
		{
			BSTR subname = NULL;
			pChildNode->get_nodeName(&subname);
			if (wcscmp(subname,L"#text") == 0)
			{
				pChildNode->put_text(CComBSTR(text));
				bFound = true;		
				break;
			}
		}
	}
	if (!bFound) elem->put_text(CComBSTR(text));
	return true;
}

bool CTangramXmlParse::put_attr(CString name,CString value)
{
	return (elem->setAttribute(CComBSTR(name),CComVariant(CComBSTR(value))) == S_OK);
}

bool CTangramXmlParse::put_attr(CString name,int value)
{
	CString strInfo;
	strInfo.Format(_T("%d"),value);
	return put_attr(name,strInfo);	
}

bool CTangramXmlParse::put_attr(CString name,__int64 value)
{
	CString strInfo;
	strInfo.Format(_T("%I64d"),value);
	return put_attr(name,strInfo);	
}

bool CTangramXmlParse::put_attr(CString name,bool value)
{
	CString strInfo = _T("false");
	if (value) strInfo = _T("true");		
	return put_attr(name,strInfo);
}

CString CTangramXmlParse::name()
{
	if (!elem) return _T("");
	CComBSTR bn; 
	elem->get_tagName(&bn);
	return CString(bn);
}

CString CTangramXmlParse::xml()
{
	if (!elem) return _T("");
	CComBSTR bn; 
	elem->get_xml(&bn);	
	return CString(bn);
}

CString CTangramXmlParse::text()
{
	if (!elem) return _T("");
	CComPtr<IXMLDOMNodeList> pList = NULL;
	if (elem->get_childNodes(&pList) == S_OK)
	{
		long nLen = 0;
		pList->get_length(&nLen);
		for(long i = 0; i<nLen; i++)
		{
			CComPtr<IXMLDOMNode> pNode = NULL;
			if (pList->get_item(i,&pNode) == S_OK)
			{
				BSTR name = NULL;
				pNode->get_nodeName(&name);
				if (CString(name).CompareNoCase(_T("#text")) == 0)
				{
				BSTR value = NULL;
				pNode->get_text(&value);
				return CString(value);
				}
			}
		}
	}
	return _T("");
}

CString CTangramXmlParse::attr(const CString name, CString def) const
{
	if (!elem) return _T("");
	CComBSTR bname(name);
	CComVariant val(VT_EMPTY);
	elem->getAttribute(bname, &val);

	if (val.vt == VT_BSTR)
	{
		CString strRet = OLE2T(val.bstrVal);
		if (strRet != _T(""))
			return strRet;
	}
	return def;
}

DWORD CTangramXmlParse::attr(const CString name, DWORD def) const
{
	if (!elem) return 0;
	CComBSTR bname(name);
	CComVariant vall(VT_EMPTY);
	elem->getAttribute(bname, &vall);
	if (vall.vt == VT_BSTR)
	{
		//DWORD rr = DWORD();
		CString s = _T("");
		s += vall.bstrVal;
		DWORD rr = _ttoi(s);
		return rr;
	}
	return def;
}

//HKEY CTangramXmlParse::attr(const CString name) const
//{
//	if(!elem) return 0;
//}

bool CTangramXmlParse::attrBool(const CString name, bool def) const
{
	CString a = attr(name, _T(""));
	if (a.CompareNoCase(_T("true")) == 0) return true;
	else if (a.CompareNoCase(_T("false")) == 0) return false;
	else return def;
}

int CTangramXmlParse::attrInt(const CString name, int def) const
{
	CString str = attr(name, _T(""));
	if (str.IsEmpty()) return def;
	return _ttoi(str);
}

__int64 CTangramXmlParse::attrInt64(const CString name, __int64 def) const
{
	CString str = attr(name, _T(""));
	if (str.IsEmpty()) return def;
	return _ttoi64(str);
}

CString CTangramXmlParse::val() const
{
	USES_CONVERSION;
	if (!elem) return _T("");
	CComVariant val(VT_EMPTY);
	elem->get_nodeTypedValue(&val);
	if (val.vt == VT_BSTR) return OLE2T(val.bstrVal);
	return _T("");
}

//ÐÂÔö
DWORD CTangramXmlParse::vall() const
{
	USES_CONVERSION;
	if (!elem) return 0;
	CComVariant val(VT_EMPTY);
	elem->get_nodeTypedValue(&val);
	if (val.vt == VT_I8 || val.vt == VT_I4) return DWORD(val.lVal);
	return 0;
}

bool CTangramXmlParse::LoadXml(CString strXML)
{
	//HRESULT hr = CoInitialize(NULL);
	if (m_pDoc != NULL) m_pDoc.Release();
	if (CoCreateInstance(CLSID_DOMDocument, NULL, CLSCTX_INPROC_SERVER, IID_IXMLDOMDocument, (void**)&m_pDoc) == S_OK)
	{
		VARIANT_BOOL vb;
		if ((m_pDoc->load(CComVariant(strXML), &vb) != S_OK) || !vb)
		{
			m_pDoc->loadXML(CComBSTR(strXML), &vb);
		}
		if (!vb)
		{
			return false;
		}
		CComPtr<IXMLDOMElement> pEle;
		if (m_pDoc->get_documentElement(&pEle) == S_OK)
		{
			Clear();
			_CTangramXmlParse(pEle);
			return true;
		}
	}
	return false;
}

bool CTangramXmlParse::LoadFile(CString strFile)
{
	HRESULT hr = CoInitializeEx(NULL,0);
	if (m_pDoc != NULL) m_pDoc.Release();
	if (CoCreateInstance(CLSID_DOMDocument, NULL, CLSCTX_INPROC_SERVER, IID_IXMLDOMDocument, (void**)&m_pDoc) == S_OK)	
	{
		CComVariant file(strFile);
		VARIANT_BOOL vb;
		if (m_pDoc->load(file,&vb) == S_OK)
		{
			if (!vb) 
			{
				return false;
			}
			CComPtr<IXMLDOMElement> pEle;
			if (m_pDoc->get_documentElement(&pEle) == S_OK)
			{
				Clear();
				_CTangramXmlParse(pEle);

				m_bCanSave = true;
				m_strFile = strFile;

				return true;
			}
		}
	}
	return false;
}
bool CTangramXmlParse::SaveFile(CString strFile)
{
	if (m_pDoc == NULL)
	{
		elem->get_ownerDocument(&m_pDoc);
	}

	if (strFile.Compare(_T("")) == 0)
	{
		if (m_bCanSave)
		{
			strFile = m_strFile;
		}
	}

	CComVariant var(strFile);
	return (m_pDoc->save(var) == S_OK);
}

bool CTangramXmlParse::Reflash()
{
	Clear();
	if(elem)
		_CTangramXmlParse(elem);
	return true;
}

bool CTangramXmlParse::Clear()
{
	for(int i = 0; i<GetCount(); i++)
	{
		delete m_aChildElements[i];
	}
	//m_aChildElements.RemoveAll();
	m_aChildElements.clear();
	return true;
}