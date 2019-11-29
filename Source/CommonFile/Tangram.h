

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for ..\CommonFile\Tangram.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Tangram_h__
#define __Tangram_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITangramExtender_FWD_DEFINED__
#define __ITangramExtender_FWD_DEFINED__
typedef interface ITangramExtender ITangramExtender;

#endif 	/* __ITangramExtender_FWD_DEFINED__ */


#ifndef __ITangramDesigner_FWD_DEFINED__
#define __ITangramDesigner_FWD_DEFINED__
typedef interface ITangramDesigner ITangramDesigner;

#endif 	/* __ITangramDesigner_FWD_DEFINED__ */


#ifndef __IEclipseExtender_FWD_DEFINED__
#define __IEclipseExtender_FWD_DEFINED__
typedef interface IEclipseExtender IEclipseExtender;

#endif 	/* __IEclipseExtender_FWD_DEFINED__ */


#ifndef __IOfficeExtender_FWD_DEFINED__
#define __IOfficeExtender_FWD_DEFINED__
typedef interface IOfficeExtender IOfficeExtender;

#endif 	/* __IOfficeExtender_FWD_DEFINED__ */


#ifndef __IVSExtender_FWD_DEFINED__
#define __IVSExtender_FWD_DEFINED__
typedef interface IVSExtender IVSExtender;

#endif 	/* __IVSExtender_FWD_DEFINED__ */


#ifndef __ITangramRestNotify_FWD_DEFINED__
#define __ITangramRestNotify_FWD_DEFINED__
typedef interface ITangramRestNotify ITangramRestNotify;

#endif 	/* __ITangramRestNotify_FWD_DEFINED__ */


#ifndef __ITangramRestObj_FWD_DEFINED__
#define __ITangramRestObj_FWD_DEFINED__
typedef interface ITangramRestObj ITangramRestObj;

#endif 	/* __ITangramRestObj_FWD_DEFINED__ */


#ifndef __IVSDocument_FWD_DEFINED__
#define __IVSDocument_FWD_DEFINED__
typedef interface IVSDocument IVSDocument;

#endif 	/* __IVSDocument_FWD_DEFINED__ */


#ifndef __ITaskNotify_FWD_DEFINED__
#define __ITaskNotify_FWD_DEFINED__
typedef interface ITaskNotify ITaskNotify;

#endif 	/* __ITaskNotify_FWD_DEFINED__ */


#ifndef __ITangramTreeNode_FWD_DEFINED__
#define __ITangramTreeNode_FWD_DEFINED__
typedef interface ITangramTreeNode ITangramTreeNode;

#endif 	/* __ITangramTreeNode_FWD_DEFINED__ */


#ifndef __ITangramTreeViewCallBack_FWD_DEFINED__
#define __ITangramTreeViewCallBack_FWD_DEFINED__
typedef interface ITangramTreeViewCallBack ITangramTreeViewCallBack;

#endif 	/* __ITangramTreeViewCallBack_FWD_DEFINED__ */


#ifndef __ITangramTreeView_FWD_DEFINED__
#define __ITangramTreeView_FWD_DEFINED__
typedef interface ITangramTreeView ITangramTreeView;

#endif 	/* __ITangramTreeView_FWD_DEFINED__ */


#ifndef __ITangramApp_FWD_DEFINED__
#define __ITangramApp_FWD_DEFINED__
typedef interface ITangramApp ITangramApp;

#endif 	/* __ITangramApp_FWD_DEFINED__ */


#ifndef __ITangramEventObj_FWD_DEFINED__
#define __ITangramEventObj_FWD_DEFINED__
typedef interface ITangramEventObj ITangramEventObj;

#endif 	/* __ITangramEventObj_FWD_DEFINED__ */


#ifndef __IWndNode_FWD_DEFINED__
#define __IWndNode_FWD_DEFINED__
typedef interface IWndNode IWndNode;

#endif 	/* __IWndNode_FWD_DEFINED__ */


#ifndef __IAppExtender_FWD_DEFINED__
#define __IAppExtender_FWD_DEFINED__
typedef interface IAppExtender IAppExtender;

#endif 	/* __IAppExtender_FWD_DEFINED__ */


#ifndef __ITangramEditor_FWD_DEFINED__
#define __ITangramEditor_FWD_DEFINED__
typedef interface ITangramEditor ITangramEditor;

#endif 	/* __ITangramEditor_FWD_DEFINED__ */


#ifndef __ITangramDoc_FWD_DEFINED__
#define __ITangramDoc_FWD_DEFINED__
typedef interface ITangramDoc ITangramDoc;

#endif 	/* __ITangramDoc_FWD_DEFINED__ */


#ifndef __ITangramDocTemplate_FWD_DEFINED__
#define __ITangramDocTemplate_FWD_DEFINED__
typedef interface ITangramDocTemplate ITangramDocTemplate;

#endif 	/* __ITangramDocTemplate_FWD_DEFINED__ */


#ifndef __ITangramJava_FWD_DEFINED__
#define __ITangramJava_FWD_DEFINED__
typedef interface ITangramJava ITangramJava;

#endif 	/* __ITangramJava_FWD_DEFINED__ */


#ifndef __ITangram_FWD_DEFINED__
#define __ITangram_FWD_DEFINED__
typedef interface ITangram ITangram;

#endif 	/* __ITangram_FWD_DEFINED__ */


#ifndef __ICompositor_FWD_DEFINED__
#define __ICompositor_FWD_DEFINED__
typedef interface ICompositor ICompositor;

#endif 	/* __ICompositor_FWD_DEFINED__ */


#ifndef __IWndNodeCollection_FWD_DEFINED__
#define __IWndNodeCollection_FWD_DEFINED__
typedef interface IWndNodeCollection IWndNodeCollection;

#endif 	/* __IWndNodeCollection_FWD_DEFINED__ */


#ifndef __ICompositorManager_FWD_DEFINED__
#define __ICompositorManager_FWD_DEFINED__
typedef interface ICompositorManager ICompositorManager;

#endif 	/* __ICompositorManager_FWD_DEFINED__ */


#ifndef __IWorkBenchWindow_FWD_DEFINED__
#define __IWorkBenchWindow_FWD_DEFINED__
typedef interface IWorkBenchWindow IWorkBenchWindow;

#endif 	/* __IWorkBenchWindow_FWD_DEFINED__ */


#ifndef __IChromeWebBrowser_FWD_DEFINED__
#define __IChromeWebBrowser_FWD_DEFINED__
typedef interface IChromeWebBrowser IChromeWebBrowser;

#endif 	/* __IChromeWebBrowser_FWD_DEFINED__ */


#ifndef __IChromeWebContent_FWD_DEFINED__
#define __IChromeWebContent_FWD_DEFINED__
typedef interface IChromeWebContent IChromeWebContent;

#endif 	/* __IChromeWebContent_FWD_DEFINED__ */


#ifndef __IOfficeObject_FWD_DEFINED__
#define __IOfficeObject_FWD_DEFINED__
typedef interface IOfficeObject IOfficeObject;

#endif 	/* __IOfficeObject_FWD_DEFINED__ */


#ifndef __ITangramCtrl_FWD_DEFINED__
#define __ITangramCtrl_FWD_DEFINED__
typedef interface ITangramCtrl ITangramCtrl;

#endif 	/* __ITangramCtrl_FWD_DEFINED__ */


#ifndef __ITangramAppCtrl_FWD_DEFINED__
#define __ITangramAppCtrl_FWD_DEFINED__
typedef interface ITangramAppCtrl ITangramAppCtrl;

#endif 	/* __ITangramAppCtrl_FWD_DEFINED__ */


#ifndef __IEclipseCtrl_FWD_DEFINED__
#define __IEclipseCtrl_FWD_DEFINED__
typedef interface IEclipseCtrl IEclipseCtrl;

#endif 	/* __IEclipseCtrl_FWD_DEFINED__ */


#ifndef ___ITangram_FWD_DEFINED__
#define ___ITangram_FWD_DEFINED__
typedef interface _ITangram _ITangram;

#endif 	/* ___ITangram_FWD_DEFINED__ */


#ifndef __Tangram_FWD_DEFINED__
#define __Tangram_FWD_DEFINED__

#ifdef __cplusplus
typedef class Tangram Tangram;
#else
typedef struct Tangram Tangram;
#endif /* __cplusplus */

#endif 	/* __Tangram_FWD_DEFINED__ */


#ifndef ___IWndNodeEvents_FWD_DEFINED__
#define ___IWndNodeEvents_FWD_DEFINED__
typedef interface _IWndNodeEvents _IWndNodeEvents;

#endif 	/* ___IWndNodeEvents_FWD_DEFINED__ */


#ifndef ___ITangramObjEvents_FWD_DEFINED__
#define ___ITangramObjEvents_FWD_DEFINED__
typedef interface _ITangramObjEvents _ITangramObjEvents;

#endif 	/* ___ITangramObjEvents_FWD_DEFINED__ */


#ifndef ___ITangramAppEvents_FWD_DEFINED__
#define ___ITangramAppEvents_FWD_DEFINED__
typedef interface _ITangramAppEvents _ITangramAppEvents;

#endif 	/* ___ITangramAppEvents_FWD_DEFINED__ */


#ifndef __TangramCtrl_FWD_DEFINED__
#define __TangramCtrl_FWD_DEFINED__

#ifdef __cplusplus
typedef class TangramCtrl TangramCtrl;
#else
typedef struct TangramCtrl TangramCtrl;
#endif /* __cplusplus */

#endif 	/* __TangramCtrl_FWD_DEFINED__ */


#ifndef __TangramJava_FWD_DEFINED__
#define __TangramJava_FWD_DEFINED__

#ifdef __cplusplus
typedef class TangramJava TangramJava;
#else
typedef struct TangramJava TangramJava;
#endif /* __cplusplus */

#endif 	/* __TangramJava_FWD_DEFINED__ */


#ifndef __TangramExtender_FWD_DEFINED__
#define __TangramExtender_FWD_DEFINED__

#ifdef __cplusplus
typedef class TangramExtender TangramExtender;
#else
typedef struct TangramExtender TangramExtender;
#endif /* __cplusplus */

#endif 	/* __TangramExtender_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_Tangram_0000_0000 */
/* [local] */ 













typedef /* [helpstring] */ 
enum BrowserWndOpenDisposition
    {
        UNKNOWN	= 0,
        CURRENT_TAB	= 0x1,
        SINGLETON_TAB	= 0x2,
        NEW_FOREGROUND_TAB	= 0x3,
        NEW_BACKGROUND_TAB	= 0x4,
        NEW_POPUP	= 0x5,
        NEW_WINDOW	= 0x6,
        SAVE_TO_DISK	= 0x7,
        OFF_THE_RECORD	= 0x8,
        IGNORE_ACTION	= 0x9,
        SWITCH_TO_TAB	= 0xa
    } 	BrowserWndOpenDisposition;

typedef /* [helpstring] */ 
enum CompositorType
    {
        MDIClientCompositor	= 0,
        MDIChildCompositor	= 0x1,
        SDICompositor	= 0x2,
        CtrlBarCompositor	= 0x3,
        WinFormMDIClientCompositor	= 0x4,
        WinFormMDIChildCompositor	= 0x5,
        WinFormCompositor	= 0x6,
        EclipseWorkBenchCompositor	= 0x7,
        EclipseViewCompositor	= 0x8,
        EclipseSWTCompositor	= 0x9,
        WinFormControlCompositor	= 0xa,
        TabbedMDIClientCompositor	= 0xb,
        NOCompositor	= 0x10a
    } 	CompositorType;

typedef /* [helpstring] */ 
enum ObjEventType
    {
        TangramNode	= 0,
        TangramDocEvent	= 0x1,
        TangramNodeAllChildNode	= 0x2,
        TangramDocAllFrameAllChildNode	= 0x3,
        TangramDocAllFrameAllTopNode	= 0x4,
        TangramFrameAllTopNodeAllChildNode	= 0x5,
        TangramFrameAllTopNode	= 0x6,
        CompositorManagerAllFrameAllTopNodeAllChildNode	= 0x7,
        CompositorManagerAllFrameAllTopNode	= 0x8,
        CompositorManagerCtrlBarFrameAllTopNodeAllChildNode	= 0x9,
        CompositorManagerCtrlBarFrameAllTopNode	= 0xa,
        CompositorManagerNotCtrlBarFrameAllTopNodeAllChildNode	= 0xb,
        CompositorManagerNotCtrlBarFrameAllTopNode	= 0xc,
        TangramDocAllCtrlBarFrameAllChildNode	= 0xd,
        TangramDocAllCtrlBarFrame	= 0xe
    } 	ObjEventType;

typedef /* [helpstring] */ 
enum TangramViewType
    {
        BlankView	= 0x1,
        ActiveX	= 0x2,
        Splitter	= 0x4,
        TabbedWnd	= 0x8,
        CLRCtrl	= 0x10,
        CLRForm	= 0x20,
        CLRWnd	= 0x40,
        TangramView	= 0x80,
        TangramTreeView	= 0x100,
        TangramListView	= 0x200,
        TabCtrl	= 0x400,
        TangramWPFCtrl	= 0x800
    } 	TangramViewType;



extern RPC_IF_HANDLE __MIDL_itf_Tangram_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_Tangram_0000_0000_v0_0_s_ifspec;

#ifndef __ITangramExtender_INTERFACE_DEFINED__
#define __ITangramExtender_INTERFACE_DEFINED__

