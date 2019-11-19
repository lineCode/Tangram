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
*
********************************************************************************/
#pragma once
#include <atlstr.h>

#define STRING2BSTR(x) (static_cast<BSTR>(Marshal::StringToBSTR(x).ToPointer()))
#define BSTR2STRING(x) (Marshal::PtrToStringUni((System::IntPtr)LPTSTR(LPCTSTR(x))))

class CCommonFunction
{
public:
	//CCommonFunction(void);
	//~CCommonFunction(void);

	template<class T> 
	static BOOL ClearObject(T* pObject)
	{
		BOOL bRet = FALSE;
		if (pObject != NULL)
		{
			ULONG dw = pObject->Release();
			while(dw > 0)
				dw = pObject->Release();
			bRet = TRUE;			
		}
		return bRet;
	}

	template<class T>
	static T* CreateObject()
	{
		CComObject<T>* pv;
		CComObject<T>::CreateInstance(&pv);
		pv->AddRef();
		return pv;
	}

	//BSTR String2BSTR(String^ str)
	//{
	//	IntPtr ip = Marshal::StringToBSTR(str);
	//	BSTR bstr = static_cast<BSTR>(ip.ToPointer());
	//	Marshal::FreeBSTR(ip);
	//	return bstr;
	//}

	//static CString GetApplicationFilename()
	//{
	//	TCHAR _szFile[MAX_PATH * 2] = {0};	
	//	GetModuleFileName(NULL,_szFile,MAX_PATH);

	//	return _szFile;
	//}

	//static CString GetApplicationPath()
	//{
	//	CString strPath = GetApplicationFilename();
	//	int iPos = strPath.ReverseFind(_T('\\'));
	//	return strPath.Left(iPos);
	//}
	
	//static HRESULT InvokeMember(IDispatch* pDisp, BSTR bstrMember, WORD wFlags = DISPATCH_METHOD, 
	//	DISPPARAMS* pParams = NULL, VARIANT* pRet = NULL, 
	//	REFIID riid = IID_NULL, LCID lcid = LOCALE_USER_DEFAULT, 
	//	EXCEPINFO* pExcepInfo = NULL, UINT* puArgErr = NULL)
	//{
	//	HRESULT hr = S_OK;
	//	if (pDisp)
	//	{
	//		DISPID dispid;
	//		hr = pDisp->GetIDsOfNames(IID_NULL, &bstrMember, 1, LOCALE_USER_DEFAULT, &dispid);
	//		if(hr == S_OK)
	//		{
	//			CComVariant varResult;				
	//			hr = pDisp->Invoke(dispid, riid, lcid, wFlags, pParams, pRet, pExcepInfo, puArgErr);				
	//		}
	//	}
	//	else
	//	{
	//		hr = E_FAIL;
	//	}
	//	return S_OK;
	//}
};
