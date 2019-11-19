// TangramTreeView.h : Declaration of the CTangramTreeView

#pragma once
#include "resource.h"       // main symbols
#include "Tangram.h"

class CTangramHtmlTreeWnd;
// CTangramTreeView

class CTangramTreeView :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<ITangramTreeView, &IID_ITangramTreeView, &LIBID_Tangram, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CTangramTreeView();

DECLARE_NO_REGISTRY()

	CTangramHtmlTreeWnd* m_pTangramHtmlTreeWnd;
	map<CString,ITangramTreeViewCallBack*>	m_mapTangramTreeViewCallBack;
BEGIN_COM_MAP(CTangramTreeView)
	COM_INTERFACE_ENTRY(ITangramTreeView)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease();

public:
	STDMETHOD(put_TangramTreeViewCallBack)(BSTR bstrKey, ITangramTreeViewCallBack* newVal);
	STDMETHOD(AddTreeNode)(long hItem, BSTR bstrXml);
	STDMETHOD(InsertNode)(BSTR bstrXml, long* hItem);
	STDMETHOD(get_FirstRoot)(long* pVal);
};
