/********************************************************************************
*					Tangram Library - version 10.0.0							*
*********************************************************************************
* Copyright (C) 2002-2018 by Tangram Team.   All Rights Reserved.				*
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
* mailto:sunhuizlz@yeah.net
* http://www.CloudAddin.com
*
********************************************************************************/

// Created by Microsoft (R) C/C++ Compiler Version 15.00.21022.08 (b3c27d6c).
// C++ source equivalent of Win32 type library C:\Program Files (x86)\Microsoft Office\Office15\OUTLCTL.DLL
// compiler-generated file created 04/20/13 at 22:46:29 - DO NOT EDIT!

#pragma once
#pragma pack(push, 8)

#include <comdef.h>

//
// Forward references and typedefs
//

struct __declspec(uuid("0006f062-0000-0000-c000-000000000046"))
/* LIBID */ __OLXLib;
struct __declspec(uuid("ba4cf450-ee13-11d3-8c45-00c04f4c517c"))
/* dispinterface */ ViewCtlEvents;
struct /* coclass */ ObjectModelCtl;
struct __declspec(uuid("00067276-0000-0000-c000-000000000046"))
/* dual interface */ IObjectModelAccess;
struct /* coclass */ ViewCtl;
struct __declspec(uuid("00067274-0000-0000-c000-000000000046"))
/* dual interface */ IViewCtl;
enum OlxDefaultFolders;
enum FIELDREGISTRY_REFRESHOPTIONS;
struct /* coclass */ DataCtl;
struct __declspec(uuid("0468c084-ca5b-11d0-af08-00609797f0e0"))
/* interface */ IDataCtl;
typedef enum FIELDREGISTRY_REFRESHOPTIONS FR_REFRESHOPTIONS;

//
// Smart pointer typedef declarations
//

_COM_SMARTPTR_TYPEDEF(ViewCtlEvents, __uuidof(ViewCtlEvents));
_COM_SMARTPTR_TYPEDEF(IObjectModelAccess, __uuidof(IObjectModelAccess));
_COM_SMARTPTR_TYPEDEF(IViewCtl, __uuidof(IViewCtl));
_COM_SMARTPTR_TYPEDEF(IDataCtl, __uuidof(IDataCtl));

//
// Type library items
//

struct __declspec(uuid("ba4cf450-ee13-11d3-8c45-00c04f4c517c"))
ViewCtlEvents : IDispatch
{};

struct __declspec(uuid("0006f069-0000-0000-c000-000000000046"))
ObjectModelCtl;
    // [ default ] interface IObjectModelAccess

struct __declspec(uuid("00067276-0000-0000-c000-000000000046"))
IObjectModelAccess : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_OutlookApplication (
        /*[out,retval]*/ IDispatch * * pVal ) = 0;
      virtual HRESULT __stdcall put_OutlookApplication (
        /*[in]*/ IDispatch * pVal ) = 0;
      virtual HRESULT __stdcall SetPref (
        BSTR szname,
        BSTR szvalue ) = 0;
      virtual HRESULT __stdcall GetPref (
        BSTR szname,
        /*[out,retval]*/ BSTR * pszvalue ) = 0;
      virtual HRESULT __stdcall DeletePrefs ( ) = 0;
      virtual HRESULT __stdcall get_ActiveDesktop (
        /*[out,retval]*/ long * pfActiveDesktop ) = 0;
      virtual HRESULT __stdcall put_ActiveDesktop (
        /*[in]*/ long pfActiveDesktop ) = 0;
      virtual HRESULT __stdcall EnableInProcOptimizations ( ) = 0;
      virtual HRESULT __stdcall FindPerson (
        BSTR bstrName ) = 0;
      virtual HRESULT __stdcall GetDate (
        /*[out,retval]*/ BSTR * pbstrDate ) = 0;
      virtual HRESULT __stdcall PickEmailFolders ( ) = 0;
};

struct __declspec(uuid("261b8ca9-3baf-4bd0-b0c2-bf04286785c6"))
ViewCtl;
    // [ default ] interface IViewCtl
    // [ default, source ] dispinterface ViewCtlEvents