/* interface ITangramExtender */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITangramExtender;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120160101")
    ITangramExtender : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveWorkBenchWindow( 
            BSTR bstrID,
            /* [retval][out] */ IWorkBenchWindow **pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITangramExtenderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITangramExtender * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITangramExtender * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITangramExtender * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITangramExtender * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITangramExtender * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITangramExtender * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITangramExtender * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            ITangramExtender * This);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveWorkBenchWindow )( 
            ITangramExtender * This,
            BSTR bstrID,
            /* [retval][out] */ IWorkBenchWindow **pVal);
        
        END_INTERFACE
    } ITangramExtenderVtbl;

    interface ITangramExtender
    {
        CONST_VTBL struct ITangramExtenderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITangramExtender_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITangramExtender_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITangramExtender_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITangramExtender_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITangramExtender_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITangramExtender_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITangramExtender_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITangramExtender_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define ITangramExtender_get_ActiveWorkBenchWindow(This,bstrID,pVal)	\
    ( (This)->lpVtbl -> get_ActiveWorkBenchWindow(This,bstrID,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITangramExtender_INTERFACE_DEFINED__ */


#ifndef __ITangramDesigner_INTERFACE_DEFINED__
#define __ITangramDesigner_INTERFACE_DEFINED__

/* interface ITangramDesigner */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITangramDesigner;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120170321")
    ITangramDesigner : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ITangramDesignerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITangramDesigner * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITangramDesigner * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITangramDesigner * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITangramDesigner * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITangramDesigner * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITangramDesigner * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITangramDesigner * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ITangramDesignerVtbl;

    interface ITangramDesigner
    {
        CONST_VTBL struct ITangramDesignerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITangramDesigner_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITangramDesigner_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITangramDesigner_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITangramDesigner_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITangramDesigner_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITangramDesigner_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITangramDesigner_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITangramDesigner_INTERFACE_DEFINED__ */


#ifndef __IEclipseExtender_INTERFACE_DEFINED__
#define __IEclipseExtender_INTERFACE_DEFINED__

/* interface IEclipseExtender */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IEclipseExtender;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120160918")
    IEclipseExtender : public ITangramExtender
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IEclipseExtenderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEclipseExtender * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEclipseExtender * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEclipseExtender * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEclipseExtender * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEclipseExtender * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEclipseExtender * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEclipseExtender * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IEclipseExtender * This);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveWorkBenchWindow )( 
            IEclipseExtender * This,
            BSTR bstrID,
            /* [retval][out] */ IWorkBenchWindow **pVal);
        
        END_INTERFACE
    } IEclipseExtenderVtbl;

    interface IEclipseExtender
    {
        CONST_VTBL struct IEclipseExtenderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEclipseExtender_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEclipseExtender_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEclipseExtender_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEclipseExtender_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEclipseExtender_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEclipseExtender_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEclipseExtender_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEclipseExtender_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IEclipseExtender_get_ActiveWorkBenchWindow(This,bstrID,pVal)	\
    ( (This)->lpVtbl -> get_ActiveWorkBenchWindow(This,bstrID,pVal) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEclipseExtender_INTERFACE_DEFINED__ */


#ifndef __IOfficeExtender_INTERFACE_DEFINED__
#define __IOfficeExtender_INTERFACE_DEFINED__

/* interface IOfficeExtender */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IOfficeExtender;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119631222")
    IOfficeExtender : public ITangramExtender
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddVBAFormsScript( 
            IDispatch *OfficeObject,
            BSTR bstrKey,
            BSTR bstrXml) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE InitVBAForm( 
            /* [in] */ IDispatch *newVal,
            /* [in] */ long nStyle,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppNode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFrameFromVBAForm( 
            IDispatch *pForm,
            /* [retval][out] */ ICompositor **ppCompositor) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetActiveTopWndNode( 
            IDispatch *pForm,
            /* [retval][out] */ IWndNode **WndNode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetObjectFromWnd( 
            LONG hWnd,
            /* [retval][out] */ IDispatch **ppObjFromWnd) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOfficeExtenderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfficeExtender * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfficeExtender * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfficeExtender * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOfficeExtender * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOfficeExtender * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOfficeExtender * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOfficeExtender * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IOfficeExtender * This);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveWorkBenchWindow )( 
            IOfficeExtender * This,
            BSTR bstrID,
            /* [retval][out] */ IWorkBenchWindow **pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddVBAFormsScript )( 
            IOfficeExtender * This,
            IDispatch *OfficeObject,
            BSTR bstrKey,
            BSTR bstrXml);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *InitVBAForm )( 
            IOfficeExtender * This,
            /* [in] */ IDispatch *newVal,
            /* [in] */ long nStyle,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppNode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFrameFromVBAForm )( 
            IOfficeExtender * This,
            IDispatch *pForm,
            /* [retval][out] */ ICompositor **ppCompositor);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetActiveTopWndNode )( 
            IOfficeExtender * This,
            IDispatch *pForm,
            /* [retval][out] */ IWndNode **WndNode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetObjectFromWnd )( 
            IOfficeExtender * This,
            LONG hWnd,
            /* [retval][out] */ IDispatch **ppObjFromWnd);
        
        END_INTERFACE
    } IOfficeExtenderVtbl;

    interface IOfficeExtender
    {
        CONST_VTBL struct IOfficeExtenderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfficeExtender_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfficeExtender_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfficeExtender_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfficeExtender_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOfficeExtender_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOfficeExtender_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOfficeExtender_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOfficeExtender_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IOfficeExtender_get_ActiveWorkBenchWindow(This,bstrID,pVal)	\
    ( (This)->lpVtbl -> get_ActiveWorkBenchWindow(This,bstrID,pVal) ) 


#define IOfficeExtender_AddVBAFormsScript(This,OfficeObject,bstrKey,bstrXml)	\
    ( (This)->lpVtbl -> AddVBAFormsScript(This,OfficeObject,bstrKey,bstrXml) ) 

#define IOfficeExtender_InitVBAForm(This,newVal,nStyle,bstrXml,ppNode)	\
    ( (This)->lpVtbl -> InitVBAForm(This,newVal,nStyle,bstrXml,ppNode) ) 

#define IOfficeExtender_GetFrameFromVBAForm(This,pForm,ppCompositor)	\
    ( (This)->lpVtbl -> GetFrameFromVBAForm(This,pForm,ppCompositor) ) 

#define IOfficeExtender_GetActiveTopWndNode(This,pForm,WndNode)	\
    ( (This)->lpVtbl -> GetActiveTopWndNode(This,pForm,WndNode) ) 

#define IOfficeExtender_GetObjectFromWnd(This,hWnd,ppObjFromWnd)	\
    ( (This)->lpVtbl -> GetObjectFromWnd(This,hWnd,ppObjFromWnd) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfficeExtender_INTERFACE_DEFINED__ */


#ifndef __IVSExtender_INTERFACE_DEFINED__
#define __IVSExtender_INTERFACE_DEFINED__

/* interface IVSExtender */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IVSExtender;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119890701")
    IVSExtender : public ITangramExtender
    {
    public:
        virtual /* [hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentDesignNode( 
            /* [retval][out] */ IWndNode **ppRetVal) = 0;
        
        virtual /* [hidden][id][propput] */ HRESULT STDMETHODCALLTYPE put_CurrentDesignNode( 
            /* [in] */ IWndNode *newVal) = 0;
        
        virtual /* [hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get_DesignNode( 
            /* [retval][out] */ IWndNode **pVal) = 0;
        
        virtual /* [hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get_DesignRootNode( 
            /* [retval][out] */ IWndNode **pVal) = 0;
        
        virtual /* [hidden][id][propput] */ HRESULT STDMETHODCALLTYPE put_DesignRootNode( 
            /* [in] */ IWndNode *newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TangramCLRProject( 
            BSTR bstrPrjPath,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TangramCLRProject( 
            BSTR bstrPrjPath,
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentSelectedPrj( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ExtendXmlUI( 
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppNode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IVSExtenderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVSExtender * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVSExtender * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVSExtender * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IVSExtender * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IVSExtender * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IVSExtender * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IVSExtender * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IVSExtender * This);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveWorkBenchWindow )( 
            IVSExtender * This,
            BSTR bstrID,
            /* [retval][out] */ IWorkBenchWindow **pVal);
        
        /* [hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentDesignNode )( 
            IVSExtender * This,
            /* [retval][out] */ IWndNode **ppRetVal);
        
        /* [hidden][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentDesignNode )( 
            IVSExtender * This,
            /* [in] */ IWndNode *newVal);
        
        /* [hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DesignNode )( 
            IVSExtender * This,
            /* [retval][out] */ IWndNode **pVal);
        
        /* [hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DesignRootNode )( 
            IVSExtender * This,
            /* [retval][out] */ IWndNode **pVal);
        
        /* [hidden][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DesignRootNode )( 
            IVSExtender * This,
            /* [in] */ IWndNode *newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TangramCLRProject )( 
            IVSExtender * This,
            BSTR bstrPrjPath,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TangramCLRProject )( 
            IVSExtender * This,
            BSTR bstrPrjPath,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentSelectedPrj )( 
            IVSExtender * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ExtendXmlUI )( 
            IVSExtender * This,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppNode);
        
        END_INTERFACE
    } IVSExtenderVtbl;

    interface IVSExtender
    {
        CONST_VTBL struct IVSExtenderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVSExtender_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVSExtender_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVSExtender_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVSExtender_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IVSExtender_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IVSExtender_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IVSExtender_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IVSExtender_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IVSExtender_get_ActiveWorkBenchWindow(This,bstrID,pVal)	\
    ( (This)->lpVtbl -> get_ActiveWorkBenchWindow(This,bstrID,pVal) ) 


#define IVSExtender_get_CurrentDesignNode(This,ppRetVal)	\
    ( (This)->lpVtbl -> get_CurrentDesignNode(This,ppRetVal) ) 

#define IVSExtender_put_CurrentDesignNode(This,newVal)	\
    ( (This)->lpVtbl -> put_CurrentDesignNode(This,newVal) ) 

#define IVSExtender_get_DesignNode(This,pVal)	\
    ( (This)->lpVtbl -> get_DesignNode(This,pVal) ) 

#define IVSExtender_get_DesignRootNode(This,pVal)	\
    ( (This)->lpVtbl -> get_DesignRootNode(This,pVal) ) 

#define IVSExtender_put_DesignRootNode(This,newVal)	\
    ( (This)->lpVtbl -> put_DesignRootNode(This,newVal) ) 

#define IVSExtender_get_TangramCLRProject(This,bstrPrjPath,pVal)	\
    ( (This)->lpVtbl -> get_TangramCLRProject(This,bstrPrjPath,pVal) ) 

#define IVSExtender_put_TangramCLRProject(This,bstrPrjPath,newVal)	\
    ( (This)->lpVtbl -> put_TangramCLRProject(This,bstrPrjPath,newVal) ) 

#define IVSExtender_get_CurrentSelectedPrj(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentSelectedPrj(This,pVal) ) 

#define IVSExtender_ExtendXmlUI(This,bstrKey,bstrXml,ppNode)	\
    ( (This)->lpVtbl -> ExtendXmlUI(This,bstrKey,bstrXml,ppNode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVSExtender_INTERFACE_DEFINED__ */


#ifndef __ITangramRestNotify_INTERFACE_DEFINED__
#define __ITangramRestNotify_INTERFACE_DEFINED__

/* interface ITangramRestNotify */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITangramRestNotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-06012017F7CD")
    ITangramRestNotify : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Notify( 
            BSTR bstrInfo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITangramRestNotifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITangramRestNotify * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITangramRestNotify * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITangramRestNotify * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITangramRestNotify * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITangramRestNotify * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITangramRestNotify * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITangramRestNotify * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Notify )( 
            ITangramRestNotify * This,
            BSTR bstrInfo);
        
        END_INTERFACE
    } ITangramRestNotifyVtbl;

    interface ITangramRestNotify
    {
        CONST_VTBL struct ITangramRestNotifyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITangramRestNotify_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITangramRestNotify_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITangramRestNotify_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITangramRestNotify_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITangramRestNotify_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITangramRestNotify_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITangramRestNotify_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITangramRestNotify_Notify(This,bstrInfo)	\
    ( (This)->lpVtbl -> Notify(This,bstrInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITangramRestNotify_INTERFACE_DEFINED__ */


#ifndef __ITangramRestObj_INTERFACE_DEFINED__
#define __ITangramRestObj_INTERFACE_DEFINED__

/* interface ITangramRestObj */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITangramRestObj;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120176C7D")
    ITangramRestObj : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TangramRestNotify( 
            /* [retval][out] */ ITangramRestNotify **pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TangramRestNotify( 
            /* [in] */ ITangramRestNotify *newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_NotifyHandle( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_NotifyHandle( 
            /* [in] */ LONGLONG newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Header( 
            BSTR bstrHeaderName,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Header( 
            BSTR bstrHeaderName,
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_RestKey( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_RestKey( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TangramNode( 
            /* [retval][out] */ IWndNode **pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TangramNode( 
            /* [in] */ IWndNode *newVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AsyncRest( 
            int nMethod,
            BSTR bstrURL,
            BSTR bstrData,
            LONGLONG hNotify) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Notify( 
            long nNotify) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UploadFile( 
            VARIANT_BOOL bUpload,
            BSTR bstrServerURL,
            BSTR bstrRequest,
            BSTR bstrFilePath) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RestData( 
            int nMethod,
            BSTR bstrServerURL,
            BSTR bstrRequest,
            BSTR bstrData,
            LONGLONG hNotify) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ClearHeaders( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Clone( 
            ITangramRestObj *pTargetObj) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_State( 
            /* [in] */ int newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITangramRestObjVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITangramRestObj * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITangramRestObj * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITangramRestObj * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITangramRestObj * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITangramRestObj * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITangramRestObj * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITangramRestObj * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TangramRestNotify )( 
            ITangramRestObj * This,
            /* [retval][out] */ ITangramRestNotify **pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TangramRestNotify )( 
            ITangramRestObj * This,
            /* [in] */ ITangramRestNotify *newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NotifyHandle )( 
            ITangramRestObj * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NotifyHandle )( 
            ITangramRestObj * This,
            /* [in] */ LONGLONG newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Header )( 
            ITangramRestObj * This,
            BSTR bstrHeaderName,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Header )( 
            ITangramRestObj * This,
            BSTR bstrHeaderName,
            /* [in] */ BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RestKey )( 
            ITangramRestObj * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RestKey )( 
            ITangramRestObj * This,
            /* [in] */ BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TangramNode )( 
            ITangramRestObj * This,
            /* [retval][out] */ IWndNode **pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TangramNode )( 
            ITangramRestObj * This,
            /* [in] */ IWndNode *newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AsyncRest )( 
            ITangramRestObj * This,
            int nMethod,
            BSTR bstrURL,
            BSTR bstrData,
            LONGLONG hNotify);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Notify )( 
            ITangramRestObj * This,
            long nNotify);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UploadFile )( 
            ITangramRestObj * This,
            VARIANT_BOOL bUpload,
            BSTR bstrServerURL,
            BSTR bstrRequest,
            BSTR bstrFilePath);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RestData )( 
            ITangramRestObj * This,
            int nMethod,
            BSTR bstrServerURL,
            BSTR bstrRequest,
            BSTR bstrData,
            LONGLONG hNotify);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ClearHeaders )( 
            ITangramRestObj * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Clone )( 
            ITangramRestObj * This,
            ITangramRestObj *pTargetObj);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            ITangramRestObj * This,
            /* [retval][out] */ int *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_State )( 
            ITangramRestObj * This,
            /* [in] */ int newVal);
        
        END_INTERFACE
    } ITangramRestObjVtbl;

    interface ITangramRestObj
    {
        CONST_VTBL struct ITangramRestObjVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITangramRestObj_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITangramRestObj_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITangramRestObj_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITangramRestObj_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITangramRestObj_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITangramRestObj_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITangramRestObj_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITangramRestObj_get_TangramRestNotify(This,pVal)	\
    ( (This)->lpVtbl -> get_TangramRestNotify(This,pVal) ) 

#define ITangramRestObj_put_TangramRestNotify(This,newVal)	\
    ( (This)->lpVtbl -> put_TangramRestNotify(This,newVal) ) 

#define ITangramRestObj_get_NotifyHandle(This,pVal)	\
    ( (This)->lpVtbl -> get_NotifyHandle(This,pVal) ) 

#define ITangramRestObj_put_NotifyHandle(This,newVal)	\
    ( (This)->lpVtbl -> put_NotifyHandle(This,newVal) ) 

#define ITangramRestObj_get_Header(This,bstrHeaderName,pVal)	\
    ( (This)->lpVtbl -> get_Header(This,bstrHeaderName,pVal) ) 

#define ITangramRestObj_put_Header(This,bstrHeaderName,newVal)	\
    ( (This)->lpVtbl -> put_Header(This,bstrHeaderName,newVal) ) 

#define ITangramRestObj_get_RestKey(This,pVal)	\
    ( (This)->lpVtbl -> get_RestKey(This,pVal) ) 

#define ITangramRestObj_put_RestKey(This,newVal)	\
    ( (This)->lpVtbl -> put_RestKey(This,newVal) ) 

#define ITangramRestObj_get_TangramNode(This,pVal)	\
    ( (This)->lpVtbl -> get_TangramNode(This,pVal) ) 

#define ITangramRestObj_put_TangramNode(This,newVal)	\
    ( (This)->lpVtbl -> put_TangramNode(This,newVal) ) 

#define ITangramRestObj_AsyncRest(This,nMethod,bstrURL,bstrData,hNotify)	\
    ( (This)->lpVtbl -> AsyncRest(This,nMethod,bstrURL,bstrData,hNotify) ) 

#define ITangramRestObj_Notify(This,nNotify)	\
    ( (This)->lpVtbl -> Notify(This,nNotify) ) 

#define ITangramRestObj_UploadFile(This,bUpload,bstrServerURL,bstrRequest,bstrFilePath)	\
    ( (This)->lpVtbl -> UploadFile(This,bUpload,bstrServerURL,bstrRequest,bstrFilePath) ) 

#define ITangramRestObj_RestData(This,nMethod,bstrServerURL,bstrRequest,bstrData,hNotify)	\
    ( (This)->lpVtbl -> RestData(This,nMethod,bstrServerURL,bstrRequest,bstrData,hNotify) ) 

#define ITangramRestObj_ClearHeaders(This)	\
    ( (This)->lpVtbl -> ClearHeaders(This) ) 

#define ITangramRestObj_Clone(This,pTargetObj)	\
    ( (This)->lpVtbl -> Clone(This,pTargetObj) ) 

#define ITangramRestObj_get_State(This,pVal)	\
    ( (This)->lpVtbl -> get_State(This,pVal) ) 

#define ITangramRestObj_put_State(This,newVal)	\
    ( (This)->lpVtbl -> put_State(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITangramRestObj_INTERFACE_DEFINED__ */


#ifndef __IVSDocument_INTERFACE_DEFINED__
#define __IVSDocument_INTERFACE_DEFINED__

/* interface IVSDocument */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IVSDocument;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120170824")
    IVSDocument : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VSClass( 
            /* [in] */ VARIANT vIndex,
            /* [retval][out] */ IDispatch **ppNode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IVSDocumentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVSDocument * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVSDocument * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVSDocument * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IVSDocument * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IVSDocument * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IVSDocument * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IVSDocument * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VSClass )( 
            IVSDocument * This,
            /* [in] */ VARIANT vIndex,
            /* [retval][out] */ IDispatch **ppNode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IVSDocument * This,
            /* [retval][out] */ IUnknown **ppVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IVSDocument * This,
            /* [retval][out] */ long *pCount);
        
        END_INTERFACE
    } IVSDocumentVtbl;

    interface IVSDocument
    {
        CONST_VTBL struct IVSDocumentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVSDocument_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVSDocument_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVSDocument_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVSDocument_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IVSDocument_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IVSDocument_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IVSDocument_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IVSDocument_get_VSClass(This,vIndex,ppNode)	\
    ( (This)->lpVtbl -> get_VSClass(This,vIndex,ppNode) ) 

#define IVSDocument_get__NewEnum(This,ppVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppVal) ) 

#define IVSDocument_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVSDocument_INTERFACE_DEFINED__ */


#ifndef __ITaskNotify_INTERFACE_DEFINED__
#define __ITaskNotify_INTERFACE_DEFINED__

/* interface ITaskNotify */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITaskNotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-0601198222C0")
    ITaskNotify : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Notify( 
            BSTR bstrInfo) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE NotifyEx( 
            VARIANT varNotify) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITaskNotifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITaskNotify * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITaskNotify * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITaskNotify * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITaskNotify * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITaskNotify * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITaskNotify * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITaskNotify * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Notify )( 
            ITaskNotify * This,
            BSTR bstrInfo);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *NotifyEx )( 
            ITaskNotify * This,
            VARIANT varNotify);
        
        END_INTERFACE
    } ITaskNotifyVtbl;

    interface ITaskNotify
    {
        CONST_VTBL struct ITaskNotifyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITaskNotify_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITaskNotify_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITaskNotify_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITaskNotify_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITaskNotify_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITaskNotify_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITaskNotify_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITaskNotify_Notify(This,bstrInfo)	\
    ( (This)->lpVtbl -> Notify(This,bstrInfo) ) 

#define ITaskNotify_NotifyEx(This,varNotify)	\
    ( (This)->lpVtbl -> NotifyEx(This,varNotify) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITaskNotify_INTERFACE_DEFINED__ */


#ifndef __ITangramTreeNode_INTERFACE_DEFINED__
#define __ITangramTreeNode_INTERFACE_DEFINED__

/* interface ITangramTreeNode */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITangramTreeNode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-06011982C951")
    ITangramTreeNode : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ITangramTreeNodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITangramTreeNode * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITangramTreeNode * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITangramTreeNode * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITangramTreeNode * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITangramTreeNode * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITangramTreeNode * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITangramTreeNode * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ITangramTreeNodeVtbl;

    interface ITangramTreeNode
    {
        CONST_VTBL struct ITangramTreeNodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITangramTreeNode_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITangramTreeNode_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITangramTreeNode_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITangramTreeNode_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITangramTreeNode_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITangramTreeNode_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITangramTreeNode_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITangramTreeNode_INTERFACE_DEFINED__ */


#ifndef __ITangramTreeViewCallBack_INTERFACE_DEFINED__
#define __ITangramTreeViewCallBack_INTERFACE_DEFINED__

/* interface ITangramTreeViewCallBack */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITangramTreeViewCallBack;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-0601198283A6")
    ITangramTreeViewCallBack : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WndNode( 
            IWndNode *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Pages( 
            long *retVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnInitTreeView( 
            ITangramTreeView *pTangramTreeView,
            BSTR bstrXml) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnClick( 
            BSTR bstrXml,
            BSTR bstrXmlData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnInit( 
            BSTR bstrXml) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnNewPage( 
            int nNewPage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TangramAction( 
            BSTR bstrXml,
            /* [retval][out] */ BSTR *bstrRetXml) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITangramTreeViewCallBackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITangramTreeViewCallBack * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITangramTreeViewCallBack * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITangramTreeViewCallBack * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITangramTreeViewCallBack * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITangramTreeViewCallBack * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITangramTreeViewCallBack * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITangramTreeViewCallBack * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WndNode )( 
            ITangramTreeViewCallBack * This,
            IWndNode *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Pages )( 
            ITangramTreeViewCallBack * This,
            long *retVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnInitTreeView )( 
            ITangramTreeViewCallBack * This,
            ITangramTreeView *pTangramTreeView,
            BSTR bstrXml);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnClick )( 
            ITangramTreeViewCallBack * This,
            BSTR bstrXml,
            BSTR bstrXmlData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnInit )( 
            ITangramTreeViewCallBack * This,
            BSTR bstrXml);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnNewPage )( 
            ITangramTreeViewCallBack * This,
            int nNewPage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TangramAction )( 
            ITangramTreeViewCallBack * This,
            BSTR bstrXml,
            /* [retval][out] */ BSTR *bstrRetXml);
        
        END_INTERFACE
    } ITangramTreeViewCallBackVtbl;

    interface ITangramTreeViewCallBack
    {
        CONST_VTBL struct ITangramTreeViewCallBackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITangramTreeViewCallBack_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITangramTreeViewCallBack_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITangramTreeViewCallBack_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITangramTreeViewCallBack_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITangramTreeViewCallBack_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITangramTreeViewCallBack_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITangramTreeViewCallBack_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITangramTreeViewCallBack_put_WndNode(This,newVal)	\
    ( (This)->lpVtbl -> put_WndNode(This,newVal) ) 

#define ITangramTreeViewCallBack_get_Pages(This,retVal)	\
    ( (This)->lpVtbl -> get_Pages(This,retVal) ) 

#define ITangramTreeViewCallBack_OnInitTreeView(This,pTangramTreeView,bstrXml)	\
    ( (This)->lpVtbl -> OnInitTreeView(This,pTangramTreeView,bstrXml) ) 

#define ITangramTreeViewCallBack_OnClick(This,bstrXml,bstrXmlData)	\
    ( (This)->lpVtbl -> OnClick(This,bstrXml,bstrXmlData) ) 

#define ITangramTreeViewCallBack_OnInit(This,bstrXml)	\
    ( (This)->lpVtbl -> OnInit(This,bstrXml) ) 

#define ITangramTreeViewCallBack_OnNewPage(This,nNewPage)	\
    ( (This)->lpVtbl -> OnNewPage(This,nNewPage) ) 

#define ITangramTreeViewCallBack_TangramAction(This,bstrXml,bstrRetXml)	\
    ( (This)->lpVtbl -> TangramAction(This,bstrXml,bstrRetXml) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITangramTreeViewCallBack_INTERFACE_DEFINED__ */


#ifndef __ITangramTreeView_INTERFACE_DEFINED__
#define __ITangramTreeView_INTERFACE_DEFINED__

/* interface ITangramTreeView */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITangramTreeView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-0601198283A5")
    ITangramTreeView : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TangramTreeViewCallBack( 
            BSTR bstrKey,
            /* [in] */ ITangramTreeViewCallBack *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FirstRoot( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddTreeNode( 
            long hItem,
            BSTR bstrXml) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InsertNode( 
            BSTR bstrXml,
            /* [retval][out] */ long *hItem) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITangramTreeViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITangramTreeView * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITangramTreeView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITangramTreeView * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITangramTreeView * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITangramTreeView * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITangramTreeView * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITangramTreeView * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TangramTreeViewCallBack )( 
            ITangramTreeView * This,
            BSTR bstrKey,
            /* [in] */ ITangramTreeViewCallBack *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstRoot )( 
            ITangramTreeView * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddTreeNode )( 
            ITangramTreeView * This,
            long hItem,
            BSTR bstrXml);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InsertNode )( 
            ITangramTreeView * This,
            BSTR bstrXml,
            /* [retval][out] */ long *hItem);
        
        END_INTERFACE
    } ITangramTreeViewVtbl;

    interface ITangramTreeView
    {
        CONST_VTBL struct ITangramTreeViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITangramTreeView_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITangramTreeView_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITangramTreeView_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITangramTreeView_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITangramTreeView_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITangramTreeView_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITangramTreeView_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITangramTreeView_put_TangramTreeViewCallBack(This,bstrKey,newVal)	\
    ( (This)->lpVtbl -> put_TangramTreeViewCallBack(This,bstrKey,newVal) ) 

#define ITangramTreeView_get_FirstRoot(This,pVal)	\
    ( (This)->lpVtbl -> get_FirstRoot(This,pVal) ) 

#define ITangramTreeView_AddTreeNode(This,hItem,bstrXml)	\
    ( (This)->lpVtbl -> AddTreeNode(This,hItem,bstrXml) ) 

#define ITangramTreeView_InsertNode(This,bstrXml,hItem)	\
    ( (This)->lpVtbl -> InsertNode(This,bstrXml,hItem) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITangramTreeView_INTERFACE_DEFINED__ */


#ifndef __ITangramApp_INTERFACE_DEFINED__
#define __ITangramApp_INTERFACE_DEFINED__

/* interface ITangramApp */
/* [unique][helpstring][nonextensible][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_ITangramApp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119820000")
    ITangramApp : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Tangram( 
            /* [retval][out] */ ITangram **ppTangramCore) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITangramAppVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITangramApp * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITangramApp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITangramApp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITangramApp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITangramApp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITangramApp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITangramApp * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tangram )( 
            ITangramApp * This,
            /* [retval][out] */ ITangram **ppTangramCore);
        
        END_INTERFACE
    } ITangramAppVtbl;

    interface ITangramApp
    {
        CONST_VTBL struct ITangramAppVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITangramApp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITangramApp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITangramApp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITangramApp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITangramApp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITangramApp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITangramApp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITangramApp_get_Tangram(This,ppTangramCore)	\
    ( (This)->lpVtbl -> get_Tangram(This,ppTangramCore) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITangramApp_INTERFACE_DEFINED__ */


#ifndef __ITangramEventObj_INTERFACE_DEFINED__
#define __ITangramEventObj_INTERFACE_DEFINED__

/* interface ITangramEventObj */
/* [unique][helpstring][nonextensible][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_ITangramEventObj;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120160928")
    ITangramEventObj : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_eventSource( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_eventSource( 
            /* [in] */ IDispatch *eventSource) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Index( 
            /* [retval][out] */ int *nVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Index( 
            int newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_EventName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_EventName( 
            BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Object( 
            int nIndex,
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Object( 
            int nIndex,
            IDispatch *newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            int nIndex,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            int nIndex,
            VARIANT newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITangramEventObjVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITangramEventObj * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITangramEventObj * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITangramEventObj * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITangramEventObj * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITangramEventObj * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITangramEventObj * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITangramEventObj * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_eventSource )( 
            ITangramEventObj * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_eventSource )( 
            ITangramEventObj * This,
            /* [in] */ IDispatch *eventSource);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Index )( 
            ITangramEventObj * This,
            /* [retval][out] */ int *nVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Index )( 
            ITangramEventObj * This,
            int newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventName )( 
            ITangramEventObj * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EventName )( 
            ITangramEventObj * This,
            BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Object )( 
            ITangramEventObj * This,
            int nIndex,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Object )( 
            ITangramEventObj * This,
            int nIndex,
            IDispatch *newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            ITangramEventObj * This,
            int nIndex,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            ITangramEventObj * This,
            int nIndex,
            VARIANT newVal);
        
        END_INTERFACE
    } ITangramEventObjVtbl;

    interface ITangramEventObj
    {
        CONST_VTBL struct ITangramEventObjVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITangramEventObj_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITangramEventObj_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITangramEventObj_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITangramEventObj_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITangramEventObj_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITangramEventObj_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITangramEventObj_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITangramEventObj_get_eventSource(This,pVal)	\
    ( (This)->lpVtbl -> get_eventSource(This,pVal) ) 

#define ITangramEventObj_put_eventSource(This,eventSource)	\
    ( (This)->lpVtbl -> put_eventSource(This,eventSource) ) 

#define ITangramEventObj_get_Index(This,nVal)	\
    ( (This)->lpVtbl -> get_Index(This,nVal) ) 

#define ITangramEventObj_put_Index(This,newVal)	\
    ( (This)->lpVtbl -> put_Index(This,newVal) ) 

#define ITangramEventObj_get_EventName(This,pVal)	\
    ( (This)->lpVtbl -> get_EventName(This,pVal) ) 

#define ITangramEventObj_put_EventName(This,newVal)	\
    ( (This)->lpVtbl -> put_EventName(This,newVal) ) 

#define ITangramEventObj_get_Object(This,nIndex,pVal)	\
    ( (This)->lpVtbl -> get_Object(This,nIndex,pVal) ) 

#define ITangramEventObj_put_Object(This,nIndex,newVal)	\
    ( (This)->lpVtbl -> put_Object(This,nIndex,newVal) ) 

#define ITangramEventObj_get_Value(This,nIndex,pVal)	\
    ( (This)->lpVtbl -> get_Value(This,nIndex,pVal) ) 

#define ITangramEventObj_put_Value(This,nIndex,newVal)	\
    ( (This)->lpVtbl -> put_Value(This,nIndex,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITangramEventObj_INTERFACE_DEFINED__ */


#ifndef __IWndNode_INTERFACE_DEFINED__
#define __IWndNode_INTERFACE_DEFINED__

/* interface IWndNode */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IWndNode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119820004")
    IWndNode : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ChildNodes( 
            /* [retval][out] */ IWndNodeCollection **ppNodeColletion) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Rows( 
            /* [retval][out] */ long *nRows) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Cols( 
            /* [retval][out] */ long *nCols) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Row( 
            /* [retval][out] */ long *nRow) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Col( 
            /* [retval][out] */ long *nCol) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NodeType( 
            /* [retval][out] */ TangramViewType *nType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ParentNode( 
            /* [retval][out] */ IWndNode **ppNode) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CompositorManager( 
            /* [retval][out] */ ICompositorManager **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RootNode( 
            /* [retval][out] */ IWndNode **ppNode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_XObject( 
            /* [retval][out] */ VARIANT *pVar) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AxPlugIn( 
            /* [in] */ BSTR bstrPlugInName,
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Caption( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Caption( 
            /* [in] */ BSTR bstrCaption) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Objects( 
            /* [in] */ long nType,
            /* [retval][out] */ IWndNodeCollection **ppNodeColletion) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Handle( 
            /* [retval][out] */ LONGLONG *hWnd) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Attribute( 
            /* [in] */ BSTR bstrKey,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Attribute( 
            /* [in] */ BSTR bstrKey,
            /* [in] */ BSTR bstrVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pVar) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT vVar) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OuterXml( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Key( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_NameAtWindowPage( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Compositor( 
            /* [retval][out] */ ICompositor **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_XML( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Extender( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Extender( 
            /* [in] */ IDispatch *newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_DocXml( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_rgbMiddle( 
            /* [retval][out] */ OLE_COLOR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_rgbMiddle( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_rgbRightBottom( 
            /* [retval][out] */ OLE_COLOR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_rgbRightBottom( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_rgbLeftTop( 
            /* [retval][out] */ OLE_COLOR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_rgbLeftTop( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Hmin( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Hmin( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Hmax( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Hmax( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Vmin( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Vmin( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Vmax( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Vmax( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_HostNode( 
            /* [retval][out] */ IWndNode **pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_HostNode( 
            /* [in] */ IWndNode *newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ActivePage( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ActivePage( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HostCompositor( 
            /* [retval][out] */ ICompositor **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MasterRow( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MasterRow( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MasterCol( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MasterCol( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OfficeObj( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_SaveToConfigFile( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_DockObj( 
            BSTR bstrName,
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_DockObj( 
            BSTR bstrName,
            /* [in] */ LONGLONG newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_VSDocument( 
            /* [retval][out] */ IVSDocument **ppVSDocument) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_URL( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_URL( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE ActiveTabPage( 
            IWndNode *pNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNodes( 
            /* [in] */ BSTR bstrName,
            /* [out] */ IWndNode **ppNode,
            /* [out] */ IWndNodeCollection **ppNodes,
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNode( 
            /* [in] */ long nRow,
            /* [in] */ long nCol,
            /* [retval][out] */ IWndNode **ppWndmNode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCtrlByName( 
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            /* [retval][out] */ IDispatch **ppCtrlDisp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Open( 
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppRetNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadXML( 
            int nType,
            BSTR bstrXML) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenEx( 
            int nRow,
            int nCol,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppRetNode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetNodeByName( 
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ IWndNodeCollection **pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCtrlValueByName( 
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            /* [retval][out] */ BSTR *bstrVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetCtrlValueByName( 
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            BSTR bstrVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE NavigateURL( 
            BSTR bstrURL,
            IDispatch *dispObjforScript) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddChannel( 
            BSTR bstrChannel) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SendIPCMessage( 
            BSTR bstrChannel,
            BSTR bstrData) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWndNodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWndNode * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWndNode * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWndNode * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWndNode * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWndNode * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWndNode * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWndNode * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ChildNodes )( 
            IWndNode * This,
            /* [retval][out] */ IWndNodeCollection **ppNodeColletion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rows )( 
            IWndNode * This,
            /* [retval][out] */ long *nRows);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cols )( 
            IWndNode * This,
            /* [retval][out] */ long *nCols);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Row )( 
            IWndNode * This,
            /* [retval][out] */ long *nRow);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Col )( 
            IWndNode * This,
            /* [retval][out] */ long *nCol);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NodeType )( 
            IWndNode * This,
            /* [retval][out] */ TangramViewType *nType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ParentNode )( 
            IWndNode * This,
            /* [retval][out] */ IWndNode **ppNode);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompositorManager )( 
            IWndNode * This,
            /* [retval][out] */ ICompositorManager **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RootNode )( 
            IWndNode * This,
            /* [retval][out] */ IWndNode **ppNode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XObject )( 
            IWndNode * This,
            /* [retval][out] */ VARIANT *pVar);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AxPlugIn )( 
            IWndNode * This,
            /* [in] */ BSTR bstrPlugInName,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Caption )( 
            IWndNode * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Caption )( 
            IWndNode * This,
            /* [in] */ BSTR bstrCaption);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IWndNode * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IWndNode * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Objects )( 
            IWndNode * This,
            /* [in] */ long nType,
            /* [retval][out] */ IWndNodeCollection **ppNodeColletion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IWndNode * This,
            /* [retval][out] */ LONGLONG *hWnd);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Attribute )( 
            IWndNode * This,
            /* [in] */ BSTR bstrKey,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Attribute )( 
            IWndNode * This,
            /* [in] */ BSTR bstrKey,
            /* [in] */ BSTR bstrVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IWndNode * This,
            /* [retval][out] */ VARIANT *pVar);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IWndNode * This,
            /* [in] */ VARIANT vVar);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OuterXml )( 
            IWndNode * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Key )( 
            IWndNode * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NameAtWindowPage )( 
            IWndNode * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IWndNode * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IWndNode * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Compositor )( 
            IWndNode * This,
            /* [retval][out] */ ICompositor **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XML )( 
            IWndNode * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            IWndNode * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Extender )( 
            IWndNode * This,
            /* [in] */ IDispatch *newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DocXml )( 
            IWndNode * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_rgbMiddle )( 
            IWndNode * This,
            /* [retval][out] */ OLE_COLOR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_rgbMiddle )( 
            IWndNode * This,
            /* [in] */ OLE_COLOR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_rgbRightBottom )( 
            IWndNode * This,
            /* [retval][out] */ OLE_COLOR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_rgbRightBottom )( 
            IWndNode * This,
            /* [in] */ OLE_COLOR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_rgbLeftTop )( 
            IWndNode * This,
            /* [retval][out] */ OLE_COLOR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_rgbLeftTop )( 
            IWndNode * This,
            /* [in] */ OLE_COLOR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Hmin )( 
            IWndNode * This,
            /* [retval][out] */ int *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Hmin )( 
            IWndNode * This,
            /* [in] */ int newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Hmax )( 
            IWndNode * This,
            /* [retval][out] */ int *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Hmax )( 
            IWndNode * This,
            /* [in] */ int newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Vmin )( 
            IWndNode * This,
            /* [retval][out] */ int *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Vmin )( 
            IWndNode * This,
            /* [in] */ int newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Vmax )( 
            IWndNode * This,
            /* [retval][out] */ int *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Vmax )( 
            IWndNode * This,
            /* [in] */ int newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostNode )( 
            IWndNode * This,
            /* [retval][out] */ IWndNode **pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HostNode )( 
            IWndNode * This,
            /* [in] */ IWndNode *newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActivePage )( 
            IWndNode * This,
            /* [retval][out] */ int *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActivePage )( 
            IWndNode * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostCompositor )( 
            IWndNode * This,
            /* [retval][out] */ ICompositor **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MasterRow )( 
            IWndNode * This,
            /* [retval][out] */ int *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MasterRow )( 
            IWndNode * This,
            /* [in] */ int newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MasterCol )( 
            IWndNode * This,
            /* [retval][out] */ int *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MasterCol )( 
            IWndNode * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OfficeObj )( 
            IWndNode * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SaveToConfigFile )( 
            IWndNode * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DockObj )( 
            IWndNode * This,
            BSTR bstrName,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DockObj )( 
            IWndNode * This,
            BSTR bstrName,
            /* [in] */ LONGLONG newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VSDocument )( 
            IWndNode * This,
            /* [retval][out] */ IVSDocument **ppVSDocument);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_URL )( 
            IWndNode * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_URL )( 
            IWndNode * This,
            /* [in] */ BSTR newVal);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *ActiveTabPage )( 
            IWndNode * This,
            IWndNode *pNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNodes )( 
            IWndNode * This,
            /* [in] */ BSTR bstrName,
            /* [out] */ IWndNode **ppNode,
            /* [out] */ IWndNodeCollection **ppNodes,
            /* [retval][out] */ long *pCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNode )( 
            IWndNode * This,
            /* [in] */ long nRow,
            /* [in] */ long nCol,
            /* [retval][out] */ IWndNode **ppWndmNode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCtrlByName )( 
            IWndNode * This,
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            /* [retval][out] */ IDispatch **ppCtrlDisp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IWndNode * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IWndNode * This,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppRetNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadXML )( 
            IWndNode * This,
            int nType,
            BSTR bstrXML);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenEx )( 
            IWndNode * This,
            int nRow,
            int nCol,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppRetNode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetNodeByName )( 
            IWndNode * This,
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ IWndNodeCollection **pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCtrlValueByName )( 
            IWndNode * This,
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            /* [retval][out] */ BSTR *bstrVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetCtrlValueByName )( 
            IWndNode * This,
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            BSTR bstrVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *NavigateURL )( 
            IWndNode * This,
            BSTR bstrURL,
            IDispatch *dispObjforScript);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddChannel )( 
            IWndNode * This,
            BSTR bstrChannel);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SendIPCMessage )( 
            IWndNode * This,
            BSTR bstrChannel,
            BSTR bstrData);
        
        END_INTERFACE
    } IWndNodeVtbl;

    interface IWndNode
    {
        CONST_VTBL struct IWndNodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWndNode_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWndNode_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWndNode_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWndNode_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWndNode_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWndNode_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWndNode_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWndNode_get_ChildNodes(This,ppNodeColletion)	\
    ( (This)->lpVtbl -> get_ChildNodes(This,ppNodeColletion) ) 

#define IWndNode_get_Rows(This,nRows)	\
    ( (This)->lpVtbl -> get_Rows(This,nRows) ) 

#define IWndNode_get_Cols(This,nCols)	\
    ( (This)->lpVtbl -> get_Cols(This,nCols) ) 

#define IWndNode_get_Row(This,nRow)	\
    ( (This)->lpVtbl -> get_Row(This,nRow) ) 

#define IWndNode_get_Col(This,nCol)	\
    ( (This)->lpVtbl -> get_Col(This,nCol) ) 

#define IWndNode_get_NodeType(This,nType)	\
    ( (This)->lpVtbl -> get_NodeType(This,nType) ) 

#define IWndNode_get_ParentNode(This,ppNode)	\
    ( (This)->lpVtbl -> get_ParentNode(This,ppNode) ) 

#define IWndNode_get_CompositorManager(This,pVal)	\
    ( (This)->lpVtbl -> get_CompositorManager(This,pVal) ) 

#define IWndNode_get_RootNode(This,ppNode)	\
    ( (This)->lpVtbl -> get_RootNode(This,ppNode) ) 

#define IWndNode_get_XObject(This,pVar)	\
    ( (This)->lpVtbl -> get_XObject(This,pVar) ) 

#define IWndNode_get_AxPlugIn(This,bstrPlugInName,pVal)	\
    ( (This)->lpVtbl -> get_AxPlugIn(This,bstrPlugInName,pVal) ) 

#define IWndNode_get_Caption(This,pVal)	\
    ( (This)->lpVtbl -> get_Caption(This,pVal) ) 

#define IWndNode_put_Caption(This,bstrCaption)	\
    ( (This)->lpVtbl -> put_Caption(This,bstrCaption) ) 

#define IWndNode_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IWndNode_put_Name(This,bstrName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrName) ) 

#define IWndNode_get_Objects(This,nType,ppNodeColletion)	\
    ( (This)->lpVtbl -> get_Objects(This,nType,ppNodeColletion) ) 

#define IWndNode_get_Handle(This,hWnd)	\
    ( (This)->lpVtbl -> get_Handle(This,hWnd) ) 

#define IWndNode_get_Attribute(This,bstrKey,pVal)	\
    ( (This)->lpVtbl -> get_Attribute(This,bstrKey,pVal) ) 

#define IWndNode_put_Attribute(This,bstrKey,bstrVal)	\
    ( (This)->lpVtbl -> put_Attribute(This,bstrKey,bstrVal) ) 

#define IWndNode_get_Tag(This,pVar)	\
    ( (This)->lpVtbl -> get_Tag(This,pVar) ) 

#define IWndNode_put_Tag(This,vVar)	\
    ( (This)->lpVtbl -> put_Tag(This,vVar) ) 

#define IWndNode_get_OuterXml(This,pVal)	\
    ( (This)->lpVtbl -> get_OuterXml(This,pVal) ) 

#define IWndNode_get_Key(This,pVal)	\
    ( (This)->lpVtbl -> get_Key(This,pVal) ) 

#define IWndNode_get_NameAtWindowPage(This,pVal)	\
    ( (This)->lpVtbl -> get_NameAtWindowPage(This,pVal) ) 

#define IWndNode_get_Width(This,pVal)	\
    ( (This)->lpVtbl -> get_Width(This,pVal) ) 

#define IWndNode_get_Height(This,pVal)	\
    ( (This)->lpVtbl -> get_Height(This,pVal) ) 

#define IWndNode_get_Compositor(This,pVal)	\
    ( (This)->lpVtbl -> get_Compositor(This,pVal) ) 

#define IWndNode_get_XML(This,pVal)	\
    ( (This)->lpVtbl -> get_XML(This,pVal) ) 

#define IWndNode_get_Extender(This,pVal)	\
    ( (This)->lpVtbl -> get_Extender(This,pVal) ) 

#define IWndNode_put_Extender(This,newVal)	\
    ( (This)->lpVtbl -> put_Extender(This,newVal) ) 

#define IWndNode_get_DocXml(This,pVal)	\
    ( (This)->lpVtbl -> get_DocXml(This,pVal) ) 

#define IWndNode_get_rgbMiddle(This,pVal)	\
    ( (This)->lpVtbl -> get_rgbMiddle(This,pVal) ) 

#define IWndNode_put_rgbMiddle(This,newVal)	\
    ( (This)->lpVtbl -> put_rgbMiddle(This,newVal) ) 

#define IWndNode_get_rgbRightBottom(This,pVal)	\
    ( (This)->lpVtbl -> get_rgbRightBottom(This,pVal) ) 

#define IWndNode_put_rgbRightBottom(This,newVal)	\
    ( (This)->lpVtbl -> put_rgbRightBottom(This,newVal) ) 

#define IWndNode_get_rgbLeftTop(This,pVal)	\
    ( (This)->lpVtbl -> get_rgbLeftTop(This,pVal) ) 

#define IWndNode_put_rgbLeftTop(This,newVal)	\
    ( (This)->lpVtbl -> put_rgbLeftTop(This,newVal) ) 

#define IWndNode_get_Hmin(This,pVal)	\
    ( (This)->lpVtbl -> get_Hmin(This,pVal) ) 

#define IWndNode_put_Hmin(This,newVal)	\
    ( (This)->lpVtbl -> put_Hmin(This,newVal) ) 

#define IWndNode_get_Hmax(This,pVal)	\
    ( (This)->lpVtbl -> get_Hmax(This,pVal) ) 

#define IWndNode_put_Hmax(This,newVal)	\
    ( (This)->lpVtbl -> put_Hmax(This,newVal) ) 

#define IWndNode_get_Vmin(This,pVal)	\
    ( (This)->lpVtbl -> get_Vmin(This,pVal) ) 

#define IWndNode_put_Vmin(This,newVal)	\
    ( (This)->lpVtbl -> put_Vmin(This,newVal) ) 

#define IWndNode_get_Vmax(This,pVal)	\
    ( (This)->lpVtbl -> get_Vmax(This,pVal) ) 

#define IWndNode_put_Vmax(This,newVal)	\
    ( (This)->lpVtbl -> put_Vmax(This,newVal) ) 

#define IWndNode_get_HostNode(This,pVal)	\
    ( (This)->lpVtbl -> get_HostNode(This,pVal) ) 

#define IWndNode_put_HostNode(This,newVal)	\
    ( (This)->lpVtbl -> put_HostNode(This,newVal) ) 

#define IWndNode_get_ActivePage(This,pVal)	\
    ( (This)->lpVtbl -> get_ActivePage(This,pVal) ) 

#define IWndNode_put_ActivePage(This,newVal)	\
    ( (This)->lpVtbl -> put_ActivePage(This,newVal) ) 

#define IWndNode_get_HostCompositor(This,pVal)	\
    ( (This)->lpVtbl -> get_HostCompositor(This,pVal) ) 

#define IWndNode_get_MasterRow(This,pVal)	\
    ( (This)->lpVtbl -> get_MasterRow(This,pVal) ) 

#define IWndNode_put_MasterRow(This,newVal)	\
    ( (This)->lpVtbl -> put_MasterRow(This,newVal) ) 

#define IWndNode_get_MasterCol(This,pVal)	\
    ( (This)->lpVtbl -> get_MasterCol(This,pVal) ) 

#define IWndNode_put_MasterCol(This,newVal)	\
    ( (This)->lpVtbl -> put_MasterCol(This,newVal) ) 

#define IWndNode_get_OfficeObj(This,pVal)	\
    ( (This)->lpVtbl -> get_OfficeObj(This,pVal) ) 

#define IWndNode_put_SaveToConfigFile(This,newVal)	\
    ( (This)->lpVtbl -> put_SaveToConfigFile(This,newVal) ) 

#define IWndNode_get_DockObj(This,bstrName,pVal)	\
    ( (This)->lpVtbl -> get_DockObj(This,bstrName,pVal) ) 

#define IWndNode_put_DockObj(This,bstrName,newVal)	\
    ( (This)->lpVtbl -> put_DockObj(This,bstrName,newVal) ) 

#define IWndNode_get_VSDocument(This,ppVSDocument)	\
    ( (This)->lpVtbl -> get_VSDocument(This,ppVSDocument) ) 

#define IWndNode_get_URL(This,pVal)	\
    ( (This)->lpVtbl -> get_URL(This,pVal) ) 

#define IWndNode_put_URL(This,newVal)	\
    ( (This)->lpVtbl -> put_URL(This,newVal) ) 

#define IWndNode_ActiveTabPage(This,pNode)	\
    ( (This)->lpVtbl -> ActiveTabPage(This,pNode) ) 

#define IWndNode_GetNodes(This,bstrName,ppNode,ppNodes,pCount)	\
    ( (This)->lpVtbl -> GetNodes(This,bstrName,ppNode,ppNodes,pCount) ) 

#define IWndNode_GetNode(This,nRow,nCol,ppWndmNode)	\
    ( (This)->lpVtbl -> GetNode(This,nRow,nCol,ppWndmNode) ) 

#define IWndNode_GetCtrlByName(This,bstrName,bFindInChild,ppCtrlDisp)	\
    ( (This)->lpVtbl -> GetCtrlByName(This,bstrName,bFindInChild,ppCtrlDisp) ) 

#define IWndNode_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IWndNode_Open(This,bstrKey,bstrXml,ppRetNode)	\
    ( (This)->lpVtbl -> Open(This,bstrKey,bstrXml,ppRetNode) ) 

#define IWndNode_LoadXML(This,nType,bstrXML)	\
    ( (This)->lpVtbl -> LoadXML(This,nType,bstrXML) ) 

#define IWndNode_OpenEx(This,nRow,nCol,bstrKey,bstrXml,ppRetNode)	\
    ( (This)->lpVtbl -> OpenEx(This,nRow,nCol,bstrKey,bstrXml,ppRetNode) ) 

#define IWndNode_GetNodeByName(This,bstrName,pVal)	\
    ( (This)->lpVtbl -> GetNodeByName(This,bstrName,pVal) ) 

#define IWndNode_GetCtrlValueByName(This,bstrName,bFindInChild,bstrVal)	\
    ( (This)->lpVtbl -> GetCtrlValueByName(This,bstrName,bFindInChild,bstrVal) ) 

#define IWndNode_SetCtrlValueByName(This,bstrName,bFindInChild,bstrVal)	\
    ( (This)->lpVtbl -> SetCtrlValueByName(This,bstrName,bFindInChild,bstrVal) ) 

#define IWndNode_NavigateURL(This,bstrURL,dispObjforScript)	\
    ( (This)->lpVtbl -> NavigateURL(This,bstrURL,dispObjforScript) ) 

#define IWndNode_AddChannel(This,bstrChannel)	\
    ( (This)->lpVtbl -> AddChannel(This,bstrChannel) ) 

#define IWndNode_SendIPCMessage(This,bstrChannel,bstrData)	\
    ( (This)->lpVtbl -> SendIPCMessage(This,bstrChannel,bstrData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWndNode_INTERFACE_DEFINED__ */


#ifndef __IAppExtender_INTERFACE_DEFINED__
#define __IAppExtender_INTERFACE_DEFINED__

/* interface IAppExtender */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAppExtender;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119822007")
    IAppExtender : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ProcessNotify( 
            /* [in] */ BSTR bstrXmlNotify) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAppExtenderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppExtender * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppExtender * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppExtender * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAppExtender * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAppExtender * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAppExtender * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAppExtender * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ProcessNotify )( 
            IAppExtender * This,
            /* [in] */ BSTR bstrXmlNotify);
        
        END_INTERFACE
    } IAppExtenderVtbl;

    interface IAppExtender
    {
        CONST_VTBL struct IAppExtenderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppExtender_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppExtender_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppExtender_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppExtender_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAppExtender_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAppExtender_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAppExtender_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAppExtender_ProcessNotify(This,bstrXmlNotify)	\
    ( (This)->lpVtbl -> ProcessNotify(This,bstrXmlNotify) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppExtender_INTERFACE_DEFINED__ */


#ifndef __ITangramEditor_INTERFACE_DEFINED__
#define __ITangramEditor_INTERFACE_DEFINED__

/* interface ITangramEditor */
/* [unique][helpstring][nonextensible][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_ITangramEditor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119826688")
    ITangramEditor : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ITangramEditorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITangramEditor * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITangramEditor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITangramEditor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITangramEditor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITangramEditor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITangramEditor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITangramEditor * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ITangramEditorVtbl;

    interface ITangramEditor
    {
        CONST_VTBL struct ITangramEditorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITangramEditor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITangramEditor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITangramEditor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITangramEditor_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITangramEditor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITangramEditor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITangramEditor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITangramEditor_INTERFACE_DEFINED__ */


#ifndef __ITangramDoc_INTERFACE_DEFINED__
#define __ITangramDoc_INTERFACE_DEFINED__

/* interface ITangramDoc */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITangramDoc;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120161101")
    ITangramDoc : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TemplateXml( 
            /* [retval][out] */ BSTR *bstrVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TemplateXml( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_DocType( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_DocID( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_DocID( 
            /* [in] */ LONGLONG newVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFrameWndXml( 
            BSTR bstrWndID,
            /* [retval][out] */ BSTR *bstrWndScriptVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITangramDocVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITangramDoc * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITangramDoc * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITangramDoc * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITangramDoc * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITangramDoc * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITangramDoc * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITangramDoc * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TemplateXml )( 
            ITangramDoc * This,
            /* [retval][out] */ BSTR *bstrVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TemplateXml )( 
            ITangramDoc * This,
            /* [in] */ BSTR newVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DocType )( 
            ITangramDoc * This,
            /* [in] */ BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DocID )( 
            ITangramDoc * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DocID )( 
            ITangramDoc * This,
            /* [in] */ LONGLONG newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFrameWndXml )( 
            ITangramDoc * This,
            BSTR bstrWndID,
            /* [retval][out] */ BSTR *bstrWndScriptVal);
        
        END_INTERFACE
    } ITangramDocVtbl;

    interface ITangramDoc
    {
        CONST_VTBL struct ITangramDocVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITangramDoc_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITangramDoc_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITangramDoc_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITangramDoc_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITangramDoc_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITangramDoc_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITangramDoc_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITangramDoc_get_TemplateXml(This,bstrVal)	\
    ( (This)->lpVtbl -> get_TemplateXml(This,bstrVal) ) 

#define ITangramDoc_put_TemplateXml(This,newVal)	\
    ( (This)->lpVtbl -> put_TemplateXml(This,newVal) ) 

#define ITangramDoc_put_DocType(This,newVal)	\
    ( (This)->lpVtbl -> put_DocType(This,newVal) ) 

#define ITangramDoc_get_DocID(This,pVal)	\
    ( (This)->lpVtbl -> get_DocID(This,pVal) ) 

#define ITangramDoc_put_DocID(This,newVal)	\
    ( (This)->lpVtbl -> put_DocID(This,newVal) ) 

#define ITangramDoc_GetFrameWndXml(This,bstrWndID,bstrWndScriptVal)	\
    ( (This)->lpVtbl -> GetFrameWndXml(This,bstrWndID,bstrWndScriptVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITangramDoc_INTERFACE_DEFINED__ */


#ifndef __ITangramDocTemplate_INTERFACE_DEFINED__
#define __ITangramDocTemplate_INTERFACE_DEFINED__

/* interface ITangramDocTemplate */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITangramDocTemplate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120170707")
    ITangramDocTemplate : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TemplateXml( 
            /* [retval][out] */ BSTR *bstrVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TemplateXml( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_DocType( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_DocID( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_DocID( 
            /* [in] */ LONGLONG newVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFrameWndXml( 
            BSTR bstrWndID,
            /* [retval][out] */ BSTR *bstrWndScriptVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITangramDocTemplateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITangramDocTemplate * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITangramDocTemplate * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITangramDocTemplate * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITangramDocTemplate * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITangramDocTemplate * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITangramDocTemplate * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITangramDocTemplate * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TemplateXml )( 
            ITangramDocTemplate * This,
            /* [retval][out] */ BSTR *bstrVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TemplateXml )( 
            ITangramDocTemplate * This,
            /* [in] */ BSTR newVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DocType )( 
            ITangramDocTemplate * This,
            /* [in] */ BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DocID )( 
            ITangramDocTemplate * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DocID )( 
            ITangramDocTemplate * This,
            /* [in] */ LONGLONG newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFrameWndXml )( 
            ITangramDocTemplate * This,
            BSTR bstrWndID,
            /* [retval][out] */ BSTR *bstrWndScriptVal);
        
        END_INTERFACE
    } ITangramDocTemplateVtbl;

    interface ITangramDocTemplate
    {
        CONST_VTBL struct ITangramDocTemplateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITangramDocTemplate_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITangramDocTemplate_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITangramDocTemplate_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITangramDocTemplate_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITangramDocTemplate_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITangramDocTemplate_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITangramDocTemplate_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITangramDocTemplate_get_TemplateXml(This,bstrVal)	\
    ( (This)->lpVtbl -> get_TemplateXml(This,bstrVal) ) 

#define ITangramDocTemplate_put_TemplateXml(This,newVal)	\
    ( (This)->lpVtbl -> put_TemplateXml(This,newVal) ) 

#define ITangramDocTemplate_put_DocType(This,newVal)	\
    ( (This)->lpVtbl -> put_DocType(This,newVal) ) 

#define ITangramDocTemplate_get_DocID(This,pVal)	\
    ( (This)->lpVtbl -> get_DocID(This,pVal) ) 

#define ITangramDocTemplate_put_DocID(This,newVal)	\
    ( (This)->lpVtbl -> put_DocID(This,newVal) ) 

#define ITangramDocTemplate_GetFrameWndXml(This,bstrWndID,bstrWndScriptVal)	\
    ( (This)->lpVtbl -> GetFrameWndXml(This,bstrWndID,bstrWndScriptVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITangramDocTemplate_INTERFACE_DEFINED__ */


#ifndef __ITangramJava_INTERFACE_DEFINED__
#define __ITangramJava_INTERFACE_DEFINED__

/* interface ITangramJava */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITangramJava;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-0601da3b0a66")
    ITangramJava : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateCompositorManager( 
            LONGLONG hWnd,
            /* [retval][out] */ IDispatch **ppCompositorManager) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateObject( 
            BSTR bstrObjID,
            /* [retval][out] */ IDispatch **ppObj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ActiveMethod( 
            BSTR bstrObjID,
            BSTR bstrMethodName,
            BSTR bstrParams) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreatingNode( 
            /* [retval][out] */ IDispatch **ppCreatingNode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Open( 
            LONGLONG hWnd,
            BSTR bstrKey,
            BSTR bstrXML,
            BSTR bstrFeatures) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITangramJavaVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITangramJava * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITangramJava * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITangramJava * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITangramJava * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITangramJava * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITangramJava * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITangramJava * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateCompositorManager )( 
            ITangramJava * This,
            LONGLONG hWnd,
            /* [retval][out] */ IDispatch **ppCompositorManager);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateObject )( 
            ITangramJava * This,
            BSTR bstrObjID,
            /* [retval][out] */ IDispatch **ppObj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ActiveMethod )( 
            ITangramJava * This,
            BSTR bstrObjID,
            BSTR bstrMethodName,
            BSTR bstrParams);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreatingNode )( 
            ITangramJava * This,
            /* [retval][out] */ IDispatch **ppCreatingNode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            ITangramJava * This,
            LONGLONG hWnd,
            BSTR bstrKey,
            BSTR bstrXML,
            BSTR bstrFeatures);
        
        END_INTERFACE
    } ITangramJavaVtbl;

    interface ITangramJava
    {
        CONST_VTBL struct ITangramJavaVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITangramJava_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITangramJava_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITangramJava_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITangramJava_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITangramJava_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITangramJava_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITangramJava_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITangramJava_CreateCompositorManager(This,hWnd,ppCompositorManager)	\
    ( (This)->lpVtbl -> CreateCompositorManager(This,hWnd,ppCompositorManager) ) 

#define ITangramJava_CreateObject(This,bstrObjID,ppObj)	\
    ( (This)->lpVtbl -> CreateObject(This,bstrObjID,ppObj) ) 

#define ITangramJava_ActiveMethod(This,bstrObjID,bstrMethodName,bstrParams)	\
    ( (This)->lpVtbl -> ActiveMethod(This,bstrObjID,bstrMethodName,bstrParams) ) 

#define ITangramJava_CreatingNode(This,ppCreatingNode)	\
    ( (This)->lpVtbl -> CreatingNode(This,ppCreatingNode) ) 

#define ITangramJava_Open(This,hWnd,bstrKey,bstrXML,bstrFeatures)	\
    ( (This)->lpVtbl -> Open(This,hWnd,bstrKey,bstrXML,bstrFeatures) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITangramJava_INTERFACE_DEFINED__ */


#ifndef __ITangram_INTERFACE_DEFINED__
#define __ITangram_INTERFACE_DEFINED__

/* interface ITangram */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITangram;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119820001")
    ITangram : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Application( 
            /* [in] */ IDispatch *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AppKeyValue( 
            BSTR bstrKey,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AppKeyValue( 
            BSTR bstrKey,
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AppExtender( 
            BSTR bstrKey,
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AppExtender( 
            BSTR bstrKey,
            /* [in] */ IDispatch *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RootNodes( 
            /* [retval][out] */ IWndNodeCollection **ppNodeColletion) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_HostWnd( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentActiveNode( 
            /* [retval][out] */ IWndNode **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CreatingNode( 
            /* [retval][out] */ IWndNode **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_RemoteTangram( 
            BSTR bstrID,
            /* [retval][out] */ ITangram **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Extender( 
            /* [retval][out] */ ITangramExtender **pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Extender( 
            /* [in] */ ITangramExtender *newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_RemoteHelperHWND( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_RemoteHelperHWND( 
            /* [in] */ LONGLONG newVal) = 0;
        
        virtual /* [hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get_DesignNode( 
            /* [retval][out] */ IWndNode **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TangramDoc( 
            LONGLONG AppProxy,
            LONGLONG nDocID,
            /* [retval][out] */ ITangramDoc **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_DocTemplate( 
            BSTR bstrID,
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveChromeBrowserWnd( 
            /* [retval][out] */ IChromeWebBrowser **ppChromeWebBrowser) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_HostChromeBrowserWnd( 
            /* [retval][out] */ IChromeWebBrowser **ppChromeWebBrowser) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE NavigateNode( 
            IWndNode *pNode,
            BSTR bstrBrowserID,
            BSTR bstrXml) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateCompositorManager( 
            LONGLONG hWnd,
            /* [retval][out] */ ICompositorManager **ppCompositorManager) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateOfficeDocument( 
            BSTR bstrXml) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateCLRObj( 
            BSTR bstrObjID,
            /* [retval][out] */ IDispatch **ppDisp) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StartApplication( 
            BSTR bstrAppID,
            BSTR bstrXml) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCompositor( 
            LONGLONG hHostWnd,
            /* [retval][out] */ ICompositor **ppCompositor) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetItemText( 
            IWndNode *pNode,
            long nCtrlID,
            LONG nMaxLengeh,
            /* [retval][out] */ BSTR *bstrRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetItemText( 
            IWndNode *pNode,
            long nCtrlID,
            BSTR bstrText) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCLRControl( 
            IDispatch *CtrlDisp,
            BSTR bstrName,
            /* [retval][out] */ IDispatch **ppRetDisp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MessageBox( 
            LONGLONG hWnd,
            BSTR bstrContext,
            BSTR bstrCaption,
            long nStyle,
            /* [retval][out] */ int *nRet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Encode( 
            BSTR bstrSRC,
            VARIANT_BOOL bEncode,
            /* [retval][out] */ BSTR *bstrRet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetHostFocus( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UpdateWndNode( 
            IWndNode *pNode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NewGUID( 
            /* [retval][out] */ BSTR *retVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ActiveCLRMethod( 
            BSTR bstrObjID,
            BSTR bstrMethod,
            BSTR bstrParam,
            BSTR bstrData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TangramGetObject( 
            IDispatch *SourceDisp,
            IDispatch **ResultDisp) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DownLoadFile( 
            BSTR strFileURL,
            BSTR bstrTargetFile,
            BSTR bstrActionXml) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCtrlByName( 
            IDispatch *pCtrl,
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            /* [retval][out] */ IDispatch **ppCtrlDisp) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetNodeFromHandle( 
            LONGLONG hWnd,
            /* [retval][out] */ IWndNode **ppRetNode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCtrlValueByName( 
            IDispatch *pCtrl,
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            /* [retval][out] */ BSTR *bstrVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetCtrlValueByName( 
            IDispatch *pCtrl,
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            BSTR bstrVal) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE CreateTangramCtrl( 
            BSTR bstrAppID,
            /* [retval][out] */ ITangramCtrl **ppRetCtrl) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AttachObjEvent( 
            IDispatch *pDisp,
            int nEventIndex) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetWindowClientDefaultNode( 
            IDispatch *pAddDisp,
            LONGLONG hParent,
            BSTR bstrWndClaName,
            BSTR bstrCompositorManagerName,
            /* [retval][out] */ IWndNode **ppNode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetDocTemplateXml( 
            BSTR bstrCaption,
            BSTR bstrPath,
            BSTR bstrFilter,
            /* [retval][out] */ BSTR *bstrTemplatePath) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenTangramFile( 
            /* [retval][out] */ ITangramDoc **ppDoc) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateTangramEventObj( 
            /* [retval][out] */ ITangramEventObj **ppTangramEventObj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE FireTangramEventObj( 
            ITangramEventObj *pTangramEventObj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenCompositors( 
            LONGLONG hWnd,
            BSTR bstrFrames,
            BSTR bstrKey,
            BSTR bstrXml,
            VARIANT_BOOL bSaveToConfigFile) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DeletePage( 
            LONGLONG PageHandle) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE LoadDocComponent( 
            BSTR bstrLib,
            /* [retval][out] */ LONGLONG *llAppProxy) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenTangramDocFile( 
            BSTR bstrFilePath,
            /* [retval][out] */ ITangramDoc **ppDoc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateOutLookObj( 
            BSTR bstrObjType,
            int nType,
            BSTR bstrURL,
            /* [retval][out] */ IDispatch **ppRetDisp) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE NewWorkBench( 
            BSTR bstrTangramDoc,
            /* [retval][out] */ IWorkBenchWindow **ppWorkBenchWindow) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadTextFromWeb( 
            BSTR bstrURL,
            BSTR bstrOrg,
            BSTR bstrRepo,
            BSTR bstrBranch,
            BSTR bstrFile,
            BSTR bstrTarget,
            LONGLONG hNotify) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ClearHeader( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DeleteFrame( 
            ICompositor *pCompositor) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE InitEclipseApp( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE InitCLRApp( 
            BSTR strInitXml,
            /* [retval][out] */ LONGLONG *llHandle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TangramCommand( 
            IDispatch *RibbonControl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TangramGetImage( 
            BSTR strValue,
            /* [retval][out] */ IPictureDisp **ppdispImage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TangramGetVisible( 
            IDispatch *RibbonControl,
            /* [retval][out] */ VARIANT *varVisible) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TangramOnLoad( 
            IDispatch *RibbonControl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TangramGetItemCount( 
            IDispatch *RibbonControl,
            /* [retval][out] */ long *nCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TangramGetItemLabel( 
            IDispatch *RibbonControl,
            long nIndex,
            /* [retval][out] */ BSTR *bstrLabel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TangramGetItemID( 
            IDispatch *RibbonControl,
            long nIndex,
            /* [retval][out] */ BSTR *bstrID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITangramVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITangram * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITangram * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITangram * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITangram * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITangram * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITangram * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITangram * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            ITangram * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Application )( 
            ITangram * This,
            /* [in] */ IDispatch *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AppKeyValue )( 
            ITangram * This,
            BSTR bstrKey,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AppKeyValue )( 
            ITangram * This,
            BSTR bstrKey,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AppExtender )( 
            ITangram * This,
            BSTR bstrKey,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AppExtender )( 
            ITangram * This,
            BSTR bstrKey,
            /* [in] */ IDispatch *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RootNodes )( 
            ITangram * This,
            /* [retval][out] */ IWndNodeCollection **ppNodeColletion);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostWnd )( 
            ITangram * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentActiveNode )( 
            ITangram * This,
            /* [retval][out] */ IWndNode **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CreatingNode )( 
            ITangram * This,
            /* [retval][out] */ IWndNode **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemoteTangram )( 
            ITangram * This,
            BSTR bstrID,
            /* [retval][out] */ ITangram **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            ITangram * This,
            /* [retval][out] */ ITangramExtender **pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Extender )( 
            ITangram * This,
            /* [in] */ ITangramExtender *newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemoteHelperHWND )( 
            ITangram * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RemoteHelperHWND )( 
            ITangram * This,
            /* [in] */ LONGLONG newVal);
        
        /* [hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DesignNode )( 
            ITangram * This,
            /* [retval][out] */ IWndNode **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TangramDoc )( 
            ITangram * This,
            LONGLONG AppProxy,
            LONGLONG nDocID,
            /* [retval][out] */ ITangramDoc **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DocTemplate )( 
            ITangram * This,
            BSTR bstrID,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveChromeBrowserWnd )( 
            ITangram * This,
            /* [retval][out] */ IChromeWebBrowser **ppChromeWebBrowser);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostChromeBrowserWnd )( 
            ITangram * This,
            /* [retval][out] */ IChromeWebBrowser **ppChromeWebBrowser);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *NavigateNode )( 
            ITangram * This,
            IWndNode *pNode,
            BSTR bstrBrowserID,
            BSTR bstrXml);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateCompositorManager )( 
            ITangram * This,
            LONGLONG hWnd,
            /* [retval][out] */ ICompositorManager **ppCompositorManager);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateOfficeDocument )( 
            ITangram * This,
            BSTR bstrXml);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateCLRObj )( 
            ITangram * This,
            BSTR bstrObjID,
            /* [retval][out] */ IDispatch **ppDisp);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StartApplication )( 
            ITangram * This,
            BSTR bstrAppID,
            BSTR bstrXml);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCompositor )( 
            ITangram * This,
            LONGLONG hHostWnd,
            /* [retval][out] */ ICompositor **ppCompositor);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetItemText )( 
            ITangram * This,
            IWndNode *pNode,
            long nCtrlID,
            LONG nMaxLengeh,
            /* [retval][out] */ BSTR *bstrRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetItemText )( 
            ITangram * This,
            IWndNode *pNode,
            long nCtrlID,
            BSTR bstrText);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCLRControl )( 
            ITangram * This,
            IDispatch *CtrlDisp,
            BSTR bstrName,
            /* [retval][out] */ IDispatch **ppRetDisp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MessageBox )( 
            ITangram * This,
            LONGLONG hWnd,
            BSTR bstrContext,
            BSTR bstrCaption,
            long nStyle,
            /* [retval][out] */ int *nRet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Encode )( 
            ITangram * This,
            BSTR bstrSRC,
            VARIANT_BOOL bEncode,
            /* [retval][out] */ BSTR *bstrRet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetHostFocus )( 
            ITangram * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UpdateWndNode )( 
            ITangram * This,
            IWndNode *pNode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NewGUID )( 
            ITangram * This,
            /* [retval][out] */ BSTR *retVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ActiveCLRMethod )( 
            ITangram * This,
            BSTR bstrObjID,
            BSTR bstrMethod,
            BSTR bstrParam,
            BSTR bstrData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TangramGetObject )( 
            ITangram * This,
            IDispatch *SourceDisp,
            IDispatch **ResultDisp);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DownLoadFile )( 
            ITangram * This,
            BSTR strFileURL,
            BSTR bstrTargetFile,
            BSTR bstrActionXml);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCtrlByName )( 
            ITangram * This,
            IDispatch *pCtrl,
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            /* [retval][out] */ IDispatch **ppCtrlDisp);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetNodeFromHandle )( 
            ITangram * This,
            LONGLONG hWnd,
            /* [retval][out] */ IWndNode **ppRetNode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCtrlValueByName )( 
            ITangram * This,
            IDispatch *pCtrl,
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            /* [retval][out] */ BSTR *bstrVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetCtrlValueByName )( 
            ITangram * This,
            IDispatch *pCtrl,
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            BSTR bstrVal);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *CreateTangramCtrl )( 
            ITangram * This,
            BSTR bstrAppID,
            /* [retval][out] */ ITangramCtrl **ppRetCtrl);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AttachObjEvent )( 
            ITangram * This,
            IDispatch *pDisp,
            int nEventIndex);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetWindowClientDefaultNode )( 
            ITangram * This,
            IDispatch *pAddDisp,
            LONGLONG hParent,
            BSTR bstrWndClaName,
            BSTR bstrCompositorManagerName,
            /* [retval][out] */ IWndNode **ppNode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetDocTemplateXml )( 
            ITangram * This,
            BSTR bstrCaption,
            BSTR bstrPath,
            BSTR bstrFilter,
            /* [retval][out] */ BSTR *bstrTemplatePath);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenTangramFile )( 
            ITangram * This,
            /* [retval][out] */ ITangramDoc **ppDoc);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateTangramEventObj )( 
            ITangram * This,
            /* [retval][out] */ ITangramEventObj **ppTangramEventObj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *FireTangramEventObj )( 
            ITangram * This,
            ITangramEventObj *pTangramEventObj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenCompositors )( 
            ITangram * This,
            LONGLONG hWnd,
            BSTR bstrFrames,
            BSTR bstrKey,
            BSTR bstrXml,
            VARIANT_BOOL bSaveToConfigFile);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DeletePage )( 
            ITangram * This,
            LONGLONG PageHandle);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *LoadDocComponent )( 
            ITangram * This,
            BSTR bstrLib,
            /* [retval][out] */ LONGLONG *llAppProxy);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenTangramDocFile )( 
            ITangram * This,
            BSTR bstrFilePath,
            /* [retval][out] */ ITangramDoc **ppDoc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateOutLookObj )( 
            ITangram * This,
            BSTR bstrObjType,
            int nType,
            BSTR bstrURL,
            /* [retval][out] */ IDispatch **ppRetDisp);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *NewWorkBench )( 
            ITangram * This,
            BSTR bstrTangramDoc,
            /* [retval][out] */ IWorkBenchWindow **ppWorkBenchWindow);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadTextFromWeb )( 
            ITangram * This,
            BSTR bstrURL,
            BSTR bstrOrg,
            BSTR bstrRepo,
            BSTR bstrBranch,
            BSTR bstrFile,
            BSTR bstrTarget,
            LONGLONG hNotify);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ClearHeader )( 
            ITangram * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DeleteFrame )( 
            ITangram * This,
            ICompositor *pCompositor);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *InitEclipseApp )( 
            ITangram * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *InitCLRApp )( 
            ITangram * This,
            BSTR strInitXml,
            /* [retval][out] */ LONGLONG *llHandle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TangramCommand )( 
            ITangram * This,
            IDispatch *RibbonControl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TangramGetImage )( 
            ITangram * This,
            BSTR strValue,
            /* [retval][out] */ IPictureDisp **ppdispImage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TangramGetVisible )( 
            ITangram * This,
            IDispatch *RibbonControl,
            /* [retval][out] */ VARIANT *varVisible);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TangramOnLoad )( 
            ITangram * This,
            IDispatch *RibbonControl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TangramGetItemCount )( 
            ITangram * This,
            IDispatch *RibbonControl,
            /* [retval][out] */ long *nCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TangramGetItemLabel )( 
            ITangram * This,
            IDispatch *RibbonControl,
            long nIndex,
            /* [retval][out] */ BSTR *bstrLabel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TangramGetItemID )( 
            ITangram * This,
            IDispatch *RibbonControl,
            long nIndex,
            /* [retval][out] */ BSTR *bstrID);
        
        END_INTERFACE
    } ITangramVtbl;

    interface ITangram
    {
        CONST_VTBL struct ITangramVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITangram_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITangram_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITangram_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITangram_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITangram_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITangram_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITangram_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITangram_get_Application(This,pVal)	\
    ( (This)->lpVtbl -> get_Application(This,pVal) ) 

#define ITangram_put_Application(This,newVal)	\
    ( (This)->lpVtbl -> put_Application(This,newVal) ) 

#define ITangram_get_AppKeyValue(This,bstrKey,pVal)	\
    ( (This)->lpVtbl -> get_AppKeyValue(This,bstrKey,pVal) ) 

#define ITangram_put_AppKeyValue(This,bstrKey,newVal)	\
    ( (This)->lpVtbl -> put_AppKeyValue(This,bstrKey,newVal) ) 

#define ITangram_get_AppExtender(This,bstrKey,pVal)	\
    ( (This)->lpVtbl -> get_AppExtender(This,bstrKey,pVal) ) 

#define ITangram_put_AppExtender(This,bstrKey,newVal)	\
    ( (This)->lpVtbl -> put_AppExtender(This,bstrKey,newVal) ) 

#define ITangram_get_RootNodes(This,ppNodeColletion)	\
    ( (This)->lpVtbl -> get_RootNodes(This,ppNodeColletion) ) 

#define ITangram_get_HostWnd(This,pVal)	\
    ( (This)->lpVtbl -> get_HostWnd(This,pVal) ) 

#define ITangram_get_CurrentActiveNode(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentActiveNode(This,pVal) ) 

#define ITangram_get_CreatingNode(This,pVal)	\
    ( (This)->lpVtbl -> get_CreatingNode(This,pVal) ) 

#define ITangram_get_RemoteTangram(This,bstrID,pVal)	\
    ( (This)->lpVtbl -> get_RemoteTangram(This,bstrID,pVal) ) 

#define ITangram_get_Extender(This,pVal)	\
    ( (This)->lpVtbl -> get_Extender(This,pVal) ) 

#define ITangram_put_Extender(This,newVal)	\
    ( (This)->lpVtbl -> put_Extender(This,newVal) ) 

#define ITangram_get_RemoteHelperHWND(This,pVal)	\
    ( (This)->lpVtbl -> get_RemoteHelperHWND(This,pVal) ) 

#define ITangram_put_RemoteHelperHWND(This,newVal)	\
    ( (This)->lpVtbl -> put_RemoteHelperHWND(This,newVal) ) 

#define ITangram_get_DesignNode(This,pVal)	\
    ( (This)->lpVtbl -> get_DesignNode(This,pVal) ) 

#define ITangram_get_TangramDoc(This,AppProxy,nDocID,pVal)	\
    ( (This)->lpVtbl -> get_TangramDoc(This,AppProxy,nDocID,pVal) ) 

#define ITangram_get_DocTemplate(This,bstrID,pVal)	\
    ( (This)->lpVtbl -> get_DocTemplate(This,bstrID,pVal) ) 

#define ITangram_get_ActiveChromeBrowserWnd(This,ppChromeWebBrowser)	\
    ( (This)->lpVtbl -> get_ActiveChromeBrowserWnd(This,ppChromeWebBrowser) ) 

#define ITangram_get_HostChromeBrowserWnd(This,ppChromeWebBrowser)	\
    ( (This)->lpVtbl -> get_HostChromeBrowserWnd(This,ppChromeWebBrowser) ) 

#define ITangram_NavigateNode(This,pNode,bstrBrowserID,bstrXml)	\
    ( (This)->lpVtbl -> NavigateNode(This,pNode,bstrBrowserID,bstrXml) ) 

#define ITangram_CreateCompositorManager(This,hWnd,ppCompositorManager)	\
    ( (This)->lpVtbl -> CreateCompositorManager(This,hWnd,ppCompositorManager) ) 

#define ITangram_CreateOfficeDocument(This,bstrXml)	\
    ( (This)->lpVtbl -> CreateOfficeDocument(This,bstrXml) ) 

#define ITangram_CreateCLRObj(This,bstrObjID,ppDisp)	\
    ( (This)->lpVtbl -> CreateCLRObj(This,bstrObjID,ppDisp) ) 

#define ITangram_StartApplication(This,bstrAppID,bstrXml)	\
    ( (This)->lpVtbl -> StartApplication(This,bstrAppID,bstrXml) ) 

#define ITangram_GetCompositor(This,hHostWnd,ppCompositor)	\
    ( (This)->lpVtbl -> GetCompositor(This,hHostWnd,ppCompositor) ) 

#define ITangram_GetItemText(This,pNode,nCtrlID,nMaxLengeh,bstrRet)	\
    ( (This)->lpVtbl -> GetItemText(This,pNode,nCtrlID,nMaxLengeh,bstrRet) ) 

#define ITangram_SetItemText(This,pNode,nCtrlID,bstrText)	\
    ( (This)->lpVtbl -> SetItemText(This,pNode,nCtrlID,bstrText) ) 

#define ITangram_GetCLRControl(This,CtrlDisp,bstrName,ppRetDisp)	\
    ( (This)->lpVtbl -> GetCLRControl(This,CtrlDisp,bstrName,ppRetDisp) ) 

#define ITangram_MessageBox(This,hWnd,bstrContext,bstrCaption,nStyle,nRet)	\
    ( (This)->lpVtbl -> MessageBox(This,hWnd,bstrContext,bstrCaption,nStyle,nRet) ) 

#define ITangram_Encode(This,bstrSRC,bEncode,bstrRet)	\
    ( (This)->lpVtbl -> Encode(This,bstrSRC,bEncode,bstrRet) ) 

#define ITangram_SetHostFocus(This)	\
    ( (This)->lpVtbl -> SetHostFocus(This) ) 

#define ITangram_UpdateWndNode(This,pNode)	\
    ( (This)->lpVtbl -> UpdateWndNode(This,pNode) ) 

#define ITangram_NewGUID(This,retVal)	\
    ( (This)->lpVtbl -> NewGUID(This,retVal) ) 

#define ITangram_ActiveCLRMethod(This,bstrObjID,bstrMethod,bstrParam,bstrData)	\
    ( (This)->lpVtbl -> ActiveCLRMethod(This,bstrObjID,bstrMethod,bstrParam,bstrData) ) 

#define ITangram_TangramGetObject(This,SourceDisp,ResultDisp)	\
    ( (This)->lpVtbl -> TangramGetObject(This,SourceDisp,ResultDisp) ) 

#define ITangram_DownLoadFile(This,strFileURL,bstrTargetFile,bstrActionXml)	\
    ( (This)->lpVtbl -> DownLoadFile(This,strFileURL,bstrTargetFile,bstrActionXml) ) 

#define ITangram_GetCtrlByName(This,pCtrl,bstrName,bFindInChild,ppCtrlDisp)	\
    ( (This)->lpVtbl -> GetCtrlByName(This,pCtrl,bstrName,bFindInChild,ppCtrlDisp) ) 

#define ITangram_GetNodeFromHandle(This,hWnd,ppRetNode)	\
    ( (This)->lpVtbl -> GetNodeFromHandle(This,hWnd,ppRetNode) ) 

#define ITangram_GetCtrlValueByName(This,pCtrl,bstrName,bFindInChild,bstrVal)	\
    ( (This)->lpVtbl -> GetCtrlValueByName(This,pCtrl,bstrName,bFindInChild,bstrVal) ) 

#define ITangram_SetCtrlValueByName(This,pCtrl,bstrName,bFindInChild,bstrVal)	\
    ( (This)->lpVtbl -> SetCtrlValueByName(This,pCtrl,bstrName,bFindInChild,bstrVal) ) 

#define ITangram_CreateTangramCtrl(This,bstrAppID,ppRetCtrl)	\
    ( (This)->lpVtbl -> CreateTangramCtrl(This,bstrAppID,ppRetCtrl) ) 

#define ITangram_AttachObjEvent(This,pDisp,nEventIndex)	\
    ( (This)->lpVtbl -> AttachObjEvent(This,pDisp,nEventIndex) ) 

#define ITangram_GetWindowClientDefaultNode(This,pAddDisp,hParent,bstrWndClaName,bstrCompositorManagerName,ppNode)	\
    ( (This)->lpVtbl -> GetWindowClientDefaultNode(This,pAddDisp,hParent,bstrWndClaName,bstrCompositorManagerName,ppNode) ) 

#define ITangram_GetDocTemplateXml(This,bstrCaption,bstrPath,bstrFilter,bstrTemplatePath)	\
    ( (This)->lpVtbl -> GetDocTemplateXml(This,bstrCaption,bstrPath,bstrFilter,bstrTemplatePath) ) 

#define ITangram_OpenTangramFile(This,ppDoc)	\
    ( (This)->lpVtbl -> OpenTangramFile(This,ppDoc) ) 

#define ITangram_CreateTangramEventObj(This,ppTangramEventObj)	\
    ( (This)->lpVtbl -> CreateTangramEventObj(This,ppTangramEventObj) ) 

#define ITangram_FireTangramEventObj(This,pTangramEventObj)	\
    ( (This)->lpVtbl -> FireTangramEventObj(This,pTangramEventObj) ) 

#define ITangram_OpenCompositors(This,hWnd,bstrFrames,bstrKey,bstrXml,bSaveToConfigFile)	\
    ( (This)->lpVtbl -> OpenCompositors(This,hWnd,bstrFrames,bstrKey,bstrXml,bSaveToConfigFile) ) 

#define ITangram_DeletePage(This,PageHandle)	\
    ( (This)->lpVtbl -> DeletePage(This,PageHandle) ) 

#define ITangram_LoadDocComponent(This,bstrLib,llAppProxy)	\
    ( (This)->lpVtbl -> LoadDocComponent(This,bstrLib,llAppProxy) ) 

#define ITangram_OpenTangramDocFile(This,bstrFilePath,ppDoc)	\
    ( (This)->lpVtbl -> OpenTangramDocFile(This,bstrFilePath,ppDoc) ) 

#define ITangram_CreateOutLookObj(This,bstrObjType,nType,bstrURL,ppRetDisp)	\
    ( (This)->lpVtbl -> CreateOutLookObj(This,bstrObjType,nType,bstrURL,ppRetDisp) ) 

#define ITangram_NewWorkBench(This,bstrTangramDoc,ppWorkBenchWindow)	\
    ( (This)->lpVtbl -> NewWorkBench(This,bstrTangramDoc,ppWorkBenchWindow) ) 

#define ITangram_ReadTextFromWeb(This,bstrURL,bstrOrg,bstrRepo,bstrBranch,bstrFile,bstrTarget,hNotify)	\
    ( (This)->lpVtbl -> ReadTextFromWeb(This,bstrURL,bstrOrg,bstrRepo,bstrBranch,bstrFile,bstrTarget,hNotify) ) 

#define ITangram_ClearHeader(This)	\
    ( (This)->lpVtbl -> ClearHeader(This) ) 

#define ITangram_DeleteFrame(This,pCompositor)	\
    ( (This)->lpVtbl -> DeleteFrame(This,pCompositor) ) 

#define ITangram_InitEclipseApp(This)	\
    ( (This)->lpVtbl -> InitEclipseApp(This) ) 

#define ITangram_InitCLRApp(This,strInitXml,llHandle)	\
    ( (This)->lpVtbl -> InitCLRApp(This,strInitXml,llHandle) ) 

#define ITangram_TangramCommand(This,RibbonControl)	\
    ( (This)->lpVtbl -> TangramCommand(This,RibbonControl) ) 

#define ITangram_TangramGetImage(This,strValue,ppdispImage)	\
    ( (This)->lpVtbl -> TangramGetImage(This,strValue,ppdispImage) ) 

#define ITangram_TangramGetVisible(This,RibbonControl,varVisible)	\
    ( (This)->lpVtbl -> TangramGetVisible(This,RibbonControl,varVisible) ) 

#define ITangram_TangramOnLoad(This,RibbonControl)	\
    ( (This)->lpVtbl -> TangramOnLoad(This,RibbonControl) ) 

#define ITangram_TangramGetItemCount(This,RibbonControl,nCount)	\
    ( (This)->lpVtbl -> TangramGetItemCount(This,RibbonControl,nCount) ) 

#define ITangram_TangramGetItemLabel(This,RibbonControl,nIndex,bstrLabel)	\
    ( (This)->lpVtbl -> TangramGetItemLabel(This,RibbonControl,nIndex,bstrLabel) ) 

#define ITangram_TangramGetItemID(This,RibbonControl,nIndex,bstrID)	\
    ( (This)->lpVtbl -> TangramGetItemID(This,RibbonControl,nIndex,bstrID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITangram_INTERFACE_DEFINED__ */


#ifndef __ICompositor_INTERFACE_DEFINED__
#define __ICompositor_INTERFACE_DEFINED__

/* interface ICompositor */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICompositor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119820003")
    ICompositor : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WndNode( 
            /* [in] */ VARIANT vIndex,
            /* [retval][out] */ IWndNode **ppNode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HWND( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VisibleNode( 
            /* [retval][out] */ IWndNode **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentNavigateKey( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CompositorManager( 
            /* [retval][out] */ ICompositorManager **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CompositorData( 
            BSTR bstrKey,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_CompositorData( 
            BSTR bstrKey,
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get_DesignerState( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [hidden][id][propput] */ HRESULT STDMETHODCALLTYPE put_DesignerState( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RootNodes( 
            /* [retval][out] */ IWndNodeCollection **ppNodeColletion) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CompositorXML( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TangramDoc( 
            /* [retval][out] */ ITangramDoc **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CompositorType( 
            /* [retval][out] */ CompositorType *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_HostBrowser( 
            /* [retval][out] */ IChromeWebBrowser **ppChromeWebBrowser) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Detach( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Attach( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ModifyHost( 
            LONGLONG hHostWnd) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Open( 
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppRetNode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetXml( 
            BSTR bstrRootName,
            /* [retval][out] */ BSTR *bstrRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenFromWeb( 
            BSTR bstrURLBase,
            BSTR bstrKey,
            BSTR bstrOrg,
            BSTR bstrRepo,
            BSTR bstrBranch,
            BSTR bstrPath) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SendIPCMessage( 
            int MessageType,
            BSTR bstrMessage,
            BSTR bstrMessageData) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICompositorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICompositor * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICompositor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICompositor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICompositor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICompositor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICompositor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICompositor * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WndNode )( 
            ICompositor * This,
            /* [in] */ VARIANT vIndex,
            /* [retval][out] */ IWndNode **ppNode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            ICompositor * This,
            /* [retval][out] */ IUnknown **ppVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HWND )( 
            ICompositor * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VisibleNode )( 
            ICompositor * This,
            /* [retval][out] */ IWndNode **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentNavigateKey )( 
            ICompositor * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompositorManager )( 
            ICompositor * This,
            /* [retval][out] */ ICompositorManager **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompositorData )( 
            ICompositor * This,
            BSTR bstrKey,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CompositorData )( 
            ICompositor * This,
            BSTR bstrKey,
            /* [in] */ VARIANT newVal);
        
        /* [hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DesignerState )( 
            ICompositor * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [hidden][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DesignerState )( 
            ICompositor * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ICompositor * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RootNodes )( 
            ICompositor * This,
            /* [retval][out] */ IWndNodeCollection **ppNodeColletion);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompositorXML )( 
            ICompositor * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TangramDoc )( 
            ICompositor * This,
            /* [retval][out] */ ITangramDoc **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompositorType )( 
            ICompositor * This,
            /* [retval][out] */ CompositorType *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            ICompositor * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostBrowser )( 
            ICompositor * This,
            /* [retval][out] */ IChromeWebBrowser **ppChromeWebBrowser);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Detach )( 
            ICompositor * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Attach )( 
            ICompositor * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ModifyHost )( 
            ICompositor * This,
            LONGLONG hHostWnd);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            ICompositor * This,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppRetNode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetXml )( 
            ICompositor * This,
            BSTR bstrRootName,
            /* [retval][out] */ BSTR *bstrRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenFromWeb )( 
            ICompositor * This,
            BSTR bstrURLBase,
            BSTR bstrKey,
            BSTR bstrOrg,
            BSTR bstrRepo,
            BSTR bstrBranch,
            BSTR bstrPath);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SendIPCMessage )( 
            ICompositor * This,
            int MessageType,
            BSTR bstrMessage,
            BSTR bstrMessageData);
        
        END_INTERFACE
    } ICompositorVtbl;

    interface ICompositor
    {
        CONST_VTBL struct ICompositorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICompositor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICompositor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICompositor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICompositor_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICompositor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICompositor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICompositor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICompositor_get_WndNode(This,vIndex,ppNode)	\
    ( (This)->lpVtbl -> get_WndNode(This,vIndex,ppNode) ) 

#define ICompositor_get__NewEnum(This,ppVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppVal) ) 

#define ICompositor_get_HWND(This,pVal)	\
    ( (This)->lpVtbl -> get_HWND(This,pVal) ) 

#define ICompositor_get_VisibleNode(This,pVal)	\
    ( (This)->lpVtbl -> get_VisibleNode(This,pVal) ) 

#define ICompositor_get_CurrentNavigateKey(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentNavigateKey(This,pVal) ) 

#define ICompositor_get_CompositorManager(This,pVal)	\
    ( (This)->lpVtbl -> get_CompositorManager(This,pVal) ) 

#define ICompositor_get_CompositorData(This,bstrKey,pVal)	\
    ( (This)->lpVtbl -> get_CompositorData(This,bstrKey,pVal) ) 

#define ICompositor_put_CompositorData(This,bstrKey,newVal)	\
    ( (This)->lpVtbl -> put_CompositorData(This,bstrKey,newVal) ) 

#define ICompositor_get_DesignerState(This,pVal)	\
    ( (This)->lpVtbl -> get_DesignerState(This,pVal) ) 

#define ICompositor_put_DesignerState(This,newVal)	\
    ( (This)->lpVtbl -> put_DesignerState(This,newVal) ) 

#define ICompositor_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#define ICompositor_get_RootNodes(This,ppNodeColletion)	\
    ( (This)->lpVtbl -> get_RootNodes(This,ppNodeColletion) ) 

#define ICompositor_get_CompositorXML(This,pVal)	\
    ( (This)->lpVtbl -> get_CompositorXML(This,pVal) ) 

#define ICompositor_get_TangramDoc(This,pVal)	\
    ( (This)->lpVtbl -> get_TangramDoc(This,pVal) ) 

#define ICompositor_get_CompositorType(This,pVal)	\
    ( (This)->lpVtbl -> get_CompositorType(This,pVal) ) 

#define ICompositor_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define ICompositor_get_HostBrowser(This,ppChromeWebBrowser)	\
    ( (This)->lpVtbl -> get_HostBrowser(This,ppChromeWebBrowser) ) 

#define ICompositor_Detach(This)	\
    ( (This)->lpVtbl -> Detach(This) ) 

#define ICompositor_Attach(This)	\
    ( (This)->lpVtbl -> Attach(This) ) 

#define ICompositor_ModifyHost(This,hHostWnd)	\
    ( (This)->lpVtbl -> ModifyHost(This,hHostWnd) ) 

#define ICompositor_Open(This,bstrKey,bstrXml,ppRetNode)	\
    ( (This)->lpVtbl -> Open(This,bstrKey,bstrXml,ppRetNode) ) 

#define ICompositor_GetXml(This,bstrRootName,bstrRet)	\
    ( (This)->lpVtbl -> GetXml(This,bstrRootName,bstrRet) ) 

#define ICompositor_OpenFromWeb(This,bstrURLBase,bstrKey,bstrOrg,bstrRepo,bstrBranch,bstrPath)	\
    ( (This)->lpVtbl -> OpenFromWeb(This,bstrURLBase,bstrKey,bstrOrg,bstrRepo,bstrBranch,bstrPath) ) 

#define ICompositor_SendIPCMessage(This,MessageType,bstrMessage,bstrMessageData)	\
    ( (This)->lpVtbl -> SendIPCMessage(This,MessageType,bstrMessage,bstrMessageData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICompositor_INTERFACE_DEFINED__ */


#ifndef __IWndNodeCollection_INTERFACE_DEFINED__
#define __IWndNodeCollection_INTERFACE_DEFINED__

/* interface IWndNodeCollection */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IWndNodeCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119820017")
    IWndNodeCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NodeCount( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long iIndex,
            /* [retval][out] */ IWndNode **ppTopWindow) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWndNodeCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWndNodeCollection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWndNodeCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWndNodeCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWndNodeCollection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWndNodeCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWndNodeCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWndNodeCollection * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NodeCount )( 
            IWndNodeCollection * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IWndNodeCollection * This,
            /* [in] */ long iIndex,
            /* [retval][out] */ IWndNode **ppTopWindow);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IWndNodeCollection * This,
            /* [retval][out] */ IUnknown **ppVal);
        
        END_INTERFACE
    } IWndNodeCollectionVtbl;

    interface IWndNodeCollection
    {
        CONST_VTBL struct IWndNodeCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWndNodeCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWndNodeCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWndNodeCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWndNodeCollection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWndNodeCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWndNodeCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWndNodeCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWndNodeCollection_get_NodeCount(This,pCount)	\
    ( (This)->lpVtbl -> get_NodeCount(This,pCount) ) 

#define IWndNodeCollection_get_Item(This,iIndex,ppTopWindow)	\
    ( (This)->lpVtbl -> get_Item(This,iIndex,ppTopWindow) ) 

#define IWndNodeCollection_get__NewEnum(This,ppVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWndNodeCollection_INTERFACE_DEFINED__ */


#ifndef __ICompositorManager_INTERFACE_DEFINED__
#define __ICompositorManager_INTERFACE_DEFINED__

/* interface ICompositorManager */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICompositorManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119820002")
    ICompositorManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Compositor( 
            /* [in] */ VARIANT vIndex,
            /* [retval][out] */ ICompositor **ppCompositor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_xtml( 
            BSTR strKey,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_xtml( 
            BSTR strKey,
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Extender( 
            BSTR bstrExtenderName,
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Extender( 
            BSTR bstrExtenderName,
            /* [in] */ IDispatch *newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Node( 
            BSTR bstrNodeName,
            /* [retval][out] */ IWndNode **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_XObject( 
            BSTR bstrName,
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CompositorName( 
            LONGLONG hHwnd,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Handle( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_NodeNames( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ ICompositorManager **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CompositorManagerXML( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ConfigName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentDesignCompositorType( 
            /* [retval][out] */ CompositorType *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentDesignNode( 
            /* [retval][out] */ IWndNode **pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateCompositor( 
            VARIANT ParentObj,
            VARIANT HostWnd,
            BSTR bstrCompositorName,
            /* [retval][out] */ ICompositor **pRetFrame) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Open( 
            IDispatch *Parent,
            BSTR CtrlName,
            BSTR FrameName,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppRetNode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenCtrl( 
            VARIANT Ctrl,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppRetNode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetWndNode( 
            BSTR bstrFrameName,
            BSTR bstrNodeName,
            /* [retval][out] */ IWndNode **pRetNode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCtrlInNode( 
            BSTR NodeName,
            BSTR CtrlName,
            /* [retval][out] */ IDispatch **ppCtrl) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCompositorFromCtrl( 
            IDispatch *ctrl,
            /* [retval][out] */ ICompositor **ppCompositor) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ConnectTangramCtrl( 
            ITangramCtrl *eventSource) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateCompositorWithDefaultNode( 
            ULONGLONG hFrameWnd,
            BSTR bstrFrameName,
            BSTR bstrDefaultNodeKey,
            BSTR bstrXml,
            VARIANT_BOOL bSaveToConfig,
            /* [retval][out] */ IWndNode **ppNode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenCompositors( 
            BSTR bstrFrames,
            BSTR bstrKey,
            BSTR bstrXml,
            VARIANT_BOOL bSaveToConfigFile) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICompositorManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICompositorManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICompositorManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICompositorManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICompositorManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICompositorManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICompositorManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICompositorManager * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Compositor )( 
            ICompositorManager * This,
            /* [in] */ VARIANT vIndex,
            /* [retval][out] */ ICompositor **ppCompositor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            ICompositorManager * This,
            /* [retval][out] */ IUnknown **ppVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ICompositorManager * This,
            /* [retval][out] */ long *pCount);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_xtml )( 
            ICompositorManager * This,
            BSTR strKey,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_xtml )( 
            ICompositorManager * This,
            BSTR strKey,
            /* [in] */ BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            ICompositorManager * This,
            BSTR bstrExtenderName,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Extender )( 
            ICompositorManager * This,
            BSTR bstrExtenderName,
            /* [in] */ IDispatch *newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Node )( 
            ICompositorManager * This,
            BSTR bstrNodeName,
            /* [retval][out] */ IWndNode **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XObject )( 
            ICompositorManager * This,
            BSTR bstrName,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompositorName )( 
            ICompositorManager * This,
            LONGLONG hHwnd,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            ICompositorManager * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            ICompositorManager * This,
            /* [retval][out] */ long *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            ICompositorManager * This,
            /* [in] */ long newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            ICompositorManager * This,
            /* [retval][out] */ long *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            ICompositorManager * This,
            /* [in] */ long newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NodeNames )( 
            ICompositorManager * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            ICompositorManager * This,
            /* [retval][out] */ ICompositorManager **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompositorManagerXML )( 
            ICompositorManager * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ConfigName )( 
            ICompositorManager * This,
            /* [in] */ BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentDesignCompositorType )( 
            ICompositorManager * This,
            /* [retval][out] */ CompositorType *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentDesignNode )( 
            ICompositorManager * This,
            /* [retval][out] */ IWndNode **pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateCompositor )( 
            ICompositorManager * This,
            VARIANT ParentObj,
            VARIANT HostWnd,
            BSTR bstrCompositorName,
            /* [retval][out] */ ICompositor **pRetFrame);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            ICompositorManager * This,
            IDispatch *Parent,
            BSTR CtrlName,
            BSTR FrameName,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppRetNode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenCtrl )( 
            ICompositorManager * This,
            VARIANT Ctrl,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppRetNode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetWndNode )( 
            ICompositorManager * This,
            BSTR bstrFrameName,
            BSTR bstrNodeName,
            /* [retval][out] */ IWndNode **pRetNode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCtrlInNode )( 
            ICompositorManager * This,
            BSTR NodeName,
            BSTR CtrlName,
            /* [retval][out] */ IDispatch **ppCtrl);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCompositorFromCtrl )( 
            ICompositorManager * This,
            IDispatch *ctrl,
            /* [retval][out] */ ICompositor **ppCompositor);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ConnectTangramCtrl )( 
            ICompositorManager * This,
            ITangramCtrl *eventSource);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateCompositorWithDefaultNode )( 
            ICompositorManager * This,
            ULONGLONG hFrameWnd,
            BSTR bstrFrameName,
            BSTR bstrDefaultNodeKey,
            BSTR bstrXml,
            VARIANT_BOOL bSaveToConfig,
            /* [retval][out] */ IWndNode **ppNode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenCompositors )( 
            ICompositorManager * This,
            BSTR bstrFrames,
            BSTR bstrKey,
            BSTR bstrXml,
            VARIANT_BOOL bSaveToConfigFile);
        
        END_INTERFACE
    } ICompositorManagerVtbl;

    interface ICompositorManager
    {
        CONST_VTBL struct ICompositorManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICompositorManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICompositorManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICompositorManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICompositorManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICompositorManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICompositorManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICompositorManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICompositorManager_get_Compositor(This,vIndex,ppCompositor)	\
    ( (This)->lpVtbl -> get_Compositor(This,vIndex,ppCompositor) ) 

#define ICompositorManager_get__NewEnum(This,ppVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppVal) ) 

#define ICompositorManager_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#define ICompositorManager_get_xtml(This,strKey,pVal)	\
    ( (This)->lpVtbl -> get_xtml(This,strKey,pVal) ) 

#define ICompositorManager_put_xtml(This,strKey,newVal)	\
    ( (This)->lpVtbl -> put_xtml(This,strKey,newVal) ) 

#define ICompositorManager_get_Extender(This,bstrExtenderName,pVal)	\
    ( (This)->lpVtbl -> get_Extender(This,bstrExtenderName,pVal) ) 

#define ICompositorManager_put_Extender(This,bstrExtenderName,newVal)	\
    ( (This)->lpVtbl -> put_Extender(This,bstrExtenderName,newVal) ) 

#define ICompositorManager_get_Node(This,bstrNodeName,pVal)	\
    ( (This)->lpVtbl -> get_Node(This,bstrNodeName,pVal) ) 

#define ICompositorManager_get_XObject(This,bstrName,pVal)	\
    ( (This)->lpVtbl -> get_XObject(This,bstrName,pVal) ) 

#define ICompositorManager_get_CompositorName(This,hHwnd,pVal)	\
    ( (This)->lpVtbl -> get_CompositorName(This,hHwnd,pVal) ) 

#define ICompositorManager_get_Handle(This,pVal)	\
    ( (This)->lpVtbl -> get_Handle(This,pVal) ) 

#define ICompositorManager_get_Width(This,pVal)	\
    ( (This)->lpVtbl -> get_Width(This,pVal) ) 

#define ICompositorManager_put_Width(This,newVal)	\
    ( (This)->lpVtbl -> put_Width(This,newVal) ) 

#define ICompositorManager_get_Height(This,pVal)	\
    ( (This)->lpVtbl -> get_Height(This,pVal) ) 

#define ICompositorManager_put_Height(This,newVal)	\
    ( (This)->lpVtbl -> put_Height(This,newVal) ) 

#define ICompositorManager_get_NodeNames(This,pVal)	\
    ( (This)->lpVtbl -> get_NodeNames(This,pVal) ) 

#define ICompositorManager_get_Parent(This,pVal)	\
    ( (This)->lpVtbl -> get_Parent(This,pVal) ) 

#define ICompositorManager_get_CompositorManagerXML(This,pVal)	\
    ( (This)->lpVtbl -> get_CompositorManagerXML(This,pVal) ) 

#define ICompositorManager_put_ConfigName(This,newVal)	\
    ( (This)->lpVtbl -> put_ConfigName(This,newVal) ) 

#define ICompositorManager_get_CurrentDesignCompositorType(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentDesignCompositorType(This,pVal) ) 

#define ICompositorManager_get_CurrentDesignNode(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentDesignNode(This,pVal) ) 

#define ICompositorManager_CreateCompositor(This,ParentObj,HostWnd,bstrCompositorName,pRetFrame)	\
    ( (This)->lpVtbl -> CreateCompositor(This,ParentObj,HostWnd,bstrCompositorName,pRetFrame) ) 

#define ICompositorManager_Open(This,Parent,CtrlName,FrameName,bstrKey,bstrXml,ppRetNode)	\
    ( (This)->lpVtbl -> Open(This,Parent,CtrlName,FrameName,bstrKey,bstrXml,ppRetNode) ) 

#define ICompositorManager_OpenCtrl(This,Ctrl,bstrKey,bstrXml,ppRetNode)	\
    ( (This)->lpVtbl -> OpenCtrl(This,Ctrl,bstrKey,bstrXml,ppRetNode) ) 

#define ICompositorManager_GetWndNode(This,bstrFrameName,bstrNodeName,pRetNode)	\
    ( (This)->lpVtbl -> GetWndNode(This,bstrFrameName,bstrNodeName,pRetNode) ) 

#define ICompositorManager_GetCtrlInNode(This,NodeName,CtrlName,ppCtrl)	\
    ( (This)->lpVtbl -> GetCtrlInNode(This,NodeName,CtrlName,ppCtrl) ) 

#define ICompositorManager_GetCompositorFromCtrl(This,ctrl,ppCompositor)	\
    ( (This)->lpVtbl -> GetCompositorFromCtrl(This,ctrl,ppCompositor) ) 

#define ICompositorManager_ConnectTangramCtrl(This,eventSource)	\
    ( (This)->lpVtbl -> ConnectTangramCtrl(This,eventSource) ) 

#define ICompositorManager_CreateCompositorWithDefaultNode(This,hFrameWnd,bstrFrameName,bstrDefaultNodeKey,bstrXml,bSaveToConfig,ppNode)	\
    ( (This)->lpVtbl -> CreateCompositorWithDefaultNode(This,hFrameWnd,bstrFrameName,bstrDefaultNodeKey,bstrXml,bSaveToConfig,ppNode) ) 

#define ICompositorManager_OpenCompositors(This,bstrFrames,bstrKey,bstrXml,bSaveToConfigFile)	\
    ( (This)->lpVtbl -> OpenCompositors(This,bstrFrames,bstrKey,bstrXml,bSaveToConfigFile) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICompositorManager_INTERFACE_DEFINED__ */


#ifndef __IWorkBenchWindow_INTERFACE_DEFINED__
#define __IWorkBenchWindow_INTERFACE_DEFINED__

/* interface IWorkBenchWindow */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IWorkBenchWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119825D34")
    IWorkBenchWindow : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Ctrl( 
            /* [in] */ VARIANT vIndex,
            /* [retval][out] */ IEclipseCtrl **ppCtrl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Handle( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TangramCtrl( 
            LONGLONG hWnd,
            /* [retval][out] */ IEclipseCtrl **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CompositorManager( 
            /* [retval][out] */ ICompositorManager **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Compositor( 
            /* [retval][out] */ ICompositor **pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Active( void) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE CloseTangramUI( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Open( 
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppNode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenEx( 
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppNode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenInView( 
            int nIndex,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppRetNode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWorkBenchWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWorkBenchWindow * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWorkBenchWindow * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWorkBenchWindow * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWorkBenchWindow * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWorkBenchWindow * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWorkBenchWindow * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWorkBenchWindow * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Ctrl )( 
            IWorkBenchWindow * This,
            /* [in] */ VARIANT vIndex,
            /* [retval][out] */ IEclipseCtrl **ppCtrl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IWorkBenchWindow * This,
            /* [retval][out] */ IUnknown **ppVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IWorkBenchWindow * This,
            /* [retval][out] */ long *pCount);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IWorkBenchWindow * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TangramCtrl )( 
            IWorkBenchWindow * This,
            LONGLONG hWnd,
            /* [retval][out] */ IEclipseCtrl **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompositorManager )( 
            IWorkBenchWindow * This,
            /* [retval][out] */ ICompositorManager **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Compositor )( 
            IWorkBenchWindow * This,
            /* [retval][out] */ ICompositor **pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Active )( 
            IWorkBenchWindow * This);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *CloseTangramUI )( 
            IWorkBenchWindow * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IWorkBenchWindow * This,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppNode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenEx )( 
            IWorkBenchWindow * This,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppNode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenInView )( 
            IWorkBenchWindow * This,
            int nIndex,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppRetNode);
        
        END_INTERFACE
    } IWorkBenchWindowVtbl;

    interface IWorkBenchWindow
    {
        CONST_VTBL struct IWorkBenchWindowVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWorkBenchWindow_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWorkBenchWindow_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWorkBenchWindow_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWorkBenchWindow_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWorkBenchWindow_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWorkBenchWindow_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWorkBenchWindow_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWorkBenchWindow_get_Ctrl(This,vIndex,ppCtrl)	\
    ( (This)->lpVtbl -> get_Ctrl(This,vIndex,ppCtrl) ) 

#define IWorkBenchWindow_get__NewEnum(This,ppVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppVal) ) 

#define IWorkBenchWindow_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#define IWorkBenchWindow_get_Handle(This,pVal)	\
    ( (This)->lpVtbl -> get_Handle(This,pVal) ) 

#define IWorkBenchWindow_get_TangramCtrl(This,hWnd,pVal)	\
    ( (This)->lpVtbl -> get_TangramCtrl(This,hWnd,pVal) ) 

#define IWorkBenchWindow_get_CompositorManager(This,pVal)	\
    ( (This)->lpVtbl -> get_CompositorManager(This,pVal) ) 

#define IWorkBenchWindow_get_Compositor(This,pVal)	\
    ( (This)->lpVtbl -> get_Compositor(This,pVal) ) 

#define IWorkBenchWindow_Active(This)	\
    ( (This)->lpVtbl -> Active(This) ) 

#define IWorkBenchWindow_CloseTangramUI(This)	\
    ( (This)->lpVtbl -> CloseTangramUI(This) ) 

#define IWorkBenchWindow_Open(This,bstrKey,bstrXml,ppNode)	\
    ( (This)->lpVtbl -> Open(This,bstrKey,bstrXml,ppNode) ) 

#define IWorkBenchWindow_OpenEx(This,bstrKey,bstrXml,ppNode)	\
    ( (This)->lpVtbl -> OpenEx(This,bstrKey,bstrXml,ppNode) ) 

#define IWorkBenchWindow_OpenInView(This,nIndex,bstrKey,bstrXml,ppRetNode)	\
    ( (This)->lpVtbl -> OpenInView(This,nIndex,bstrKey,bstrXml,ppRetNode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWorkBenchWindow_INTERFACE_DEFINED__ */


#ifndef __IChromeWebBrowser_INTERFACE_DEFINED__
#define __IChromeWebBrowser_INTERFACE_DEFINED__

/* interface IChromeWebBrowser */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IChromeWebBrowser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120180828")
    IChromeWebBrowser : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenURL( 
            BSTR bstrURL,
            BrowserWndOpenDisposition nDisposition,
            BSTR bstrKey,
            BSTR bstrXml) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IChromeWebBrowserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IChromeWebBrowser * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IChromeWebBrowser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IChromeWebBrowser * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IChromeWebBrowser * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IChromeWebBrowser * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IChromeWebBrowser * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IChromeWebBrowser * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenURL )( 
            IChromeWebBrowser * This,
            BSTR bstrURL,
            BrowserWndOpenDisposition nDisposition,
            BSTR bstrKey,
            BSTR bstrXml);
        
        END_INTERFACE
    } IChromeWebBrowserVtbl;

    interface IChromeWebBrowser
    {
        CONST_VTBL struct IChromeWebBrowserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChromeWebBrowser_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IChromeWebBrowser_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IChromeWebBrowser_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IChromeWebBrowser_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IChromeWebBrowser_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IChromeWebBrowser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IChromeWebBrowser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IChromeWebBrowser_OpenURL(This,bstrURL,nDisposition,bstrKey,bstrXml)	\
    ( (This)->lpVtbl -> OpenURL(This,bstrURL,nDisposition,bstrKey,bstrXml) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IChromeWebBrowser_INTERFACE_DEFINED__ */


#ifndef __IChromeWebContent_INTERFACE_DEFINED__
#define __IChromeWebContent_INTERFACE_DEFINED__

/* interface IChromeWebContent */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IChromeWebContent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120180903")
    IChromeWebContent : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IChromeWebContentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IChromeWebContent * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IChromeWebContent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IChromeWebContent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IChromeWebContent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IChromeWebContent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IChromeWebContent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IChromeWebContent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IChromeWebContentVtbl;

    interface IChromeWebContent
    {
        CONST_VTBL struct IChromeWebContentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChromeWebContent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IChromeWebContent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IChromeWebContent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IChromeWebContent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IChromeWebContent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IChromeWebContent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IChromeWebContent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IChromeWebContent_INTERFACE_DEFINED__ */


#ifndef __IOfficeObject_INTERFACE_DEFINED__
#define __IOfficeObject_INTERFACE_DEFINED__

/* interface IOfficeObject */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IOfficeObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119650606")
    IOfficeObject : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Show( 
            VARIANT_BOOL bShow) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Open( 
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppNode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UnloadTangram( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOfficeObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfficeObject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfficeObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfficeObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOfficeObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOfficeObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOfficeObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOfficeObject * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Show )( 
            IOfficeObject * This,
            VARIANT_BOOL bShow);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IOfficeObject * This,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppNode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UnloadTangram )( 
            IOfficeObject * This);
        
        END_INTERFACE
    } IOfficeObjectVtbl;

    interface IOfficeObject
    {
        CONST_VTBL struct IOfficeObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfficeObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfficeObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfficeObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfficeObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOfficeObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOfficeObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOfficeObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOfficeObject_Show(This,bShow)	\
    ( (This)->lpVtbl -> Show(This,bShow) ) 

#define IOfficeObject_Open(This,bstrKey,bstrXml,ppNode)	\
    ( (This)->lpVtbl -> Open(This,bstrKey,bstrXml,ppNode) ) 

#define IOfficeObject_UnloadTangram(This)	\
    ( (This)->lpVtbl -> UnloadTangram(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfficeObject_INTERFACE_DEFINED__ */


#ifndef __ITangramCtrl_INTERFACE_DEFINED__
#define __ITangramCtrl_INTERFACE_DEFINED__

/* interface ITangramCtrl */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITangramCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-0601198231DC")
    ITangramCtrl : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HWND( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Tangram( 
            /* [retval][out] */ ITangram **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_tag( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_tag( 
            /* [in] */ VARIANT newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITangramCtrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITangramCtrl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITangramCtrl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITangramCtrl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITangramCtrl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITangramCtrl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITangramCtrl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITangramCtrl * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HWND )( 
            ITangramCtrl * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tangram )( 
            ITangramCtrl * This,
            /* [retval][out] */ ITangram **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_tag )( 
            ITangramCtrl * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_tag )( 
            ITangramCtrl * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } ITangramCtrlVtbl;

    interface ITangramCtrl
    {
        CONST_VTBL struct ITangramCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITangramCtrl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITangramCtrl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITangramCtrl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITangramCtrl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITangramCtrl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITangramCtrl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITangramCtrl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITangramCtrl_get_HWND(This,pVal)	\
    ( (This)->lpVtbl -> get_HWND(This,pVal) ) 

#define ITangramCtrl_get_Tangram(This,pVal)	\
    ( (This)->lpVtbl -> get_Tangram(This,pVal) ) 

#define ITangramCtrl_get_tag(This,pVal)	\
    ( (This)->lpVtbl -> get_tag(This,pVal) ) 

#define ITangramCtrl_put_tag(This,newVal)	\
    ( (This)->lpVtbl -> put_tag(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITangramCtrl_INTERFACE_DEFINED__ */


#ifndef __ITangramAppCtrl_INTERFACE_DEFINED__
#define __ITangramAppCtrl_INTERFACE_DEFINED__

/* interface ITangramAppCtrl */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITangramAppCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120161001")
    ITangramAppCtrl : public ITangramCtrl
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_AppCtrl( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITangramAppCtrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITangramAppCtrl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITangramAppCtrl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITangramAppCtrl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITangramAppCtrl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITangramAppCtrl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITangramAppCtrl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITangramAppCtrl * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HWND )( 
            ITangramAppCtrl * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tangram )( 
            ITangramAppCtrl * This,
            /* [retval][out] */ ITangram **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_tag )( 
            ITangramAppCtrl * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_tag )( 
            ITangramAppCtrl * This,
            /* [in] */ VARIANT newVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AppCtrl )( 
            ITangramAppCtrl * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } ITangramAppCtrlVtbl;

    interface ITangramAppCtrl
    {
        CONST_VTBL struct ITangramAppCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITangramAppCtrl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITangramAppCtrl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITangramAppCtrl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITangramAppCtrl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITangramAppCtrl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITangramAppCtrl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITangramAppCtrl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITangramAppCtrl_get_HWND(This,pVal)	\
    ( (This)->lpVtbl -> get_HWND(This,pVal) ) 

#define ITangramAppCtrl_get_Tangram(This,pVal)	\
    ( (This)->lpVtbl -> get_Tangram(This,pVal) ) 

#define ITangramAppCtrl_get_tag(This,pVal)	\
    ( (This)->lpVtbl -> get_tag(This,pVal) ) 

#define ITangramAppCtrl_put_tag(This,newVal)	\
    ( (This)->lpVtbl -> put_tag(This,newVal) ) 


#define ITangramAppCtrl_put_AppCtrl(This,newVal)	\
    ( (This)->lpVtbl -> put_AppCtrl(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITangramAppCtrl_INTERFACE_DEFINED__ */


#ifndef __IEclipseCtrl_INTERFACE_DEFINED__
#define __IEclipseCtrl_INTERFACE_DEFINED__

/* interface IEclipseCtrl */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IEclipseCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120160912")
    IEclipseCtrl : public ITangramCtrl
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TangramHandle( 
            BSTR bstrHandleName,
            /* [in] */ LONGLONG newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_EclipseViewHandle( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CompositorManager( 
            /* [retval][out] */ ICompositorManager **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_WorkBenchWindow( 
            /* [retval][out] */ IWorkBenchWindow **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TopCompositorManager( 
            /* [retval][out] */ ICompositorManager **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TopCompositor( 
            /* [retval][out] */ ICompositor **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveTopNode( 
            /* [retval][out] */ IWndNode **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AppKeyValue( 
            BSTR bstrKey,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AppKeyValue( 
            BSTR bstrKey,
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Open( 
            BSTR bstrFrameName,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppNode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenEx( 
            BSTR bstrFrameName,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppNode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE InitCtrl( 
            BSTR bstrXml) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEclipseCtrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEclipseCtrl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEclipseCtrl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEclipseCtrl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEclipseCtrl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEclipseCtrl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEclipseCtrl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEclipseCtrl * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HWND )( 
            IEclipseCtrl * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tangram )( 
            IEclipseCtrl * This,
            /* [retval][out] */ ITangram **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_tag )( 
            IEclipseCtrl * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_tag )( 
            IEclipseCtrl * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TangramHandle )( 
            IEclipseCtrl * This,
            BSTR bstrHandleName,
            /* [in] */ LONGLONG newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EclipseViewHandle )( 
            IEclipseCtrl * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompositorManager )( 
            IEclipseCtrl * This,
            /* [retval][out] */ ICompositorManager **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WorkBenchWindow )( 
            IEclipseCtrl * This,
            /* [retval][out] */ IWorkBenchWindow **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TopCompositorManager )( 
            IEclipseCtrl * This,
            /* [retval][out] */ ICompositorManager **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TopCompositor )( 
            IEclipseCtrl * This,
            /* [retval][out] */ ICompositor **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveTopNode )( 
            IEclipseCtrl * This,
            /* [retval][out] */ IWndNode **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AppKeyValue )( 
            IEclipseCtrl * This,
            BSTR bstrKey,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AppKeyValue )( 
            IEclipseCtrl * This,
            BSTR bstrKey,
            /* [in] */ VARIANT newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IEclipseCtrl * This,
            BSTR bstrFrameName,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppNode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenEx )( 
            IEclipseCtrl * This,
            BSTR bstrFrameName,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IWndNode **ppNode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *InitCtrl )( 
            IEclipseCtrl * This,
            BSTR bstrXml);
        
        END_INTERFACE
    } IEclipseCtrlVtbl;

    interface IEclipseCtrl
    {
        CONST_VTBL struct IEclipseCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEclipseCtrl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEclipseCtrl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEclipseCtrl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEclipseCtrl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEclipseCtrl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEclipseCtrl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEclipseCtrl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEclipseCtrl_get_HWND(This,pVal)	\
    ( (This)->lpVtbl -> get_HWND(This,pVal) ) 

#define IEclipseCtrl_get_Tangram(This,pVal)	\
    ( (This)->lpVtbl -> get_Tangram(This,pVal) ) 

#define IEclipseCtrl_get_tag(This,pVal)	\
    ( (This)->lpVtbl -> get_tag(This,pVal) ) 

#define IEclipseCtrl_put_tag(This,newVal)	\
    ( (This)->lpVtbl -> put_tag(This,newVal) ) 


#define IEclipseCtrl_put_TangramHandle(This,bstrHandleName,newVal)	\
    ( (This)->lpVtbl -> put_TangramHandle(This,bstrHandleName,newVal) ) 

#define IEclipseCtrl_get_EclipseViewHandle(This,pVal)	\
    ( (This)->lpVtbl -> get_EclipseViewHandle(This,pVal) ) 

#define IEclipseCtrl_get_CompositorManager(This,pVal)	\
    ( (This)->lpVtbl -> get_CompositorManager(This,pVal) ) 

#define IEclipseCtrl_get_WorkBenchWindow(This,pVal)	\
    ( (This)->lpVtbl -> get_WorkBenchWindow(This,pVal) ) 

#define IEclipseCtrl_get_TopCompositorManager(This,pVal)	\
    ( (This)->lpVtbl -> get_TopCompositorManager(This,pVal) ) 

#define IEclipseCtrl_get_TopCompositor(This,pVal)	\
    ( (This)->lpVtbl -> get_TopCompositor(This,pVal) ) 

#define IEclipseCtrl_get_ActiveTopNode(This,pVal)	\
    ( (This)->lpVtbl -> get_ActiveTopNode(This,pVal) ) 

#define IEclipseCtrl_get_AppKeyValue(This,bstrKey,pVal)	\
    ( (This)->lpVtbl -> get_AppKeyValue(This,bstrKey,pVal) ) 

#define IEclipseCtrl_put_AppKeyValue(This,bstrKey,newVal)	\
    ( (This)->lpVtbl -> put_AppKeyValue(This,bstrKey,newVal) ) 

#define IEclipseCtrl_Open(This,bstrFrameName,bstrKey,bstrXml,ppNode)	\
    ( (This)->lpVtbl -> Open(This,bstrFrameName,bstrKey,bstrXml,ppNode) ) 

#define IEclipseCtrl_OpenEx(This,bstrFrameName,bstrKey,bstrXml,ppNode)	\
    ( (This)->lpVtbl -> OpenEx(This,bstrFrameName,bstrKey,bstrXml,ppNode) ) 

#define IEclipseCtrl_InitCtrl(This,bstrXml)	\
    ( (This)->lpVtbl -> InitCtrl(This,bstrXml) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEclipseCtrl_INTERFACE_DEFINED__ */



#ifndef __Tangram_LIBRARY_DEFINED__
#define __Tangram_LIBRARY_DEFINED__

/* library Tangram */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_Tangram;

#ifndef ___ITangram_DISPINTERFACE_DEFINED__
#define ___ITangram_DISPINTERFACE_DEFINED__

/* dispinterface _ITangram */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ITangram;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("19631222-1992-0612-1965-060119821002")
    _ITangram : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ITangramVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ITangram * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ITangram * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ITangram * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ITangram * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ITangram * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ITangram * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ITangram * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _ITangramVtbl;

    interface _ITangram
    {
        CONST_VTBL struct _ITangramVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ITangram_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ITangram_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ITangram_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ITangram_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ITangram_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ITangram_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ITangram_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ITangram_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Tangram;

#ifdef __cplusplus

class DECLSPEC_UUID("19631222-1992-0612-1965-060119990606")
Tangram;
#endif

#ifndef ___IWndNodeEvents_DISPINTERFACE_DEFINED__
#define ___IWndNodeEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IWndNodeEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IWndNodeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("19631222-1992-0612-1965-060119821001")
    _IWndNodeEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IWndNodeEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IWndNodeEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IWndNodeEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IWndNodeEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IWndNodeEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IWndNodeEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IWndNodeEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IWndNodeEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _IWndNodeEventsVtbl;

    interface _IWndNodeEvents
    {
        CONST_VTBL struct _IWndNodeEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IWndNodeEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IWndNodeEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IWndNodeEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IWndNodeEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IWndNodeEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IWndNodeEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IWndNodeEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IWndNodeEvents_DISPINTERFACE_DEFINED__ */


#ifndef ___ITangramObjEvents_DISPINTERFACE_DEFINED__
#define ___ITangramObjEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ITangramObjEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ITangramObjEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("19631222-1992-0612-1965-060119821992")
    _ITangramObjEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ITangramObjEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ITangramObjEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ITangramObjEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ITangramObjEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ITangramObjEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ITangramObjEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ITangramObjEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ITangramObjEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _ITangramObjEventsVtbl;

    interface _ITangramObjEvents
    {
        CONST_VTBL struct _ITangramObjEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ITangramObjEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ITangramObjEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ITangramObjEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ITangramObjEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ITangramObjEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ITangramObjEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ITangramObjEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ITangramObjEvents_DISPINTERFACE_DEFINED__ */


#ifndef ___ITangramAppEvents_DISPINTERFACE_DEFINED__
#define ___ITangramAppEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ITangramAppEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ITangramAppEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("19631222-1992-0612-1965-060120160930")
    _ITangramAppEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ITangramAppEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ITangramAppEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ITangramAppEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ITangramAppEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ITangramAppEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ITangramAppEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ITangramAppEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ITangramAppEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _ITangramAppEventsVtbl;

    interface _ITangramAppEvents
    {
        CONST_VTBL struct _ITangramAppEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ITangramAppEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ITangramAppEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ITangramAppEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ITangramAppEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ITangramAppEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ITangramAppEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ITangramAppEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ITangramAppEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_TangramCtrl;

#ifdef __cplusplus

class DECLSPEC_UUID("19631222-1992-0612-1965-060120071001")
TangramCtrl;
#endif

EXTERN_C const CLSID CLSID_TangramJava;

#ifdef __cplusplus

class DECLSPEC_UUID("19631222-1992-0612-1965-060120190303")
TangramJava;
#endif

EXTERN_C const CLSID CLSID_TangramExtender;

#ifdef __cplusplus

class DECLSPEC_UUID("19631222-1992-0612-1965-060100000000")
TangramExtender;
#endif
#endif /* __Tangram_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