enum OlxDefaultFolders
{
    olxFolderDeletedItems = 3,
    olxFolderOutbox = 4,
    olxFolderSentMail = 5,
    olxFolderInbox = 6,
    olxFolderCalendar = 9,
    olxFolderContacts = 10,
    olxFolderJournal = 11,
    olxFolderNotes = 12,
    olxFolderTasks = 13,
    olxFolderDrafts = 16
};

struct __declspec(uuid("00067274-0000-0000-c000-000000000046"))
IViewCtl : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_View (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_View (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_Folder (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_Folder (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_Namespace (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_Namespace (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_ActiveFolder (
        /*[out,retval]*/ IDispatch * * pVal ) = 0;
      virtual HRESULT __stdcall get_OutlookApplication (
        /*[out,retval]*/ IDispatch * * pVal ) = 0;
      virtual HRESULT __stdcall get_Restriction (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_Restriction (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_DeferUpdate (
        /*[out,retval]*/ VARIANT_BOOL * pVal ) = 0;
      virtual HRESULT __stdcall put_DeferUpdate (
        /*[in]*/ VARIANT_BOOL pVal ) = 0;
      virtual HRESULT __stdcall Open ( ) = 0;
      virtual HRESULT __stdcall Reply ( ) = 0;
      virtual HRESULT __stdcall ReplyAll ( ) = 0;
      virtual HRESULT __stdcall Forward ( ) = 0;
      virtual HRESULT __stdcall ReplyInFolder ( ) = 0;
      virtual HRESULT __stdcall NewDefaultItem ( ) = 0;
      virtual HRESULT __stdcall NewOfficeDocument ( ) = 0;
      virtual HRESULT __stdcall SaveAs ( ) = 0;
      virtual HRESULT __stdcall PrintItem ( ) = 0;
      virtual HRESULT __stdcall FlagItem ( ) = 0;
      virtual HRESULT __stdcall ForceUpdate ( ) = 0;
      virtual HRESULT __stdcall Categories ( ) = 0;
      virtual HRESULT __stdcall MarkAllAsRead ( ) = 0;
      virtual HRESULT __stdcall GoToToday ( ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall AdvancedFind ( ) = 0;
      virtual HRESULT __stdcall AddressBook ( ) = 0;
      virtual HRESULT __stdcall MoveItem ( ) = 0;
      virtual HRESULT __stdcall NewForm ( ) = 0;
      virtual HRESULT __stdcall NewMessage ( ) = 0;
      virtual HRESULT __stdcall NewPost ( ) = 0;
      virtual HRESULT __stdcall NewAppointment ( ) = 0;
      virtual HRESULT __stdcall NewMeetingRequest ( ) = 0;
      virtual HRESULT __stdcall NewTask ( ) = 0;
      virtual HRESULT __stdcall NewTaskRequest ( ) = 0;
      virtual HRESULT __stdcall NewContact ( ) = 0;
      virtual HRESULT __stdcall NewJournalEntry ( ) = 0;
      virtual HRESULT __stdcall CustomizeView ( ) = 0;
      virtual HRESULT __stdcall Sort ( ) = 0;
      virtual HRESULT __stdcall GroupBy ( ) = 0;
      virtual HRESULT __stdcall ShowFields ( ) = 0;
      virtual HRESULT __stdcall CollapseAllGroups ( ) = 0;
      virtual HRESULT __stdcall ExpandAllGroups ( ) = 0;
      virtual HRESULT __stdcall CollapseGroup ( ) = 0;
      virtual HRESULT __stdcall ExpandGroup ( ) = 0;
      virtual HRESULT __stdcall AddToPFFavorites ( ) = 0;
      virtual HRESULT __stdcall SynchFolder ( ) = 0;
      virtual HRESULT __stdcall SendAndReceive ( ) = 0;
      virtual HRESULT __stdcall MarkAsRead ( ) = 0;
      virtual HRESULT __stdcall MarkAsUnread ( ) = 0;
      virtual HRESULT __stdcall OpenSharedDefaultFolder (
        /*[in]*/ BSTR bstrRecipient,
        /*[in]*/ enum OlxDefaultFolders FolderType ) = 0;
      virtual HRESULT __stdcall NewNote ( ) = 0;
      virtual HRESULT __stdcall NewDistributionList ( ) = 0;
      virtual HRESULT __stdcall AddressMessage (
        /*[in]*/ IDispatch * pdispContainer ) = 0;
      virtual HRESULT __stdcall AddressMeeting (
        /*[in]*/ IDispatch * pdispContainer ) = 0;
      virtual HRESULT __stdcall get_Dirty (
        /*[out,retval]*/ VARIANT_BOOL * pVal ) = 0;
      virtual HRESULT __stdcall put_Dirty (
        /*[in]*/ VARIANT_BOOL pVal ) = 0;
      virtual HRESULT __stdcall SaveView (
        /*[in]*/ BSTR ViewName ) = 0;
      virtual HRESULT __stdcall SetDesignMode ( ) = 0;
      virtual HRESULT __stdcall GoToDate (
        /*[in]*/ BSTR newDate ) = 0;
      virtual HRESULT __stdcall get_Filter (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_Filter (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_FilterAppend (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_FilterAppend (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_ItemCount (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall RefreshFieldRegistry (
        /*[in]*/ FR_REFRESHOPTIONS fro ) = 0;
      virtual HRESULT __stdcall get_EnableRowPersistance (
        /*[out,retval]*/ VARIANT_BOOL * pVal ) = 0;
      virtual HRESULT __stdcall put_EnableRowPersistance (
        /*[in]*/ VARIANT_BOOL pVal ) = 0;
      virtual HRESULT __stdcall get_Selection (
        /*[out,retval]*/ IDispatch * * pVal ) = 0;
      virtual HRESULT __stdcall get_ViewXML (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_ViewXML (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_SelectedDate (
        /*[out,retval]*/ DATE * pVal ) = 0;
      virtual HRESULT __stdcall ExplorerActivate ( ) = 0;
      virtual HRESULT __stdcall ExplorerSelectionChange ( ) = 0;
      virtual HRESULT __stdcall ExplorerViewSwitch ( ) = 0;
      virtual HRESULT __stdcall ExplorerBeforeViewSwitch (
        BSTR bStrNewView,
        VARIANT_BOOL * pVarCancel ) = 0;
};

enum FIELDREGISTRY_REFRESHOPTIONS
{
    fro_Forms = 0,
    fro_Fields = 1,
    fro_View = 2
};

struct __declspec(uuid("0468c085-ca5b-11d0-af08-00609797f0e0"))
DataCtl;
    // [ default ] interface IDataCtl

struct __declspec(uuid("0468c084-ca5b-11d0-af08-00609797f0e0"))
IDataCtl : IUnknown
{};

//
// Named GUID constants initializations
//

extern "C" const GUID __declspec(selectany) LIBID_OLXLib =
    {0x0006f062,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) DIID_ViewCtlEvents =
    {0xba4cf450,0xee13,0x11d3,{0x8c,0x45,0x00,0xc0,0x4f,0x4c,0x51,0x7c}};
extern "C" const GUID __declspec(selectany) CLSID_ObjectModelCtl =
    {0x0006f069,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IObjectModelAccess =
    {0x00067276,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_ViewCtl =
    {0x261b8ca9,0x3baf,0x4bd0,{0xb0,0xc2,0xbf,0x04,0x28,0x67,0x85,0xc6}};
extern "C" const GUID __declspec(selectany) IID_IViewCtl =
    {0x00067274,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_DataCtl =
    {0x0468c085,0xca5b,0x11d0,{0xaf,0x08,0x00,0x60,0x97,0x97,0xf0,0xe0}};
extern "C" const GUID __declspec(selectany) IID_IDataCtl =
    {0x0468c084,0xca5b,0x11d0,{0xaf,0x08,0x00,0x60,0x97,0x97,0xf0,0xe0}};

#pragma pack(pop)
