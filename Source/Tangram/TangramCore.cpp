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

// TangramCore.cpp : Implementation of CTangram
/*
C:\src\chromium_stable_75\src\third_party\blink\renderer\core\events
BUILD.gn：
	"wheel_event.cc",
	"wheel_event.h",
	# begin Add by TangramTeam
	"//chrome_proxy/blink/core/tangram_event.cc",
	"//chrome_proxy/blink/core/tangram_event.h",
	# end Add by TangramTeam
event_type_names.json5
	"writestart",
	"zoom",
	# begin ChromeProxy
	"tangrammsg",
	# end ChromeProxy
event_target_names.json5：
	"XMLHttpRequest",
	"XMLHttpRequestUpload",
	# begin ChromeProxy
	"Tangram",
	# end ChromeProxy
*/

#include "stdafx.h"
#include "TangramCore.h"
#include "TangramApp.h"
#include "atlenc.h"
#include "ProgressFX.h"
#include "HourglassFX.h"
#include "DocTemplateDlg.h"
#include "TangramTreeView.h"
#include "TangramListView.h"
#include "TangramTabCtrl.h"
#include "TangramHtmlTreeExWnd.h"
#include "EclipsePlus\EclipseAddin.h"

#include "OfficePlus\OfficeAddin.h"
#include "OfficePlus\ExcelPlus\Excel.h"
#include "OfficePlus\WordPlus\MSWord.h"
#include "OfficePlus\ProjectPlus\MSPrj.h"
#include "OfficePlus\OutLookPlus\MsOutl.h"
#include "OfficePlus\PowerpointPlus\msppt.h"
#include "CloudUtilities\TangramDownLoad.h"
#include "VisualStudioPlus\VSAddin.h"
#include <io.h>
#include <stdio.h>

#include "NodeWnd.h"
#include "WndNode.h"
#include "Compositor.h"
#include "WpfView.h"
#include "SplitterWnd.h"
#include "TangramJavaHelper.h"
#include "TangramCoreEvents.h"
#include "TangramHtmlTreeWnd.h"

#include <shellapi.h>
#include <shlobj.h>
#define MAX_LOADSTRING 100
#ifdef _WIN32
#include <direct.h>
#else
#include <unistd.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <sys/stat.h>
#include "eclipseUnicode.h"
#include "eclipseJni.h"
#include "eclipseCommon.h"

#include "CloudUtilities\TangramComponentInstaller.h"
#include "Markup.h"

using namespace ChromePlus;

#define NAME         _T("-name")
#define VMARGS       _T("-vmargs")					/* special option processing required */
#define LIBRARY		  _T("--launcher.library")
#define SUPRESSERRORS _T("--launcher.suppressErrors")
#define INI			  _T("--launcher.ini")
#define PROTECT	     _T("-protect")	/* This argument is also handled in eclipse.c for Mac specific processing */
#define ROOT		  _T("root")		/* the only level of protection we care now */

_TCHAR* name = NULL;			/* program name */
extern _TCHAR** userVMarg;     		/* user specific args for the Java VM */
int      suppressErrors;/* = 0;	*/			/* supress error dialogs */
int      protectRoot = 0;				/* check if launcher was run as root, currently works only on Linux/UNIX platforms */

LPWSTR* szArglist = nullptr;
extern _TCHAR* jniLib;
extern _TCHAR* jarFile;

extern int initialArgc;
extern _TCHAR** initialArgv;
extern _TCHAR* eclipseLibrary;// = NULL; /* path to the eclipse shared library */
extern JNIEnv* env;

extern int GetLaunchMode();
extern _TCHAR* findStartupJar();

void setInitialArgsW(int argc, _TCHAR** argv, _TCHAR* lib);
int runW(int argc, _TCHAR* argv[], _TCHAR* vmArgs[]);
int readIniFile(_TCHAR* program, int* argc, _TCHAR*** argv);
int readConfigFile(_TCHAR* config_file, int* argc, _TCHAR*** argv);
_TCHAR* getIniFile(_TCHAR* program, int consoleLauncher);

typedef jint(JNICALL *JNI_GetCreatedJavaVMs_)(JavaVM **, jsize, jsize *);

// CTangram

CTangram::CTangram()
{
	m_pActiveBrowser = nullptr;
	m_pClrHost = nullptr;
	m_nJVMVersion = JNI_VERSION_10;
	g_pTangram = this;
	m_bCLRObjTemplateInit = false;
	m_bOfficeAddinUnLoad = true;
	m_bCreatingForm = false;
	m_bLoadEclipseDelay = false;
	m_bUsingDefaultAppDocTemplate = false;
	m_bWinFormActived = false;
	m_bAdmin = false;
	m_bCanClose = false;
	m_bFrameDefaultState = true;
	m_bDeleteCompositorManager = false;
	m_bFirstDocCreated = false;
	m_bEnableProcessFormTabKey = false;
	m_bChromeNeedClosed = false;
	m_pActiveHtmlWnd = nullptr;
	m_bCreatingDevTool = false;
	m_bOMNIBOXPOPUPVISIBLE = false;
	m_pHtmlWndCreated = nullptr;
	//m_pTangramMainDllLoader = nullptr;
	m_strDefaultXml = _T("<default><window><node name=\"tangram\" id=\"HostView\"/></window></default>");
	m_bNewFile = FALSE;
	m_nRef = 4;
	m_nAppID = -1;
	m_nAppType = 0;
	m_pMDIMainWnd = nullptr;
	m_pActiveMDIChildWnd = nullptr;
	m_hTangramWnd = NULL;
	m_hHostBrowserWnd = NULL;
	m_hHostWnd = NULL;
	m_hEclipseHideWnd = NULL;
	m_hActiveWnd = NULL;
	m_hTemplateWnd = NULL;
	m_hTemplateChildWnd = NULL;
	m_hChildHostWnd = NULL;
	m_hCBTHook = NULL;
	m_hVSToolBoxWnd = NULL;
	m_hForegroundIdleHook = NULL;
	m_pDocTemplateFrame = nullptr;
	m_lpszSplitterClass = nullptr;
	m_pCompositorManager = nullptr;
	m_pActiveTemplate = nullptr;
	m_pTangramDocTemplateInfo = nullptr;
	m_pActiveNode = nullptr;
	m_pCompositor = nullptr;
	m_pDesignWindowNode = nullptr;
	m_pDesigningFrame = nullptr;
	m_pHostDesignUINode = nullptr;
	m_pDesignRootNode = nullptr;
	m_pDesignerFrame = nullptr;
	m_pDesignerCompositorManager = nullptr;
	m_pRootNodes = nullptr;
	m_pDocDOMTree = nullptr;
	m_pTangramAppCtrl = nullptr;
	m_pTangramAppProxy = nullptr;
	m_pTangramCLRAppProxy = nullptr;
	m_pExtender = nullptr;
	m_pAppDisp = nullptr;
	m_pActiveDocWnd = nullptr;
	m_pHostViewDesignerNode = nullptr;
	m_pActiveAppProxy = nullptr;
	m_pCLRProxy = nullptr;
	m_pMainFormDisp = nullptr;
	m_pActiveEclipseWnd = nullptr;
	m_pTangramPackageProxy = nullptr;
	m_pTangramDelegate = nullptr;
	m_strStartupCLRObj = _T("");
	m_strWorkBenchStrs = _T("");
	m_strExeName = _T("");
	m_strAppName = _T("Tangram System");
	m_strAppKey = _T("");
	m_strCurrentKey = _T("");
	m_strCurrentAppID = _T("");
	m_strConfigFile = _T("");
	m_strConfigDataFile = _T("");
	m_strDefaultTemplateXml = _T("");
	m_strAppCommonDocPath = _T("");
	m_strNodeSelectedText = _T("");
	m_strTemplatePath = _T("");
	m_strDesignerTip1 = _T("");
	m_strDesignerTip2 = _T("");
	m_strDesignerXml = _T("");
	m_strNewDocXml = _T("");
	m_strDesignerInfo = _T("");
	m_strExcludeAppExtenderIDs = _T("");
	m_strCurrentDocTemplateXml = _T("");
	m_strCurrentFrameID = _T("");
	m_strDocFilters = _T("");
	m_strStartJarPath = _T("");
	m_strBridgeJavaClass = "";
	m_strDocTemplateStrs = _T("");
	m_strDefaultTemplate = _T("");
	m_strDefaultTemplate2 = _T("");
	m_strLibs = _T("");
	m_strCurrentEclipsePagePath = _T("");
	m_strTangramURLBase = _T("http://tangramdesigner.com/TangramDesigner/");
	m_strDesignerToolBarCaption = _T("Tangram Designer");
	m_strOfficeAppIDs = _T("word.application,excel.application,outlook.application,onenote.application,infopath.application,project.application,visio.application,access.application,powerpoint.application,lync.ucofficeintegration.1,");
	m_nTangramObj = 0;
	launchMode = -1;
#ifdef _DEBUG
	m_nTangram = 0;
	m_nJsObj = 0;
	m_nTangramCtrl = 0;
	m_nTangramFrame = 0;
	m_nOfficeDocs = 0;
	m_nOfficeDocsSheet = 0;
	m_nTangramNodeCommonData = 0;
#endif
	m_mapValInfo[_T("currenteclipeworkBenchid")] = CComVariant(_T(""));
	m_pObjectFactory = new Object::ObjectFactory();
	m_TabWndClassInfoDictionary[_T("hostview")] = RUNTIME_CLASS(CNodeWnd);
	m_TabWndClassInfoDictionary[_T("tangramlistview")] = RUNTIME_CLASS(CTangramListView);
	m_TabWndClassInfoDictionary[_T("wpfctrl")] = RUNTIME_CLASS(CWPFView);
	m_TabWndClassInfoDictionary[TGM_SPLITTER] = RUNTIME_CLASS(CSplitterNodeWnd);
	m_TabWndClassInfoDictionary[_T("tabctrl")] = RUNTIME_CLASS(CTangramTabCtrl);
}

BOOL CTangram::CopyFolder(CString strSrcPath, CString strDesPath)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	WCHAR _szTmp[1025] = { 0 };
	::memcpy(_szTmp, strSrcPath, 1024);

	CString _szSrcPath = strSrcPath;
	CString _szDesPath = strDesPath;

	WCHAR _szNewSrcPath[1025] = { 0 };
	WCHAR _szNewDesPath[1025] = { 0 };

	::wcscat(_szTmp, L"*");

	hFind = FindFirstFile(_szTmp, &FindFileData);
	if (hFind == NULL) return FALSE;

	do
	{
		if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if (wcscmp(FindFileData.cFileName, L"."))
			{
				if (wcscmp(FindFileData.cFileName, L".."))
				{
					swprintf(_szNewDesPath, L"%s%s\\", _szDesPath.GetBuffer(), FindFileData.cFileName);
					swprintf(_szNewSrcPath, L"%s%s\\", _szSrcPath.GetBuffer(), FindFileData.cFileName);
					_szDesPath.ReleaseBuffer();
					_szSrcPath.ReleaseBuffer();
					CreateDirectory(_szNewDesPath, NULL);
					CopyFolder(_szNewSrcPath, _szNewDesPath);
				}
			}
		}
		else
		{
			WCHAR _szSrcFile[1025] = { 0 };
			WCHAR _szDesFile[1025] = { 0 };
			swprintf(_szDesFile, L"%s%s", _szDesPath.GetBuffer(), FindFileData.cFileName);
			swprintf(_szSrcFile, L"%s%s", _szSrcPath.GetBuffer(), FindFileData.cFileName);
			_szDesPath.ReleaseBuffer();
			_szSrcPath.ReleaseBuffer();
			BOOL l_bRet = CopyFile(_szSrcFile, _szDesFile, TRUE);
		}
	} while (FindNextFile(hFind, &FindFileData));

	::FindClose(hFind);
	return TRUE;
}

typedef BOOL(WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);

LPFN_ISWOW64PROCESS fnIsWow64Process;

BOOL IsWow64()
{
	BOOL bIsWow64 = FALSE;

	//IsWow64Process is not available on all supported versions of Windows.
	//Use GetModuleHandle to get a handle to the DLL that contains the function
	//and GetProcAddress to get a pointer to the function if available.

	fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(
		GetModuleHandle(TEXT("kernel32")), "IsWow64Process");

	if (NULL != fnIsWow64Process)
	{
		if (!fnIsWow64Process(GetCurrentProcess(), &bIsWow64))
		{
			//handle error
		}
	}
	return bIsWow64;
}

void CTangram::Init()
{ 
	static bool bInit = false;
	if (bInit)
		return;
	bInit = true;
	SYSTEM_INFO si;
	GetNativeSystemInfo(&si);

	if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64 ||
		si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64||
		si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_ARM64)
		m_b64bitSystem = true;
	if (m_b64bitSystem)
	{
		m_bX86App = IsWow64();
	}
	else
		m_bX86App = true;


	if (m_bOfficeApp == false && m_nAppID != 9)
	{
		//m_strConfigDataFile = m_strAppDataPath;
		if (::PathIsDirectory(m_strAppDataPath) == false)
		{
			::SHCreateDirectory(nullptr, m_strAppDataPath);
		}
		m_strAppFormsPath = m_strAppPath + _T("CommonForms\\");
		if (::PathIsDirectory(m_strAppFormsPath) == false)
		{
			::SHCreateDirectory(nullptr, m_strAppFormsPath);
		}
		m_strAppFormsInfoPath = m_strAppDataPath + _T("TangramFormsInfo\\");
		if (::PathIsDirectory(m_strAppFormsInfoPath) == false)
		{
			::SHCreateDirectory(nullptr, m_strAppFormsInfoPath);
		}
		m_strAppWPFObjsInfoPath = m_strAppDataPath + _T("TangramWPFsInfo\\");
		if (::PathIsDirectory(m_strAppWPFObjsInfoPath) == false)
		{
			::SHCreateDirectory(nullptr, m_strAppWPFObjsInfoPath);
		}
		
		m_strAppControlsInfoPath = m_strAppDataPath + _T("TangramControlsInfo\\");
		if (::PathIsDirectory(m_strAppControlsInfoPath) == false)
		{
			::SHCreateDirectory(nullptr, m_strAppControlsInfoPath);
		}
		m_strAppFormsTemplatePath = m_strAppDataPath + _T("TangramFormsTemplate\\");
		if (::PathIsDirectory(m_strAppFormsTemplatePath) == false)
		{
			::SHCreateDirectory(nullptr, m_strAppFormsTemplatePath);
		}
	}

	SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, 0, m_szBuffer);
	m_strProgramFilePath = CString(m_szBuffer);

	::GetModuleFileName(NULL, m_szBuffer, MAX_PATH);
	m_strWinAppConfigFile = CString(m_szBuffer);
	m_strWinAppConfigFile += _T(".config");
	if (::PathFileExists(m_strWinAppConfigFile) == FALSE)
	{
		// Create App.exe.config
		CString strDefaultAppConfigFile = m_strProgramFilePath + _T("\\Tangram\\App.exe.config");
		if (::PathFileExists(strDefaultAppConfigFile))
			::CopyFile(strDefaultAppConfigFile, m_strWinAppConfigFile, true);
	}

	m_strAppCommonDocPath2 = m_strProgramFilePath + _T("\\Tangram\\CommonDocComponent\\");
	m_strAppCommonFormsPath = m_strProgramFilePath + _T("\\Tangram\\CommonForms\\");
	if (::PathIsDirectory(m_strAppCommonFormsPath) == false)
	{
		::SHCreateDirectory(nullptr, m_strAppCommonFormsPath);
	}
	m_mapValInfo[_T("apppath")] = CComVariant(m_strAppPath);
	m_mapValInfo[_T("appdatapath")] = CComVariant(m_strAppDataPath);
	m_mapValInfo[_T("appdatafile")] = CComVariant(m_strConfigDataFile);
	m_mapValInfo[_T("appname")] = CComVariant(m_strExeName);
	m_mapValInfo[_T("appkey")] = CComVariant(m_strAppKey);

	if (m_nAppID != 9)
	{
		g_pTangram->TangramInit();
		HWND hWnd = ::CreateWindowEx(WS_EX_NOACTIVATE, _T("Tangram Message Window Class"), _T(""), WS_VISIBLE | WS_POPUP, 0, 0, 0, 0, nullptr, nullptr, theApp.m_hInstance, nullptr);
	}


	CString _strPath = _T("");
		_strPath = m_strAppPath + m_strExeName + _T("InitData\\");
	if (::PathIsDirectory(_strPath))
	{
		//auto task = create_task([this, _strPath]()
		//{
			CTangramXmlParse m_Parse;
			CTangramXmlParse* pZipNode = nullptr;
			BOOL b = m_Parse.LoadFile(m_strConfigDataFile);
			if (b)
			{
				pZipNode = m_Parse.GetChild(_T("tangramappdata"));
				if (pZipNode == nullptr)
				{
					CopyFolder(_strPath, m_strAppDataPath);
					pZipNode = m_Parse.AddNode(_T("tangramappdata"));
					m_Parse.SaveFile(m_strConfigDataFile);
				}
			}
		//});
	}

	if (m_nAppID != 9 && ::PathFileExists(m_strConfigFile) && m_bOfficeApp == false)
	{
		CTangramXmlParse m_Parse;
		if (m_Parse.LoadFile(m_strConfigFile))
		{
			CTangramXmlParse* _pXmlParse = m_Parse.GetChild(_T("designerscript"));
			if (_pXmlParse)
			{
				CTangramXmlParse* pXmlParse = _pXmlParse->GetChild(_T("selected"));
				if (pXmlParse)
					m_strNodeSelectedText = pXmlParse->text();
				pXmlParse = _pXmlParse->GetChild(_T("infotip1"));
				if (pXmlParse)
					m_strDesignerTip1 = pXmlParse->text();
				pXmlParse = _pXmlParse->GetChild(_T("infotip2"));
				if (pXmlParse)
					m_strDesignerTip2 = pXmlParse->text();
				pXmlParse = _pXmlParse->GetChild(_T("designertoolcaption"));
				if (pXmlParse)
				{
					m_strDesignerToolBarCaption = pXmlParse->text();
				}
				pXmlParse = _pXmlParse->GetChild(_T("designertoolxml"));
				if (pXmlParse&&pXmlParse->GetChild(_T("window")))
				{
					CString strCaption = m_strDesignerToolBarCaption = pXmlParse->attr(_T("caption"), _T("Tangram Designer"));
					strCaption.Trim();
					if (strCaption != _T(""))
						m_strDesignerToolBarCaption = strCaption;
					m_strDesignerXml = pXmlParse->xml();
				}
			}

			if (::PathFileExists(m_strConfigDataFile) == FALSE)
			{
				_pXmlParse = m_Parse.GetChild(_T("tangrampage"));
				CString strXml = _T("");
				if (_pXmlParse)
				{
					strXml.Format(_T("<%s>%s</%s>"), m_strExeName, _pXmlParse->xml(), m_strExeName);
					CTangramXmlParse xmlParse;
					if (xmlParse.LoadXml(strXml))
					{
						xmlParse.SaveFile(m_strConfigDataFile);
					}
				}
				else
				{
					if (m_bEclipse)
					{
						strXml.Format(_T("<%s><openedworkbench></openedworkbench></%s>"), m_strExeName, m_strExeName);
						CTangramXmlParse xmlParse;
						if (xmlParse.LoadXml(strXml))
						{
							xmlParse.SaveFile(m_strConfigDataFile);
						}
					}
				}
			}
			else
			{
				if (m_bEclipse)
				{
					CTangramXmlParse xmlParse;
					if (xmlParse.LoadFile(m_strConfigDataFile))
					{
						CTangramXmlParse* pParse = xmlParse.GetChild(_T("openedworkbench"));
						if (pParse)
						{
							m_strWorkBenchStrs = pParse->text();
							pParse->put_text(_T(""));
							xmlParse.SaveFile(m_strConfigDataFile);
						}
					}
				}
			}
		}
	}
	if (m_strNodeSelectedText == _T(""))
	{
		m_strNodeSelectedText = m_strNodeSelectedText + _T("  ----Please Select an Object Type From Designer ToolBox for this Tangram View----") +
			_T("\n  you can use Tangram XML to various applications such as ") +
			_T("\n  .net framework application, MFC Application, Eclipcse RCP, ") +
			_T("\n  Office Application etc.") +
			_T("\n  ") +
			_T("\n  ") +
			_T("\n  Creating a \"hostview\" in this place,if you want to show application") +
			_T("\n  Component come from original application, ") +
			_T("\n  Creating an Object Type other than \"hostview\" in this place, if you want to show dynamic") +
			_T("\n  Component come from some Components... ");
	}
	if (m_strDesignerTip1 == _T(""))
		m_strDesignerTip1 = _T("  ----Click me to Design This Tangram Object----\n  ");
	if (m_strDesignerTip2 == _T(""))
	{
		m_strDesignerTip2 = m_strDesignerTip2 +
			_T("  ----Tangram Object Information----") +
			_T("\n  ") +
			_T("\n   Object Name:   %s") +
			_T("\n   Object Caption:%s\n\n");
	}

	if (m_nAppID != 9 && m_bOfficeApp == false && ::IsWindow(m_hHostWnd) == false)
	{
		auto it = m_mapValInfo.find(_T("designertoolcaption"));
		if (it != m_mapValInfo.end())
			m_strDesignerToolBarCaption = OLE2T(it->second.bstrVal);
		CString strExeName = m_strExeName;
		strExeName.MakeLower();
		m_strDesignerToolBarCaption = strExeName + _T(" - ") + m_strDesignerToolBarCaption;
		m_hHostWnd = ::CreateWindowEx(WS_EX_PALETTEWINDOW, _T("Tangram Window Class"), m_strDesignerToolBarCaption, WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, 0, 0, 400, 400, NULL, 0, theApp.m_hInstance, NULL);
		m_hChildHostWnd = ::CreateWindowEx(NULL, _T("Tangram Window Class"), _T(""), WS_VISIBLE | WS_CHILD, 0, 0, 0, 0, m_hHostWnd, 0, theApp.m_hInstance, NULL);
	}
}

CTangram::~CTangram()
{
	OutputDebugString(_T("------------------Begin Release CTangram------------------------\n"));
	
	delete m_pObjectFactory;

	for (auto it : m_mapTangramDocTemplateInfo)
	{
		delete it.second;
	}
	m_mapTangramDocTemplateInfo.clear();
	for (auto it : m_mapTangramFormsTemplateInfo)
	{
		delete it.second;
	}
	m_mapTangramFormsTemplateInfo.clear();

	if (m_mapWindowPage.size())
	{
		auto it = m_mapWindowPage.begin();
		while (it != m_mapWindowPage.end())
		{
			CCompositorManager* pCompositorManager = (CCompositorManager*)it->second;
			delete pCompositorManager;
			m_mapWindowPage.erase(it);
			if (m_mapWindowPage.size())
				it = m_mapWindowPage.begin();
			else
				it = m_mapWindowPage.end();
		}
	}
	
	//for (auto it : m_mapIPCCollection)
	//{
	//	delete it.second;
	//}
	//m_mapIPCCollection.clear();

	while (m_mapWndNodeCollection.size())
	{
		auto it = m_mapWndNodeCollection.begin();
		delete it->second;
	}

	while (m_mapTangramWindowProvider.size())
		m_mapTangramWindowProvider.erase(m_mapTangramWindowProvider.begin());

	if (m_nTangramObj)
		TRACE(_T("TangramObj Count: %d\n"), m_nTangramObj);
#ifdef _DEBUG
	if (m_nTangram)
		TRACE(_T("Tangram Count: %d\n"), m_nTangram);
	if (m_nJsObj)
		TRACE(_T("JSObj Count: %d\n"), m_nJsObj);
	if (m_nTangramCtrl)
		TRACE(_T("TangramCtrl Count: %d\n"), m_nTangramCtrl);
	if (m_nTangramFrame)
		TRACE(_T("TangramFrame Count: %d\n"), m_nTangramFrame);
	if (m_nOfficeDocs)
		TRACE(_T("TangramOfficeDoc Count: %d\n"), m_nOfficeDocs);
	if (m_nOfficeDocsSheet)
		TRACE(_T("TangramExcelWorkBookSheet Count: %d\n"), m_nOfficeDocsSheet);
	if (m_nTangramNodeCommonData)
		TRACE(_T("m_nTangramNodeCommonData Count: %d\n"), m_nTangramNodeCommonData);
#endif

	if (m_pExtender)
		m_pExtender->Close();

	if (m_pRootNodes)
		CCommonFunction::ClearObject<CWndNodeCollection>(m_pRootNodes);

	if (m_nAppID == 3)
	{
		for (auto it : m_mapThreadInfo)
		{
			if (it.second->m_hGetMessageHook)
			{
				UnhookWindowsHookEx(it.second->m_hGetMessageHook);
				it.second->m_hGetMessageHook = NULL;
			}
			delete it.second;
		}
		m_mapThreadInfo.erase(m_mapThreadInfo.begin(), m_mapThreadInfo.end());

		_clearObjects();

		auto itDTE = m_mapObjDic.find(_T("dte"));
		if (itDTE != m_mapObjDic.end())
			m_mapObjDic.erase(itDTE);
		for (auto it : m_mapObjDic)
		{
			it.second->Release();
		}
		for (auto it : m_mapValInfo)
		{
			::VariantClear(&it.second);
		}
		m_mapValInfo.clear();

		m_TabWndClassInfoDictionary.clear();
	}

	if (m_pClrHost&&m_nAppID == -1 && theApp.m_bHostCLR == false)
	{
		OutputDebugString(_T("------------------Begin Stop CLR------------------------\n"));
		HRESULT hr = m_pClrHost->Stop();
		ASSERT(hr == S_OK);
		if (hr == S_OK)
		{
			OutputDebugString(_T("------------------Stop CLR Successed!------------------------\n"));
		}
		DWORD dw = m_pClrHost->Release();
		ASSERT(dw == 0);
		if (dw == 0)
		{
			m_pClrHost = nullptr;
			OutputDebugString(_T("------------------ClrHost Release Successed!------------------------\n"));
		}
		OutputDebugString(_T("------------------End Stop CLR------------------------\n"));
	}
	g_pTangram = nullptr;
	OutputDebugString(_T("------------------End Release CTangram------------------------\n"));
}

void CTangram::ExportComponentInfo()
{
	if (m_bExportComponent == false)
		return;
	//ReadTextFromWeb(CComBSTR("https://tangramdesigner.com/TangramDesigner/"), CComBSTR(m_strExeName), CComBSTR(""), CComBSTR(""), CComBSTR("tangraminit.xml"), CComBSTR("tangraminit.xml"), 0);
	CString strPath = m_strProgramFilePath + _T("\\tangram\\") + m_strExeName + _T("\\tangraminit.xml");
	if (::PathFileExists(strPath))
	{
		CTangramXmlParse m_Parse;
		if (m_Parse.LoadFile(strPath))
		{
			int nCount = m_Parse.GetCount();
			for (int i = 0; i < nCount; i++)
			{
				CTangramXmlParse* pParse = m_Parse.GetChild(i);
				CString strID = pParse->attr(_T("id"), _T(""));
				CString strXml = pParse->GetChild(0)->xml();
				if (strID == _T("xmlRibbon"))
				{
					CString strPath = m_strAppCommonDocPath + _T("OfficeRibbon\\") + m_strExeName + _T("\\ribbon.xml");
					CTangramXmlParse m_Parse2;
					if (m_Parse2.LoadXml(strXml))
						m_Parse2.SaveFile(strPath);
				}
				if (strID == _T("tangramdesigner"))
					m_strDesignerXml = strXml;
				else
				{
					strID.MakeLower();
					if (strID == _T("newtangramdocument"))
					{
						m_strNewDocXml = strXml;
					}
					else
					{
						m_mapValInfo[strID] = CComVariant(strXml);
					}
				}
			}
		}
	}
	CString _strPath = m_strAppCommonDocPath + _T("Tangramdoctemplate.xml");
	CString _strPathReg = m_strAppCommonDocPath + _T("TangramReg.xml");
	BOOL bModifyed = false;
	CTangramXmlParse m_Parse;
	CTangramXmlParse m_ParseReg;
	if (m_Parse.LoadFile(_strPath) == FALSE)
	{
		m_Parse.LoadXml(_T("<TangramDocTemplate />"));
	}
	if (m_ParseReg.LoadFile(_strPathReg) == FALSE)
	{
		m_ParseReg.LoadXml(_T("<TangramDocReg />"));
		m_ParseReg.SaveFile(_strPathReg);
	}

	strPath = m_strProgramFilePath + _T("\\tangram\\CommonDocComponent\\*.*");

	_wfinddata_t fd;
	fd.attrib = FILE_ATTRIBUTE_DIRECTORY;
	intptr_t pf = _wfindfirst(strPath, &fd);
	if (pf != -1)
	{
		while (!_wfindnext(pf, &fd))
		{
			if (fd.attrib&FILE_ATTRIBUTE_DIRECTORY)
			{
				CString str = fd.name;
				str.MakeLower();
				if (str != _T(".."))
				{
					CString strXml = m_strProgramFilePath + _T("\\tangram\\CommonDocComponent\\") + str + _T("\\tangram.xml");
					if (m_ParseReg.GetChild(str) == nullptr)
					{
						int nPos = str.Find(_T("."));
						CString strLib = _T("");
						if (nPos != -1)
						{
							strLib = str.Left(nPos);
							strLib = m_strProgramFilePath + _T("\\tangram\\CommonDocComponent\\") + str + _T("\\") + strLib + _T(".dll");
							if (::PathFileExists(strLib))
							{
								m_strLibs += strLib;
								m_strLibs += _T("|");
							}
							else
							{
								CTangramXmlParse m_Parse2;
								if (m_Parse2.LoadFile(strXml))
								{
									strLib = m_Parse2.attr(_T("lib"), _T(""));
									if (strLib != _T(""))
									{
										strLib = m_strProgramFilePath + _T("\\tangram\\CommonDocComponent\\") + str + _T("\\") + strLib + _T(".dll");
										if (::PathFileExists(strLib))
										{
											m_strLibs += strLib;
											m_strLibs += _T("|");
										}
									}
								}
							}
						}
					}
					if (::PathFileExists(strXml))
					{
						CTangramXmlParse m_Parse2;
						if (m_Parse2.LoadFile(strXml))
						{
							int nCount = m_Parse2.GetCount();
							for (int i = 0; i < nCount; i++)
							{
								CTangramXmlParse* pParse = m_Parse2.GetChild(i);
								str = pParse->name().MakeLower();
								if (m_Parse.GetChild(str) == nullptr)
								{
									bModifyed = true;
									m_Parse.AddNode(pParse, str);
								}
							}
						}
					}
				}
			}
		}
		_findclose(pf);
	}
	if (bModifyed)
		m_Parse.SaveFile(_strPath);

	if (m_strLibs != _T(""))
	{
		int nPos = m_strLibs.Find(_T("|"));
		while (nPos != -1)
		{
			CString strLib = g_pTangram->m_strLibs.Left(nPos);
			g_pTangram->m_strLibs = g_pTangram->m_strLibs.Mid(nPos + 1);
			nPos = g_pTangram->m_strLibs.Find(_T("|"));
			::LoadLibrary(strLib);
		}
	}
	m_bExportComponent = false;
};

CString CTangram::GetOfficePath()
{
	CString strOfficePath = _T("");
	CString strPath = m_strAppCommonDocPath + _T("officeappinfo.xml");
	if (::PathFileExists(strPath))
	{
		CTangramXmlParse m_Parse;
		if (m_Parse.LoadFile(strPath))
		{
			strOfficePath = m_Parse.attr(_T("path"), _T(""));
			if (strOfficePath != _T("")&&::PathIsDirectory(strOfficePath))
				return strOfficePath;
		}
	}
	//Install Office Component:
	BOOL m_b32bitOffice = false;
	BOOL m_b64bitSystem = false;

	SYSTEM_INFO si;
	GetNativeSystemInfo(&si);

	if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64 ||
		si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64)
		m_b64bitSystem = true;

	wchar_t buf[_MAX_PATH];
	strPath = _T("SOFTWARE\\Microsoft\\Office\\ClickToRun\\Configuration\\");
	swprintf_s(buf, strPath);
	DWORD size = _MAX_PATH;
	HKEY hKey = NULL;
	REGSAM hREGSAM = KEY_READ | KEY_QUERY_VALUE;
	if (m_b64bitSystem)
		hREGSAM |= KEY_WOW64_64KEY;
	if (RegCreateKeyEx(HKEY_LOCAL_MACHINE, buf, 0, NULL, REG_OPTION_NON_VOLATILE, hREGSAM, NULL, &hKey, NULL) == ERROR_SUCCESS)
	{
		wchar_t szPlatForm[_MAX_PATH];
		if (RegQueryValueEx(hKey, L"Platform", 0, NULL, (BYTE*)&szPlatForm, &size) == ERROR_SUCCESS)
		{
			CString strVal = szPlatForm;
			if (strVal.CompareNoCase(_T("x86")) == 0)
				m_b32bitOffice = true;
		}
		RegCloseKey(hKey);
	}
	else
		return _T("");
	strPath = _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\");
	strPath += _T("winword.exe");
	swprintf_s(buf, strPath);
	hKey = NULL;
	if (RegCreateKeyEx(HKEY_LOCAL_MACHINE, buf, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_READ | KEY_QUERY_VALUE | KEY_WOW64_32KEY, NULL, &hKey, NULL) == ERROR_SUCCESS)
	{
		wchar_t path[_MAX_PATH];
		if (RegQueryValueEx(hKey, L"Path", 0, NULL, (BYTE*)&path, &size) == ERROR_SUCCESS)
		{
			strOfficePath = path;
		}
		RegCloseKey(hKey);
	}
	if (strOfficePath==_T("")&&RegCreateKeyEx(HKEY_LOCAL_MACHINE, buf, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_READ | KEY_QUERY_VALUE | KEY_WOW64_64KEY, NULL, &hKey, NULL) == ERROR_SUCCESS)
	{
		wchar_t path[_MAX_PATH];
		if (RegQueryValueEx(hKey, L"Path", 0, NULL, (BYTE*)&path, &size) == ERROR_SUCCESS)
		{
			strOfficePath = path;
		}
		RegCloseKey(hKey);
	}
	if (strOfficePath != _T(""))
	{
		CTangramXmlParse m_Parse;
		if (m_Parse.LoadXml(_T("<officeappinfo />")))
		{
			m_Parse.put_attr(_T("path"), strOfficePath);
			m_Parse.put_attr(_T("officeapp"), _T("excel;winword;powerpnt;outlook"));
			CString strPath = m_strAppCommonDocPath + _T("officeappinfo.xml");
			m_Parse.SaveFile(strPath);
		}
		return strOfficePath;
	}
	return _T("");
}

LRESULT CTangram::Close(void)
{
	if (m_mapTangramEvent.size())
	{
		for (auto it = m_mapTangramEvent.begin(); it != m_mapTangramEvent.end(); it++)
		{
			CTangramEventObj* pObj = it->second;
			delete pObj;
		}
		m_mapTangramEvent.clear();
	}

	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		DISPPARAMS params = { NULL, NULL, 0, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			Unlock();
			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);
			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(2, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	return S_OK;
}

void CTangram::FireNodeEvent(int nIndex, CWndNode* pNode, CTangramEventObj* pObj)
{
	switch (nIndex)
	{
	case 0:
	{
		TangramViewType type = pNode->m_nViewType;
		if (type == Splitter || type == TabbedWnd)
		{
			for (auto it : pNode->m_vChildNodes)
			{
				FireNodeEvent(nIndex, it, pObj);
			}
		}
		else
		{
			for (auto it : pNode->m_mapWndNodeProxy)
			{
				it.second->OnTangramDocEvent(pObj);
			}
		}
	}
	break;
	case 1:
	{
		for (auto it : pNode->m_mapWndNodeProxy)
		{
			it.second->OnTangramDocEvent(pObj);
		}
	}
	break;
	case 2:
	{
		for (auto it : pNode->m_mapWndNodeProxy)
		{
			it.second->OnTangramDocEvent(pObj);
		}
	}
	break;
	}
}

void CTangram::FireTangramAppEvent(CTangramEventObj* pObj)
{
	if (pObj)
	{
		if (m_pTangramAppProxy)
			m_pTangramAppProxy->OnTangramEvent(pObj);
		for (auto it : m_mapTangramAppProxy)
		{
			if (it.second != m_pTangramAppProxy)
				it.second->OnTangramEvent(pObj);
		}
		if (m_pTangramCLRAppProxy)
			m_pTangramCLRAppProxy->OnTangramEvent(pObj);
		CString strEventName = pObj->m_strEventName;
		strEventName.MakeLower();
		if (strEventName.Find(_T("tangramdoc")) == 0 && pObj->m_mapDisp.size())
		{
			ITangramDoc* pDoc = nullptr;
			CComQIPtr<ITangramDoc> _pDoc(pObj->m_mapDisp[0]);
			if (_pDoc)
			{
				CTangramDoc* pDoc = (CTangramDoc*)_pDoc.p;
				if (pDoc->m_mapCompositor.size() && pObj->m_mapVar.size() && pObj->m_mapVar[0].vt == VT_I4)
				{
					ObjEventType nIndex = (ObjEventType)pObj->m_mapVar[0].intVal;
					switch (nIndex)
					{
					case TangramDocAllFrameAllChildNode://fire event a Tangram Doc, to every Frame topnode and all its child nodes 
					{
						for (auto it : pDoc->m_mapCompositor)
						{
							CCompositor* pCompositor = it.second->m_pHostCompositor;
							if (pCompositor)
							{
								CWndNode* pNode = pCompositor->m_pWorkNode;
								FireNodeEvent(0, pNode, pObj);
							}
						}
					}
					break;
					case TangramDocAllFrameAllTopNode://fire event a Tangram Doc, to every Frame topnode 
					{
						for (auto it : pDoc->m_mapCompositor)
						{
							CCompositor* pCompositor = it.second->m_pHostCompositor;
							if (pCompositor)
							{
								CWndNode* pNode = pCompositor->m_pWorkNode;
								FireNodeEvent(1, pNode, pObj);
							}
						}
					}
					break;
					case TangramDocAllCtrlBarFrameAllChildNode://fire event a Tangram Doc  ControlBar Frame, to every Frame topnode and all its child nodes 
					{
						for (auto it : pDoc->m_mapCompositor)
						{
							CTangramDocWnd* pWnd = it.second->m_pCurrentWnd;
							if (pWnd)
							{
								for (auto it : pWnd->m_mapCtrlBar)
								{
									HWND hwnd = it.second;
									CCompositorManager* pCompositorManager = pWnd->m_pDocFrame->m_pHostCompositor->m_pCompositorManager;
									for (auto it2 : pCompositorManager->m_mapCompositor)
									{
										auto it3 = pCompositorManager->m_mapCompositor.find(hwnd);
										if (it3 != pCompositorManager->m_mapCompositor.end())
											FireNodeEvent(0, it3->second->m_pWorkNode, pObj);
									}
								}
							}
						}
					}
					break;
					case TangramDocAllCtrlBarFrame://fire event a Tangram Doc ControlBar Frame, to every Frame topnode 
					{
						for (auto it : pDoc->m_mapCompositor)
						{
							CTangramDocWnd* pWnd = it.second->m_pCurrentWnd;
							if (pWnd)
							{
								for (auto it : pWnd->m_mapCtrlBar)
								{
									HWND hwnd = it.second;
									CCompositorManager* pCompositorManager = pWnd->m_pDocFrame->m_pHostCompositor->m_pCompositorManager;
									for (auto it2 : pCompositorManager->m_mapCompositor)
									{
										auto it3 = pCompositorManager->m_mapCompositor.find(hwnd);
										if (it3 != pCompositorManager->m_mapCompositor.end())
											FireNodeEvent(1, it3->second->m_pWorkNode, pObj);
									}
								}
							}
						}
					}
					break;
					case TangramNodeAllChildNode://fire event a Wnd Node, and all its child nodes 
					{
						auto it = pObj->m_mapDisp.find(1);
						if (it != pObj->m_mapDisp.end())
						{
							CComQIPtr<IWndNode> pNode(it->second);
							if (pNode)
							{
								CWndNode* _pNode = (CWndNode*)pNode.p;
								FireNodeEvent(0, _pNode, pObj);
							}
						}
					}
					break;
					case TangramNode://fire event a Wnd Node TangramNode
					{
						auto it = pObj->m_mapDisp.find(1);
						if (it != pObj->m_mapDisp.end())
						{
							CComQIPtr<IWndNode> pNode(it->second);
							if (pNode)
							{
								CWndNode* _pNode = (CWndNode*)pNode.p;
								FireNodeEvent(1, _pNode, pObj);
							}
						}
					}
					break;
					case TangramFrameAllTopNodeAllChildNode://fire event a Wnd Frame, to every Frame topnode and all its child nodes 
					{
						auto it = pObj->m_mapDisp.find(1);
						if (it != pObj->m_mapDisp.end())
						{
							CComQIPtr<ICompositor> pCompositor(it->second);
							if (pCompositor)
							{
								CCompositor* _pCompositor = (CCompositor*)pCompositor.p;
								for (auto it : _pCompositor->m_mapNode)
								{
									FireNodeEvent(0, it.second, pObj);
								}
							}
						}
					}
					break;
					case TangramFrameAllTopNode://fire event a Wnd Frame, to every Frame topnode only 
					{
						auto it = pObj->m_mapDisp.find(1);
						if (it != pObj->m_mapDisp.end())
						{
							CComQIPtr<ICompositor> pCompositor(it->second);
							if (pCompositor)
							{
								CCompositor* _pCompositor = (CCompositor*)pCompositor.p;
								for (auto it : _pCompositor->m_mapNode)
								{
									FireNodeEvent(1, it.second, pObj);
								}
							}
						}
					}
					break;
					case CompositorManagerAllFrameAllTopNodeAllChildNode://fire event to Wnd Page All Frames, to every Frame topnode and all its child nodes 
					{
						auto it = pObj->m_mapDisp.find(1);
						if (it != pObj->m_mapDisp.end())
						{
							CComQIPtr<ICompositorManager> pCompositorManager(it->second);
							if (pCompositorManager)
							{
								CCompositorManager* _pCompositorManager = (CCompositorManager*)pCompositorManager.p;
								for (auto it : _pCompositorManager->m_mapCompositor)
								{
									CCompositor* pCompositor = it.second;
									for (auto it : pCompositor->m_mapNode)
										FireNodeEvent(0, it.second, pObj);
								}
							}
						}
					}
					break;
					case CompositorManagerAllFrameAllTopNode://fire event to Wnd Page All Frames, to every Frame topnode   
					{
						auto it = pObj->m_mapDisp.find(1);
						if (it != pObj->m_mapDisp.end())
						{
							CComQIPtr<ICompositorManager> pCompositorManager(it->second);
							if (pCompositorManager)
							{
								CCompositorManager* _pCompositorManager = (CCompositorManager*)pCompositorManager.p;
								for (auto it : _pCompositorManager->m_mapCompositor)
								{
									CCompositor* pCompositor = it.second;
									for (auto it : pCompositor->m_mapNode)
										FireNodeEvent(1, it.second, pObj);
								}
							}
						}
					}
					break;
					case CompositorManagerCtrlBarFrameAllTopNodeAllChildNode://fire event to CompositorManager, fire Frame in Controlbars,not in Document Frame, to Frame topnode and all its child nodes 
					{
						auto it = pObj->m_mapDisp.find(1);
						if (it != pObj->m_mapDisp.end())
						{
							CComQIPtr<ICompositorManager> pCompositorManager(it->second);
							if (pCompositorManager)
							{
								CCompositorManager* _pCompositorManager = (CCompositorManager*)pCompositorManager.p;
								if (_pCompositorManager->m_mapCtrlBarCompositor.size())
								{
									for (auto it : _pCompositorManager->m_mapCtrlBarCompositor)
									{
										CCompositor* pCompositor = it.second;
										for (auto it : pCompositor->m_mapNode)
											FireNodeEvent(0, it.second, pObj);
									}
								}
							}
						}
					}
					break;
					case CompositorManagerCtrlBarFrameAllTopNode://fire event CompositorManager, fire Frame in Controlbars,not in Document Frame, to Frame topnode only 
					{
						auto it = pObj->m_mapDisp.find(1);
						if (it != pObj->m_mapDisp.end())
						{
							CComQIPtr<ICompositorManager> pCompositorManager(it->second);
							if (pCompositorManager)
							{
								CCompositorManager* _pCompositorManager = (CCompositorManager*)pCompositorManager.p;
								if (_pCompositorManager->m_mapCtrlBarCompositor.size())
								{
									for (auto it : _pCompositorManager->m_mapCtrlBarCompositor)
									{
										CCompositor* pCompositor = it.second;
										for (auto it : pCompositor->m_mapNode)
											FireNodeEvent(1, it.second, pObj);
									}
								}
							}
						}
					}
					break;
					case CompositorManagerNotCtrlBarFrameAllTopNodeAllChildNode://fire event CompositorManager, not fire Frame in Controlbars, to Frame topnode and all its child nodes 
					{
						auto it = pObj->m_mapDisp.find(1);
						if (it != pObj->m_mapDisp.end())
						{
							CComQIPtr<ICompositorManager> pCompositorManager(it->second);
							if (pCompositorManager)
							{
								CCompositorManager* _pCompositorManager = (CCompositorManager*)pCompositorManager.p;
								if (_pCompositorManager->m_mapCtrlBarCompositor.size())
								{
									for (auto it : _pCompositorManager->m_mapCompositor)
									{
										HWND hwnd = it.first;
										auto it2 = _pCompositorManager->m_mapCtrlBarCompositor.find(hwnd);
										if (it2 == _pCompositorManager->m_mapCtrlBarCompositor.end())
										{
											CCompositor* pCompositor = it.second;
											for (auto it : pCompositor->m_mapNode)
												FireNodeEvent(0, it.second, pObj);
										}
									}
								}
							}
						}
					}
					break;
					case CompositorManagerNotCtrlBarFrameAllTopNode://fire event CompositorManager, not fire Frame in Controlbars, to Frame topnode 
					{
						auto it = pObj->m_mapDisp.find(1);
						if (it != pObj->m_mapDisp.end())
						{
							CComQIPtr<ICompositorManager> pCompositorManager(it->second);
							if (pCompositorManager)
							{
								CCompositorManager* _pCompositorManager = (CCompositorManager*)pCompositorManager.p;
								if (_pCompositorManager->m_mapCtrlBarCompositor.size())
								{
									for (auto it : _pCompositorManager->m_mapCompositor)
									{
										HWND hwnd = it.first;
										auto it2 = _pCompositorManager->m_mapCtrlBarCompositor.find(hwnd);
										if (it2 == _pCompositorManager->m_mapCtrlBarCompositor.end())
										{
											CCompositor* pCompositor = it.second;
											for (auto it : pCompositor->m_mapNode)
												FireNodeEvent(1, it.second, pObj);
										}
									}
								}
							}
						}
					}
					break;
					default:
					{
						pDoc->m_pDocProxy->TangramDocEvent(pObj);
					}
					break;
					}
				}
			}
			delete pObj;
			return;
		}
		HRESULT hr = S_OK;
		int cConnections = m_vec.GetSize();
		int cConnections2 = 0;
		if (m_pTangramAppCtrl)
			cConnections2 = m_pTangramAppCtrl->m_vec.GetSize();

		if (cConnections + cConnections2)
		{
			CComVariant avarParams[1];
			avarParams[0] = (ITangramEventObj*)pObj;
			avarParams[0].vt = VT_DISPATCH;
			DISPPARAMS params = { avarParams, NULL, 1, 0 };
			IDispatch * pConnection = nullptr;
			if (cConnections)
			{
				for (int iConnection = 0; iConnection < cConnections; iConnection++)
				{
					Lock();
					CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
					Unlock();
					pConnection = static_cast<IDispatch *>(punkConnection.p);
					if (pConnection)
					{
						CComVariant varResult;
						hr = pConnection->Invoke(3, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
					}
				}
			}
			if (cConnections2)
			{
				for (int iConnection = 0; iConnection < cConnections2; iConnection++)
				{
					Lock();
					CComPtr<IUnknown> punkConnection = m_pTangramAppCtrl->m_vec.GetAt(iConnection);
					Unlock();
					pConnection = static_cast<IDispatch *>(punkConnection.p);
					if (pConnection)
					{
						CComVariant varResult;
						hr = pConnection->Invoke(1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
					}
				}
			}
		}

		delete pObj;
	}
}

CString CTangram::GetXmlData(CString strName, CString strXml)
{
	if (strName == _T("") || strXml == _T(""))
		return _T("");
	int nLength = strName.GetLength();
	CString strKey = _T("<") + strName + _T(">");
	int nPos = strXml.Find(strKey);
	if (nPos != -1)
	{
		CString strData1 = strXml.Mid(nPos);
		strKey = _T("</") + strName + _T(">");
		nPos = strData1.Find(strKey);
		if (nPos != -1)
			return strData1.Left(nPos + nLength + 3);
	}
	return _T("");
}

BOOL CTangram::LoadImageFromResource(ATL::CImage *pImage, HMODULE hMod, CString strResID, LPCTSTR lpTyp)
{
	if (pImage == nullptr)
		return false;

	pImage->Destroy();

	// 查找资源
	//HRSRC hRsrc = ::FindResource(hMod, nResID, lpTyp);
	HRSRC hRsrc = ::FindResource(hMod, strResID, lpTyp);
	if (hRsrc == NULL)
		return false;
	HGLOBAL hImgData = ::LoadResource(hMod, hRsrc);
	if (hImgData == NULL)
	{
		::FreeResource(hImgData);
		return false;
	}

	// 锁定内存中的指定资源
	LPVOID lpVoid = ::LockResource(hImgData);

	LPSTREAM pStream = nullptr;
	DWORD dwSize = ::SizeofResource(hMod, hRsrc);
	HGLOBAL hNew = ::GlobalAlloc(GHND, dwSize);
	LPBYTE lpByte = (LPBYTE)::GlobalLock(hNew);
	::memcpy(lpByte, lpVoid, dwSize);

	// 解除内存中的指定资源
	::GlobalUnlock(hNew);
	// 从指定内存创建流对象
	HRESULT ht = ::CreateStreamOnHGlobal(hNew, true, &pStream);
	if (ht == S_OK)
	{
		// 加载图片
		pImage->Load(pStream);

	}
	GlobalFree(hNew);
	// 释放资源
	::FreeResource(hImgData);
	return true;
}

BOOL CTangram::LoadImageFromResource(ATL::CImage *pImage, HMODULE hMod, UINT nResID, LPCTSTR lpTyp)
{
	if (pImage == nullptr)
		return false;

	pImage->Destroy();

	// 查找资源
	//HRSRC hRsrc = ::FindResource(hMod, nResID, lpTyp);
	HRSRC hRsrc = ::FindResource(hMod, MAKEINTRESOURCE(nResID), lpTyp);
	if (hRsrc == NULL)
		return false;
	HGLOBAL hImgData = ::LoadResource(hMod, hRsrc);
	if (hImgData == NULL)
	{
		::FreeResource(hImgData);
		return false;
	}

	// 锁定内存中的指定资源
	LPVOID lpVoid = ::LockResource(hImgData);

	LPSTREAM pStream = nullptr;
	DWORD dwSize = ::SizeofResource(hMod, hRsrc);
	HGLOBAL hNew = ::GlobalAlloc(GHND, dwSize);
	LPBYTE lpByte = (LPBYTE)::GlobalLock(hNew);
	::memcpy(lpByte, lpVoid, dwSize);

	// 解除内存中的指定资源
	::GlobalUnlock(hNew);
	// 从指定内存创建流对象
	HRESULT ht = ::CreateStreamOnHGlobal(hNew, true, &pStream);
	if (ht == S_OK)
	{
		// 加载图片
		pImage->Load(pStream);

	}
	GlobalFree(hNew);
	// 释放资源
	::FreeResource(hImgData);
	return true;
}

void CTangram::TangramLoad()
{
	TCHAR szDriver[MAX_PATH] = { 0 };
	TCHAR szDir[MAX_PATH] = { 0 };
	TCHAR szExt[MAX_PATH] = { 0 };
	TCHAR szFile2[MAX_PATH] = { 0 };
	::GetModuleFileName(NULL, m_szBuffer, MAX_PATH);

	m_strConfigFile = CString(m_szBuffer);
	m_strConfigFile.MakeLower();
	m_strAppKey = ComputeHash(m_strConfigFile);
	m_strConfigFile += _T(".tangram");
	_tsplitpath_s(m_szBuffer, szDriver, szDir, szFile2, szExt);
	m_strAppPath = szDriver;
	m_strAppPath += szDir;

	::GetTempPath(MAX_PATH, m_szBuffer);
	m_strTempPath = CString(m_szBuffer);
	m_bAdmin = IsUserAdministrator();
	HRESULT hr = SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0, m_szBuffer);
	m_strAppDataPath = CString(m_szBuffer)+_T("\\");
	m_strAppDataPath.Replace(_T("\\\\"), _T("\\"));
	m_strAppCommonDocPath += m_strAppDataPath + _T("TangramCommonDocTemplate\\");
	if (::PathIsDirectory(m_strAppCommonDocPath) == false)
	{
		::SHCreateDirectory(nullptr, m_strAppCommonDocPath);
	}
	m_strAppCommonFormsInfoPath = m_strAppDataPath + _T("TangramCommonFormsInfo\\");
	if (::PathIsDirectory(m_strAppCommonFormsInfoPath) == false)
	{
		::SHCreateDirectory(nullptr, m_strAppCommonFormsInfoPath);
	}
	m_strAppCommonFormsTemplatePath = m_strAppDataPath + _T("TangramCommonFormsTemplate\\");
	if (::PathIsDirectory(m_strAppCommonFormsTemplatePath) == false)
	{
		::SHCreateDirectory(nullptr, m_strAppCommonFormsTemplatePath);
	}

	m_strNewDocXml = g_pTangram->m_strAppCommonDocPath + _T("newdocument.xml");

	CString strPath = m_strAppCommonDocPath + _T("\\Tangramdoctemplate.xml");
	if (::PathFileExists(strPath) == FALSE)
	{
		CTangramXmlParse m_Parse;
		m_Parse.LoadXml(_T("<TangramDocTemplate />"));
		m_Parse.SaveFile(strPath);
	}

	m_strAppDataPath += _T("TangramData\\");
	m_strAppDataPath += m_strExeName;
	m_strAppDataPath += _T("\\");
	m_strAppDataPath += m_strAppKey;
	m_strAppDataPath += _T("\\");

	strPath = g_pTangram->m_strAppDataPath + _T("default.tangramdoc");
	if (::PathFileExists(strPath) == false)
	{
		CString _strPath = g_pTangram->m_strAppPath + _T("default.tangramdoc");
		if (::PathFileExists(_strPath))
		{
			::CopyFile(_strPath, strPath, true);
		}
	}
}

void CTangram::TangramInit()
{
	if (m_bTangramInit)
		return;
	m_bTangramInit = true;
	CTangramXmlParse _m_Parse;
	bool bLoad = false;
	m_strConfigDataFile += m_strExeName;
	m_strConfigDataFile += _T(".tangram");
	if (::PathFileExists(m_strConfigFile) == FALSE)
	{
		if (::PathFileExists(m_strConfigDataFile) == TRUE)
			::DeleteFile(m_strConfigDataFile);
		CString strXml = _T("");
		strXml.Format(_T("<%s developermodel='true' companypathname='%s %s'  productname='%s' />"), g_pTangram->m_strExeName, g_pTangram->m_strExeName, _T(" team"), g_pTangram->m_strExeName);
		_m_Parse.LoadXml(strXml);
		_m_Parse.SaveFile(g_pTangram->m_strConfigFile);
		bLoad = true;
		m_bEclipse = false;
		CString strplugins = m_strAppPath + _T("plugins\\");
		if (::PathIsDirectory(strplugins)) {
			CString strPath = strplugins + _T("*.jar");
			_wfinddata_t fd;
			fd.attrib = FILE_ATTRIBUTE_DIRECTORY;
			intptr_t pf = _wfindfirst(strPath, &fd);
			if ((fd.attrib & FILE_ATTRIBUTE_DIRECTORY) == 0) {
				m_bEclipse = true;
			}
			else {
				while (!_wfindnext(pf, &fd)) {
					if ((fd.attrib & FILE_ATTRIBUTE_DIRECTORY) == 0) {
						m_bEclipse = true;
						break;
					}
				}
			}
			_findclose(pf);
		}
		if (m_bEclipse) {
			_m_Parse.put_attr(_T("eclipseapp"), _T("true"));
			_m_Parse.SaveFile(m_strConfigDataFile);
			CString strPath = g_pTangram->m_strAppDataPath + _T("default.workbench");
			if (::PathFileExists(strPath) == false) {
				CString _strPath = g_pTangram->m_strAppPath + _T("default.workbench");
				if (::PathFileExists(_strPath)) {
					::CopyFile(_strPath, strPath, true);
				}
			}
		}
	}

	if (bLoad == false) {
		bLoad = _m_Parse.LoadFile(m_strConfigFile);
	}
	if (bLoad) {
		//m_bDeveloperModel = _m_Parse.attrBool(_T("developermodel"));
		m_nJVMVersion = _m_Parse.attrInt(_T("jvmver"), JNI_VERSION_10);
		m_bEclipse = _m_Parse.attrBool(_T("eclipseapp"));
		m_strAppName = _m_Parse.attr(_T("appname"), _T("Tangram System"));
		m_strStartupCLRObj = _m_Parse.attr(_T("startupclrobj"), _T(""));
		if (m_strStartupCLRObj != _T("") && m_strStartupCLRObj.Find(_T(",")) != -1)
		{
		}
	}
	if (m_bEclipse) {
		if (launchMode == -1)
			GetLaunchMode();
		if (launchMode != -1) {
			m_strStartJarPath = _m_Parse.attr(_T("startupjarname"), DEFAULT_EQUINOX_STARTUP);
			CString _strBridgeJavaClass = _m_Parse.attr(_T("bridgeclass"), _T("org.eclipse.equinox.launcher.JNIBridge"));
			_strBridgeJavaClass.Replace(_T("."), _T("/"));
			USES_CONVERSION;
			m_strBridgeJavaClass = T2A(_strBridgeJavaClass);
			jarFile = findStartupJar();
			m_bEclipse = (jarFile != nullptr);
		}
		else
			m_bEclipse = false;
	}
	//ReadTextFromWeb(CComBSTR("https://tangramdesigner.com/TangramDesigner/"), CComBSTR(m_strExeName), CComBSTR(""), CComBSTR(""), CComBSTR("tangraminit.xml"), CComBSTR("tangraminit.xml"), 0);
	CString strPath = m_strProgramFilePath + _T("\\tangram\\") + m_strExeName + _T("\\tangraminit.xml");
	if (::PathFileExists(strPath)) {
		CTangramXmlParse m_Parse;
		if (m_Parse.LoadFile(strPath)) {
			int nCount = m_Parse.GetCount();
			for (int i = 0; i < nCount; i++) {
				CTangramXmlParse* pParse = m_Parse.GetChild(i);
				CString strID = pParse->attr(_T("id"), _T(""));
				CString strXml = pParse->GetChild(0)->xml();
				if (strID == _T("xmlRibbon")) {
					CString strPath = m_strAppCommonDocPath + _T("OfficeRibbon\\") + m_strExeName + _T("\\ribbon.xml");
					CTangramXmlParse m_Parse2;
					if (m_Parse2.LoadXml(strXml))
						m_Parse2.SaveFile(strPath);
				}
				if (strID == _T("tangramdesigner"))
					m_strDesignerXml = strXml;
				else {
					strID.MakeLower();
					if (strID == _T("newtangramdocument")) {
						m_strNewDocXml = strXml;
					}
					else {
						m_mapValInfo[strID] = CComVariant(strXml);
					}
				}
			}
		}
	}
	CString _strPath = m_strAppCommonDocPath + _T("Tangramdoctemplate.xml");
	CString _strPathReg = m_strAppCommonDocPath + _T("TangramReg.xml");
	BOOL bModifyed = false;
	CTangramXmlParse m_Parse;
	CTangramXmlParse m_ParseReg;
	if (m_Parse.LoadFile(_strPath) == FALSE) {
		m_Parse.LoadXml(_T("<TangramDocTemplate />"));
	}
	if (m_ParseReg.LoadFile(_strPathReg) == FALSE) {
		m_ParseReg.LoadXml(_T("<TangramDocReg />"));
		m_ParseReg.SaveFile(_strPathReg);
	}

	strPath = m_strProgramFilePath + _T("\\tangram\\CommonDocComponent\\*.*");

	_wfinddata_t fd;
	fd.attrib = FILE_ATTRIBUTE_DIRECTORY;
	intptr_t pf = _wfindfirst(strPath, &fd);
	if (pf != -1) {
		while (!_wfindnext(pf, &fd)) {
			if (fd.attrib & FILE_ATTRIBUTE_DIRECTORY) {
				CString str = fd.name;
				str.MakeLower();
				if (str != _T("..")) {
					CString strXml = m_strProgramFilePath + _T("\\tangram\\CommonDocComponent\\") + str + _T("\\tangram.xml");
					if (m_ParseReg.GetChild(str) == nullptr) {
						int nPos = str.Find(_T("."));
						CString strLib = _T("");
						if (nPos != -1) {
							strLib = str.Left(nPos);
							strLib = m_strProgramFilePath + _T("\\tangram\\CommonDocComponent\\") + str + _T("\\") + strLib + _T(".dll");
							if (::PathFileExists(strLib)) {
								m_strLibs += strLib;
								m_strLibs += _T("|");
							}
							else {
								CTangramXmlParse m_Parse2;
								if (m_Parse2.LoadFile(strXml)) {
									strLib = m_Parse2.attr(_T("lib"), _T(""));
									if (strLib != _T("")) {
										strLib = m_strProgramFilePath + _T("\\tangram\\CommonDocComponent\\") + str + _T("\\") + strLib + _T(".dll");
										if (::PathFileExists(strLib)) {
											m_strLibs += strLib;
											m_strLibs += _T("|");
										}
									}
								}
							}
						}
					}
					if (::PathFileExists(strXml)) {
						CTangramXmlParse m_Parse2;
						if (m_Parse2.LoadFile(strXml)) {
							int nCount = m_Parse2.GetCount();
							for (int i = 0; i < nCount; i++) {
								CTangramXmlParse* pParse = m_Parse2.GetChild(i);
								str = pParse->name().MakeLower();
								if (m_Parse.GetChild(str) == nullptr) {
									bModifyed = true;
									m_Parse.AddNode(pParse, str);
								}
							}
						}
					}
				}
			}
		}
		_findclose(pf);
	}
	if (bModifyed)
		m_Parse.SaveFile(_strPath);
	if (m_strLibs != _T(""))
		::PostMessage(m_hTangramWnd, WM_TANGRAMMSG, 0, 19651963);
}

void CTangram::ExitInstance()
{
	if (m_mapTangramEvent.size())
	{
		auto it = m_mapTangramEvent.begin();
		for (it = m_mapTangramEvent.begin(); it != m_mapTangramEvent.end(); it++)
		{
			delete it->second;
		}
		m_mapTangramEvent.clear();
	}

	if (m_hCBTHook)
		UnhookWindowsHookEx(m_hCBTHook);
	if (m_hForegroundIdleHook)
		UnhookWindowsHookEx(m_hForegroundIdleHook);
	for (auto it : m_mapThreadInfo)
	{
		if (it.second->m_hGetMessageHook)
		{
			UnhookWindowsHookEx(it.second->m_hGetMessageHook);
			it.second->m_hGetMessageHook = NULL;
		}
		delete it.second;
	}
	m_mapThreadInfo.erase(m_mapThreadInfo.begin(), m_mapThreadInfo.end());
	_clearObjects();
	if (m_mapWindowPage.size())
	{
		auto it2 = m_mapWindowPage.begin();
		while (it2 != m_mapWindowPage.end())
		{
			delete it2->second;
			if (m_mapWindowPage.size() == 0)
				break;
			it2 = m_mapWindowPage.begin();
		}
	}

	for (auto it : m_mapObjDic)
	{
		if (it.first.CompareNoCase(_T("dte")))
		{
			CString strKey = _T(",");
			strKey += it.first;
			strKey += _T(",");
			if (m_strExcludeAppExtenderIDs.Find(strKey) == -1)
				it.second->Release();
			else
				m_strExcludeAppExtenderIDs.Replace(strKey, _T(""));
		}
	}

	m_mapObjDic.erase(m_mapObjDic.begin(), m_mapObjDic.end());

	for (auto it : m_mapValInfo)
	{
		::VariantClear(&it.second);
	}
	m_mapValInfo.erase(m_mapValInfo.begin(), m_mapValInfo.end());
	m_mapValInfo.clear();
}

TangramThreadInfo* CTangram::GetThreadInfo(DWORD ThreadID)
{
	TangramThreadInfo* pInfo = nullptr;

	DWORD nThreadID = ThreadID;
	if (nThreadID == 0)
		nThreadID = GetCurrentThreadId();
	auto it = m_mapThreadInfo.find(nThreadID);
	if (it != m_mapThreadInfo.end())
	{
		pInfo = it->second;
	}
	else
	{
		pInfo = new TangramThreadInfo();
		pInfo->m_hGetMessageHook = NULL;
		m_mapThreadInfo[nThreadID] = pInfo;
	}
	return pInfo;
}

// IPC message
void CTangram::DispatchToOtherBrokers(CString strChannel, CString strData)
{
	for (auto it = m_mapWindowPage.begin(); it != m_mapWindowPage.end(); ++it)
	{
		IPC::Broker* pBroker = (IPC::Broker*)it->second;
		pBroker->DispatchIPCMessage(strChannel, strData);
	}
}

IPC::Broker* CTangram::GetBroker()
{
	return this;
}

void CTangram::OnIPCMessageReceived(CString strChannel, CString strData)
{
	// TODO
}

ULONG CTangram::InternalRelease()
{
	if (m_bCanClose == false)
		return 1;
	else if (m_nAppID == 3)
	{
		m_nRef--;
		return m_nRef;
	}

	return 1;
}

void CTangram::ProcessMsg(LPMSG lpMsg)
{
	switch (lpMsg->message)
	{
	case WM_NCLBUTTONDOWN:
	case WM_NCRBUTTONDOWN:
	case WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
		HWND hPWnd = ::GetAncestor(lpMsg->hwnd, GA_ROOT);
		if (lpMsg->hwnd != hPWnd)
		{
			auto it = m_mapBrowserWnd.find(hPWnd);
			if (it != m_mapBrowserWnd.end())
			{
				HWND _hPWnd = ::GetParent(hPWnd);
				if (_hPWnd == nullptr)
				{
					ChromePlus::CBrowserWnd* pBrowserWnd = (ChromePlus::CBrowserWnd*)it->second;
					if (pBrowserWnd->m_pOmniboxViewViews&& pBrowserWnd->m_pOmniboxViewViews->IsFocused() == false)
						return;
					CHtmlWnd * pWnd = pBrowserWnd->m_pVisibleWebWnd;
					if (pWnd && lpMsg->hwnd != pWnd->m_hWnd)
					{
						CWndNode* pRetNode = (CWndNode*)::SendMessage(lpMsg->hwnd, WM_TANGRAMGETNODE, 0, 0);
						switch (lpMsg->message)
						{
							//case WM_POINTERDOWN:
						case WM_LBUTTONDOWN:
							if (pRetNode == nullptr || pRetNode->m_nViewType != Splitter)
							{
								::SendMessage(pWnd->m_hWnd, WM_LBUTTONDOWN, (WPARAM)lpMsg, 0);
							}
							break;
						case WM_LBUTTONUP:
							//case WM_POINTERUP:
							if (pRetNode && pRetNode->m_nViewType == Splitter)
							{
								::PostMessage(pWnd->m_hWnd, WM_LBUTTONDOWN, (WPARAM)lpMsg, 0);
							}
							break;
						}
					}
				}
			}
			return;
		}
		return;
	}
	if (m_bEclipse&&m_pTangramAppProxy)
	{
		BOOL bToolBarMg = false;
		ITangramAppProxy* pProxy = m_pActiveAppProxy;
		HWND hActiveMenu = nullptr;
		if (pProxy == nullptr)
			pProxy = m_pTangramAppProxy;
		if (pProxy)
		{
			hActiveMenu = pProxy->GetActivePopupMenu(lpMsg->hwnd);
		}
		if (lpMsg->message != WM_LBUTTONDOWN)
		{
			if (m_pTangramDelegate)
			{
				if (m_pTangramDelegate->OnTangramPreTranslateMessage(lpMsg))
					return;
			}
			if (pProxy)
			{
				pProxy->TangramPreTranslateMessage(lpMsg);
			}
		}
		else
		{
			::GetClassName(lpMsg->hwnd, m_szBuffer, MAX_PATH);
			CString strClassName = CString(m_szBuffer);
			if (strClassName.Find(_T("Afx:ToolBar:")) == 0)
			{
				bToolBarMg = true;
				ATLTRACE(_T("Afx:ToolBar:%x\n"), lpMsg->hwnd);
				if (::GetWindowLong(::GetParent(lpMsg->hwnd), GWL_STYLE) & WS_POPUP)
				{
					TranslateMessage(lpMsg);
					DispatchMessage(lpMsg);//
					return;
				}
			}
			else
			{
				//if (g_pTangram->m_pTangramAppImpl)
				//{
				//	if (g_pTangram->m_pTangramAppImpl->OnTangramPreTranslateMessage(lpMsg))
				//		return;
				//}
				if (pProxy)
				{
					pProxy->TangramPreTranslateMessage(lpMsg);
				}
			}
		}
		if (bToolBarMg == false && ::IsChild(hActiveMenu, lpMsg->hwnd) == false)
			::PostMessage(hActiveMenu, WM_CLOSE, 0, 0);
		return;
	}
	//if ((long)(g_pTangram->m_pActiveAppProxy) > 1)
	if (m_pActiveAppProxy)
	{
		HWND hMenuWnd = m_pActiveAppProxy->GetActivePopupMenu(nullptr);
		if (hMenuWnd&&::IsWindow(hMenuWnd))
			::PostMessage(hMenuWnd, WM_CLOSE, 0, 0);
	}
}

void CTangram::CreateCommonDesignerToolBar()
{
	CString strName = this->m_strExeName;
	if (::IsWindow(m_hHostWnd) == false)
	{
		auto it = m_mapValInfo.find(_T("c"));
		if (it != m_mapValInfo.end())
			m_strDesignerToolBarCaption = OLE2T(it->second.bstrVal);
		m_hHostWnd = ::CreateWindowEx(WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW, _T("Tangram Window Class"), m_strDesignerToolBarCaption, WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, 0, 0, 400, 400, NULL, 0, theApp.m_hInstance, NULL);
		m_hChildHostWnd = ::CreateWindowEx(NULL, _T("Tangram Window Class"), _T(""), WS_VISIBLE | WS_CHILD, 0, 0, 0, 0, m_hHostWnd, 0, theApp.m_hInstance, NULL);
	}
	CString strDesignerDll = m_strAppPath + _T("tangramdesigner.dll");
	if (::PathFileExists(strDesignerDll) == false)
		return;
	if (m_pCLRProxy && m_pCLRProxy->IsSupportDesigner() == false)
		return;
	HWND hwnd = ::GetActiveWindow();
	if (m_hHostWnd&&m_pDesignerCompositorManager == nullptr)
	{
		RECT rc;
		::GetWindowRect(hwnd, &rc);
		::SetWindowPos(m_hHostWnd, NULL, rc.left + 40, rc.top + 40, 400, 600, SWP_NOACTIVATE | SWP_NOREDRAW);
		if (m_pDesignerCompositorManager == nullptr)
		{
			auto it = m_mapWindowPage.find(m_hHostWnd);
			if (it != m_mapWindowPage.end())
				m_pDesignerCompositorManager = (CCompositorManager*)it->second;
			else
			{
				m_pDesignerCompositorManager = new CComObject<CCompositorManager>();
				m_pDesignerCompositorManager->m_hWnd = m_hHostWnd;
				m_mapWindowPage[m_hHostWnd] = m_pDesignerCompositorManager;
			}
			CString strPath = m_strExeName + _T(".designer");
			CTangramXmlParse m_Parse;
			bool bSupportDesigner = m_Parse.LoadFile(strPath);
			if (bSupportDesigner == false)
			{
				strPath = m_strProgramFilePath + _T("\\Tangram\\TangramDesigner.designer");
				bSupportDesigner = m_Parse.LoadFile(strPath);
			}
			if (bSupportDesigner)
			{
				//m_strDesignerXml = _T("<designertoolbar><window><node name = 'designer' url = 'https://www.tangram.dev/cloud/designer.html'></node></window></designertoolbar>");
				m_strDesignerXml = m_Parse.xml();
				if (m_strDesignerXml != _T(""))
				{
					auto it = m_pDesignerCompositorManager->m_mapCompositor.find(m_hChildHostWnd);
					if (it == m_pDesignerCompositorManager->m_mapCompositor.end())
					{
						ICompositor* pCompositor = nullptr;
						HRESULT hr = m_pDesignerCompositorManager->CreateCompositor(CComVariant(0), CComVariant((__int64)m_hChildHostWnd), CComBSTR(L"DeignerTool"), &pCompositor);
						if (pCompositor)
						{
							IWndNode* pNode = nullptr;
							pCompositor->Open(CComBSTR(L"DeignerToolBox"), CComBSTR(m_strDesignerXml), &pNode);
							m_pDesignerFrame = (CCompositor*)pCompositor;
							m_pDesignerFrame->m_bDesignerState = false;
						}
					}
				}
			}
		}
	}

	::ShowWindow(m_hHostWnd, SW_SHOW);
	::UpdateWindow(m_hHostWnd);
}

void CTangram::AttachNode(void* pNodeEvents)
{
	CWndNodeEvents*	m_pCLREventConnector = (CWndNodeEvents*)pNodeEvents;
	CWndNode* pNode = (CWndNode*)m_pCLREventConnector->m_pWndNode;
	pNode->m_pCLREventConnector = m_pCLREventConnector;
}

ICompositor* CTangram::ConnectCompositorManager(HWND hFrame, CString _strFrameName, ICompositorManager* _pCompositorManager, CompositorInfo* pInfo)
{
	if (m_nAppID == 9)
		return nullptr;
	CCompositorManager* pCompositorManager = (CCompositorManager*)_pCompositorManager;
	if (pCompositorManager->m_hWnd == g_pTangram->m_hHostWnd)
		return nullptr;
	CString strFrameName = _strFrameName;

	CTangramDocTemplate* pDocTemplate = nullptr;
	if (m_pMDIMainWnd)
	{
		if (m_pMDIMainWnd->m_pCompositorManager == pCompositorManager)
		{
			pDocTemplate = m_pMDIMainWnd->m_pDocTemplate;
			strFrameName = m_pMDIMainWnd->m_pDocTemplate->m_strClientKey + _strFrameName;
		}
		else
		{
			HWND hWnd = pCompositorManager->m_hWnd;
			if (::GetWindowLong(hWnd, GWL_EXSTYLE)&WS_EX_MDICHILD)
			{
				CTangramMDIChildWnd* pWnd = (CTangramMDIChildWnd*)::SendMessage(hWnd, WM_TANGRAMMSG, 0, 19631222);
				if (pWnd&&pWnd->m_pDocTemplate)
				{
					//strFrameName = _strFrameName;
					pDocTemplate = pWnd->m_pDocTemplate;
				}
			}
		}
	}

	ICompositor* pCompositor = nullptr;
	pCompositorManager->CreateCompositor(CComVariant(0), CComVariant((__int64)hFrame), strFrameName.AllocSysString(), &pCompositor);
	if (pCompositor)
	{
		CCompositor* _pCompositor = (CCompositor*)pCompositor;
		_pCompositor->m_pCompositorInfo = pInfo;
		_pCompositor->m_strCurrentXml = pInfo->m_strNodeXml;
		CComQIPtr<IWndNode> pParentNode(pInfo->m_pParentDisp);
		IWndNode* pNode = nullptr;
		CString str = _T("");
		if (pDocTemplate == nullptr)
		{
			m_mapFramePage[hFrame] = pCompositorManager;
		}
		else
		{
			HWND hWnd = _pCompositor->m_pCompositorManager->m_hWnd;
			CTangramMDIChildWnd* pWnd = (CTangramMDIChildWnd*)::SendMessage(hWnd, WM_TANGRAMMSG, 0, 19631222);
			if (pWnd == nullptr)
			{
				_pCompositor->m_pTangramDocTemplate = pDocTemplate;
				pDocTemplate->m_mapConnectedFrame[hFrame] = _pCompositor;
			}
		}
		CString strKey = _T("default");
		if (pDocTemplate)
		{
			if (pDocTemplate->m_strClientKey == _T(""))
				pDocTemplate->m_strClientKey = _T("default");
			strKey = pDocTemplate->m_strClientKey;
		}
		str.Format(_T("<%s><window><node name='%s' /></window></%s>"), strKey, _strFrameName, strKey);
		pCompositor->Open(CComBSTR(strKey), CComBSTR(str), &pNode);
		if (pDocTemplate == nullptr)
		{
			CWndNode* _pNode = (CWndNode*)pNode;
			HWND hWnd = _pNode->m_pTangramNodeCommonData->m_pCompositorManager->m_hWnd;
			auto it = m_mapTangramMDIChildWnd.find(hWnd);
			if (it == m_mapTangramMDIChildWnd.end())
			{
				return pCompositor;
			}
			CTangramWinFormWnd* pWnd = (CTangramWinFormWnd*)::SendMessage(hWnd, WM_TANGRAMDATA, 0, 20190214);
			if (pWnd)
			{
				if ((::GetWindowLong(hWnd, GWL_EXSTYLE)&WS_EX_MDICHILD)||(pWnd->m_bMdiForm&&pWnd->m_strChildFormPath != _T("")))
					return pCompositor;
			}
			pNode->put_SaveToConfigFile(true);
		}
	}

	return pCompositor;
}

bool g_bInit = false;
void CTangram::BrowserAppStart()
{ 
	Init();
	if (g_bInit == true)
		return;
	g_bInit = true;
	if (m_nAppType!= TANGRAM_APP_BROWSER &&m_pBrowserFactory && ::IsWindow(m_hChildHostWnd)) {
		if(m_nAppType == TANGRAM_APP_BROWSERAPP)
			m_hMainWnd = m_hHostWnd;
		::PostMessage(m_hHostWnd, WM_TANGRAMMSG, 0, TANGRAM_CHROME_APP_INIT);
		if (::PathFileExists(g_pTangram->m_strStartupURL) == false) {
			return;
		}
		CString str = _T("<host popup='true'><url></url></host>");
		CTangramXmlParse m_Parse;
		if (m_Parse.LoadXml(str)) {
			CTangramXmlParse* pParse = nullptr;
			m_Parse[_T("url")].put_text(g_pTangram->m_strStartupURL);
		}
		m_hHostBrowserWnd = m_pBrowserFactory->CreateBrowser((HWND)m_hChildHostWnd, m_Parse.xml());
	}
	::PostAppMessage(::GetCurrentThreadId(), WM_TANGRAMMSG, 0, 2019111701);
}

bool CTangram::IsMDIClientCompositorNode(IWndNode* pNode)
{
	if (m_pMDIMainWnd == nullptr)
		return false;

	CWndNode* _pNode = (CWndNode*)pNode;
	HWND hWnd = _pNode->m_pTangramNodeCommonData->m_pCompositorManager->m_hWnd;
	if (::GetWindowLong(hWnd, GWL_EXSTYLE)&WS_EX_MDICHILD)
	{
		return false;
	}
	//CTangramMDIChildWnd* pWnd = (CTangramMDIChildWnd*)::SendMessage(hWnd, WM_TANGRAMMSG, 0, 19631222);
	//if (pWnd)
	//{
	//	return false;
	//}
	////if (::IsChild(m_pMDIMainWnd->m_hWnd, hWnd) == false)
	////	return false;
	//if (::IsChild(m_pMDIMainWnd->m_hMDIClient, hWnd))
	//{
	//	return false;
	//}

	return true;
}

IWndNode* CTangram::OpenCtrl(__int64 handle, CString name, CString NodeTag)
{
	ICompositor* pCompositor = nullptr;
	GetCompositor(handle, &pCompositor);
	if (pCompositor)
	{
		CString strPath = m_strAppDataPath + name + _T("\\");
		if (::PathIsDirectory(strPath) == false)
		{
			::CreateDirectory(strPath, nullptr);
		}
		strPath += NodeTag + _T(".nodexml");
		if (::PathFileExists(strPath) == false)
		{
			CString strXml = _T("<nodexml><window><node name='StartNode' /></window></nodexml>");
			CTangramXmlParse m_Parse;
			m_Parse.LoadXml(strXml);
			m_Parse.SaveFile(strPath);
		}
		IWndNode* pNode = nullptr;
		pCompositor->Open(NodeTag.AllocSysString(), strPath.AllocSysString(), &pNode);
		CCompositor* _pCompositor = (CCompositor*)pCompositor;
		_pCompositor->m_mapNodeScript[strPath] = (CWndNode*)pNode;
		//m_mapTreeCtrlScript[(HWND)handle] = NodeTag;
		return pNode;
	}
	return nullptr;
};

ICompositorManager* CTangram::Open(HWND hFrame, CString strName, CString strKey)
{
	auto it = m_mapFramePage.find(hFrame);
	if (it != m_mapFramePage.end())
	{
		CCompositorManager* pCompositorManager = (CCompositorManager*)it->second;
		ICompositor* pCompositor = nullptr;
		auto it2 = pCompositorManager->m_mapCompositor.find(hFrame);
		if (it2 == pCompositorManager->m_mapCompositor.end())
			pCompositorManager->CreateCompositor(CComVariant(0), CComVariant((__int64)hFrame), CComBSTR(strName), &pCompositor);
		else
			pCompositor = it2->second;
		IWndNode* pNode = nullptr;
		CString str = _T("");
		str.Format(_T("<default><window><node name='%s' /></window></default>"), strName);
		pCompositor->Open(CComBSTR(strKey), CComBSTR(str), &pNode);
		VARIANT_BOOL bNewVersion;
		pCompositorManager->get_NewVersion(&bNewVersion);
		if (!bNewVersion)
		{
			pNode->put_SaveToConfigFile(true);
		}
		return pCompositorManager;
	}
	return nullptr;
};

CString CTangram::GetNewLayoutNodeName(BSTR bstrCnnID, IWndNode* pDesignNode)
{
	BOOL bGetNew = false;
	CString strNewName = _T("");
	CString strName = OLE2T(bstrCnnID);
	CString str = m_strExeName + _T(".appwnd.");
	strName.Replace(str, _T(""));
	int nIndex = 0;
	CWndNode* _pNode = ((CWndNode*)pDesignNode);
	CWndNode* pNode = _pNode->m_pRootObj;
	auto it = pNode->m_pTangramNodeCommonData->m_mapLayoutNodes.find(strName);
	if (it == pNode->m_pTangramNodeCommonData->m_mapLayoutNodes.end())
	{
		return strName;
	}
	while (bGetNew == false)
	{
		strNewName.Format(_T("%s%d"), strName, nIndex);
		it = pNode->m_pTangramNodeCommonData->m_mapLayoutNodes.find(strNewName);
		if (it == pNode->m_pTangramNodeCommonData->m_mapLayoutNodes.end())
		{
			return strNewName;
		}
		nIndex++;
	}
	return _T("");
};

CString CTangram::GetDesignerInfo(CString strIndex)
{
	if (m_pDesignerCompositorManager)
	{
		auto it = m_pDesignerCompositorManager->m_mapXtml.find(strIndex);
		if (it != m_pDesignerCompositorManager->m_mapXtml.end())
			return it->second;
	}
	return _T("");
};

CString CTangram::InitEclipse(_TCHAR* jarFile)
{
	if (m_hForegroundIdleHook == NULL)
		m_hForegroundIdleHook = SetWindowsHookEx(WH_FOREGROUNDIDLE, CTangramApp::ForegroundIdleProc, NULL, ::GetCurrentThreadId());
	//if (m_hCBTHook == NULL)
	//	m_hCBTHook = SetWindowsHookEx(WH_CBT, CTangramApp::CBTProc, NULL, ::GetCurrentThreadId());
	m_bEnableProcessFormTabKey = true;
	if (m_hHostWnd == NULL)
	{
		m_hHostWnd = ::CreateWindowEx(WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW, _T("Tangram Window Class"), m_strDesignerToolBarCaption, WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, 0, 0, 0, 0, NULL, NULL, theApp.m_hInstance, NULL);
		m_hChildHostWnd = ::CreateWindowEx(NULL, _T("Tangram Window Class"), _T(""), WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE | WS_CHILD, 0, 0, 0, 0, g_pTangram->m_hHostWnd, NULL, theApp.m_hInstance, NULL);
	}

	jclass			jarFileClass = nullptr;
	jclass			manifestClass = nullptr;
	jclass			attributesClass = nullptr;

	jmethodID		jarFileConstructor = nullptr;
	jmethodID		getManifestMethod = nullptr;
	jmethodID		getMainAttributesMethod = nullptr;
	jmethodID		closeJarMethod = nullptr;
	jmethodID		getValueMethod = nullptr;

	::PostMessage(m_hHostWnd, WM_TANGRAMAPPINIT, 1963, 1222);
	JNIEnv* pJVMenv = m_pTangramDelegate->m_pJVMenv;
	jarFileClass = pJVMenv->FindClass("java/util/jar/JarFile");
	if (jarFileClass != nullptr) {
		manifestClass = pJVMenv->FindClass("java/util/jar/Manifest");
		if (manifestClass != nullptr) {
			attributesClass = pJVMenv->FindClass("java/util/jar/Attributes");
		}
	}
	DefaultExceptionProcess(pJVMenv);
	if (attributesClass == nullptr)
		return _T("");
	/* get the classes we need */

	/* find the methods */
	jarFileConstructor = pJVMenv->GetMethodID(jarFileClass, "<init>", "(Ljava/lang/String;Z)V");
	if (jarFileConstructor != nullptr) {
		getManifestMethod = pJVMenv->GetMethodID(jarFileClass, "getManifest", "()Ljava/util/jar/Manifest;");
		if (getManifestMethod != nullptr) {
			closeJarMethod = pJVMenv->GetMethodID(jarFileClass, "close", "()V");
			if (closeJarMethod != nullptr) {
				getMainAttributesMethod = pJVMenv->GetMethodID(manifestClass, "getMainAttributes", "()Ljava/util/jar/Attributes;");
				if (getMainAttributesMethod != nullptr) {
					getValueMethod = pJVMenv->GetMethodID(attributesClass, "getValue", "(Ljava/lang/String;)Ljava/lang/String;");
				}
			}
		}
	}
	DefaultExceptionProcess(pJVMenv);
	if (getValueMethod == nullptr)
		return _T("");

	jobject jarFileObject, manifest, attributes;

	jstring mainClassString = nullptr;
	jstring jarFileString, headerString;

	jarFileString = newJavaString(pJVMenv, jarFile);
	/* headerString = new String("Main-Class"); */
	headerString = newJavaString(pJVMenv, _T("Main-Class"));
	if (jarFileString != nullptr && headerString != nullptr) {
		/* jarfileObject = new JarFile(jarFileString, false); */
		jarFileObject = pJVMenv->NewObject(jarFileClass, jarFileConstructor, jarFileString, JNI_FALSE);
		if (jarFileObject != nullptr) {
			/* manifest = jarFileObject.getManifest(); */
			manifest = pJVMenv->CallObjectMethod(jarFileObject, getManifestMethod);
			if (manifest != nullptr) {
				/*jarFileObject.close() */
				pJVMenv->CallVoidMethod(jarFileObject, closeJarMethod);
				if (!pJVMenv->ExceptionOccurred()) {
					/* attributes = manifest.getMainAttributes(); */
					attributes = pJVMenv->CallObjectMethod(manifest, getMainAttributesMethod);
					if (attributes != nullptr) {
						/* mainClassString = attributes.getValue(headerString); */
						mainClassString = (jstring)pJVMenv->CallObjectMethod(attributes, getValueMethod, headerString);
					}
				}
			}
			pJVMenv->DeleteLocalRef(jarFileObject);
		}
	}

	if (jarFileString != nullptr)
		pJVMenv->DeleteLocalRef(jarFileString);
	if (headerString != NULL)
		pJVMenv->DeleteLocalRef(headerString);

	DefaultExceptionProcess(pJVMenv);

	if (mainClassString == nullptr)
		return _T("");

	const _TCHAR * stringChars = (_TCHAR *)pJVMenv->GetStringChars(mainClassString, 0);
	CString strName = CString(stringChars);
	pJVMenv->ReleaseStringChars(mainClassString, (const jchar *)stringChars);
	strName.Trim();
	strName.Replace(_T("."), _T("/"));
	
	return strName;
}

void CTangram::CreateEclipseApp(CString strKey, CString strXml)
{
	if (eclipseLibrary)
		return;
	m_bEclipse = false;
	CString strplugins = m_strAppPath + _T("plugins\\");
	if (::PathIsDirectory(strplugins))
	{
		CString strPath = strplugins + _T("*.jar");

		_wfinddata_t fd;
		fd.attrib = FILE_ATTRIBUTE_DIRECTORY;
		intptr_t pf = _wfindfirst(strPath, &fd);
		if ((fd.attrib & FILE_ATTRIBUTE_DIRECTORY) == 0)
		{
			m_bEclipse = true;
		}
		else
		{
			while (!_wfindnext(pf, &fd))
			{
				if ((fd.attrib & FILE_ATTRIBUTE_DIRECTORY) == 0)
				{
					m_bEclipse = true;
					break;
				}
			}
		}
		_findclose(pf);
	}
	if (m_bEclipse)
	{
		if (launchMode == -1)
			GetLaunchMode();
		if (launchMode != -1)
		{
			CTangramXmlParse _m_Parse;
			_m_Parse.LoadFile(g_pTangram->m_strConfigFile);
			m_strStartJarPath = _m_Parse.attr(_T("startupjarname"), DEFAULT_EQUINOX_STARTUP);
			CString _strBridgeJavaClass = _m_Parse.attr(_T("bridgeclass"), _T("org.eclipse.equinox.launcher.JNIBridge"));
			_strBridgeJavaClass.Replace(_T("."), _T("/"));
			USES_CONVERSION;
			m_strBridgeJavaClass = T2A(_strBridgeJavaClass);
			jarFile = findStartupJar();
			m_bEclipse = (jarFile != nullptr);
		}
		else
			m_bEclipse = false;
	}
	if (m_bEclipse)
	{
		if (m_pTangramAppProxy)
		{
			m_pTangramAppProxy->m_pvoid = nullptr;
			if (m_hCBTHook == NULL)
				m_hCBTHook = SetWindowsHookEx(WH_CBT, CTangramApp::CBTProc, NULL, ::GetCurrentThreadId());
			m_bEnableProcessFormTabKey = true;
			GetLaunchMode();
			if (g_pTangram->launchMode != -1)
			{
				TCHAR	m_szBuffer[MAX_PATH];
				::GetModuleFileName(theApp.m_hInstance, m_szBuffer, MAX_PATH);
				eclipseLibrary = m_szBuffer;

				setlocale(LC_ALL, "");
				int		nArgs;
				szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
				CEclipseExtender* pExtender = new CComObject<CEclipseExtender>;
				m_pExtender = pExtender;
				runW(nArgs, szArglist, userVMarg);
				if (m_bLoadEclipseDelay)
				{
					::PostQuitMessage(0);
				}
			}
		}
	}
}

int CTangram::LoadCLR()
{
	if (m_pCLRProxy == nullptr&&m_pClrHost == nullptr)
	{
		HMODULE	hMscoreeLib = LoadLibrary(TEXT("mscoree.dll"));
		if (hMscoreeLib)
		{
			TangramCLRCreateInstance CLRCreateInstance = (TangramCLRCreateInstance)GetProcAddress(hMscoreeLib, "CLRCreateInstance");
			if (CLRCreateInstance)
			{
				HRESULT hrStart = 0;
				ICLRMetaHost* m_pMetaHost = NULL;
				hrStart = CLRCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, (LPVOID *)&m_pMetaHost);
				CString strVer = _T("v4.0.30319");
				ICLRRuntimeInfo * lpRuntimeInfo = nullptr;
				hrStart = m_pMetaHost->GetRuntime(strVer.AllocSysString(), IID_ICLRRuntimeInfo, (LPVOID *)&lpRuntimeInfo);
				if (FAILED(hrStart))
					return S_FALSE;
				hrStart = lpRuntimeInfo->GetInterface(CLSID_CLRRuntimeHost, IID_ICLRRuntimeHost, (LPVOID *)&m_pClrHost);
				if (FAILED(hrStart))
					return S_FALSE;

				hrStart = m_pClrHost->Start();
				if (FAILED(hrStart))
				{
					return S_FALSE;
				}
				if (hrStart == S_FALSE)
				{
					theApp.m_bHostCLR = true;
				}
				else
					m_bEnableProcessFormTabKey = true;

				CString strPath = m_strAppPath + _T("tangram_clr_rt.dll");

				HANDLE hFind; // file handle
				WIN32_FIND_DATA FindFileData;
				if (::PathFileExists(strPath) == false)
				{
					strPath = _T("");
					hFind = FindFirstFile(m_strAppPath + _T("tangram_clr_rt.dll"), &FindFileData); // find the first file
					if (hFind != INVALID_HANDLE_VALUE)
					{
						bool bSearch = true;
						while (bSearch) // until we finds an entry
						{
							if (FindNextFile(hFind, &FindFileData))
							{
								// Don't care about . and ..
								//if(IsDots(FindFileData.cFileName))
								if ((_tcscmp(FindFileData.cFileName, _T(".")) == 0) ||
									(_tcscmp(FindFileData.cFileName, _T("..")) == 0))
									continue;

								// We have found a directory
								if ((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
								{
									strPath = m_strAppPath + FindFileData.cFileName + _T("\\");
									strPath += _T("tangram_clr_rt.dll");
									if (::PathFileExists(strPath))
									{
										break;
									}
								}

							}//FindNextFile
						}//while
					}
				}

				if (strPath == _T(""))
				{
					int nVer = 0;
	#ifdef _WIN64
					nVer = 64;
	#else
					nVer = 32;
	#endif
					strPath.Format(_T("%s\\Microsoft.NET\\assembly\\GAC_%d\\tangram_clr_rt\\v4.0_1.0.1992.1963__1bcc94f26a4807a7\\Tangram_CLR_RT.dll"), m_szBuffer, nVer);
				}

				CTangramImpl* pTangramProxyBase = static_cast<CTangramImpl*>(this);
				CString strInfo = _T("");
				strInfo.Format(_T("%I64d"), (__int64)pTangramProxyBase);
				DWORD dwRetCode = 0;
				hrStart = m_pClrHost->ExecuteInDefaultAppDomain(
					strPath,
					_T("TangramCLR.TangramProxy"),
					_T("TangramInit"),
					CComBSTR(strInfo),
					&dwRetCode);
				m_pMetaHost->Release();
				m_pMetaHost = nullptr;
				FreeLibrary(hMscoreeLib);
				if (hrStart != S_OK)
					return -1;
			}
		}
	}
	return 0;
}

CString CTangram::RemoveUTF8BOM(CString strUTF8)
{
	int cc = 0;
	if ((cc = WideCharToMultiByte(CP_UTF8, 0, strUTF8, -1, NULL, 0, 0, 0)) > 2)
	{
		char* cstr = (char*)malloc(cc);
		WideCharToMultiByte(CP_UTF8, 0, strUTF8, -1, cstr, cc, 0, 0);

		if (cstr[0] == (char)0xEF && cstr[1] == (char)0xBB && cstr[2] == (char)0xBF)
		{
			char* new_cstr = (char*)malloc(cc - 3);
			memcpy(new_cstr, cstr + 3, cc - 3);

			CStringW newStrUTF8;
			wchar_t *buf = newStrUTF8.GetBuffer(cc - 3);
			MultiByteToWideChar(CP_UTF8, 0, new_cstr, -1, buf, cc - 3);
			newStrUTF8.ReleaseBuffer();
			free(new_cstr);
			free(cstr);
			return newStrUTF8;
		}

		free(cstr);
	}
	return strUTF8;
}

CWndNode* CTangram::OpenEx(long hWnd, CString strExXml, CString strXml)
{
	strXml = RemoveUTF8BOM(strXml);
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CTangramXmlParse* m_pParse = new CTangramXmlParse();
	bool bXml = m_pParse->LoadXml(strXml);
	if (bXml == false)
		bXml = m_pParse->LoadFile(strXml);

	if (bXml == false)
	{
		delete m_pParse;
		return nullptr;
	}

	BOOL bSizable = m_pParse->attrBool(_T("sizable"), false);
	CTangramXmlParse* pWndNode = m_pParse->GetChild(_T("window"));
	if (pWndNode == nullptr)
	{
		delete m_pParse;
		return nullptr;
	}

	CTangramXmlParse* pNode = pWndNode->GetChild(_T("node"));
	if (pNode == nullptr)
	{
		delete m_pParse;
		return nullptr;
	}

	HWND m_hHostMain = (HWND)hWnd;
	CCompositor* _pCompositor = m_pCompositor;
	CWnd* pWnd = CWnd::FromHandle(m_hHostMain);
	if (pWnd)
	{
		::GetClassName(m_hHostMain, g_pTangram->m_szBuffer, MAX_PATH);
		CString strName = CString(g_pTangram->m_szBuffer);
		if (strName.Find(_T("AfxMDIClientCompositor")) == 0)
			pWnd->ModifyStyle(0, WS_CLIPSIBLINGS);
		else
			pWnd->ModifyStyle(0, WS_CLIPSIBLINGS | WS_CLIPCHILDREN);

		_pCompositor->m_bChromeFrame = strName == _T("Chrome Extended Window Class");
	}

	CWndNode *pRootNode = nullptr;
	m_pCompositorManager = nullptr;
	pRootNode = _pCompositor->OpenXtmlDocument(m_pParse, m_strCurrentKey, strXml);
	m_strCurrentKey = _T("");
	if (pRootNode != nullptr)
	{
		if (bSizable)
		{
			HWND hParent = ::GetParent(pRootNode->m_pHostWnd->m_hWnd);
			CWindow m_wnd;
			m_wnd.Attach(hParent);
			if ((m_wnd.GetStyle() | WS_CHILD) == 0)
			{
				m_wnd.ModifyStyle(0, WS_SIZEBOX | WS_BORDER | WS_MINIMIZEBOX | WS_MAXIMIZEBOX);
			}
			m_wnd.Detach();
			::PostMessage(hParent, WM_TANGRAMMSG, 0, 1965);
		}
	}
	return pRootNode;
}

STDMETHODIMP CTangram::put_Application(IDispatch* newVal)
{
	if (m_pAppDisp == nullptr)
	{
		m_pAppDisp = newVal;
		m_pAppDisp->AddRef();
		return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CTangram::get_ActiveChromeBrowserWnd(IChromeWebBrowser** ppChromeWebBrowser) 
{
	ITangram* pTangram = nullptr;
	get_RemoteTangram(CComBSTR("chromeplus.tangram"), &pTangram);
	if (pTangram)
	{
		CComPtr<IChromeWebBrowser> pBrowser;
		pTangram->get_ActiveChromeBrowserWnd(&pBrowser);
		if (pBrowser)
		{
			*ppChromeWebBrowser = pBrowser.Detach();
			return S_OK;
		}
	}
	if (m_pActiveBrowser->m_pProxy)
	{
		CBrowserWnd* pCBrowserWnd = (CBrowserWnd*)m_pActiveBrowser->m_pProxy;
		pCBrowserWnd->QueryInterface(__uuidof(IChromeWebBrowser), (void**)ppChromeWebBrowser);
	}
	return S_OK;
}

STDMETHODIMP CTangram::get_HostChromeBrowserWnd(IChromeWebBrowser** ppChromeWebBrowser) 
{
	if (::GetModuleHandle(L"chrome_elf.dll"))
	{
		auto it = g_pTangram->m_mapBrowserWnd.find(m_hHostBrowserWnd);
		if (it != g_pTangram->m_mapBrowserWnd.end())
		{
			*ppChromeWebBrowser = it->second;
		}
	}
	return S_OK;
}

STDMETHODIMP CTangram::get_RootNodes(IWndNodeCollection** pNodeColletion)
{
	if (m_pRootNodes == nullptr)
	{
		CComObject<CWndNodeCollection>::CreateInstance(&m_pRootNodes);
		m_pRootNodes->AddRef();
	}

	m_pRootNodes->m_pNodes->clear();

	for (auto& it : m_mapWindowPage)
	{
		CCompositorManager* pCompositor = (CCompositorManager*)it.second;
		for (auto fit : pCompositor->m_mapCompositor)
		{
			CCompositor* pCompositor = fit.second;
			for (auto it : pCompositor->m_mapNode)
			{
				m_pRootNodes->m_pNodes->push_back(it.second);
			}
		}
	}
	return m_pRootNodes->QueryInterface(IID_IWndNodeCollection, (void**)pNodeColletion);
}

STDMETHODIMP CTangram::get_CurrentActiveNode(IWndNode** pVal)
{
	if (m_pActiveNode)
		*pVal = m_pActiveNode;

	return S_OK;
}

STDMETHODIMP CTangram::SetHostFocus(void)
{
	m_pCompositor = nullptr;
	return S_OK;
}

STDMETHODIMP CTangram::CreateCLRObj(BSTR bstrObjID, IDispatch** ppDisp)
{
	CString strID = OLE2T(bstrObjID);
	strID.Trim();
	strID.MakeLower();
	int nPos = strID.Find(_T("@"));
	if (nPos != -1)
	{
		CString strAppID = strID.Mid(nPos + 1);
		if (strAppID != _T(""))
		{
			ITangram* pRemoteTangram = nullptr;
			auto it = m_mapRemoteTangramCore.find(strAppID);
			if (it == m_mapRemoteTangramCore.end())
			{
				CComPtr<IDispatch> pApp;
				pApp.CoCreateInstance(CComBSTR(strAppID), nullptr, CLSCTX_LOCAL_SERVER | CLSCTX_INPROC_SERVER);
				if (pApp)
				{
					int nPos = m_strOfficeAppIDs.Find(strAppID);
					if (nPos != -1)
					{
						CString str = m_strOfficeAppIDs.Left(nPos);
						CComPtr<Office::COMAddIns> pAddins;
						int nIndex = str.Replace(_T(","), _T(""));
						switch (nIndex)
						{
						case 0:
						{
							CComQIPtr<Word::_Application> pWordApp(pApp);
							if (pWordApp)
							{
								pWordApp->put_Visible(true);
								pWordApp->get_COMAddIns(&pAddins);
							}
						}
						break;
						case 1:
						{
							CComQIPtr<Excel::_Application> pExcelApp(pApp);
							pExcelApp->put_UserControl(true);
							pExcelApp->get_COMAddIns(&pAddins);
							pExcelApp->put_Visible(0, true);
						}
						break;
						case 2:
						{
							CComQIPtr<OutLook::_Application> pOutLookApp(pApp);
							pOutLookApp->get_COMAddIns(&pAddins);
						}
						break;
						case 3:
						{
							//CComQIPtr<OneNote::_Application> pOneNoteApp(pApp);
							//pOneNoteApp->get_COMAddIns(&pAddins);
						}
						break;
						case 4:
						{
							//CComQIPtr<OneNote::_Application> pOneNoteApp(pApp);
							//pOneNoteApp->get_COMAddIns(&pAddins);
						}
						break;
						case 5:
						{
							CComQIPtr<MSProject::_MSProject> pProjectApp(pApp);
							//pProjectApp->get_COMAddIns(&pAddins);
						}
						break;
						case 6:
						{
							//CComQIPtr<OneNote::_Application> pOneNoteApp(pApp);
							//pOneNoteApp->get_COMAddIns(&pAddins);
						}
						break;
						case 7:
						{
							//CComQIPtr<OneNote::_Application> pOneNoteApp(pApp);
							//pOneNoteApp->get_COMAddIns(&pAddins);
						}
						break;
						case 8:
						{
							CComQIPtr<PowerPoint::_Application> pPptApp(pApp);
							pPptApp->get_COMAddIns(&pAddins);
							pPptApp->put_Visible(Office::MsoTriState::msoTrue);
							//IDispatch* pDisp = pApp.Detach();
							//pDisp->Release();
							//pPptApp.Detach();
						}
						break;
						case 9:
						{
						}
						break;
						default:
							break;
						}

						if (pAddins)
						{
							CComPtr<Office::COMAddIn> pAddin;
							pAddins->Item(&CComVariant(_T("tangram.tangram")), &pAddin);
							if (pAddin)
							{
								CComPtr<IDispatch> pAddin2;
								pAddin->get_Object(&pAddin2);
								CComQIPtr<ITangram> _pTangramAddin(pAddin2);
								if (_pTangramAddin)
								{
									pRemoteTangram = _pTangramAddin.p;
									if (::GetModuleHandle(_T("TangramPackage.dll")))
										_pTangramAddin->put_AppKeyValue(CComBSTR(L"fromvisualstudio"), CComVariant((VARIANT_BOOL)true));
									m_mapRemoteTangramCore[strAppID] = _pTangramAddin.p;
									_pTangramAddin.p->AddRef();
									LONGLONG h = 0;
									_pTangramAddin->get_RemoteHelperHWND(&h);
									if (h)
									{
										HWND hWnd = (HWND)h;
										CHelperWnd* pWnd = new CHelperWnd();
										pWnd->m_strID = strAppID;
										pWnd->Create(hWnd, 0, _T(""), WS_CHILD);
										m_mapRemoteTangramHelperWnd[strAppID] = pWnd;
									}
								}
							}
						}
					}
					else 
					{
						pApp->QueryInterface(IID_ITangram, (void**)&pRemoteTangram);
						if (pRemoteTangram)
						{
							pRemoteTangram->AddRef();
							m_mapRemoteTangramCore[strAppID] = pRemoteTangram;
							LONGLONG h = 0;
							pRemoteTangram->get_RemoteHelperHWND(&h);
							HWND hWnd = (HWND)h;
							if (::IsWindow(hWnd))
							{
								CHelperWnd* pWnd = new CHelperWnd();
								pWnd->m_strID = strAppID;
								pWnd->Create(hWnd, 0, strAppID, WS_VISIBLE | WS_CHILD);
								m_mapRemoteTangramHelperWnd[strAppID] = pWnd;
							}
						}
						else
						{
							DISPID dispID = 0;
							DISPPARAMS dispParams = { NULL, NULL, 0, 0 };
							VARIANT result = { 0 };
							EXCEPINFO excepInfo;
							memset(&excepInfo, 0, sizeof excepInfo);
							UINT nArgErr = (UINT)-1; // initialize to invalid arg
							LPOLESTR func = L"Tangram";
							HRESULT hr = pApp->GetIDsOfNames(GUID_NULL, &func, 1, LOCALE_SYSTEM_DEFAULT, &dispID);
							if (S_OK == hr)
							{
								hr = pApp->Invoke(dispID, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &dispParams, &result, &excepInfo, &nArgErr);
								if (S_OK == hr && VT_DISPATCH == result.vt&&result.pdispVal)
								{
									result.pdispVal->QueryInterface(IID_ITangram, (void**)&pRemoteTangram);
									if (pRemoteTangram)
									{
										pRemoteTangram->AddRef();
										m_mapRemoteTangramCore[strAppID] = pRemoteTangram;

										LONGLONG h = 0;
										pRemoteTangram->get_RemoteHelperHWND(&h);
										HWND hWnd = (HWND)h;
										if (::IsWindow(hWnd))
										{
											CHelperWnd* pWnd = new CHelperWnd();
											pWnd->m_strID = strAppID;
											pWnd->Create(hWnd, 0, _T(""), WS_CHILD);
											m_mapRemoteTangramHelperWnd[strAppID] = pWnd;
											m_mapAppDispDic[strAppID] = pApp.Detach();
										}
										::VariantClear(&result);
									}
								}
							}
						}
					}
				}
			}
			else
			{
				pRemoteTangram = it->second;
			}
			if (pRemoteTangram)
			{
				strID = strID.Left(nPos);
				return pRemoteTangram->CreateCLRObj(CComBSTR(strID), ppDisp);
			}
		}
	}
	
	nPos = strID.Find(_T(","));
	if (nPos!=-1||strID.CompareNoCase(_T("chromert"))==0)
	{
		LoadCLR();

		if (m_pCLRProxy&&bstrObjID != L"")
		{
			*ppDisp = m_pCLRProxy->CreateCLRObj(OLE2T(bstrObjID));
			if (*ppDisp)
				(*ppDisp)->AddRef();
		}
	}
	else
	{
		CComPtr<IDispatch> pDisp;
		pDisp.CoCreateInstance(CComBSTR(strID));
		*ppDisp = pDisp.Detach();
		if (*ppDisp)
		{
			(*ppDisp)->AddRef();
			return S_OK;
		}
		else
			return S_FALSE;
	}
	return S_OK;
}

STDMETHODIMP CTangram::get_CreatingNode(IWndNode** pVal)
{
	if (m_pActiveNode)
		*pVal = m_pActiveNode;

	return S_OK;
}

STDMETHODIMP CTangram::get_DesignNode(IWndNode** pVal)
{
	if (m_pDesignWindowNode)
		(*pVal) = (IWndNode*)m_pDesignWindowNode;
	return S_OK;
}

CString CTangram::EncodeFileToBase64(CString strSRC)
{
	DWORD dwDesiredAccess = GENERIC_READ;
	DWORD dwShareMode = FILE_SHARE_READ;
	DWORD dwFlagsAndAttributes = FILE_ATTRIBUTE_NORMAL;
	HANDLE hFile = ::CreateFile(strSRC, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_RANDOM_ACCESS, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		TRACE(_T("ERROR: CreateFile failed - %s\n"), strSRC);
		return _T("");
	}
	else
	{
		DWORD dwFileSizeHigh = 0;
		__int64 qwFileSize = GetFileSize(hFile, &dwFileSizeHigh);
		qwFileSize |= (((__int64)dwFileSizeHigh) << 32);
		DWORD dwFileSize = qwFileSize;
		if ((dwFileSize == 0) || (dwFileSize == INVALID_FILE_SIZE))
		{
			TRACE(_T("ERROR: GetFileSize failed - %s\n"), strSRC);
			CloseHandle(hFile);
			return _T("");
		}
		else
		{
			BYTE* buffer = new BYTE[dwFileSize];
			memset(buffer, 0, (dwFileSize) * sizeof(BYTE));
			DWORD dwBytesRead = 0;
			if (!ReadFile(hFile, buffer, dwFileSize, &dwBytesRead, NULL))
			{
				TRACE(_T("ERROR: ReadFile failed - %s\n"), strSRC);
				CloseHandle(hFile);
			}
			else
			{
				int nMaxLineLen = dwFileSize * 2;
				char *pDstInfo = new char[nMaxLineLen];
				memset(pDstInfo, 0, dwFileSize * 2);
				Base64Encode(buffer, dwFileSize, pDstInfo, &nMaxLineLen, 0);
				CString strInfo = CA2W(pDstInfo);
				delete[] pDstInfo;
				delete[] buffer;
				CloseHandle(hFile);
				return strInfo;
			}
		}
	}

	return _T("");
}

CString CTangram::Encode(CString strSRC, BOOL bEnCode)
{
	if (bEnCode)
	{
		LPCWSTR srcInfo = strSRC;
		std::string strSrc = (LPCSTR)CW2A(srcInfo, CP_UTF8);
		int nSrcLen = strSrc.length();
		int nDstLen = Base64EncodeGetRequiredLength(nSrcLen);
		char *pDstInfo = new char[nSrcLen * 2];
		memset(pDstInfo, 0, nSrcLen * 2);
		ATL::Base64Encode((BYTE*)strSrc.c_str(), nSrcLen, pDstInfo, &nDstLen);
		CString strInfo = CA2W(pDstInfo);
		delete[] pDstInfo;
		return strInfo;
	}
	else
	{
		long nSrcSize = strSRC.GetLength();
		BYTE *pDecodeStr = new BYTE[nSrcSize];
		memset(pDecodeStr, 0, nSrcSize);
		int nLen = nSrcSize;
		ATL::Base64Decode(CW2A(strSRC), nSrcSize, pDecodeStr, &nLen);
		////直接在内存里面构建CIMAGE,需要使用IStream接口,如何使用
		////构建内存环境 
		//HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, nLen); 
		//void * pData = GlobalLock(hGlobal); 
		//memcpy(pData, pDecodeStr, nLen); 
		//// 拷贝位图数据进去 
		//GlobalUnlock(hGlobal); 
		//// 创建IStream 
		//IStream * pStream = NULL; 
		//if (CreateStreamOnHGlobal(hGlobal, TRUE, &pStream) != S_OK) 
		//	return _T(""); 
		//// 使用CImage加载位图内存 
		//CImage img; 
		//if (SUCCEEDED(img.Load(pStream)) ) 
		//{ 
		//	//CClientDC dc(this);
		//	////使用内在中构造的图像 直接在对话框上绘图 
		//	//img.Draw(dc.m_hDC, 0, 0, 500, 300); 
		//} 
		////释放内存
		//pStream->Release(); 
		//GlobalFree(hGlobal); 
		CString str = CA2W((char*)pDecodeStr, CP_UTF8);
		delete[] pDecodeStr;
		pDecodeStr = NULL;
		return str;
	}
}

CString	CTangram::BuildSipURICodeStr(CString strURI, CString strPrev, CString strFix, CString strData, int n1)
{
	CString strGUID = GetNewGUID();
	CString strHelp1 = _T("");
	CString strHelp2 = _T("");
	int nPos = strGUID.Find(_T("-"));
	strHelp1 = strGUID.Left(nPos);
	nPos = strGUID.ReverseFind('-');
	strHelp2 = strGUID.Mid(nPos + 1);
	CString strTime = _T("");
	CString strTime2 = _T("");
	if (strData == _T(""))
	{
		CTime startTime = CTime::GetCurrentTime();
		strTime.Format(_T("%d-%d-%d"), startTime.GetYear(), startTime.GetMonth(), startTime.GetDay());
		strTime2.Format(_T("%02d:%02d:%02d"), startTime.GetHour(), startTime.GetMinute(), startTime.GetSecond());
	}
	else
	{
		nPos = strData.Find(_T(" "));
		strTime = strData.Left(nPos);
		strTime2 = strData.Mid(nPos + 1);
	}
	int n2 = (rand() + 100) % 7 + 2;
	CString strRet = _T("");
	if (strURI != _T("") && strPrev != _T("") && strFix != _T(""))
	{
		int nPos = strURI.Find(_T("@"));
		if (nPos != -1)
		{
			CString s = _T("");
			s.Format(_T("%s%s%s%s%s%s%s%s"), strHelp1, strTime2, strPrev, strURI.Left(nPos), strHelp2, strTime, strFix, strURI.Mid(nPos));
			CString s1 = Encode(s, true);
			s1.Replace(_T("\r\n"), _T(""));
			int n = n1 * 10 + n2;
			int m = (n2 * 2) % 7 + 2;
			strGUID = GetNewGUID();
			strGUID.Replace(_T("-"), _T(""));
			strGUID = strGUID.Left(m);
			strRet.Format(_T("%s%d%s%d"), strGUID, n1, s1, n2);

			int nLen = strRet.GetLength();
			CString str = _T("");
			int nLen1 = nLen;
			while (nLen1)
			{
				nLen1 -= n;
				strGUID = GetNewGUID();
				strGUID.Replace(_T("-"), _T(""));
				if (nLen1)
					strGUID = strGUID.Left(m);
				str += strRet.Left(n);
				str += strGUID;
				strRet = strRet.Mid(n);
				if ((nLen1 < n) && nLen1)
				{
					str += strRet;
					strGUID = GetNewGUID();
					strGUID.Replace(_T("-"), _T(""));
					str += strGUID.Left(17);
					nLen1 = 0;
				}
			}
			strRet = str.MakeReverse();
			nPos = strRet.Find(_T("="));
			if (nPos != -1)
			{
				strGUID = GetNewGUID();
				strGUID.Replace(_T("-"), _T(""));
				CString strGUID2 = GetNewGUID();
				strGUID2.Replace(_T("-"), _T(""));
				strRet.Replace(_T("="), strGUID);
				strRet = strGUID.MakeReverse() + strGUID2.Left(13) + strRet;
			}
		}
	}
	return strRet;
}

CString CTangram::tangram_for_eclipse(CString strKey, CString strData, CString strFeatures)
{
	return _T("");
}

CString	CTangram::GetDataFromStr(CString strCoded, CString& strTime, CString strPrev, CString strFix, int n1)
{
	CString strRet = _T("");
	if (strCoded != _T(""))
	{
		CString strKey = strCoded.Left(32);
		CString strX = strCoded;
		int nCount = strX.Replace(strKey.MakeReverse(), _T("="));
		if (nCount == 1)
		{
			strCoded = strX.Mid(32 + 13);
		}
		strCoded = strCoded.MakeReverse();
		int nLen = strCoded.GetLength();
		strRet = strCoded.Left(nLen - 17);
		CString s1 = strRet.Mid(nLen - 18);
		strRet = strCoded.Left(nLen - 18);
		int n2 = _wtoi(s1);
		int n = n1 * 10 + n2;
		int m = (n2 * 2) % 7 + 2;
		nLen = strCoded.GetLength();
		int nIndex = -1;
		CString str = _T("");
		while (nLen)
		{
			str += strRet.Left(n);
			if (nLen >= m)
			{
				strRet = strRet.Mid(n + m);
				nLen = strRet.GetLength();
			}
			else
			{
				nLen = 0;
			}
		}
		strRet = str;
		strRet = strRet.Mid(m + 1);
		strRet = Encode(strRet, false);
		strRet = strRet.MakeReverse();
		strRet.Replace(strPrev, _T(""));
		strRet.Replace(strFix, _T(""));
		strRet = strRet.Mid(8);
		CString strTime1 = strRet.Left(8);
		strRet = strRet.Mid(8);
		int nPos = strRet.Find(_T("@"));
		CString strSip2 = strRet.Mid(nPos);
		strRet = strRet.Left(nPos);
		CString strTime2 = strRet.Mid(strRet.GetLength() - 10);
		strRet = strRet.Left(strRet.GetLength() - 22);
		strRet += strSip2;
		strTime2 += _T(" ");
		strTime2 += strTime1;
		strTime = strTime2;
	}
	return strRet;
}

STDMETHODIMP CTangram::Encode(BSTR bstrSRC, VARIANT_BOOL bEncode, BSTR* bstrRet)
{
	CString strSRC = OLE2T(bstrSRC);
	strSRC.Trim();
	if (::PathFileExists(strSRC))
		strSRC = EncodeFileToBase64(strSRC);
	else if (strSRC != _T(""))
		strSRC = Encode(strSRC, bEncode ? true : false);
	::SysFreeString(bstrSRC);
	if (bstrRet != nullptr)
		::SysFreeString(*bstrRet);
	*bstrRet = strSRC.AllocSysString();
	return S_OK;
}

STDMETHODIMP CTangram::get_Application(IDispatch** pVal)
{
	if (m_pAppDisp)
	{
		*pVal = m_pAppDisp;
		(*pVal)->AddRef();
	}
	return S_OK;
}

STDMETHODIMP CTangram::get_AppExtender(BSTR bstrKey, IDispatch** pVal)
{
	CString strName = OLE2T(bstrKey);
	strName.MakeLower();
	if (strName != _T(""))
	{
		auto it = m_mapObjDic.find(strName);
		if (it == m_mapObjDic.end())
			return S_OK;
		else {
			*pVal = it->second;
			(*pVal)->AddRef();
		}
	}

	return S_OK;
}

STDMETHODIMP CTangram::put_AppExtender(BSTR bstrKey, IDispatch* newVal)
{
	CString strName = OLE2T(bstrKey);
	strName.Trim();
	strName.MakeLower();
	CString strKey = _T(",");
	strKey += strName;
	strKey += _T(",");
	if (strName != _T(""))
	{
		auto it = m_mapObjDic.find(strName);
		if (it != m_mapObjDic.end())
		{
			m_mapObjDic.erase(it);
			m_strExcludeAppExtenderIDs.Replace(strKey, _T(""));
		}
		if (newVal != nullptr)
		{
			if (strName.CompareNoCase(_T("HostViewNode")) == 0)
			{
				CComQIPtr<IWndNode> pNode(newVal);
				if (pNode)
					m_pHostViewDesignerNode = pNode.Detach();
				return S_OK;
			}
			m_mapObjDic[strName] = newVal;
			newVal->AddRef();
			void* pDisp = nullptr;
			if (newVal->QueryInterface(IID_IWndNode, (void**)&pDisp) == S_OK
				|| newVal->QueryInterface(IID_ICompositor, (void**)&pDisp) == S_OK
				|| newVal->QueryInterface(IID_ICompositorManager, (void**)&pDisp) == S_OK)
			{
				if (m_strExcludeAppExtenderIDs.Find(strKey) == -1)
				{
					m_strExcludeAppExtenderIDs += strKey;
				}
			}
		}

#ifndef _WIN64
		if (strName.CompareNoCase(_T("DTE")) == 0)
		{
			VisualStudioPlus::CVSAddin* pAddin = (VisualStudioPlus::CVSAddin*)this;
			CComQIPtr<VxDTE::_DTE> pDTE(newVal);
			pAddin->m_pDTE = pDTE.p;
			pAddin->m_pDTE->AddRef();
			pAddin->OnInitInstance();
		}
#endif
	}
	return S_OK;
}

STDMETHODIMP CTangram::get_RemoteHelperHWND(LONGLONG* pVal)
{
	if (::IsWindow(m_hHostWnd) == false)
	{
		m_hHostWnd = ::CreateWindowEx(WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW, _T("Tangram Window Class"), m_strDesignerToolBarCaption, WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, 0, 0, 0, 0, NULL, NULL, theApp.m_hInstance, NULL);
		if (::IsWindow(m_hHostWnd))
			m_hChildHostWnd = ::CreateWindowEx(NULL, _T("Tangram Window Class"), _T(""), WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE | WS_CHILD, 0, 0, 0, 0, m_hHostWnd, NULL, theApp.m_hInstance, NULL);
	}
	*pVal = (LONGLONG)m_hHostWnd;
	return S_OK;
}

STDMETHODIMP CTangram::get_DocTemplate(BSTR bstrKey, LONGLONG* pVal)
{
	CString strKey = OLE2T(bstrKey);
	strKey.MakeLower();
	auto it = m_mapTemplateInfo.find(strKey);
	if (it != m_mapTemplateInfo.end())
		*pVal = (LONGLONG)it->second;
	return S_OK;
}

void CTangram::InitDesignerTreeCtrl(CString strXml)
{
	if (strXml != _T("") && m_pDocDOMTree)
	{
		m_pDocDOMTree->m_pHostXmlParse = new CTangramXmlParse();
		m_pDocDOMTree->m_pHostXmlParse->LoadXml(strXml);
		m_pDocDOMTree->m_hFirstRoot = m_pDocDOMTree->LoadXmlFromXmlParse(m_pDocDOMTree->m_pHostXmlParse);
		m_pDocDOMTree->ExpandAll();
	}
}

STDMETHODIMP CTangram::get_AppKeyValue(BSTR bstrKey, VARIANT* pVal)
{
	CString strKey = OLE2T(bstrKey);
	if (strKey != _T(""))
	{
		strKey.Trim();
		strKey.MakeLower();
		if (strKey == _T("tangramproxy"))
		{
			(*pVal).vt = VT_I8;
			(*pVal).llVal = (__int64)(CTangramImpl*)this;
			return S_OK;
		}
		if (strKey == _T("tangramobjcount"))
		{
			(*pVal).vt = VT_I4;
			(*pVal).lVal = (long)m_nTangramObj;
			return S_OK;
		}
		if (strKey == _T("tangrammsgwnd"))
		{
			(*pVal).vt = VT_I8;
			(*pVal).llVal = (LONGLONG)m_hTangramWnd;
			return S_OK;
		}
		if (strKey == _T("eclipseapp"))
		{
			*pVal = CComVariant((bool)m_bEclipse);
			return S_OK;
		}
		if (strKey == _T("clrproxy"))
		{
			(*pVal).vt = VT_I8;
			(*pVal).llVal = (__int64)m_pCLRProxy;
			return S_OK;
		}

		if (strKey == _T("toolboxxml"))
		{
			(*pVal).vt = VT_BSTR;
			pVal->bstrVal = CComBSTR(m_strDesignerXml);
			return S_OK;
		}
		auto it = m_mapValInfo.find(strKey);
		if (it != m_mapValInfo.end())
		{
			*pVal = CComVariant(it->second);
			return S_OK;
		}
	}
	return S_FALSE;
}

STDMETHODIMP CTangram::put_AppKeyValue(BSTR bstrKey, VARIANT newVal)
{
	CString strKey = OLE2T(bstrKey);

	if (strKey == _T(""))
		return S_OK;
	strKey.Trim();
	strKey.MakeLower();

	auto it = m_mapValInfo.find(strKey);
	if (it != m_mapValInfo.end())
	{
		::VariantClear(&it->second);
		m_mapValInfo.erase(it);
	}
	if (newVal.vt == VT_BSTR)
	{
		CString strData = OLE2T(newVal.bstrVal);
		strData = strData.Trim();
		if (strKey == _T("tangramctrlappid") && strData != _T(""))
		{
			m_strCurrentAppID = strData;
		}
		if (strKey == _T("appname") && strData != _T(""))
		{
			m_strAppName = strData;
			::VariantClear(&newVal);
			return S_OK;
		}
		if (strKey == _T("currentdocdata"))
		{
			if (m_pMDIMainWnd)
			{
				m_pMDIMainWnd->OnCreateDoc(strData);
				return S_OK;
			}
			else if (m_pActiveMDIChildWnd)
			{
				m_pActiveMDIChildWnd->OnCreateDoc(strData);
				return S_OK;
			}
		}
		if (strKey == _T("defaulttemplate") && strData != _T(""))
		{
			m_strDefaultTemplate = strData;
			return S_OK;
		}
		if (strKey == _T("defaulttemplate2") && strData != _T(""))
		{
			m_strDefaultTemplate2 = strData;
			return S_OK;
		}
		if (strKey == _T("designertoolcaption") && strData != _T("") && ::IsWindow(m_hHostWnd))
		{
			::SetWindowText(m_hHostWnd, strData);
		}
		if (strKey == _T("newtangramdocument"))
		{
			m_strNewDocXml = strData;
			return S_OK;
		}
	}

	if (strKey.CompareNoCase(_T("CLRProxy")) == 0)
	{
		if (newVal.llVal == 0&& m_pCLRProxy)
		{
			for (auto it : m_mapThreadInfo)
			{
				if (it.second->m_hGetMessageHook)
				{
					UnhookWindowsHookEx(it.second->m_hGetMessageHook);
					it.second->m_hGetMessageHook = NULL;
				}
				delete it.second;
			}
			m_mapThreadInfo.erase(m_mapThreadInfo.begin(), m_mapThreadInfo.end());
			if (m_mapTangramEvent.size())
			{
				auto it = m_mapTangramEvent.begin();
				for (it = m_mapTangramEvent.begin(); it != m_mapTangramEvent.end(); it++)
				{
					delete it->second;
				}
				m_mapTangramEvent.clear();
			}

			m_pCLRProxy = nullptr;

			if (::IsWindow(m_hHostWnd))
			{
				::DestroyWindow(m_hHostWnd);
				m_hHostWnd = NULL;
			}

			if (m_hCBTHook)
				UnhookWindowsHookEx(m_hCBTHook);
			if (m_hForegroundIdleHook)
				UnhookWindowsHookEx(m_hForegroundIdleHook);
			_clearObjects();
			m_pTangramCLRAppProxy = nullptr;
		}
		return S_OK;
	}
	if (strKey.CompareNoCase(_T("CurrentDesignerInfo")) == 0)
	{
		if (m_pDesignWindowNode)
		{
			m_strDesignerInfo = OLE2T(newVal.bstrVal);
			m_pDesignWindowNode->m_pHostWnd->Invalidate();
		}
		return S_OK;
	}
	if (strKey.CompareNoCase(_T("usingdefaultappdoctemplate")) == 0)
	{
		if (newVal.vt == VT_BOOL)
		{
			m_bUsingDefaultAppDocTemplate = newVal.boolVal;
		}
		return S_OK;
	}
	if (strKey.CompareNoCase(_T("StartData")) == 0)
	{
		m_strCurrentEclipsePagePath = OLE2T(newVal.bstrVal);
		if (m_mapWorkBenchWnd.size())
		{
			CComPtr<IWorkBenchWindow> pWorkBenchWindow;
			NewWorkBench(newVal.bstrVal, &pWorkBenchWindow);
		}
		return S_OK;
	}
	if (strKey.CompareNoCase(_T("unloadclr")) == 0)
	{
		if (m_pClrHost&&m_nAppID == -1 && theApp.m_bHostCLR == false)
		{
			if (m_hCBTHook)
			{
				UnhookWindowsHookEx(m_hCBTHook);
				m_hCBTHook = nullptr;
			}
			DWORD dw = m_pClrHost->Release();
			ASSERT(dw == 0);
			if (dw == 0)
			{
				m_pClrHost = nullptr;
				m_pCLRProxy = nullptr;
				OutputDebugString(_T("------------------ClrHost Release Successed!------------------------\n"));
			}
			OutputDebugString(_T("------------------End Stop CLR------------------------\n"));
		}
		return S_OK;
	}

	m_mapValInfo[strKey] = newVal;
	if (strKey.CompareNoCase(_T("EnableProcessFormTabKey")) == 0)
	{
		m_bEnableProcessFormTabKey = (newVal.vt == VT_I4 && newVal.lVal == 0) ? false : true;
	}

	return S_OK;
}

STDMETHODIMP CTangram::NavigateNode(IWndNode* pNode, BSTR bstrBrowserID, BSTR bstrXnl)
{
	return S_OK;
}

STDMETHODIMP CTangram::MessageBox(LONGLONG hWnd, BSTR bstrContext, BSTR bstrCaption, long nStyle, int* nRet)
{
	*nRet = ::MessageBox((HWND)hWnd, OLE2T(bstrContext), OLE2T(bstrCaption), nStyle);
	return S_OK;
}

CString CTangram::GetNewGUID()
{
	GUID   m_guid;
	CString   strGUID = _T("");
	if (S_OK == ::CoCreateGuid(&m_guid))
	{
		strGUID.Format(_T("%08X-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X"),
			m_guid.Data1, m_guid.Data2, m_guid.Data3,
			m_guid.Data4[0], m_guid.Data4[1],
			m_guid.Data4[2], m_guid.Data4[3],
			m_guid.Data4[4], m_guid.Data4[5],
			m_guid.Data4[6], m_guid.Data4[7]);
	}

	return strGUID;
}

CString CTangram::GetPropertyFromObject(IDispatch* pObj, CString strPropertyName)
{
	CString strRet = _T("");
	if (pObj)
	{
		//ITypeLib* pTypeLib = nullptr;
		//ITypeInfo* pTypeInfo = nullptr;
		//pObj->GetTypeInfo(0, 0, &pTypeInfo);
		//if (pTypeInfo)
		//{
		//	pTypeInfo->GetContainingTypeLib(&pTypeLib, 0);
		//	pTypeInfo->Release();
		//	pTypeLib->Release();
		//}

		BSTR szMember = strPropertyName.AllocSysString();
		DISPID dispid = -1;
		HRESULT hr = pObj->GetIDsOfNames(IID_NULL, &szMember, 1, LOCALE_USER_DEFAULT, &dispid);
		if (hr == S_OK)
		{
			DISPPARAMS dispParams = { NULL, NULL, 0, 0 };
			VARIANT result = { 0 };
			EXCEPINFO excepInfo;
			memset(&excepInfo, 0, sizeof excepInfo);
			UINT nArgErr = (UINT)-1;
			HRESULT hr = pObj->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &dispParams, &result, &excepInfo, &nArgErr);
			if (S_OK == hr && VT_BSTR == result.vt)
			{
				strRet = OLE2T(result.bstrVal);
			}
			::VariantClear(&result);
		}
	}
	return strRet;
}

STDMETHODIMP CTangram::NewGUID(BSTR* retVal)
{
	*retVal = GetNewGUID().AllocSysString();
	return S_OK;
}

STDMETHODIMP CTangram::LoadDocComponent(BSTR bstrLib, LONGLONG* llAppProxy)
{
	CString strLib = OLE2T(bstrLib);
	strLib.Trim();
	strLib.MakeLower();
	BOOL bOK = FALSE;
	if (strLib == _T("") || strLib.CompareNoCase(_T("default")) == 0)
	{
		*llAppProxy = (LONGLONG)m_pTangramAppProxy;
		return S_OK;
	}
	auto it = m_mapValInfo.find(strLib);
	if (it == m_mapValInfo.end())
	{
		CString strPath = m_strAppCommonDocPath + strLib + _T(".xml");
		CString strPath2 = m_strAppCommonDocPath2 + strLib + _T("\\");
		CTangramXmlParse m_Parse;
		if (m_Parse.LoadFile(strPath))
		{
			strPath2 += m_Parse.attr(_T("LibName"), _T(""));
			strPath2 += _T(".dll");
			if (::PathFileExists(strPath2) && ::LoadLibrary(strPath2))
				bOK = TRUE;
		}
		if (bOK)
		{
			if (m_hForegroundIdleHook == NULL)
				m_hForegroundIdleHook = SetWindowsHookEx(WH_FOREGROUNDIDLE, CTangramApp::ForegroundIdleProc, NULL, ::GetCurrentThreadId());
			auto it = m_mapValInfo.find(strLib);
			if (it != m_mapValInfo.end())
			{
				LONGLONG llProxy = it->second.llVal;
				*llAppProxy = llProxy;
				m_mapTangramAppProxy[strLib] = (ITangramAppProxy*)llProxy;
			}
			return S_OK;
		}
	}
	else
	{
		if (it->second.vt == VT_I8)
			*llAppProxy = it->second.llVal;
	}
	return S_OK;
}

STDMETHODIMP CTangram::TangramGetObject(IDispatch* SourceDisp, IDispatch** ResultDisp)
{
	IStream* pStream = 0;
	HRESULT hr = ::CoMarshalInterThreadInterfaceInStream(IID_IDispatch, SourceDisp, &pStream);
	if (hr == S_OK)
	{
		IDispatch* pEventTarget = nullptr;
		hr = ::CoGetInterfaceAndReleaseStream(pStream, IID_IDispatch, (LPVOID *)&pEventTarget);
		if (hr == S_OK && pEventTarget)
		{
			*ResultDisp = pEventTarget;
		}
	}
	return S_OK;
}

STDMETHODIMP CTangram::GetCLRControl(IDispatch* CtrlDisp, BSTR bstrNames, IDispatch** ppRetDisp)
{
	CString strNames = OLE2T(bstrNames);
	if (m_pCLRProxy&&strNames != _T("") && CtrlDisp)
		*ppRetDisp = m_pCLRProxy->GetCLRControl(CtrlDisp, bstrNames);

	return S_OK;
}

STDMETHODIMP CTangram::ActiveCLRMethod(BSTR bstrObjID, BSTR bstrMethod, BSTR bstrParam, BSTR bstrData)
{
	LoadCLR();

	if (m_pCLRProxy)
		m_pCLRProxy->ActiveCLRMethod(bstrObjID, bstrMethod, bstrParam, bstrData);

	return S_OK;
}

STDMETHODIMP CTangram::CreateCompositorManager(LONGLONG hWnd, ICompositorManager** ppCompositorManager)
{
	HWND _hWnd = (HWND)hWnd;
	if (::IsWindow(_hWnd))
	{
		CCompositorManager* pCompositorManager = nullptr;
		auto it = m_mapWindowPage.find(_hWnd);
		if (it != m_mapWindowPage.end())
			pCompositorManager = (CCompositorManager*)it->second;
		else
		{
			pCompositorManager = new CComObject<CCompositorManager>();
			pCompositorManager->m_hWnd = _hWnd;
			m_mapWindowPage[_hWnd] = pCompositorManager;

			for (auto it : g_pTangram->m_mapTangramAppProxy)
			{
				CCompositorManagerProxy* pTangramProxy = it.second->OnCompositorManagerCreated(pCompositorManager);
				if (pTangramProxy)
					pCompositorManager->m_mapCompositorManagerProxy[it.second] = pTangramProxy;
			}
		}
		*ppCompositorManager = pCompositorManager;
	}
	return S_OK;
}

STDMETHODIMP CTangram::GetCompositor(LONGLONG hHostWnd, ICompositor** ppCompositor)
{
	HWND m_hHostMain = (HWND)hHostWnd;
	DWORD dwID = ::GetWindowThreadProcessId(m_hHostMain, NULL);
	TangramThreadInfo* pThreadInfo = GetThreadInfo(dwID);

	CCompositor* m_pCompositor = nullptr;
	auto iter = pThreadInfo->m_mapCompositor.find(m_hHostMain);
	if (iter != pThreadInfo->m_mapCompositor.end())
	{
		m_pCompositor = (CCompositor*)iter->second;
		*ppCompositor = m_pCompositor;
	}

	return S_OK;
}

STDMETHODIMP CTangram::GetItemText(IWndNode* pNode, long nCtrlID, LONG nMaxLengeh, BSTR* bstrRet)
{
	if (pNode == nullptr)
		return S_OK;
	LONGLONG h = 0;
	pNode->get_Handle(&h);

	HWND hWnd = (HWND)h;
	if (::IsWindow(hWnd))
	{
		if (nMaxLengeh == 0)
		{
			hWnd = ::GetDlgItem(hWnd, nCtrlID);
			m_HelperWnd.Attach(hWnd);
			CString strText(_T(""));
			m_HelperWnd.GetWindowText(strText);
			m_HelperWnd.Detach();
			*bstrRet = strText.AllocSysString();
		}
		else
		{
			LPWSTR lpsz = _T("");
			::GetDlgItemText(hWnd, nCtrlID, lpsz, nMaxLengeh);
			*bstrRet = CComBSTR(lpsz);
		}
	}
	return S_OK;
}

STDMETHODIMP CTangram::SetItemText(IWndNode* pNode, long nCtrlID, BSTR bstrText)
{
	if (pNode == nullptr)
		return S_OK;
	LONGLONG h = 0;
	pNode->get_Handle(&h);

	HWND hWnd = (HWND)h;
	if (::IsWindow(hWnd))
		::SetDlgItemText(hWnd, nCtrlID, OLE2T(bstrText));

	return S_OK;
}

STDMETHODIMP CTangram::StartApplication(BSTR bstrAppID, BSTR bstrXml)
{ 
	CString strAppID = OLE2T(bstrAppID);
	strAppID.Trim();
	strAppID.MakeLower();
	if (strAppID == _T(""))
		return S_FALSE;

	auto it = m_mapRemoteTangramCore.find(strAppID);
	if (it == m_mapRemoteTangramCore.end())
	{
		CComPtr<IDispatch> pApp;
		pApp.CoCreateInstance(bstrAppID, nullptr, CLSCTX_LOCAL_SERVER | CLSCTX_INPROC_SERVER);
		if (pApp)
		{
			int nPos = m_strOfficeAppIDs.Find(strAppID);
			if (nPos != -1)
			{
				CString str = m_strOfficeAppIDs.Left(nPos);
				CComPtr<Office::COMAddIns> pAddins;
				int nIndex = str.Replace(_T(","), _T(""));
				switch (nIndex)
				{
				case 0:
				{
					CComQIPtr<Word::_Application> pWordApp(pApp);
					if (pWordApp)
					{
						pWordApp->put_Visible(true);
						pWordApp->get_COMAddIns(&pAddins);
					}
				}
				break;
				case 1:
				{
					CComQIPtr<Excel::_Application> pExcelApp(pApp);
					pExcelApp->put_UserControl(true);
					pExcelApp->get_COMAddIns(&pAddins);
					pExcelApp->put_Visible(0, true);
				}
				break;
				case 2:
				{
					CComQIPtr<OutLook::_Application> pOutLookApp(pApp);
					pOutLookApp->get_COMAddIns(&pAddins);
				}
				break;
				case 3:
				{
					//CComQIPtr<OneNote::_Application> pOneNoteApp(pApp);
					//pOneNoteApp->get_COMAddIns(&pAddins);
				}
				break;
				case 4:
				{
					//CComQIPtr<OneNote::_Application> pOneNoteApp(pApp);
					//pOneNoteApp->get_COMAddIns(&pAddins);
				}
				break;
				case 5:
				{
					CComQIPtr<MSProject::_MSProject> pProjectApp(pApp);
					//pProjectApp->get_COMAddIns(&pAddins);
				}
				break;
				case 6:
				{
					//CComQIPtr<OneNote::_Application> pOneNoteApp(pApp);
					//pOneNoteApp->get_COMAddIns(&pAddins);
				}
				break;
				case 7:
				{
					//CComQIPtr<OneNote::_Application> pOneNoteApp(pApp);
					//pOneNoteApp->get_COMAddIns(&pAddins);
				}
				break;
				case 8:
				{
					CComQIPtr<PowerPoint::_Application> pPptApp(pApp);
					pPptApp->get_COMAddIns(&pAddins);
					pPptApp->put_Visible(Office::MsoTriState::msoTrue);
				}
				break;
				case 9:
				{
				}
				break;
				default:
					break;
				}

				if (pAddins)
				{
					CComPtr<Office::COMAddIn> pAddin;
					pAddins->Item(&CComVariant(_T("tangram.tangram")), &pAddin);
					if (pAddin)
					{
						CComPtr<IDispatch> pAddin2;
						pAddin->get_Object(&pAddin2);
						CComQIPtr<ITangram> _pTangramAddin(pAddin2);
						if (_pTangramAddin)
						{
							if (::GetModuleHandle(_T("TangramPackage.dll")))
								_pTangramAddin->put_AppKeyValue(CComBSTR(L"fromvisualstudio"), CComVariant((VARIANT_BOOL)true));
							_pTangramAddin->put_AppKeyValue(CComBSTR(L"doctemplate"), CComVariant(bstrXml));
							m_mapRemoteTangramCore[strAppID] = _pTangramAddin.p;
							_pTangramAddin.p->AddRef();
							LONGLONG h = 0;
							_pTangramAddin->get_RemoteHelperHWND(&h);
							if (h)
							{
								HWND hWnd = (HWND)h;
								CHelperWnd* pWnd = new CHelperWnd();
								pWnd->m_strID = strAppID;
								pWnd->Create(hWnd, 0, _T(""), WS_CHILD);
								m_mapRemoteTangramHelperWnd[strAppID] = pWnd;
							}
						}
					}
				}
			}
			else if (strAppID == _T("chromeplus")&&::GetModuleHandle(_T("chrome.dll")))
			{
				if (::IsWindow(m_hHostBrowserWnd))
				{
					auto it = m_mapBrowserWnd.find(m_hHostBrowserWnd);
					if (it != m_mapBrowserWnd.end())
					{
						HWND hBrowser = m_pBrowserFactory->CreateBrowser(NULL, OLE2T(bstrXml));
					}
				}
			}
			else
			{
				DISPID dispID = 0;
				DISPPARAMS dispParams = { NULL, NULL, 0, 0 };
				VARIANT result = { 0 };
				EXCEPINFO excepInfo;
				memset(&excepInfo, 0, sizeof excepInfo);
				UINT nArgErr = (UINT)-1; // initialize to invalid arg
				LPOLESTR func = L"Tangram";
				HRESULT hr = pApp->GetIDsOfNames(GUID_NULL, &func, 1, LOCALE_SYSTEM_DEFAULT, &dispID);
				if (S_OK == hr)
				{
					hr = pApp->Invoke(dispID, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &dispParams, &result, &excepInfo, &nArgErr);
					if (S_OK == hr && VT_DISPATCH == result.vt&&result.pdispVal)
					{
						ITangram* pRemoteTangram = nullptr;
						result.pdispVal->QueryInterface(IID_ITangram, (void**)&pRemoteTangram);
						if (pRemoteTangram)
						{
							pRemoteTangram->AddRef();
							m_mapRemoteTangramCore[strAppID] = pRemoteTangram;

							CString strData = OLE2T(bstrXml);
							if (strData != _T(""))
							{
								pRemoteTangram->put_AppKeyValue(CComBSTR(L"StartData"), CComVariant(bstrXml));
							}
							LONGLONG h = 0;
							pRemoteTangram->get_RemoteHelperHWND(&h);
							HWND hWnd = (HWND)h;
							if (::IsWindow(hWnd))
							{
								CHelperWnd* pWnd = new CHelperWnd();
								pWnd->m_strID = strAppID;
								pWnd->Create(hWnd, 0, _T(""), WS_CHILD);
								m_mapRemoteTangramHelperWnd[strAppID] = pWnd;
								m_mapAppDispDic[strAppID] = pApp.Detach();
							}
							::VariantClear(&result);
						}
					}
				}
			}
		}
		else
		{
			int nPos = strAppID.Find(_T(","));
			if (nPos != -1)
			{
				
			}
		}
	}
	else// (it != m_mapRemoteTangramCore.end())
	{
		it->second->put_AppKeyValue(CComBSTR(L"doctemplate"), CComVariant(bstrXml));
	}
	return S_OK;
}

bool CTangram::CheckUrl(CString&   url)
{
	char*		res = nullptr;
	char		dwCode[20];
	DWORD		dwIndex, dwCodeLen;
	HINTERNET   hSession, hFile;

	url.MakeLower();

	hSession = InternetOpen(_T("Tangram"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (hSession)
	{
		hFile = InternetOpenUrl(hSession, url, NULL, 0, INTERNET_FLAG_RELOAD, 0);
		if (hFile == NULL)
		{
			InternetCloseHandle(hSession);
			return false;
		}
		dwIndex = 0;
		dwCodeLen = 10;
		HttpQueryInfo(hFile, HTTP_QUERY_STATUS_CODE, dwCode, &dwCodeLen, &dwIndex);
		res = dwCode;
		if (strcmp(res, "200 ") || strcmp(res, "302 "))
		{
			//200,302未重定位标志    
			if (hFile)
				InternetCloseHandle(hFile);
			InternetCloseHandle(hSession);
			return   true;
		}
	}
	return   false;
}

STDMETHODIMP CTangram::DownLoadFile(BSTR bstrFileURL, BSTR bstrTargetFile, BSTR bstrActionXml)
{
	CString  strFileURL = OLE2T(bstrFileURL);
	strFileURL.Trim();
	if (CheckUrl(strFileURL) == false)
		return S_FALSE;
	if (strFileURL == _T(""))
		return S_FALSE;
	CString strTargetFile = OLE2T(bstrTargetFile);
	CString _strTarget = _T("");
	int nPos = strTargetFile.Find(_T("\\"));
	if (nPos != -1)
	{
		_strTarget = strTargetFile.Left(nPos);
		if (_strTarget.CompareNoCase(_T("TangramData")) == 0)
		{
			_strTarget = strTargetFile.Mid(nPos);
			strTargetFile = m_strAppDataPath + _strTarget;
		}
		else
			_strTarget = _T("");
	}

	nPos = strTargetFile.ReverseFind('\\');
	if (nPos != -1)
	{
		CString strDir = strTargetFile.Left(nPos);
		if (::PathIsDirectory(strDir) == false)
			::SHCreateDirectory(NULL, strDir);
	}

	Utilities::CDownLoadObj* pDownLoadoObj = new Utilities::CDownLoadObj();
	pDownLoadoObj->m_strActionXml = OLE2T(bstrActionXml);
	pDownLoadoObj->DownLoadFile(strFileURL, strTargetFile);
	return S_OK;
}

STDMETHODIMP CTangram::UpdateWndNode(IWndNode* pNode)
{
	CWndNode* pWindowNode = (CWndNode*)pNode;
	if (pWindowNode)
	{
		if (pWindowNode->m_pTangramWindow)
		{
			if (pWindowNode->m_nActivePage > 0)
			{
				CString strVal = _T("");
				strVal.Format(_T("%d"), pWindowNode->m_nActivePage);
				pWindowNode->m_pHostParse->put_attr(_T("activepage"), strVal);
			}
			pWindowNode->m_pTangramWindow->Save();
		}
		if (pWindowNode->m_nViewType == Splitter)
		{
			((CSplitterNodeWnd*)pWindowNode->m_pHostWnd)->Save(); 
		}
		for (auto it2 : pWindowNode->m_vChildNodes)
		{
			UpdateWndNode(it2);
		}

		if ((pWindowNode == pWindowNode->m_pRootObj|| pWindowNode->m_pParentObj==nullptr)&&pWindowNode->m_pTangramNodeCommonData->m_pOfficeObj)
		{
			CTangramXmlParse* pWndParse = pWindowNode->m_pTangramNodeCommonData->m_pTangramParse->GetChild(_T("window"));
			CString strXml = pWndParse->xml();
			CString strNodeName = pWindowNode->m_pTangramNodeCommonData->m_pTangramParse->name();
			UpdateOfficeObj(pWindowNode->m_pTangramNodeCommonData->m_pOfficeObj, strXml, strNodeName);
		}
	}

	return S_OK;
}

STDMETHODIMP CTangram::GetNodeFromHandle(LONGLONG hWnd, IWndNode** ppRetNode)
{
	HWND _hWnd = (HWND)hWnd;
	if (::IsWindow(_hWnd))
	{
		LRESULT lRes = ::SendMessage(_hWnd, WM_TANGRAMGETNODE, 0, 0);
		if (lRes)
			*ppRetNode = (IWndNode*)lRes;
	}
	return S_OK;
}

CString CTangram::GetDocTemplateXml(CString strCaption, CString _strPath, CString strFilter)
{
	CString strTemplate = _T("");

	Lock();
	auto it = m_mapValInfo.find(_T("doctemplate"));
	if (it != m_mapValInfo.end())
	{
		strTemplate = OLE2T(it->second.bstrVal);
		::VariantClear(&it->second);
		m_mapValInfo.erase(it);
	}
	if (strTemplate == _T(""))
	{
		CString str = _strPath;
		CString strPath = _T("DocTemplate\\");
		if (::PathIsDirectory(str) == false)
		{
			if (_strPath != _T(""))
			{
				strPath += _strPath;
				strPath += _T("\\");
			}
			strPath = g_pTangram->m_strAppPath + strPath;
		}
		else
			strPath = str;
		if (::PathFileExists(strPath) == false)
			return _T("");
		CDocTemplateDlg dlg;
		if (strFilter != _T(""))
			dlg.m_strFilter = strFilter;
		dlg.m_strDir = strPath;
		dlg.m_strCaption = strCaption;
		if (dlg.DoModal() == IDOK)
			strTemplate = dlg.m_strDocTemplatePath;
		else
			strTemplate = m_strDefaultTemplateXml;
	}
	Unlock();
	return strTemplate;
}

STDMETHODIMP CTangram::get_HostWnd(LONGLONG* pVal)
{
	*pVal = (LONGLONG)m_hHostWnd;

	return S_OK;
}

STDMETHODIMP CTangram::get_RemoteTangram(BSTR bstrID, ITangram** pVal)
{
	CString strID = OLE2T(bstrID);
	strID.MakeLower();
	auto it = m_mapRemoteTangramCore.find(strID);
	if (it != m_mapRemoteTangramCore.end())
	{
		*pVal = it->second;
	}
	else if (strID == _T("chromeplus.tangram"))
	{
		StartApplication(bstrID, CComBSTR(""));
		it = m_mapRemoteTangramCore.find(strID);
		if (it != m_mapRemoteTangramCore.end())
		{
			*pVal = it->second;
		}
	}
	return S_OK;
}

STDMETHODIMP CTangram::GetCtrlByName(IDispatch* pCtrl, BSTR bstrName, VARIANT_BOOL bFindInChild, IDispatch** ppRetDisp)
{
	if (m_pCLRProxy)
	{
		*ppRetDisp = m_pCLRProxy->GetCtrlByName(pCtrl, bstrName, bFindInChild ? true : false);
	}
	return S_OK;
}

STDMETHODIMP CTangram::GetCtrlValueByName(IDispatch* pCtrl, BSTR bstrName, VARIANT_BOOL bFindInChild, BSTR* bstrVal)
{
	if (m_pCLRProxy)
	{
		*bstrVal = m_pCLRProxy->GetCtrlValueByName(pCtrl, bstrName, bFindInChild ? true : false);
	}
	return S_OK;
}

STDMETHODIMP CTangram::SetCtrlValueByName(IDispatch* pCtrl, BSTR bstrName, VARIANT_BOOL bFindInChild, BSTR bstrVal)
{
	if (m_pCLRProxy)
	{
		m_pCLRProxy->SetCtrlValueByName(pCtrl, bstrName, bFindInChild ? true : false, bstrVal);
	}
	return S_OK;
}

STDMETHODIMP CTangram::get_Extender(ITangramExtender** pVal)
{
	if (m_pExtender)
	{
		*pVal = m_pExtender;
		(*pVal)->AddRef();
	}

	return S_OK;
}

STDMETHODIMP CTangram::put_Extender(ITangramExtender* newVal)
{
	if (m_pExtender == nullptr)
	{
		m_pExtender = newVal;
		m_pExtender->AddRef();
	}

	return S_OK;
}

STDMETHODIMP CTangram::CreateTangramCtrl(BSTR bstrAppID, ITangramCtrl** ppRetCtrl)
{
	CString strAppID = OLE2T(bstrAppID);
	strAppID.Trim();
	strAppID.MakeLower();
	if (strAppID == _T(""))
	{
		return CoCreateInstance(CLSID_TangramCtrl, NULL, CLSCTX_ALL, IID_ITangramCtrl, (LPVOID*)ppRetCtrl);
	}
	auto it = m_mapRemoteTangramCore.find(strAppID);
	if (it == m_mapRemoteTangramCore.end())
	{
		CComPtr<IDispatch> pApp;
		pApp.CoCreateInstance(bstrAppID, nullptr, CLSCTX_LOCAL_SERVER | CLSCTX_INPROC_SERVER);
		if (pApp)
		{
			int nPos = m_strOfficeAppIDs.Find(strAppID);
			if (nPos != -1)
			{
				CString str = m_strOfficeAppIDs.Left(nPos);
				int nIndex = str.Replace(_T(","), _T(""));
				CComPtr<Office::COMAddIns> pAddins;
				switch (nIndex)
				{
				case 0:
				{
					CComQIPtr<Word::_Application> pWordApp(pApp);
					if (pWordApp)
					{
						pWordApp->put_Visible(true);
						pWordApp->get_COMAddIns(&pAddins);
					}
				}
				break;
				case 1:
				{
					CComQIPtr<Excel::_Application> pExcelApp(pApp);
					pExcelApp->put_UserControl(true);
					pExcelApp->get_COMAddIns(&pAddins);
					pExcelApp->put_Visible(0, true);
				}
				break;
				case 2:
				{
					CComQIPtr<OutLook::_Application> pOutLookApp(pApp);
					pOutLookApp->get_COMAddIns(&pAddins);
				}
				break;
				case 3:
				{
					//CComQIPtr<OneNote::_Application> pOneNoteApp(pApp);
					//pOneNoteApp->get_COMAddIns(&pAddins);
				}
				break;
				case 4:
				{
					//CComQIPtr<OneNote::_Application> pOneNoteApp(pApp);
					//pOneNoteApp->get_COMAddIns(&pAddins);
				}
				break;
				case 5:
				{
					CComQIPtr<MSProject::_MSProject> pProjectApp(pApp);
					//pProjectApp->get_COMAddIns(&pAddins);
				}
				break;
				case 6:
				{
					//CComQIPtr<OneNote::_Application> pOneNoteApp(pApp);
					//pOneNoteApp->get_COMAddIns(&pAddins);
				}
				break;
				case 7:
				{
					//CComQIPtr<OneNote::_Application> pOneNoteApp(pApp);
					//pOneNoteApp->get_COMAddIns(&pAddins);
				}
				break;
				case 8:
				{
					CComQIPtr<PowerPoint::_Application> pPptApp(pApp);
					pPptApp->get_COMAddIns(&pAddins);
				}
				break;
				case 9:
				{
				}
				break;
				default:
					break;
				}

				if (pAddins)
				{
					CComPtr<Office::COMAddIn> pAddin;
					pAddins->Item(&CComVariant(_T("tangram.tangram")), &pAddin);
					if (pAddin)
					{
						CComPtr<IDispatch> pAddin2;
						pAddin->get_Object(&pAddin2);
						CComQIPtr<ITangram> _pTangramAddin(pAddin2);
						if (_pTangramAddin)
						{
							m_mapRemoteTangramCore[strAppID] = _pTangramAddin.p;
							_pTangramAddin.p->AddRef();
							LONGLONG h = 0;
							_pTangramAddin->get_RemoteHelperHWND(&h);
							if (h)
							{
								HWND hWnd = (HWND)h;
								CHelperWnd* pWnd = new CHelperWnd();
								pWnd->m_strID = strAppID;
								pWnd->Create(hWnd, 0, _T(""), WS_CHILD);
								m_mapRemoteTangramHelperWnd[strAppID] = pWnd;
							}
							return _pTangramAddin->CreateTangramCtrl(CComBSTR(L""), ppRetCtrl);
						}
					}
				}
			}
			else
			{
				DISPID dispID = 0;
				DISPPARAMS dispParams = { NULL, NULL, 0, 0 };
				VARIANT result = { 0 };
				EXCEPINFO excepInfo;
				memset(&excepInfo, 0, sizeof excepInfo);
				UINT nArgErr = (UINT)-1; // initialize to invalid arg
				LPOLESTR func = L"Tangram";
				HRESULT hr = pApp->GetIDsOfNames(GUID_NULL, &func, 1, LOCALE_SYSTEM_DEFAULT, &dispID);
				if (S_OK == hr)
				{
					hr = pApp->Invoke(dispID, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &dispParams, &result, &excepInfo, &nArgErr);
					if (S_OK == hr && VT_DISPATCH == result.vt&&result.pdispVal)
					{
						ITangram* pCloudAddin = nullptr;
						result.pdispVal->QueryInterface(IID_ITangram, (void**)&pCloudAddin);
						if (pCloudAddin)
						{
							pCloudAddin->AddRef();
							m_mapRemoteTangramCore[strAppID] = pCloudAddin;

							LONGLONG h = 0;
							pCloudAddin->get_RemoteHelperHWND(&h);
							HWND hWnd = (HWND)h;
							if (::IsWindow(hWnd))
							{
								CHelperWnd* pWnd = new CHelperWnd();
								pWnd->m_strID = strAppID;
								pWnd->Create(hWnd, 0, _T(""), WS_CHILD);
								m_mapRemoteTangramHelperWnd[strAppID] = pWnd;
								m_mapAppDispDic[strAppID] = pApp.Detach();
							}
							::VariantClear(&result);
							return pCloudAddin->CreateTangramCtrl(CComBSTR(L""), ppRetCtrl);
						}
					}
				}
			}
		}
	}
	else
	{
		return it->second->CreateTangramCtrl(CComBSTR(L""), ppRetCtrl);
	}
	return S_OK;
}

CTangramEventObj::CTangramEventObj()
{
	m_bNotFired = true;
	m_nEventIndex = 19631965;
	m_strEventName = _T("");
	m_pSourceObj = nullptr;
}

CTangramEventObj::~CTangramEventObj()
{
	auto it = g_pTangram->m_mapTangramEvent.find((LONGLONG)this);
	if (it != g_pTangram->m_mapTangramEvent.end())
		g_pTangram->m_mapTangramEvent.erase(it);
	m_strEventName = _T("");
	//m_pSourceObj->Release();
	m_pSourceObj = nullptr;
	for (auto it : m_mapVar)
	{
		::VariantClear(&it.second);
	}
	m_mapVar.clear();
	for (auto it : m_mapDisp)
	{
		//it.second->Release();
	}
	m_mapDisp.clear();
}

STDMETHODIMP CTangramEventObj::get_EventName(BSTR* pVal)
{
	*pVal = m_strEventName.AllocSysString();
	return S_OK;
}

STDMETHODIMP CTangramEventObj::put_EventName(BSTR newVal)
{
	m_strEventName = OLE2T(newVal);
	return S_OK;
}

STDMETHODIMP CTangramEventObj::get_Index(int* pVal)
{
	*pVal = m_nEventIndex;
	return S_OK;
}

STDMETHODIMP CTangramEventObj::put_Index(int newVal)
{
	m_nEventIndex = newVal;
	return S_OK;
}

STDMETHODIMP CTangramEventObj::get_Object(int nIndex, IDispatch** pVal)
{
	auto it = m_mapDisp.find(nIndex);
	if (it != m_mapDisp.end())
	{
		*pVal = it->second;
		//(*pVal)->AddRef();
		return S_OK;
	}

	return S_FALSE;
}

STDMETHODIMP CTangramEventObj::put_Object(int nIndex, IDispatch* newVal)
{
	auto it = m_mapDisp.find(nIndex);
	if (it != m_mapDisp.end())
	{
		it->second->Release();
		m_mapDisp.erase(it);
	}
	if (newVal)
	{
		m_mapDisp[nIndex] = newVal;
		newVal->AddRef();
	}
	return S_OK;
}

STDMETHODIMP CTangramEventObj::get_Value(int nIndex, VARIANT* pVal)
{
	auto it = m_mapVar.find(nIndex);
	if (it != m_mapVar.end())
	{
		*pVal = it->second;
		return S_OK;
	}

	return S_FALSE;
}

STDMETHODIMP CTangramEventObj::put_Value(int nIndex, VARIANT newVal)
{
	auto it = m_mapVar.find(nIndex);
	if (it != m_mapVar.end())
	{
		::VariantClear(&it->second);
		m_mapVar.erase(it);
		return S_OK;
	}
	m_mapVar[nIndex] = newVal;
	return S_FALSE;
}

STDMETHODIMP CTangramEventObj::get_eventSource(IDispatch** pVal)
{
	if (m_pSourceObj)
	{
		*pVal = m_pSourceObj;
		(*pVal)->AddRef();
		return S_OK;
	}

	return S_FALSE;
}

STDMETHODIMP CTangramEventObj::put_eventSource(IDispatch* pSource)
{
	if (m_pSourceObj == nullptr)
	{
		m_pSourceObj = pSource;
		m_pSourceObj->AddRef();
		return S_OK;
	}
	else
	{
		m_pSourceObj->Release();
		m_pSourceObj = nullptr;
		m_pSourceObj = pSource;
		m_pSourceObj->AddRef();
	}

	return S_FALSE;
}

STDMETHODIMP CTangram::get_TangramDoc(LONGLONG AppProxy, LONGLONG nDocID, ITangramDoc** pVal)
{
	ITangramAppProxy* pProxy = (ITangramAppProxy*)AppProxy;
	*pVal = pProxy->GetDoc(nDocID);

	return S_OK;
}

STDMETHODIMP CTangram::AttachObjEvent(IDispatch* pDisp, int nEventIndex)
{
	if (pDisp)
	{
		IDispatch* _pDisp = nullptr;
		if (pDisp->QueryInterface(IID_IDispatch, (void**)_pDisp) == S_OK && _pDisp)
		{
			auto it = m_mapObjEventDic.find(pDisp);
			if (it != m_mapObjEventDic.end())
			{
				CString strEventIndexs = it->second;
				if (nEventIndex >= 0)
				{
					CString strIndex = _T("");
					strIndex.Format(_T(",%d,"), nEventIndex);
					if (strEventIndexs.Find(strIndex) == -1)
					{
						strEventIndexs += strIndex;
						m_mapObjEventDic.erase(it);
						m_mapObjEventDic[pDisp] = strEventIndexs;
					}
				}
			}
			else
			{
				if (nEventIndex >= 0)
				{
					CString strIndex = _T("");
					strIndex.Format(_T(",%d,"), nEventIndex);
					m_mapObjEventDic[pDisp] = strIndex;
				}
			}
		}
	}
	return S_OK;
}

#include <wincrypt.h>

int CTangram::CalculateByteMD5(BYTE* pBuffer, int BufferSize, CString &MD5)
{
	HCRYPTPROV hProv = NULL;
	DWORD dw = 0;
	// Acquire a cryptographic provider context handle.
	if (CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, 0))
	{
		HCRYPTHASH hHash;
		// Create the hash object.
		if (CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash))
		{
			// Compute the cryptographic hash of the buffer.
			if (CryptHashData(hHash, pBuffer, BufferSize, 0))
			{
				DWORD dwCount = 16;
				unsigned char digest[16];
				CryptGetHashParam(hHash, HP_HASHVAL, digest, &dwCount, 0);

				if (hHash)
					CryptDestroyHash(hHash);

				// Release the provider handle.
				if (hProv)
					CryptReleaseContext(hProv, 0);

				unsigned char b;
				char c;
				char *Value = new char[1024];
				int k = 0;
				for (int i = 0; i < 16; i++)
				{
					b = digest[i];
					for (int j = 4; j >= 0; j -= 4)
					{
						c = ((char)(b >> j) & 0x0F);
						if (c < 10) c += '0';
						else c = ('a' + (c - 10));
						Value[k] = c;
						k++;
					}
				}
				Value[k] = '\0';
				MD5 = CString(Value);
				delete Value;
			}
		}
	}
	else
	{
		dw = GetLastError();
		if (dw == NTE_BAD_KEYSET)               //同样，如果当不存在这样的容器的时候，创建一个
		{
			if (CryptAcquireContext(
				&hProv,
				NULL,
				NULL,
				PROV_RSA_FULL,
				CRYPT_NEWKEYSET))
			{
				_tprintf(TEXT("CryptAcquireContext succeeded.\n"));
			}
			else
			{
				_tprintf(TEXT("CryptAcquireContext falied.\n"));
			}
		}
	}

	return 1;
}

CString CTangram::ComputeHash(CString source)
{
	std::string strSrc = (LPCSTR)CW2A(source, CP_UTF8);
	int nSrcLen = strSrc.length();
	CString strRet = _T("");
	CalculateByteMD5((BYTE*)strSrc.c_str(), nSrcLen, strRet);
	return strRet;
}


BOOL CTangram::IsUserAdministrator()
{
	BOOL bRet = false;
	PSID psidRidGroup;
	SID_IDENTIFIER_AUTHORITY siaNtAuthority = SECURITY_NT_AUTHORITY;

	bRet = AllocateAndInitializeSid(&siaNtAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &psidRidGroup);
	if (bRet)
	{
		if (!CheckTokenMembership(NULL, psidRidGroup, &bRet))
			bRet = false;
		FreeSid(psidRidGroup);
	}

	return (BOOL)bRet;
}


STDMETHODIMP CTangram::GetWindowClientDefaultNode(IDispatch* pAddDisp, LONGLONG hParent, BSTR bstrWndClsName, BSTR bstrCompositorManagerName, IWndNode** ppNode)
{
	if (hParent == 0)
		return S_FALSE;
	HWND hPWnd = (HWND)hParent;
	CString strClsName = OLE2T(bstrWndClsName);
	strClsName.Trim();
	if (strClsName == _T(""))
	{
		strClsName = _T("MDIClient");
	}
	strClsName.MakeLower();
	HWND hWnd = ::FindWindowEx(hPWnd, NULL, strClsName, NULL);
	if (hWnd == nullptr)
		return S_FALSE;
	strClsName = OLE2T(bstrCompositorManagerName);
	strClsName.Trim();
	if (strClsName == _T(""))
	{
		strClsName = _T("default");
	}
	CCompositorManager* pCompositorManager = nullptr;
	auto it = m_mapWindowPage.find(hPWnd);
	if (it == m_mapWindowPage.end())
	{
		pCompositorManager = new CComObject<CCompositorManager>;
		pCompositorManager->m_hWnd = hPWnd;
		m_mapWindowPage[hPWnd] = pCompositorManager;
		for (auto it : m_mapTangramAppProxy)
		{
			CCompositorManagerProxy* pProxy = it.second->OnCompositorManagerCreated(pCompositorManager);
			if (pProxy)
				pCompositorManager->m_mapCompositorManagerProxy[it.second] = pProxy;
		}
	}
	else
		pCompositorManager = (CCompositorManager*)it->second;
	if (pCompositorManager != nullptr)
	{
		pCompositorManager->put_ConfigName(strClsName.AllocSysString());
		ICompositor* pCompositor = nullptr;
		pCompositorManager->CreateCompositor(CComVariant(0), CComVariant((LONGLONG)hWnd), CComBSTR(L"default"), &pCompositor);
		if (pCompositor)
		{
			return pCompositor->Open(CComBSTR(L"default"), CComBSTR(L"<default><window><node name=\"Start\" /></window></default>"), ppNode);
		}
	}
	return S_FALSE;
}

STDMETHODIMP CTangram::GetDocTemplateXml(BSTR bstrCaption, BSTR bstrPath, BSTR bstrFilter, BSTR* bstrTemplatePath)
{
	CString strTemplate = GetDocTemplateXml(OLE2T(bstrCaption), OLE2T(bstrPath), OLE2T(bstrFilter));
	if (strTemplate == _T(""))
		return S_FALSE;
	*bstrTemplatePath = strTemplate.AllocSysString();
	return S_OK;
}

STDMETHODIMP CTangram::CreateTangramEventObj(ITangramEventObj** ppTangramEventObj)
{
	CTangramEventObj* pObj = new CComObject<CTangramEventObj>;
	*ppTangramEventObj = pObj;
	m_mapTangramEvent[(LONGLONG)pObj] = pObj;
	return S_OK;
}

STDMETHODIMP CTangram::FireTangramEventObj(ITangramEventObj* pTangramEventObj)
{
	CTangramEventObj* pObj = (CTangramEventObj*)pTangramEventObj;
	if (pObj)
	{
		FireTangramAppEvent(pObj);
	}
	return S_OK;
}

CTangramDocTemplate::CTangramDocTemplate()
{
	m_strKey = _T("");
	m_strClientKey = _T("");
	m_strDocTemplatePath = _T("");
}

CTangramDocTemplate::~CTangramDocTemplate()
{
	if (g_pTangram->m_pMDIMainWnd->m_pDocTemplate == this)
		g_pTangram->m_pMDIMainWnd->m_pDocTemplate = nullptr;
}

void CTangramDocTemplate::InitXmlData()
{
	if (m_mapXml.size() == 0)
	{
		CString strKey = m_strKey;
		if (strKey != _T(""))
		{
			int nPos = strKey.Find(_T("_"));
			if (nPos != -1)
			{
				CString _strKey = strKey.Mid(nPos + 1);
				CString strPath = _T("");
				if (m_strDocTemplatePath == _T(""))
				{
					strPath = g_pTangram->m_strAppDataPath + _T("DocTemplateData\\");
				}
				else
				{
					strPath = m_strDocTemplatePath + _T("DocTemplateData\\");
				}
				if (::PathIsDirectory(strPath) == false)
				{
					::CreateDirectory(strPath, nullptr);
				}
				strPath += _strKey + _T(".doctemplate");
				if (::PathFileExists(strPath))
				{
					CTangramXmlParse m_Parse;
					if (m_Parse.LoadFile(strPath))
					{
						CTangramXmlParse* pChild = nullptr;
						int nCount = m_Parse.GetCount();
						for (int i = 0; i < nCount; i++)
						{
							pChild = m_Parse.GetChild(i);
							m_mapXml[pChild->name()] = pChild->xml();
						}
					}
				}
			}
			if (g_pTangram->m_pMDIMainWnd&&g_pTangram->m_pMDIMainWnd->m_pDocTemplate == this)
			{
				CTangramXmlParse m_Parse;
				CString strPath = g_pTangram->m_strAppDataPath + _T("default.doctemplate");
				if (::PathFileExists(strPath))
				{
					if (m_Parse.LoadFile(strPath))
					{
						CTangramXmlParse* pChild = nullptr;
						int nCount = m_Parse.GetCount();
						for (int i = 0; i < nCount; i++)
						{
							pChild = m_Parse.GetChild(i);
							m_mapXml[pChild->name()] = pChild->xml();
						}
					}
				}
				else
				{
					CString strXml = _T("<TangramDocTemplate><mdiclient><window><node name='mdiclient'/></window></mdiclient></TangramDocTemplate>");
					if (m_Parse.LoadXml(strXml))
					{
						m_Parse.SaveFile(strPath);
						m_mapXml[_T("mdiclient")] = _T("<mdiclient><window><node name='mdiclient'/></window></mdiclient>");
					}
				}
			}
		}
	}
}

bool CTangramDocTemplate::SaveXmlData()
{
	bool bRet = false;
	if (m_mapMainPageNode.size())
	{
		CString strKey = _T("");
		CString strXml = _T("<TangramDocTemplate>");
		for (auto it : m_mapMainPageNode)
		{
			CString strName = _T("");
			if (it.first == g_pTangram->m_pMDIMainWnd->m_hMDIClient)
			{
				strName = _T("mdiclient");
			}
			else
			{
				::GetWindowText(::GetParent(it.first), g_pTangram->m_szBuffer, MAX_PATH);
				strName = CString(g_pTangram->m_szBuffer);
				strName.Replace(_T(" "), _T("_"));
			}
			if (strName != _T(""))
			{
				ICompositor* pCompositor = nullptr;
				g_pTangram->GetCompositor((__int64)it.first, &pCompositor);
				if (pCompositor)
				{
					((CCompositor*)pCompositor)->UpdateWndNode();
					CTangramXmlParse* pParse = it.second->m_pTangramNodeCommonData->m_pTangramParse->GetChild(_T("window"));
					CString s = _T("");
					s.Format(_T("<%s>%s</%s>"), strName, pParse->xml(), strName);
					strXml += s;
				}
				else
					return false;
			}
		}
		for (auto it : m_mapConnectedFrame)
		{
			CString strName = it.second->m_strCompositorName;
			strName.Replace(_T("@"), _T("_"));
			CTangramXmlParse* pParse = it.second->UpdateWndNode();
			CComBSTR bstr("");
			it.second->get_CompositorXML(&bstr);
			CString s = _T("");
			s.Format(_T("<%s>%s</%s>"), strName, pParse->xml(), strName);
			strXml += s;
		}
		strXml += _T("</TangramDocTemplate>");
		CTangramXmlParse m_Parse;
		if (m_Parse.LoadXml(strXml))
		{
			strKey = m_strKey;
			if (strKey != _T(""))
			{
				CString strPath = _T("");
				int nPos = strKey.Find(_T("_"));
				if (nPos != -1)
				{
					strKey = strKey.Mid(nPos + 1);
					if (m_strDocTemplatePath == _T(""))
					{
						strPath = g_pTangram->m_strAppDataPath + _T("DocTemplateData\\");
					}
					else
					{
						strPath = m_strDocTemplatePath + _T("DocTemplateData\\");
					}

					if (::PathIsDirectory(strPath) == false)
						::CreateDirectory(strPath, nullptr);
					strPath += strKey + _T(".doctemplate");
					bRet = m_Parse.SaveFile(strPath);
				}
				else if (g_pTangram->m_pMDIMainWnd&&g_pTangram->m_pMDIMainWnd->m_pDocTemplate == this)
				{
					strPath = g_pTangram->m_strAppDataPath + _T("default.doctemplate");
					bRet = m_Parse.SaveFile(strPath);
				}
			}
		}
		if (m_mapTangramMDIChildWnd.size() == 0)
		{
			strKey = m_strClientKey;
			strKey.MakeLower();
			CCompositor* pCompositor = nullptr;
			for (auto it : g_pTangram->m_pMDIMainWnd->m_mapDesignableWnd)
			{
				ICompositor* _pCompositor = nullptr;
				g_pTangram->GetCompositor((__int64)it.first, &_pCompositor);
				pCompositor = (CCompositor*)_pCompositor;
				if (pCompositor)
				{
					auto it2 = pCompositor->m_mapNode.find(strKey);
					if (it2 != pCompositor->m_mapNode.end())
					{
						::DestroyWindow(it2->second->m_pHostWnd->m_hWnd);
					}
				}
			}
			ICompositor* _pCompositor = nullptr;
			g_pTangram->GetCompositor((__int64)g_pTangram->m_pMDIMainWnd->m_hMDIClient, &_pCompositor);
			if (_pCompositor)
			{
				pCompositor = (CCompositor*)_pCompositor;
				auto it2 = pCompositor->m_mapNode.find(strKey);
				if (it2 != pCompositor->m_mapNode.end())
				{
					::DestroyWindow(it2->second->m_pHostWnd->m_hWnd);
				}
			}
			delete this;
		}
	}

	return bRet;
}

STDMETHODIMP CTangramDocTemplate::get_TemplateXml(BSTR* bstrDocData)
{
	return S_OK;
}

STDMETHODIMP CTangramDocTemplate::put_TemplateXml(BSTR newVal)
{
	if (g_pTangram->m_pMDIMainWnd)
	{
		g_pTangram->m_pMDIMainWnd->OnCreateDoc(OLE2T(newVal));
		::SysFreeString(newVal);
		return S_OK;
	}
	return S_OK;
}

STDMETHODIMP CTangramDocTemplate::put_DocType(BSTR newVal)
{
	return S_OK;
}

STDMETHODIMP CTangramDocTemplate::GetFrameWndXml(BSTR bstrWndID, BSTR* bstrWndScriptVal)
{
	return S_OK;
}

STDMETHODIMP CTangramDocTemplate::get_DocID(LONGLONG* pVal)
{
	return S_OK;
}

STDMETHODIMP CTangramDocTemplate::put_DocID(LONGLONG newVal)
{
	return S_OK;
}

CTangramDoc::CTangramDoc()
{
	m_nState = -1992;
	m_strPath = _T("");
	m_strMainFrameID = _T("");
	m_strTemplateXml = _T("");
	m_pDocProxy = nullptr;
	m_pAppProxy = nullptr;
	m_pActiveWnd = nullptr;
	m_strCurrentWndID = _T("default");
}

CTangramDoc::~CTangramDoc()
{
	if (m_strPath != _T(""))
	{
		m_strPath.MakeLower();
		auto it = g_pTangram->m_mapOpenDoc.find(m_strPath);
		if (it != g_pTangram->m_mapOpenDoc.end())
			g_pTangram->m_mapOpenDoc.erase(it);
	}
	m_pAppProxy->RemoveDoc(m_llDocID);
}

STDMETHODIMP CTangramDoc::get_TemplateXml(BSTR* bstrDocData)
{
	CString strPath = OLE2T(*bstrDocData);
	strPath.Trim();
	if (strPath != _T("") && ::PathFileExists(strPath))
	{
		strPath.MakeLower();
		if (m_strPath == _T(""))
		{
			m_strPath = strPath;
			g_pTangram->m_mapOpenDoc[m_strPath] = this;
		}
		else if (strPath.CompareNoCase(m_strPath) != 0)
		{
			auto it = g_pTangram->m_mapOpenDoc.find(m_strPath);
			if (it != g_pTangram->m_mapOpenDoc.end())
			{
				g_pTangram->m_mapOpenDoc.erase(it);
			}
			m_strPath = strPath;
			g_pTangram->m_mapOpenDoc[strPath] = this;
		}
	}
	m_strTemplateXml = _T("<") + m_strDocID + _T(" mainframeid =\"") + m_strMainFrameID + _T("\" proxyid =\"") + m_pAppProxy->m_strProxyID + _T("\">");
	for (auto it : m_mapCompositor)
	{
		CCompositor* pCompositor = it.second->m_pHostCompositor;
		pCompositor->UpdateWndNode();
		CString strID = it.second->m_strWndID;
		auto it2 = it.second->m_pHostCompositor->m_mapNode.find(strID);
		if (it2 != it.second->m_pHostCompositor->m_mapNode.end())
		{
			CString strXml = it2->second->m_pTangramNodeCommonData->m_pTangramParse->xml();
			CString _strName = it2->second->m_pTangramNodeCommonData->m_pTangramParse->name();
			if (_strName != strID)
			{
				CString strName = _T("<") + _strName;
				int nPos = strXml.ReverseFind('<');
				CString str = strXml.Left(nPos);
				nPos = str.Find(strName);
				str = str.Mid(nPos + strName.GetLength());
				strXml = _T("<");
				strXml += strID;
				strXml += str;
				strXml += _T("</");
				strXml += strID;
				strXml += _T(">");
			}
			m_strTemplateXml += strXml;
		}
		if (it.second->m_mapWnd.size())
		{
			for (auto it2 : it.second->m_mapWnd)
			{
				CTangramDocWnd* pWnd = it2.second;
				if (pWnd->m_mapCtrlBar.size())
				{
					for (auto it3 : pWnd->m_mapCtrlBar)
					{
						CString strName = it3.first;
						HWND hwnd = it3.second;
						ICompositor* _pCompositor = nullptr;
						g_pTangram->GetCompositor((LONGLONG)hwnd, &_pCompositor);
						if (_pCompositor)
						{
							CCompositor* pCompositor = (CCompositor*)_pCompositor;
							pCompositor->UpdateWndNode();
							CString strID = strName;
							strID.MakeLower();
							auto it2 = pCompositor->m_mapNode.find(strID);
							if (it2 != pCompositor->m_mapNode.end())
							{
								CString strXml = it2->second->m_pTangramNodeCommonData->m_pTangramParse->xml();
								CString _strName = it2->second->m_pTangramNodeCommonData->m_pTangramParse->name();
								if (_strName != strName)
								{
									CString strName2 = _T("<") + _strName;
									int nPos = strXml.ReverseFind('<');
									CString str = strXml.Left(nPos);
									nPos = str.Find(strName2);
									str = str.Mid(nPos + strName2.GetLength());
									strXml = _T("<");
									strXml += strName;
									strXml += str;
									strXml += _T("</");
									strXml += strName;
									strXml += _T(">");
								}
								m_strTemplateXml += strXml;
							}
						}
					}
				}
			}
		}

		CCompositorManager* pCompositorManager = pCompositor->m_pCompositorManager;
		for (auto it : pCompositorManager->m_mapCompositor)
		{
			CString str = it.second->m_strCompositorName;
			if (str != pCompositor->m_strCompositorName)
			{
				it.second->UpdateWndNode();
				for (auto it2 : it.second->m_mapNode)
				{
					CString strXml = it2.second->m_pTangramNodeCommonData->m_pTangramParse->xml();
					CString _strName = it2.second->m_pTangramNodeCommonData->m_pTangramParse->name();
					CString strKey = str + _T("_") + it2.second->m_strKey;
					if (_strName != strKey)
					{
						CString strName = _T("<") + _strName;
						int nPos = strXml.ReverseFind('<');
						CString str = strXml.Left(nPos);
						nPos = str.Find(strName);
						str = str.Mid(nPos + strName.GetLength());
						strXml = _T("<");
						strXml += strKey;
						strXml += str;
						strXml += _T("</");
						strXml += strKey;
						strXml += _T(">");
					}
					m_strTemplateXml += strXml;
				}
			}
		}
	}
	m_strTemplateXml += _T("</") + m_strDocID + _T(">");

	*bstrDocData = m_strTemplateXml.AllocSysString();
	return S_OK;
}

STDMETHODIMP CTangramDoc::put_TemplateXml(BSTR newVal)
{
	m_strTemplateXml = OLE2T(newVal);
	m_strTemplateXml.Trim();
	if (m_strTemplateXml == _T(""))
	{
		int nSize = g_pTangram->m_mapMDTFrame.size();
		if (nSize == 0 && g_pTangram->m_bEclipse == false && g_pTangram->m_bOfficeApp == false && g_pTangram->m_bFirstDocCreated == false && g_pTangram->m_strCurrentDocTemplateXml == _T(""))
		{
			g_pTangram->m_bFirstDocCreated = true;
			m_strTemplateXml = _T("");
			CString strPath = g_pTangram->m_strAppPath + g_pTangram->m_strExeName + _T("_StartDoc.xml");
			if (::PathFileExists(strPath))
				m_strTemplateXml = strPath;
		}
		if (m_strTemplateXml == _T(""))
		{
			if (m_strMainFrameID == _T(""))
				m_strMainFrameID = g_pTangram->m_strCurrentFrameID;
			m_strTemplateXml = g_pTangram->m_strCurrentDocTemplateXml;
		}
	}
	g_pTangram->m_strCurrentFrameID = _T("");
	g_pTangram->m_strCurrentDocTemplateXml = _T("");
	CTangramDocWnd* pWnd = nullptr;
	CCompositorManager* pCompositorManager = nullptr;
	CComBSTR bstrXml(L"");
	if (m_strTemplateXml != _T(""))
	{
		m_nState = 1;
		CTangramXmlParse m_Parse;
		if (m_Parse.LoadXml(m_strTemplateXml) || m_Parse.LoadFile(m_strTemplateXml))
		{
			m_strMainFrameID = m_Parse.attr(_T("mainframeid"), _T("default"));
			m_strMainFrameID.Trim();
			m_strMainFrameID.MakeLower();
			CString strProxyID = m_Parse.attr(_T("proxyid"), _T("default"));
			strProxyID.MakeLower().Trim();
			g_pTangram->m_strCurrentFrameID = m_strMainFrameID;
			auto it = g_pTangram->m_mapTangramAppProxy.find(strProxyID);
			if (it != g_pTangram->m_mapTangramAppProxy.end())
			{
				m_pAppProxy = it->second;
				if (m_strMainFrameID != _T(""))
					m_pAppProxy->CreateNewFrame(m_strMainFrameID);
			}
			CTangramXmlParse* pChild = nullptr;
			int nCount = m_Parse.GetCount();
			for (int i = 0; i < nCount; i++)
			{
				pChild = m_Parse.GetChild(i);
				CString strName = pChild->name();
				m_mapWndScript[strName] = pChild->xml();
			}
		}
	}
	else
	{
		m_nState = 0;
	}
	if (m_mapCompositor.size())
	{
		CTangramDocFrame* pDocFrame = m_mapCompositor.begin()->second;
		if (pDocFrame)
		{
			if (pDocFrame->m_pHostCompositor)
			{
				pCompositorManager = pDocFrame->m_pHostCompositor->m_pCompositorManager;
				g_pTangram->DeletePage((LONGLONG)pCompositorManager->m_hWnd);
				pDocFrame->m_pHostCompositor = nullptr;
				pWnd = pDocFrame->m_pCurrentWnd;
				pWnd->m_pDocFrame->m_strWndID = _T("default");
				pWnd->m_pDocFrame->m_mapWnd[pWnd->m_hWnd] = pWnd;
				pCompositorManager = new CComObject<CCompositorManager>;
				pCompositorManager->m_hWnd = pWnd->m_hWnd;
				g_pTangram->m_mapWindowPage[pWnd->m_hWnd] = pCompositorManager;
				for (auto it : g_pTangram->m_mapTangramAppProxy)
				{
					CCompositorManagerProxy* pTangramProxy = it.second->OnCompositorManagerCreated(pCompositorManager);
					if (pTangramProxy)
						pCompositorManager->m_mapCompositorManagerProxy[it.second] = pTangramProxy;
				}
				if (m_strTemplateXml == _T(""))
				{
					g_pTangram->GetDocTemplateXml(CComBSTR("Please select New Window Template:"), pDocFrame->m_pTangramDoc->m_strDocID.AllocSysString(), _T(".xtml"), &bstrXml);
					pDocFrame->m_pTangramDoc->m_mapWndScript.clear();
				}
				else
				{
					auto it = pDocFrame->m_pTangramDoc->m_mapWndScript.find(pWnd->m_pDocFrame->m_strWndID);
					if (it != pDocFrame->m_pTangramDoc->m_mapWndScript.end())
					{
						bstrXml = it->second.AllocSysString();
					}
				}
			}
		}
	}
	if (pWnd)
	{
		IWndNode* pNode = nullptr;
		pCompositorManager->CreateCompositorWithDefaultNode((LONGLONG)pWnd->m_hView, CComBSTR(L"default"), pWnd->m_strWndID.AllocSysString(), bstrXml, false, &pNode);
		if (pNode)
		{
			pWnd->m_pDocFrame->m_pHostCompositor = ((CWndNode*)pNode)->m_pTangramNodeCommonData->m_pCompositor;
			pWnd->m_pDocFrame->m_pHostCompositor->m_pDoc = pWnd->m_pDocFrame->m_pTangramDoc;
		}
		for (auto it2 = pWnd->m_mapCtrlBar.begin(); it2 != pWnd->m_mapCtrlBar.end(); it2++)
		{
			ICompositor* pCompositor = nullptr;
			pCompositorManager->CreateCompositor(CComVariant((LONGLONG)0), CComVariant((LONGLONG)it2->second), CComBSTR(it2->first), &pCompositor);
			if (pCompositor)
			{
				CString strXml = _T("");
				auto it = pWnd->m_pDocFrame->m_pTangramDoc->m_mapWndScript.find(it2->first);
				if (it != pWnd->m_pDocFrame->m_pTangramDoc->m_mapWndScript.end())
				{
					strXml = it->second;
				}
				pCompositor->Open(CComBSTR(it2->first), strXml.AllocSysString(), &pNode);
			}
		}
	}
	return S_OK;
}

STDMETHODIMP CTangramDoc::put_DocType(BSTR newVal)
{
	m_strDocID = OLE2T(newVal);
	m_strDocID.Trim();
	if (m_strDocID != _T(""))
	{

	}
	return S_OK;
}

STDMETHODIMP CTangramDoc::GetFrameWndXml(BSTR bstrWndID, BSTR* bstrWndScriptVal)
{
	CString strWndID = OLE2T(bstrWndID);
	strWndID.Trim();
	if (strWndID != _T(""))
	{
		auto it = m_mapWndScript.find(strWndID);
		if (it != m_mapWndScript.end())
		{
			*bstrWndScriptVal = it->second.AllocSysString();
		}
	}

	return S_OK;
}

STDMETHODIMP CTangramDoc::get_DocID(LONGLONG* pVal)
{
	*pVal = m_llDocID;

	return S_OK;
}

STDMETHODIMP CTangramDoc::put_DocID(LONGLONG newVal)
{
	m_llDocID = newVal;

	return S_OK;
}

CTangramDocFrame::CTangramDocFrame()
{
	m_strWndID = _T("");
	m_pHostCompositor = nullptr;
	m_pTangramDoc = nullptr;
	m_pCurrentWnd = nullptr;
}

CTangramDocFrame::~CTangramDocFrame()
{
	if (m_strWndID != _T(""))
	{
		auto it = m_pTangramDoc->m_mapCompositor.find(m_strWndID);
		if (it != m_pTangramDoc->m_mapCompositor.end())
			m_pTangramDoc->m_mapCompositor.erase(it);
		if (m_pTangramDoc->m_mapCompositor.size() == 0)
		{
			delete m_pTangramDoc;
			m_pTangramDoc = nullptr;
		}
	}
}

STDMETHODIMP CTangram::OpenCompositors(LONGLONG hWnd, BSTR bstrFrames, BSTR bstrKey, BSTR bstrXml, VARIANT_BOOL bSave)
{
	LRESULT lRes = ::SendMessage((HWND)hWnd, WM_TANGRAMDATA, 0, 20190214);
	CString _strXml = _T("<");
	CString strKey = OLE2T(bstrKey);
	CTangramWinFormWnd* pWnd = nullptr;
	if (lRes)
	{
		pWnd = (CTangramWinFormWnd*)lRes;
	}
	if (pWnd)
	{
		_strXml += strKey;
		_strXml += _T(">");
	}
	auto it = m_mapWindowPage.find((HWND)hWnd);
	if (it != m_mapWindowPage.end())
	{
		CString strFrames = OLE2T(bstrFrames);
		CString strKey = OLE2T(bstrKey);
		CString strXml = OLE2T(bstrXml);
		if (strFrames == _T(""))
		{
			for (auto it1 : ((CCompositorManager*)it->second)->m_mapCompositor)
			{
				if (it1.second != ((CCompositorManager*)it->second)->m_pBKFrame)
				{
					IWndNode* pNode = nullptr;
					it1.second->Open(bstrKey, bstrXml, &pNode);
					if (pNode&&bSave)
						pNode->put_SaveToConfigFile(true);
					if (pWnd&&pWnd->m_bMdiForm)
					{
						CWndNode* _pNode = (CWndNode*)pNode;
						CString strXml = _pNode->m_pTangramNodeCommonData->m_pTangramParse->xml();
						strXml.Replace(_T("/><"), _T("/>\r\n<"));
						strXml.Replace(_T("/>"), _T("></node>"));
						CString s = _T("");
						s.Format(_T("<%s>%s</%s>"), it1.second->m_strCompositorName, strXml, it1.second->m_strCompositorName);
						_strXml += s;
					}
				}
			}
			if (pWnd&&pWnd->m_bMdiForm)
			{
				_strXml += _T("</");
				_strXml += strKey;
				_strXml += _T(">");
				auto it = pWnd->m_mapKey.find(strKey);
				if (it == pWnd->m_mapKey.end())
				{
					pWnd->m_mapKey[strKey] = _strXml;
				}
				else
				{
					pWnd->m_mapKey.erase(it);
					pWnd->m_mapKey[strKey] = _strXml;
				}
			}
		}
		else
		{
			strFrames = _T(",") + strFrames;
			for (auto it1 : ((CCompositorManager*)it->second)->m_mapCompositor)
			{
				CString strName = _T(",") + it1.second->m_strCompositorName + _T(",");
				if (strFrames.Find(strName) != -1)
				{
					IWndNode* pNode = nullptr;
					it1.second->Open(bstrKey, bstrXml, &pNode);
					if (pNode&&bSave)
						pNode->put_SaveToConfigFile(true);
				}
			}
		}
	}

	return S_OK;
}

STDMETHODIMP CTangram::DeleteFrame(ICompositor* pCompositor)
{
	CCompositor* _pCompositor = (CCompositor*)pCompositor;
	if (_pCompositor)
	{
		HWND hwnd = ::CreateWindowEx(NULL, _T("Tangram Window Class"), _T(""), WS_CHILD, 0, 0, 0, 0, m_hHostWnd, NULL, AfxGetInstanceHandle(), NULL);
		_pCompositor->ModifyHost((LONGLONG)::CreateWindowEx(NULL, _T("Tangram Window Class"), _T(""), WS_CHILD, 0, 0, 0, 0, (HWND)hwnd, NULL, AfxGetInstanceHandle(), NULL));
		::DestroyWindow(hwnd);
	}
	return S_OK;
}

STDMETHODIMP CTangram::DeletePage(LONGLONG CompositorManagerHandle)
{
	m_bDeleteCompositorManager = TRUE;
	HWND hPage = (HWND)CompositorManagerHandle;
	auto it = m_mapWindowPage.find(hPage);
	if (it != m_mapWindowPage.end())
	{
		CCompositorManager* pCompositorManager = (CCompositorManager*)it->second;
		auto it2 = pCompositorManager->m_mapCompositor.begin();
		while (it2 != pCompositorManager->m_mapCompositor.end())
		{
			CCompositor* pCompositor = it2->second;
			pCompositorManager->m_mapCompositor.erase(it2);
			if (pCompositor)
			{
				pCompositor->m_pCompositorManager = nullptr;
				RECT rc;
				HWND hwnd = pCompositor->m_hWnd;
				int nSize = pCompositor->m_mapNode.size();
				if (nSize > 1)
				{
					for (auto it : pCompositor->m_mapNode)
					{
						if (it.second != pCompositor->m_pWorkNode)
						{
							::SetParent(it.second->m_pHostWnd->m_hWnd, pCompositor->m_pWorkNode->m_pHostWnd->m_hWnd);
						}
					}
				}
				if (pCompositor->m_pWorkNode)
				{
					::GetWindowRect(pCompositor->m_pWorkNode->m_pHostWnd->m_hWnd, &rc);
					pCompositor->GetParent().ScreenToClient(&rc);
					::DestroyWindow(pCompositor->m_pWorkNode->m_pHostWnd->m_hWnd);
					::SetWindowPos(hwnd, HWND_TOP, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, SWP_NOACTIVATE);
				}
			}
			it2 = pCompositorManager->m_mapCompositor.begin();
		}
		delete pCompositorManager;
	}
	return S_OK;
}

CString CTangram::GetDesignerData(CWndNode* pNode)
{
	if (pNode)
	{
		CCompositor* pCompositor = pNode->m_pTangramNodeCommonData->m_pCompositor;
		if (pCompositor)
		{
			CString strKey = pCompositor->m_strCurrentKey;
			switch (pCompositor->m_nCompositorType)
			{
			case MDIClientCompositor:
			{
			}
			break;
			case MDIChildCompositor:
			{
			}
			break;
			case SDICompositor:
			{
			}
			break;
			case CtrlBarCompositor:
			{
			}
			break;
			case WinFormMDIClientCompositor:
			{
			}
			break;
			case WinFormMDIChildCompositor:
			{
			}
			break;
			case WinFormCompositor:
			{
			}
			break;
			case EclipseWorkBenchCompositor:
			{
			}
			break;
			case EclipseViewCompositor:
			{
			}
			break;
			case EclipseSWTCompositor:
			{
			}
			break;
			case WinFormControlCompositor:
			{
			}
			break;
			default:
				break;
			}
		}
	}
	return _T("");
}

_TCHAR* findProgram(_TCHAR* argv[]) {
	_TCHAR * program;
	/* windows, make sure we are looking for the .exe */
	_TCHAR * ch;
	int length = _tcslen(argv[0]);
	ch = (_TCHAR*)malloc((length + 5) * sizeof(_TCHAR));
	_tcscpy(ch, argv[0]);

	if (length <= 4 || _tcsicmp(&ch[length - 4], _T(".exe")) != 0)
		_tcscat(ch, _T_ECLIPSE(".exe"));

	program = findCommand(ch);
	if (ch != program)
		free(ch);
	if (program == NULL)
	{
		program = (_TCHAR*)malloc(MAX_PATH_LENGTH + 1);
		GetModuleFileName(NULL, program, MAX_PATH_LENGTH);
		argv[0] = program;
	}
	else if (_tcscmp(argv[0], program) != 0) {
		argv[0] = program;
	}
	return program;
}

/*
* Parse arguments of the command.
*/
void parseArgs(int* pArgc, _TCHAR* argv[], int useVMargs)
{
	int     index;

	/* Ensure the list of user argument is NULL terminated. */
	argv[*pArgc] = NULL;

	/* For each user defined argument */
	for (index = 0; index < *pArgc; index++) {
		if (_tcsicmp(argv[index], VMARGS) == 0) {
			if (useVMargs == 1) { //Use the VMargs as the user specified vmArgs
				userVMarg = &argv[index + 1];
			}
			argv[index] = NULL;
			*pArgc = index;
		}
		else if (_tcsicmp(argv[index], NAME) == 0) {
			name = argv[++index];
		}
		else if (_tcsicmp(argv[index], LIBRARY) == 0) {
			eclipseLibrary = argv[++index];
			index++;
		}
		else if (_tcsicmp(argv[index], SUPRESSERRORS) == 0) {
			suppressErrors = 1;
		}
		else if (_tcsicmp(argv[index], PROTECT) == 0) {
			if (_tcsicmp(argv[++index], ROOT) == 0) {
				protectRoot = 1;
			}
		}
	}
}

/* We need to look for --launcher.ini before parsing the other args */
_TCHAR* checkForIni(int argc, _TCHAR* argv[])
{
	int index;
	for (index = 0; index < (argc - 1); index++) {
		if (_tcsicmp(argv[index], INI) == 0) {
			return argv[++index];
		}
	}
	return NULL;
}

/*
* Create a new array containing user arguments from the config file first and
* from the command line second.
* Allocate an array large enough to host all the strings passed in from
* the argument configArgv and argv. That array is passed back to the
* argv argument. That array must be freed with the regular free().
* Note that both arg lists are expected to contain the argument 0 from the C
* main method. That argument contains the path/executable name. It is
* only copied once in the resulting list.
*
* Returns 0 if success.
*/
int createUserArgs(int configArgc, _TCHAR **configArgv, int *argc, _TCHAR ***argv)
{
	_TCHAR** newArray = (_TCHAR **)malloc((configArgc + *argc + 1) * sizeof(_TCHAR *));

	newArray[0] = (*argv)[0];	/* use the original argv[0] */
	memcpy(newArray + 1, configArgv, configArgc * sizeof(_TCHAR *));

	/* Skip the argument zero (program path and name) */
	memcpy(newArray + 1 + configArgc, *argv + 1, (*argc - 1) * sizeof(_TCHAR *));

	/* Null terminate the new list of arguments and return it. */
	*argv = newArray;
	*argc += configArgc;
	(*argv)[*argc] = NULL;

	return 0;
}

/*
* Determine the default official application name
*
* This function provides the default application name that appears in a variety of
* places such as: title of message dialog, title of splash screen window
* that shows up in Windows task bar.
* It is computed from the name of the launcher executable and
* by capitalizing the first letter. e.g. "c:/ide/eclipse.exe" provides
* a default name of "Eclipse".
*/
_TCHAR* getDefaultOfficialName(_TCHAR* program)
{
	_TCHAR *ch = NULL;

	/* Skip the directory part */
	ch = lastDirSeparator(program);
	if (ch == NULL) ch = program;
	else ch++;

	ch = _tcsdup(ch);
#ifdef _WIN32
	{
		/* Search for the extension .exe and cut it */
		_TCHAR *extension = _tcsrchr(ch, _T_ECLIPSE('.'));
		if (extension != NULL)
		{
			*extension = _T_ECLIPSE('\0');
		}
	}
#endif
	/* Upper case the first character */
#ifndef LINUX
	{
		*ch = _totupper(*ch);
	}
#else
	{
		if (*ch >= 'a' && *ch <= 'z')
		{
			*ch -= 32;
		}
	}
#endif
	return ch;
}

void CTangram::EclipseInit()
{
	if (eclipseLibrary)
		return;
	GetLaunchMode();
	if (launchMode != -1)
	{
		TCHAR	m_szBuffer[MAX_PATH];
		::GetModuleFileName(theApp.m_hInstance, m_szBuffer, MAX_PATH);
		eclipseLibrary = m_szBuffer;
		if (m_pTangramAppProxy == nullptr)
		{
			LoadCLR();
			m_pTangramAppProxy = m_pTangramCLRAppProxy;
		}
		m_pTangramAppProxy->m_pvoid = nullptr;
		m_bEnableProcessFormTabKey = true;

		setlocale(LC_ALL, "");
		int		nArgs;
		szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
		CEclipseExtender* pExtender = new CComObject<CEclipseExtender>;
		m_pExtender = pExtender;
		if (m_pTangramAppProxy == NULL)
		{
			LoadCLR();
			m_pTangramAppProxy = m_pTangramCLRAppProxy;
		}
		m_pTangramAppProxy->m_pvoid = nullptr;
		m_bEnableProcessFormTabKey = true;
		if (m_nAppType != TANGRAM_APP_BROWSER_ECLIPSE)
			m_nAppType = TANGRAM_APP_ECLIPSE;
		runW(nArgs, szArglist, userVMarg);

		m_bChromeNeedClosed = true;

		for (auto it : m_mapBrowserWnd)
		{
			::PostMessage(it.first, WM_CLOSE, 0, 0);
			//it.second->PostMessageW(WM_CLOSE, 0, 0);
		}

		if (::IsWindow(m_hHostWnd))
			::DestroyWindow(m_hHostWnd);
		if (::IsWindow(m_hTangramWnd))
			::DestroyWindow(m_hTangramWnd);
		if(::IsWindow(m_hMainWnd))
			::DestroyWindow(m_hMainWnd);
	}
}

/*
//
// ICONS (.ICO type 1) are structured like this:
//
// ICONHEADER (just 1)
// ICONDIR [1...n] (an array, 1 for each image)
// [BITMAPINFOHEADER+COLOR_BITS+MASK_BITS] [1...n] (1 after the other, for each image)
//
// CURSORS (.ICO type 2) are identical in structure, but use
// two monochrome bitmaps (real XOR and AND masks, this time).
//

typedef struct
{
	WORD idReserved; // must be 0
	WORD idType; // 1 = ICON, 2 = CURSOR
	WORD idCount; // number of images (and ICONDIRs)

	// ICONDIR [1...n]
	// ICONIMAGE [1...n]

} ICONHEADER;

//
// An array of ICONDIRs immediately follow the ICONHEADER
//
typedef struct
{
	BYTE bWidth;
	BYTE bHeight;
	BYTE bColorCount;
	BYTE bReserved;
	WORD wPlanes; // for cursors, this field = wXHotSpot
	WORD wBitCount; // for cursors, this field = wYHotSpot
	DWORD dwBytesInRes;
	DWORD dwImageOffset; // file-offset to the start of ICONIMAGE

} ICONDIR;

//
// After the ICONDIRs follow the ICONIMAGE structures -
// consisting of a BITMAPINFOHEADER, (optional) RGBQUAD array, then
// the color and mask bitmap bits (all packed together
//
typedef struct
{
	BITMAPINFOHEADER biHeader; // header for color bitmap (no mask header)
	//RGBQUAD rgbColors[1...n];
	//BYTE bXOR[1]; // DIB bits for color bitmap
	//BYTE bAND[1]; // DIB bits for mask bitmap

} ICONIMAGE;

//
// Write the ICO header to disk
//
static UINT WriteIconHeader(HANDLE hFile, int nImages)
{
	ICONHEADER iconheader;
	DWORD nWritten;

	// Setup the icon header
	iconheader.idReserved = 0; // Must be 0
	iconheader.idType = 1; // Type 1 = ICON (type 2 = CURSOR)
	iconheader.idCount = nImages; // number of ICONDIRs

	// Write the header to disk
	WriteFile(hFile, &iconheader, sizeof(iconheader), &nWritten, 0);

	// following ICONHEADER is a series of ICONDIR structures (idCount of them, in fact)
	return nWritten;
}

//
// Return the number of BYTES the bitmap will take ON DISK
//
static UINT NumBitmapBytes(BITMAP *pBitmap)
{
	int nWidthBytes = pBitmap->bmWidthBytes;

	// bitmap scanlines MUST be a multiple of 4 bytes when stored
	// inside a bitmap resource, so round up if necessary
	if (nWidthBytes & 3)
		nWidthBytes = (nWidthBytes + 4) & ~3;

	return nWidthBytes * pBitmap->bmHeight;
}

//
// Return number of bytes written
//
static UINT WriteIconImageHeader(HANDLE hFile, BITMAP *pbmpColor, BITMAP *pbmpMask)
{
	BITMAPINFOHEADER biHeader;
	DWORD nWritten;
	UINT nImageBytes;

	// calculate how much space the COLOR and MASK bitmaps take
	nImageBytes = NumBitmapBytes(pbmpColor) + NumBitmapBytes(pbmpMask);

	// write the ICONIMAGE to disk (first the BITMAPINFOHEADER)
	ZeroMemory(&biHeader, sizeof(biHeader));

	// Fill in only those fields that are necessary
	biHeader.biSize = sizeof(biHeader);
	biHeader.biWidth = pbmpColor->bmWidth;
	biHeader.biHeight = pbmpColor->bmHeight * 2; // height of color+mono
	biHeader.biPlanes = pbmpColor->bmPlanes;
	biHeader.biBitCount = pbmpColor->bmBitsPixel;
	biHeader.biSizeImage = nImageBytes;

	// write the BITMAPINFOHEADER
	WriteFile(hFile, &biHeader, sizeof(biHeader), &nWritten, 0);

	// write the RGBQUAD color table (for 16 and 256 colour icons)
	if (pbmpColor->bmBitsPixel == 2 || pbmpColor->bmBitsPixel == 8)
	{

	}

	return nWritten;
}

//
// Wrapper around GetIconInfo and GetObject(BITMAP)
//
static BOOL GetIconBitmapInfo(HICON hIcon, ICONINFO *pIconInfo, BITMAP *pbmpColor, BITMAP *pbmpMask)
{
	if (!GetIconInfo(hIcon, pIconInfo))
		return FALSE;

	if (!GetObject(pIconInfo->hbmColor, sizeof(BITMAP), pbmpColor))
		return FALSE;

	if (!GetObject(pIconInfo->hbmMask, sizeof(BITMAP), pbmpMask))
		return FALSE;

	return TRUE;
}

//
// Write one icon directory entry - specify the index of the image
//
static UINT WriteIconDirectoryEntry(HANDLE hFile, int nIdx, HICON hIcon, UINT nImageOffset)
{
	ICONINFO iconInfo;
	ICONDIR iconDir;

	BITMAP bmpColor;
	BITMAP bmpMask;

	DWORD nWritten;
	UINT nColorCount;
	UINT nImageBytes;

	GetIconBitmapInfo(hIcon, &iconInfo, &bmpColor, &bmpMask);

	nImageBytes = NumBitmapBytes(&bmpColor) + NumBitmapBytes(&bmpMask);

	if (bmpColor.bmBitsPixel >= 8)
		nColorCount = 0;
	else
		nColorCount = 1 << (bmpColor.bmBitsPixel * bmpColor.bmPlanes);

	// Create the ICONDIR structure
	iconDir.bWidth = (BYTE)bmpColor.bmWidth;
	iconDir.bHeight = (BYTE)bmpColor.bmHeight;
	iconDir.bColorCount = nColorCount;
	iconDir.bReserved = 0;
	iconDir.wPlanes = bmpColor.bmPlanes;
	iconDir.wBitCount = bmpColor.bmBitsPixel;
	iconDir.dwBytesInRes = sizeof(BITMAPINFOHEADER) + nImageBytes;
	iconDir.dwImageOffset = nImageOffset;

	// Write to disk
	WriteFile(hFile, &iconDir, sizeof(iconDir), &nWritten, 0);

	// Free resources
	DeleteObject(iconInfo.hbmColor);
	DeleteObject(iconInfo.hbmMask);

	return nWritten;
}

static UINT WriteIconData(HANDLE hFile, HBITMAP hBitmap)
{
	BITMAP bmp;
	int i;
	BYTE * pIconData;

	UINT nBitmapBytes;
	DWORD nWritten;

	GetObject(hBitmap, sizeof(BITMAP), &bmp);

	nBitmapBytes = NumBitmapBytes(&bmp);

	pIconData = (BYTE *)malloc(nBitmapBytes);

	GetBitmapBits(hBitmap, nBitmapBytes, pIconData);

	// bitmaps are stored inverted (vertically) when on disk..
	// so write out each line in turn, starting at the bottom + working
	// towards the top of the bitmap. Also, the bitmaps are stored in packed
	// in memory - scanlines are NOT 32bit aligned, just 1-after-the-other
	for (i = bmp.bmHeight - 1; i >= 0; i--)
	{
		// Write the bitmap scanline
		WriteFile(
			hFile,
			pIconData + (i * bmp.bmWidthBytes), // calculate offset to the line
			bmp.bmWidthBytes, // 1 line of BYTES
			&nWritten,
			0);

		// extend to a 32bit boundary (in the file) if necessary
		if (bmp.bmWidthBytes & 3)
		{
			DWORD padding = 0;
			WriteFile(hFile, &padding, 4 - bmp.bmWidthBytes, &nWritten, 0);
		}
	}

	free(pIconData);

	return nBitmapBytes;
}

//
// Create a .ICO file, using the specified array of HICON images
//
BOOL SaveIcon3(TCHAR *szIconFile, HICON hIcon[], int nNumIcons)
{
	HANDLE hFile;
	int i;
	int * pImageOffset;

	if (hIcon == 0 || nNumIcons < 1)
		return FALSE;

	// Save icon to disk:
	hFile = CreateFile(szIconFile, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, 0);

	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	//
	// Write the iconheader first of all
	//
	WriteIconHeader(hFile, nNumIcons);

	//
	// Leave space for the IconDir entries
	//
	SetFilePointer(hFile, sizeof(ICONDIR) * nNumIcons, 0, FILE_CURRENT);

	pImageOffset = (int *)malloc(nNumIcons * sizeof(int));

	//
	// Now write the actual icon images!
	//
	for (i = 0; i < nNumIcons; i++)
	{
		ICONINFO iconInfo;
		BITMAP bmpColor, bmpMask;

		GetIconBitmapInfo(hIcon[i], &iconInfo, &bmpColor, &bmpMask);

		// record the file-offset of the icon image for when we write the icon directories
		pImageOffset[i] = SetFilePointer(hFile, 0, 0, FILE_CURRENT);

		// bitmapinfoheader + colortable
		WriteIconImageHeader(hFile, &bmpColor, &bmpMask);

		// color and mask bitmaps
		WriteIconData(hFile, iconInfo.hbmColor);
		WriteIconData(hFile, iconInfo.hbmMask);

		DeleteObject(iconInfo.hbmColor);
		DeleteObject(iconInfo.hbmMask);
	}

	//
	// Lastly, skip back and write the icon directories.
	//
	SetFilePointer(hFile, sizeof(ICONHEADER), 0, FILE_BEGIN);

	for (i = 0; i < nNumIcons; i++)
	{
		WriteIconDirectoryEntry(hFile, i, hIcon[i], pImageOffset[i]);
	}

	free(pImageOffset);

	// finished!
	CloseHandle(hFile);

	return TRUE;
}


int saveIcon(TCHAR* filename, TCHAR* iconFile) {
	HICON hIconLarge;
	HICON hIconSmall;
	BOOL ret;


	if (ExtractIconEx(filename, 0, &hIconLarge, &hIconSmall, 1) == 0) {
		return 1;
	}

	ret = SaveIcon3(iconFile, &hIconSmall, 1);
	if (ret) {
		return 0;
	}
	return -1;
}

void SaveIconToFile(HICON hico, LPCTSTR szFileName, BOOL bAutoDelete = FALSE)
{
	PICTDESC pd = { sizeof(pd), PICTYPE_ICON };
	pd.icon.hicon = hico;

	CComPtr<IPicture> pPict = NULL;
	CComPtr<IStream>  pStrm = NULL;
	LONG cbSize = 0;

	BOOL res = FALSE;

	res = SUCCEEDED(::CreateStreamOnHGlobal(NULL, TRUE, &pStrm));
	res = SUCCEEDED(::OleCreatePictureIndirect(&pd, IID_IPicture, bAutoDelete, (void**)&pPict));
	res = SUCCEEDED(pPict->SaveAsFile(pStrm, TRUE, &cbSize));

	if (res)
	{
		// rewind stream to the beginning
		LARGE_INTEGER li = { 0 };
		pStrm->Seek(li, STREAM_SEEK_SET, NULL);

		// write to file
		HANDLE hFile = ::CreateFile(szFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
		if (INVALID_HANDLE_VALUE != hFile)
		{
			DWORD dwWritten = 0, dwRead = 0, dwDone = 0;
			BYTE  buf[4096];
			while (dwDone < cbSize)
			{
				if (SUCCEEDED(pStrm->Read(buf, sizeof(buf), &dwRead)))
				{
					::WriteFile(hFile, buf, dwRead, &dwWritten, NULL);
					if (dwWritten != dwRead)
						break;
					dwDone += dwRead;
				}
				else
					break;
			}

			_ASSERTE(dwDone == cbSize);
			::CloseHandle(hFile);
		}
	}
}
*/

void CTangram::InitTangramDocManager()
{
	TangramDocTemplateInfo* pTangramDocTemplateInfo = nullptr;
	CString strPath = _T("");
	TCHAR	szBuffer[MAX_PATH];
	memset(m_szBuffer, 0, sizeof(szBuffer));
	::GetModuleFileName(nullptr, szBuffer, MAX_PATH);
	strPath = CString(szBuffer);
	int nPos = strPath.ReverseFind('\\');
	int i = 0;
	CString str1 = _T("");
	CString str2 = _T("");
	CString str3 = _T("");
	strPath = strPath.Left(nPos + 1);
	HINSTANCE hInstResource = ::GetModuleHandle(NULL);
	m_DocImageList.Create(48, 48, ILC_COLOR32, 0, 4);
	if(m_DocTemplateImageList.m_hImageList==0)
		m_DocTemplateImageList.Create(32, 32, ILC_COLOR32, 0, 4);
	m_strDocFilters = _T("");
	if (m_strDefaultTemplate != _T(""))
	{
		CTangramXmlParse _Parse;
		if (_Parse.LoadXml(m_strDefaultTemplate))
		{
			str2 = _Parse.xml();
			if (m_bUsingDefaultAppDocTemplate)
			{
				nPos = str2.Find(_T("/"));
				while (nPos != -1)
				{
					str1 = str2.Left(nPos - 2);
					if (str1 == _T(""))
						break;
					str2 = str2.Mid(nPos + 1);
					nPos = str1.ReverseFind('|');
					if (nPos == -1)
						break;
					pTangramDocTemplateInfo = new TangramDocTemplateInfo();
					pTangramDocTemplateInfo->m_hWnd = m_pMDIMainWnd ? m_pMDIMainWnd->m_hWnd : nullptr;
					pTangramDocTemplateInfo->m_strFilter = _T("*.xml");
					CString strLib = str1.Mid(nPos + 1);
					str1 = str1.Left(nPos + 1);
					nPos = str1.ReverseFind('>');
					str3 = str1.Left(nPos - 1);
					str1 = str1.Mid(nPos);
					nPos = str1.Find(_T("|"));
					pTangramDocTemplateInfo->m_strDocTemplateKey = str1.Left(nPos).MakeLower().Mid(1);
					CString strDir = m_pMDIMainWnd ? _T("MDI") : _T("SDI");
					pTangramDocTemplateInfo->m_strTemplatePath = m_strAppCommonDocPath + _T("CommonMFCAppTemplate\\") + strDir + _T("\\DocTemplate\\");
					if (::PathIsDirectory(pTangramDocTemplateInfo->m_strTemplatePath) == false)
					{
						::CreateDirectory(pTangramDocTemplateInfo->m_strTemplatePath, nullptr);
					}
					CString str4 = str1.Mid(nPos + 1);
					m_strDocFilters += str4;
					nPos = str4.ReverseFind('.');
					str4 = str4.Mid(nPos);
					nPos = str4.ReverseFind('|');
					pTangramDocTemplateInfo->m_strExt = str4.Left(nPos);
					m_mapTangramDocTemplateInfo2[pTangramDocTemplateInfo->m_strExt] = pTangramDocTemplateInfo;
					ATLTRACE(_T("pTangramDocTemplateInfo:%x\n"), pTangramDocTemplateInfo);
					nPos = str3.ReverseFind('.');
					str1 = str3.Mid(nPos + 1);
					str3 = str3.Left(nPos);
					nPos = str3.ReverseFind('<');
					CString strProxyID = str3.Mid(nPos + 1);
					ATLTRACE(_T("ProxyID:%s\n"), strProxyID);
					pTangramDocTemplateInfo->m_strProxyID = strProxyID;
					nPos = str1.ReverseFind('\"');
					str1 = str1.Mid(nPos + 1);
					int nIndex = _wtoi(str1);
					ATLTRACE(_T("ResID:%x\n"), nIndex);
					HMODULE hHandle = nullptr;
					if (strLib != _T("") && strProxyID != _T(""))
					{
						if (m_pMDIMainWnd || m_pActiveMDIChildWnd)
						{
							CString s = strProxyID;
							s.Replace(_T("tangram"), _T(""));
							__int64 nTemplate = _wtoi64(s);
							pTangramDocTemplateInfo->m_pDocTemplate = (void*)nTemplate;
						}

						CString strKey = pTangramDocTemplateInfo->m_strDocTemplateKey;
						strKey.Replace(_T("."), _T(" "));
						int nImageIndex = -1;

						HICON hIcon = ::LoadIcon(hInstResource, MAKEINTRESOURCE(nIndex));
						if (hIcon)
						{
							nImageIndex = m_DocImageList.Add(hIcon);
							m_DocTemplateImageList.Add(hIcon);
							pTangramDocTemplateInfo->m_strLib = _T("");
						}
						pTangramDocTemplateInfo->m_nImageIndex = nImageIndex;
						if (nImageIndex != -1)
						{
							m_mapTangramDocTemplateInfo[i] = pTangramDocTemplateInfo;
							i++;
						}
						else
							delete pTangramDocTemplateInfo;
					}
					nPos = str2.Find(_T("/"));
				}
			}
			str2 = _Parse.xml();
			OutputDebugString(str2);

			nPos = str2.Find(_T("/"));
			while (nPos != -1)
			{
				str1 = str2.Left(nPos - 2);
				if (str1 == _T(""))
					break;
				str2 = str2.Mid(nPos + 1);
				nPos = str1.ReverseFind('|');
				if (nPos == -1)
					break;
				pTangramDocTemplateInfo = new TangramDocTemplateInfo();
				pTangramDocTemplateInfo->m_hWnd = m_pMDIMainWnd ? m_pMDIMainWnd->m_hWnd : nullptr;
				pTangramDocTemplateInfo->m_strFilter = _T("*.xml");
				CString strLib = str1.Mid(nPos + 1);
				str1 = str1.Left(nPos + 1);
				nPos = str1.ReverseFind('>');
				str3 = str1.Left(nPos - 1);
				str1 = str1.Mid(nPos);
				nPos = str1.Find(_T("|"));
				pTangramDocTemplateInfo->m_strDocTemplateKey = str1.Left(nPos).MakeLower().Mid(1);
				pTangramDocTemplateInfo->m_strTemplatePath = g_pTangram->m_strAppDataPath + _T("DocTemplate\\");
				CString str4 = str1.Mid(nPos + 1);
				m_strDocFilters += str4;
				nPos = str4.ReverseFind('.');
				str4 = str4.Mid(nPos);
				nPos = str4.ReverseFind('|');
				pTangramDocTemplateInfo->m_strExt = str4.Left(nPos);
				m_mapTangramDocTemplateInfo2[pTangramDocTemplateInfo->m_strExt] = pTangramDocTemplateInfo;
				ATLTRACE(_T("pTangramDocTemplateInfo:%x\n"), pTangramDocTemplateInfo);
				nPos = str3.ReverseFind('.');
				str1 = str3.Mid(nPos + 1);
				str3 = str3.Left(nPos);
				nPos = str3.ReverseFind('<');
				CString strProxyID = str3.Mid(nPos + 1);
				ATLTRACE(_T("ProxyID:%s\n"), strProxyID);
				pTangramDocTemplateInfo->m_strProxyID = strProxyID;
				nPos = str1.ReverseFind('\"');
				str1 = str1.Mid(nPos + 1);
				int nIndex = _wtoi(str1);
				ATLTRACE(_T("ResID:%x\n"), nIndex);
				HMODULE hHandle = nullptr;
				if (strLib != _T("") && strProxyID != _T(""))
				{
					if (m_pMDIMainWnd || m_pActiveMDIChildWnd)
					{
						CString s = strProxyID;
						s.Replace(_T("tangram"), _T(""));
						__int64 nTemplate = _wtoi64(s);
						pTangramDocTemplateInfo->m_pDocTemplate = (void*)nTemplate;
					}

					CString strKey = pTangramDocTemplateInfo->m_strDocTemplateKey;
					strKey.Replace(_T("."), _T(" "));
					CString strDir = pTangramDocTemplateInfo->m_strTemplatePath + strKey + _T("\\");
					if (::PathIsDirectory(strDir) == false)
					{
						if (::SHCreateDirectoryEx(NULL, strDir, NULL))
						{
							ATLTRACE(L"CreateDirectory failed (%d)\n", GetLastError());
						}
						else
						{
							CString strXml = _T("");
							strXml.Format(_T("<%s mainframeid='defaultmainframe' apptitle='%s' />"), pTangramDocTemplateInfo->m_strDocTemplateKey, strKey);
							CTangramXmlParse m_Parse;
							m_Parse.LoadXml(strXml);
							m_Parse.SaveFile(strDir + _T("Startup.xml"));
						}
					}
					int nImageIndex = -1;
					HICON hIcon = ::LoadIcon(hInstResource, MAKEINTRESOURCE(nIndex));
					if (hIcon)
					{
						nImageIndex = m_DocImageList.Add(hIcon);
						m_DocTemplateImageList.Add(hIcon);
						pTangramDocTemplateInfo->m_strLib = _T("");
					}
					pTangramDocTemplateInfo->m_nImageIndex = nImageIndex;
					if (nImageIndex != -1)
					{
						m_mapTangramDocTemplateInfo[i] = pTangramDocTemplateInfo;
						i++;
					}
					else
						delete pTangramDocTemplateInfo;
				}
				nPos = str2.Find(_T("/"));
			}
		}
	}
	else if (m_strDefaultTemplate2 != _T(""))
	{
		CTangramXmlParse _Parse;
		if (_Parse.LoadXml(m_strDefaultTemplate2))
		{
			str2 = _Parse.xml();
			int nCount = _Parse.GetCount();
			for (int i = 0; i < nCount; i++)
			{
				CTangramXmlParse* pParse = _Parse.GetChild(i);
				if (pParse)
				{
					int nImageIndex = -1;
					pTangramDocTemplateInfo = new TangramDocTemplateInfo();
					pTangramDocTemplateInfo->m_hWnd = m_pMDIMainWnd ? m_pMDIMainWnd->m_hWnd : nullptr;
					pTangramDocTemplateInfo->m_strFilter = _T("*.xml");
					int nIndex = pParse->attr(_T("ResID"), 0);
					if (nIndex == 0)
					{
						::GetModuleFileName(theApp.m_hInstance, m_szBuffer, MAX_PATH);
						CString strPath = m_szBuffer;
						int nPos = strPath.ReverseFind('\\');
						strPath = strPath.Left(nPos + 1) + _T("TangramInit.dll");
						if (::PathFileExists(strPath))
						{
							HMODULE hHandle = ::LoadLibraryEx(strPath, nullptr, LOAD_LIBRARY_AS_DATAFILE);
							HICON hIcon = ::LoadIcon(hHandle, MAKEINTRESOURCE(100));
							if (hIcon)
							{
								nImageIndex = m_DocImageList.Add(hIcon);
								m_DocTemplateImageList.Add(hIcon);
							}
						}
					}
					else
					{
						HICON hIcon = ::LoadIcon(hInstResource, MAKEINTRESOURCE(nIndex));
						if (hIcon)
						{
							nImageIndex = m_DocImageList.Add(hIcon);
							m_DocTemplateImageList.Add(hIcon);
						}
					}
					if (nImageIndex != -1)
						pTangramDocTemplateInfo->m_nImageIndex = nImageIndex;
					pTangramDocTemplateInfo->m_strLib = _T("");
					m_mapTangramDocTemplateInfo[i] = pTangramDocTemplateInfo;
					pTangramDocTemplateInfo->m_strDocTemplateKey = pParse->attr(_T("name"), _T("default"));
					pTangramDocTemplateInfo->m_strTemplatePath = m_strAppDataPath + _T("DocTemplate\\");
				}
			}
			i = nCount;
		}
	}
	CTangramXmlParse _Parse;
	if (_Parse.LoadFile(_T("Tangramdoctemplate.xml")))
	{
		str2 = _Parse.xml();
		OutputDebugString(str2);

		nPos = str2.Find(_T("/"));
		while (nPos != -1)
		{
			str1 = str2.Left(nPos - 2);
			if (str1 == _T(""))
				break;
			str2 = str2.Mid(nPos + 1);
			nPos = str1.ReverseFind('|');
			if (nPos == -1)
				break;
			pTangramDocTemplateInfo = new TangramDocTemplateInfo();
			pTangramDocTemplateInfo->m_hWnd = nullptr;
			pTangramDocTemplateInfo->m_strFilter = _T("*.xml");
			CString strLib = str1.Mid(nPos + 1);
			str1 = str1.Left(nPos + 1);
			nPos = str1.ReverseFind('>');
			str3 = str1.Left(nPos - 1);
			str1 = str1.Mid(nPos);
			nPos = str1.Find(_T("|"));
			pTangramDocTemplateInfo->m_strDocTemplateKey = str1.Left(nPos).MakeLower().Mid(1);
			pTangramDocTemplateInfo->m_strLib = strLib;
			CString str4 = str1.Mid(nPos + 1);
			m_strDocFilters += str4;
			nPos = str4.ReverseFind('.');
			str4 = str4.Mid(nPos);
			nPos = str4.ReverseFind('|');
			pTangramDocTemplateInfo->m_strExt = str4.Left(nPos);
			m_mapTangramDocTemplateInfo2[pTangramDocTemplateInfo->m_strExt] = pTangramDocTemplateInfo;
			ATLTRACE(_T("pTangramDocTemplateInfo:%x\n"), pTangramDocTemplateInfo);
			nPos = str3.ReverseFind('.');
			str1 = str3.Mid(nPos + 1);
			str3 = str3.Left(nPos);
			nPos = str3.ReverseFind('<');
			CString strProxyID = str3.Mid(nPos + 1);
			ATLTRACE(_T("ProxyID:%s\n"), strProxyID);
			pTangramDocTemplateInfo->m_strProxyID = strProxyID;
			pTangramDocTemplateInfo->m_strTemplatePath = m_strAppCommonDocPath + strProxyID + _T("\\");;
			nPos = str1.ReverseFind('\"');
			str1 = str1.Mid(nPos + 1);
			int nIndex = _wtoi(str1);
			ATLTRACE(_T("ResID:%x\n"), nIndex);
			HMODULE hHandle = nullptr;
			if (strLib != _T("") && strProxyID != _T(""))
			{
				int nImageIndex = -1;
				HICON hIcon = ::LoadIcon(hInstResource, MAKEINTRESOURCE(nIndex));
				if (hIcon)
				{
					nImageIndex = m_DocImageList.Add(hIcon);
					m_DocTemplateImageList.Add(hIcon);
					pTangramDocTemplateInfo->m_strLib = _T("");
				}
				pTangramDocTemplateInfo->m_nImageIndex = nImageIndex;
				if (nImageIndex != -1)
				{
					m_mapTangramDocTemplateInfo[i] = pTangramDocTemplateInfo;
					i++;
				}
				else
					delete pTangramDocTemplateInfo;
			}
			nPos = str2.Find(_T("/"));
		}
	}
	CTangramXmlParse m_Parse;
	if (m_Parse.LoadFile(g_pTangram->m_strAppCommonDocPath + _T("\\Tangramdoctemplate.xml")))
	{
		str2 = m_Parse.xml();
		OutputDebugString(str2);

		nPos = str2.Find(_T("/"));
		while (nPos != -1)
		{
			str1 = str2.Left(nPos - 2);
			if (str1 == _T(""))
				break;
			str2 = str2.Mid(nPos + 1);
			nPos = str1.ReverseFind('|');
			if (nPos == -1)
				break;
			pTangramDocTemplateInfo = new TangramDocTemplateInfo();
			pTangramDocTemplateInfo->m_hWnd = nullptr;
			pTangramDocTemplateInfo->m_strFilter = _T("*.xml");
			CString strLib = str1.Mid(nPos + 1);
			str1 = str1.Left(nPos + 1);
			nPos = str1.ReverseFind('>');
			str3 = str1.Left(nPos - 1);
			str1 = str1.Mid(nPos);
			nPos = str1.Find(_T("|"));
			pTangramDocTemplateInfo->m_strDocTemplateKey = str1.Left(nPos).MakeLower().Mid(1);
			pTangramDocTemplateInfo->m_strLib = strLib;
			CString str4 = str1.Mid(nPos + 1);
			m_strDocFilters += str4;
			nPos = str4.ReverseFind('.');
			str4 = str4.Mid(nPos);
			nPos = str4.ReverseFind('|');
			pTangramDocTemplateInfo->m_strExt = str4.Left(nPos);
			m_mapTangramDocTemplateInfo2[pTangramDocTemplateInfo->m_strExt] = pTangramDocTemplateInfo;
			ATLTRACE(_T("pTangramDocTemplateInfo:%x\n"), pTangramDocTemplateInfo);
			nPos = str3.ReverseFind('.');
			str1 = str3.Mid(nPos + 1);
			str3 = str3.Left(nPos);
			nPos = str3.ReverseFind('<');
			CString strProxyID = str3.Mid(nPos + 1);
			ATLTRACE(_T("ProxyID:%s\n"), strProxyID);
			pTangramDocTemplateInfo->m_strProxyID = strProxyID;
			pTangramDocTemplateInfo->m_strTemplatePath = m_strAppCommonDocPath + strProxyID + _T("\\");
			nPos = str1.ReverseFind('\"');
			str1 = str1.Mid(nPos + 1);
			int nIndex = _wtoi(str1);
			ATLTRACE(_T("ResID:%x\n"), nIndex);
			HMODULE hHandle = nullptr;
			if (strLib != _T("") && strProxyID != _T(""))
			{
				int nImageIndex = -1;
				CString strdll = strPath + strProxyID + _T("\\") + strLib + _T(".dll");
				if (::PathFileExists(strdll))
				{
					hHandle = ::LoadLibraryEx(strdll, nullptr, LOAD_LIBRARY_AS_DATAFILE);
				}
				if (hHandle == nullptr)
				{
					strdll = m_strAppCommonDocPath2 + strProxyID + _T("\\") + strLib + _T(".dll");
					if (::PathFileExists(strdll))
					{
						hHandle = ::LoadLibraryEx(strdll, nullptr, LOAD_LIBRARY_AS_DATAFILE);
					}
				}
				if (hHandle)
				{
					nImageIndex = m_DocImageList.Add(::LoadIcon(hHandle, MAKEINTRESOURCE(nIndex)));
					m_DocTemplateImageList.Add(::LoadIcon(hHandle, MAKEINTRESOURCE(nIndex)));
					pTangramDocTemplateInfo->m_strLib = strdll;
					::FreeLibrary(hHandle);
				}
				else
				{
					HICON hIcon = ::LoadIcon(hInstResource, MAKEINTRESOURCE(nIndex));
					if (hIcon)
					{
						nImageIndex = m_DocImageList.Add(hIcon);
						m_DocTemplateImageList.Add(hIcon);
						pTangramDocTemplateInfo->m_strLib = _T("");
					}
				}
				pTangramDocTemplateInfo->m_nImageIndex = nImageIndex;
				if (nImageIndex != -1)
				{
					m_mapTangramDocTemplateInfo[i] = pTangramDocTemplateInfo;
					i++;
				}
				else
					delete pTangramDocTemplateInfo;
			}
			nPos = str2.Find(_T("/"));
		}

		pTangramDocTemplateInfo = nullptr;
		CString strOfficePath = g_pTangram->GetOfficePath();
		if (strOfficePath != _T(""))
		{
			SHFILEINFO sfi;
			SHGetFileInfo(strOfficePath+_T("excel.exe"),	0,&sfi,	sizeof(SHFILEINFO),	SHGFI_ICON|SHGFI_SYSICONINDEX | SHGFI_LARGEICON);
			int nImageIndex = m_DocImageList.Add(sfi.hIcon);
			m_DocTemplateImageList.Add(sfi.hIcon);
			pTangramDocTemplateInfo = new TangramDocTemplateInfo();
			pTangramDocTemplateInfo->m_hWnd = nullptr;
			pTangramDocTemplateInfo->m_strFilter = _T("*.xml");
			pTangramDocTemplateInfo->m_bCOMObj = true;
			pTangramDocTemplateInfo->m_nImageIndex = nImageIndex;
			pTangramDocTemplateInfo->m_strProxyID = _T("excel.application");
			pTangramDocTemplateInfo->m_strDocTemplateKey = _T("Excel WorkBook");
			pTangramDocTemplateInfo->m_strTemplatePath = m_strAppCommonDocPath + pTangramDocTemplateInfo->m_strProxyID + _T("\\");;
			m_mapTangramDocTemplateInfo[i] = pTangramDocTemplateInfo;
			i++;

			SHGetFileInfo(strOfficePath + _T("winword.exe"), 0, &sfi, sizeof(SHFILEINFO), SHGFI_ICON | SHGFI_SYSICONINDEX | SHGFI_LARGEICON);
			nImageIndex = m_DocImageList.Add(sfi.hIcon);
			m_DocTemplateImageList.Add(sfi.hIcon);
			pTangramDocTemplateInfo = new TangramDocTemplateInfo();
			pTangramDocTemplateInfo->m_hWnd = nullptr;
			pTangramDocTemplateInfo->m_bCOMObj = true;
			pTangramDocTemplateInfo->m_strFilter = _T("*.xml");
			pTangramDocTemplateInfo->m_nImageIndex = nImageIndex;
			pTangramDocTemplateInfo->m_strProxyID = _T("word.application");
			pTangramDocTemplateInfo->m_strTemplatePath = g_pTangram->m_strAppCommonDocPath + pTangramDocTemplateInfo->m_strProxyID + _T("\\");;
			pTangramDocTemplateInfo->m_strDocTemplateKey = _T("Word Document");
			m_mapTangramDocTemplateInfo[i] = pTangramDocTemplateInfo;
			i++;

			SHGetFileInfo(strOfficePath + _T("powerpnt.exe"), 0, &sfi, sizeof(SHFILEINFO), SHGFI_ICON | SHGFI_SYSICONINDEX | SHGFI_LARGEICON);
			nImageIndex = m_DocImageList.Add(sfi.hIcon);
			m_DocTemplateImageList.Add(sfi.hIcon);
			pTangramDocTemplateInfo = new TangramDocTemplateInfo();
			m_mapTangramDocTemplateInfo[i] = pTangramDocTemplateInfo;
			pTangramDocTemplateInfo->m_hWnd = nullptr;
			pTangramDocTemplateInfo->m_bCOMObj = true;
			pTangramDocTemplateInfo->m_strFilter = _T("*.xml");
			pTangramDocTemplateInfo->m_nImageIndex = nImageIndex;
			pTangramDocTemplateInfo->m_strDocTemplateKey = _T("Powerpoint Presentation");
			pTangramDocTemplateInfo->m_strProxyID = _T("powerpoint.application");
			pTangramDocTemplateInfo->m_strTemplatePath = g_pTangram->m_strAppCommonDocPath + pTangramDocTemplateInfo->m_strProxyID + _T("\\");;
			i++;

			SHGetFileInfo(strOfficePath + _T("outlook.exe"), 0, &sfi, sizeof(SHFILEINFO), SHGFI_ICON | SHGFI_SYSICONINDEX | SHGFI_LARGEICON);
			nImageIndex = m_DocImageList.Add(sfi.hIcon);
			m_DocTemplateImageList.Add(sfi.hIcon);
			pTangramDocTemplateInfo = new TangramDocTemplateInfo();
			pTangramDocTemplateInfo->m_nImageIndex = nImageIndex;
			pTangramDocTemplateInfo->m_strFilter = _T("*.xml");
			pTangramDocTemplateInfo->m_hWnd = nullptr;
			pTangramDocTemplateInfo->m_bCOMObj = true;
			m_mapTangramDocTemplateInfo[i] = pTangramDocTemplateInfo;
			pTangramDocTemplateInfo->m_strDocTemplateKey = _T("OutLook Explorer");
			pTangramDocTemplateInfo->m_strProxyID = _T("outlook.application");
			pTangramDocTemplateInfo->m_strTemplatePath = g_pTangram->m_strAppCommonDocPath + pTangramDocTemplateInfo->m_strProxyID + _T("\\");;
			i++;
		}
		if (m_bEclipse)
		{
			::GetModuleFileName(theApp.m_hInstance, m_szBuffer, MAX_PATH);
			CString strPath = m_szBuffer;
			int nPos = strPath.ReverseFind('\\');
			strPath = strPath.Left(nPos + 1) + _T("TangramInit.dll");
			if (::PathFileExists(strPath))
			{
				HMODULE hHandle = ::LoadLibraryEx(strPath, nullptr, LOAD_LIBRARY_AS_DATAFILE);
				int nImageIndex = m_DocImageList.Add(::LoadIcon(hHandle, MAKEINTRESOURCE(106)));
				m_DocTemplateImageList.Add(::LoadIcon(hHandle, MAKEINTRESOURCE(106)));
				pTangramDocTemplateInfo = new TangramDocTemplateInfo();
				pTangramDocTemplateInfo->m_hWnd = nullptr;
				pTangramDocTemplateInfo->m_nImageIndex = nImageIndex;
				pTangramDocTemplateInfo->m_strFilter = _T("*.*");
				pTangramDocTemplateInfo->m_bCOMObj = true;
				m_mapTangramDocTemplateInfo[i] = pTangramDocTemplateInfo;
				pTangramDocTemplateInfo->m_strDocTemplateKey = _T("Eclipse WorkBench");
				pTangramDocTemplateInfo->m_strProxyID = _T("eclipse.application");
				pTangramDocTemplateInfo->m_strTemplatePath = m_strAppDataPath + _T("WorkBench\\");
				//pTangramDocTemplateInfo->m_strTemplatePath = m_strAppCommonDocPath + pTangramDocTemplateInfo->m_strProxyID + _T("\\");;
				i++;
				::FreeLibrary(hHandle);
			}
		}

		m_strDocFilters += _T("All Files (*.*)|*.*||");
	}
}

STDMETHODIMP CTangram::OpenTangramFile(ITangramDoc** ppDoc)
{
	if (m_mapTangramDocTemplateInfo.size() == 0)
		InitTangramDocManager();
	LRESULT lRes = ::SendMessage(m_hTangramWnd, WM_TANGRAMMSG, 1, 0);
	if (lRes)
	{
		CTangramDoc* pDoc = (CTangramDoc*)lRes;
		*ppDoc = pDoc;
	}
	return S_OK;
}

CString CTangram::ConfigJavaVMInfo(CString stroption)
{
	CString strRet = _T("");
	if (stroption.Find(_T("java.class.path=")) != -1)
	{
		CString strJavaClassPath = m_strAppPath + _T("TangramJavaClassPath.xml");
		if (::PathFileExists(strJavaClassPath))
		{
			int nPos = stroption.Find(_T("="));
			CString s0 = stroption.Left(nPos + 1);
			stroption = stroption.Mid(nPos + 1);
			nPos = stroption.ReverseFind('/');
			if (nPos == -1)
				nPos = stroption.ReverseFind('\\');
			CTangramXmlParse m_Parse;
			if (m_Parse.LoadFile(strJavaClassPath))
			{
				CString s1 = _T("");
				CString str2 = stroption.Left(nPos + 1);
				int nCount = m_Parse.GetCount();
				for (int j = 0; j < nCount; j++)
				{
					CTangramXmlParse* pParse = m_Parse.GetChild(j);
					if (pParse)
					{
						CString strClass = pParse->attr(_T("classinfo"), _T(""));
						CString strLib = pParse->attr(_T("lib"), _T(""));
						if (strLib != _T("") && strClass != _T(""))
						{
							g_pTangram->m_mapJavaNativeInfo[strLib] = strClass;
						}
						CString strFile = str2 + pParse->text();
						if (::PathFileExists(strFile))
						{
							s1 += strFile;
							s1 += _T(";");
						}
					}
				}
				stroption = s0 + stroption + ";" + s1;
				//stroption += m_strProgramFilePath + _T("Tangram\\tangramjava");
				strRet = stroption;
			}
		}
	}
	return strRet;
}

HICON CTangram::GetAppIcon(int nIndex)
{
	switch (nIndex)
	{
	case 0:
		{
			if (m_hLargeIcon == nullptr)
			{
				if(g_pTangram->m_pCLRProxy)
					m_hLargeIcon=g_pTangram->m_pCLRProxy->GetAppIcon(nIndex);
			}
			return m_hLargeIcon;
		}
		break;
	case 1:
		{
			if (m_hSmallIcon == nullptr)
			{
				if(g_pTangram->m_pCLRProxy)
					m_hSmallIcon =g_pTangram->m_pCLRProxy->GetAppIcon(nIndex);
			}
			return m_hSmallIcon;
		}
		break;
	}

	return nullptr;
}

bool CTangram::ImportTangramDocTemplate(CString strFilePath)
{
	TangramDocInfo m_TangramDocInfo;
	m_TangramDocInfo.m_strAppProxyID = m_TangramDocInfo.m_strDocID = m_TangramDocInfo.m_strMainFrameID = m_TangramDocInfo.m_strTangramData = m_TangramDocInfo.m_strTangramID = _T("");
	GetTangramInfo(strFilePath, &m_TangramDocInfo);
	::DeleteFile(strFilePath);
	if (m_TangramDocInfo.m_strTangramID == _T("19631222199206121965060119820911"))
	{
		CTangramXmlParse m_Parse;
		if (m_Parse.LoadXml(m_TangramDocInfo.m_strTangramData))
		{
			CString strCommonDocPath = m_strAppCommonDocPath + m_TangramDocInfo.m_strAppProxyID + _T("\\");
			CString strCategory = _T("");
			int nPos = strFilePath.ReverseFind('/');
			if (nPos == -1)
			{
				nPos = strFilePath.Find(_T("\\"));
			}
			if (nPos != -1)
			{
				CString strPath = strFilePath.Left(nPos);
				int nPos2 = strPath.ReverseFind('\\');
				CString strPath2 = strPath.Left(nPos2);
				strCategory = strPath.Mid(nPos2 + 1);
				strCommonDocPath += strCategory;
				strCommonDocPath += _T("\\");
				if (::PathIsDirectory(strCommonDocPath) == false)
					if (::SHCreateDirectoryEx(NULL, strCommonDocPath, NULL))
						return false;

				CString strName = strFilePath.Mid(nPos + 1);
				nPos = strName.ReverseFind('.');
				strName = strName.Left(nPos) + _T(".xml");
				strCommonDocPath += strName;
			}
			m_Parse.put_attr(_T("apptitle"), strCategory);
			return m_Parse.SaveFile(strCommonDocPath);
		}
	}
	return false;
}

STDMETHODIMP CTangram::OpenTangramDocFile(BSTR bstrFilePath, ITangramDoc** ppDoc)
{
	CString strFilePath = OLE2T(bstrFilePath);
	if (::PathFileExists(strFilePath))
	{
		m_pActiveMDIChildWnd = nullptr;
		strFilePath.MakeLower();

		auto itDoc = m_mapOpenDoc.find(strFilePath);
		if (itDoc != m_mapOpenDoc.end())
		{
			CTangramDoc* pDoc = itDoc->second;
			pDoc->m_strPath = strFilePath;
			CTangramDocWnd* pWnd = pDoc->m_pActiveWnd;
			WINDOWPLACEMENT wndPlacement;
			pWnd->GetWindowPlacement(&wndPlacement);
			if (wndPlacement.showCmd == SW_MINIMIZE || wndPlacement.showCmd == SW_SHOWMINIMIZED)
			{
				pWnd->ShowWindow(SW_RESTORE);
			};
			pWnd->SetFocus();
		}

		TangramDocInfo m_TangramDocInfo;
		m_TangramDocInfo.m_strAppProxyID = m_TangramDocInfo.m_strDocID = m_TangramDocInfo.m_strMainFrameID = m_TangramDocInfo.m_strTangramData = m_TangramDocInfo.m_strTangramID = _T("");
		GetTangramInfo(strFilePath, &m_TangramDocInfo);
		if (m_TangramDocInfo.m_strTangramID == _T("19631222199206121965060119820911"))
		{
			ITangramAppProxy* pProxy = nullptr;
			auto it = m_mapTangramAppProxy.find(m_TangramDocInfo.m_strAppProxyID.MakeLower());
			if (it != m_mapTangramAppProxy.end())
				pProxy = it->second;
			else
			{
				CString strPath = m_strAppPath;
				int nPos = m_TangramDocInfo.m_strAppProxyID.Find(_T("."));
				m_TangramDocInfo.m_strAppName = m_TangramDocInfo.m_strAppProxyID.Left(nPos);
				HMODULE hHandle = nullptr;
				CString strdll = strPath + m_TangramDocInfo.m_strAppProxyID + _T("\\") + m_TangramDocInfo.m_strAppName + _T(".dll");
				m_strCurrentFrameID = m_TangramDocInfo.m_strMainFrameID;
				if (::PathFileExists(strdll))
					hHandle = ::LoadLibrary(strdll);
				if (hHandle == nullptr)
				{
					strdll = m_strAppCommonDocPath2 + m_TangramDocInfo.m_strAppProxyID + _T("\\") + m_TangramDocInfo.m_strAppName + _T(".dll");
					if (::PathFileExists(strdll))
						hHandle = ::LoadLibrary(strdll);
				}
				if (hHandle)
				{
					it = m_mapTangramAppProxy.find(m_TangramDocInfo.m_strAppProxyID.MakeLower());
					if (it != m_mapTangramAppProxy.end())
					{
						pProxy = it->second;
					}
				}
				m_strCurrentFrameID = _T("");
			}
			if (pProxy)
			{
				HWND hMainWnd = pProxy->CreateNewFrame(m_TangramDocInfo.m_strMainFrameID);
				auto itDoc = m_mapOpenDoc.find(strFilePath);
				if (itDoc == m_mapOpenDoc.end())
				{
					auto it2 = m_mapTemplateInfo.find(m_TangramDocInfo.m_strDocID.MakeLower());
					if (it2 != m_mapTemplateInfo.end())
					{
						*ppDoc = it->second->OpenDocument(it2->second, strFilePath, true);
						CTangramDoc* pDoc = (CTangramDoc*)(*ppDoc);
						pDoc->m_strPath = strFilePath;
						m_mapOpenDoc[strFilePath] = pDoc;
					}
				}
				else
				{
					CTangramDoc* pDoc = itDoc->second;
					pDoc->m_strPath = strFilePath;
					CTangramDocWnd* pWnd = pDoc->m_pActiveWnd;
					if (pWnd)
					{
						WINDOWPLACEMENT wndPlacement;
						pWnd->GetWindowPlacement(&wndPlacement);
						if (wndPlacement.showCmd == SW_MINIMIZE || wndPlacement.showCmd == SW_SHOWMINIMIZED)
						{
							pWnd->ShowWindow(SW_RESTORE);
						};
						pWnd->SetFocus();
					}
				}
			}
		}
		else
		{
			HWND hwnd = nullptr;
			if (m_pMDIMainWnd)
			{
				hwnd = m_pMDIMainWnd->m_hWnd;
				::SendMessage(hwnd, WM_QUERYAPPPROXY, (WPARAM)strFilePath.GetBuffer(), TANGRAM_CONST_OPENFILE);
			}
			else if (m_pActiveMDIChildWnd)
			{
				hwnd = m_pActiveMDIChildWnd->m_hWnd;
				::SendMessage(hwnd, WM_TANGRAMMSG, (WPARAM)strFilePath.GetBuffer(), TANGRAM_CONST_OPENFILE);
			}
		}
	}

	return S_OK;
}

void CTangram::GetTangramInfo(CString strFile, TangramDocInfo* pTangramDocInfo)
{
	if (pTangramDocInfo == nullptr)
		return;
#define DELETE_EXCEPTION(e) do { if(e) { e->Delete(); } } while (0)
	CMirrorFile* pFile = new CMirrorFile;
	if (!pFile->Open(strFile, CFile::modeRead, nullptr))
	{
		delete pFile;
		pFile = NULL;
		return;
	}
	CArchive loadArchive(pFile, CArchive::load);
	TRY
	{
		if (pFile->GetLength() != 0)
		{
			loadArchive >> pTangramDocInfo->m_strTangramID;
			if (pTangramDocInfo->m_strTangramID == _T("19631222199206121965060119820911"))
			{
				loadArchive >> pTangramDocInfo->m_strAppProxyID;
				loadArchive >> pTangramDocInfo->m_strAppName;
				loadArchive >> pTangramDocInfo->m_strMainFrameID;
				loadArchive >> pTangramDocInfo->m_strDocID;
				loadArchive >> pTangramDocInfo->m_strTangramData;
			}
		}
		loadArchive.Close();
		ASSERT_KINDOF(CFile, pFile);
		pFile->Close();
		delete pFile;
	}
		CATCH_ALL(e)
	{
		pFile->Abort();
		delete pFile;
		DELETE_EXCEPTION(e);
		return;
	}
	END_CATCH_ALL
}

STDMETHODIMP CTangram::CreateOfficeDocument(BSTR bstrXml)
{
	CComPtr<IWorkBenchWindow> pWorkBenchWindow;
	NewWorkBench(bstrXml, &pWorkBenchWindow);
	return S_OK;
}

STDMETHODIMP CTangram::NewWorkBench(BSTR bstrTangramDoc, IWorkBenchWindow** ppWorkBenchWindow)
{
	BOOL bTangramDoc = FALSE;
	CString strDoc = OLE2T(bstrTangramDoc);
	TangramDocInfo m_TangramDocInfo;
	m_TangramDocInfo.m_strAppProxyID = m_TangramDocInfo.m_strDocID = m_TangramDocInfo.m_strMainFrameID = m_TangramDocInfo.m_strTangramData = m_TangramDocInfo.m_strTangramID = _T("");
	GetTangramInfo(strDoc, &m_TangramDocInfo);
	if (m_TangramDocInfo.m_strTangramID == _T("19631222199206121965060119820911"))
		bTangramDoc = TRUE;
	if (bTangramDoc)
	{
		if (::IsWindow(m_hEclipseHideWnd) && m_mapWorkBenchWnd.size())
		{
			CEclipseWnd* pWnd = (CEclipseWnd*)m_mapWorkBenchWnd.begin()->second;
			if (pWnd)
			{
				m_strCurrentEclipsePagePath = strDoc;
				::SendMessage(pWnd->m_hWnd, WM_COMMAND, pWnd->m_nNewWinCmdID, 0);
				*ppWorkBenchWindow = m_pActiveEclipseWnd;
			}
		}
		else
		{
			CString strAppID = _T("eclipse.application.1");
			auto it = m_mapRemoteTangramCore.find(strAppID);
			if (it == m_mapRemoteTangramCore.end())
				StartApplication(CComBSTR(L"eclipse.application.1"), bstrTangramDoc);
			else
			{
				CComPtr<IWorkBenchWindow> pIWorkBenchWindow;
				it->second->NewWorkBench(bstrTangramDoc, &pIWorkBenchWindow);
			}
		}
	}

	return S_OK;
}

STDMETHODIMP CTangram::CreateOutLookObj(BSTR bstrObjType, int nType, BSTR bstrURL, IDispatch** ppRetDisp)
{
	CString m_strAppName = OLE2T(bstrObjType);

	CComPtr<OutLook::_Application> pApp;
	pApp.CoCreateInstance(CComBSTR(L"OutLook.Application"), 0, CLSCTX_INPROC_SERVER | CLSCTX_LOCAL_SERVER);
	*ppRetDisp = pApp.p;
	(*ppRetDisp)->AddRef();
	CComPtr<OutLook::_Explorers>		m_pExplorers;
	CComPtr<OutLook::_Inspectors>		m_pInspectors;
	pApp->get_Explorers(&m_pExplorers);
	pApp->get_Inspectors(&m_pInspectors);
	if (m_pExplorers)
	{
		CComPtr<OutLook::_Explorer>		m_pExplorer;
		CComPtr<OutLook::_NameSpace>	pSessionDisp;
		HRESULT hr = pApp->get_Session(&pSessionDisp);
		if (hr == S_OK)
		{
			if (m_strAppName.CompareNoCase(_T("explorer")) == 0)
			{
				CComPtr<OutLook::MAPIFolder> m_pFolder;
				pSessionDisp->GetDefaultFolder((OutLook::OlDefaultFolders)nType, &m_pFolder);
				m_pExplorers->Add(CComVariant(m_pFolder), OutLook::OlFolderDisplayMode::olFolderDisplayNormal, &m_pExplorer);
				if (m_pExplorer)
					m_pExplorer->Display();
			}
			else
			{
				//enum OlItemType
				//{
				//	olMailItem = 0,
				//	olAppointmentItem = 1,
				//	olContactItem = 2,
				//	olTaskItem = 3,
				//	olJournalItem = 4,
				//	olNoteItem = 5,
				//	olPostItem = 6,
				//	olDistributionListItem = 7,
				//	olMobileItemSMS = 11,
				//	olMobileItemMMS = 12
				//};
				CComPtr<IDispatch> pItem;
				pApp->CreateItem((OutLook::OlItemType)nType, &pItem);
				CComQIPtr<OutLook::_MailItem> pMailItem(pItem);
				if (pMailItem)
				{
					//pMailItem->put_To(CComBSTR(L"xxx@mailtest.com"));
				}
				CComPtr<OutLook::_Inspector> _pInspector;
				m_pInspectors->Add(pItem, &_pInspector);
				_pInspector->Display();
			}
		}
	}

	return S_OK;
}

STDMETHODIMP CTangram::ClearHeader()
{
	return S_OK;
}

STDMETHODIMP CTangram::InitEclipseApp()
{
	if (launchMode == -1)
	{
		GetLaunchMode();
		if (launchMode == -1)
			return S_OK;
	}
	if (launchMode != -1 && m_pTangramDelegate->m_pJVMenv == nullptr)
	{
		{
			if (m_strAppPath == _T(""))
				Init();
			CString strplugins = m_strAppPath + _T("plugins\\");
			m_bEclipse = ::PathIsDirectory(strplugins);
		}
		if (m_bEclipse)
		{
			CString strPath = m_strAppPath + _T("plugins\\*.jar");
			//CString strPath = strplugins + _T("*.jar");

			_wfinddata_t fd;
			fd.attrib = FILE_ATTRIBUTE_DIRECTORY;
			intptr_t pf = _wfindfirst(strPath, &fd);
			m_bEclipse = (fd.attrib&FILE_ATTRIBUTE_DIRECTORY) == 0;
			if (m_bEclipse == false)
			{
				while (!_wfindnext(pf, &fd))
				{
					m_bEclipse = (fd.attrib&FILE_ATTRIBUTE_DIRECTORY) == 0;
					if (m_bEclipse)
					{
						break;
					}
				}
			}
			_findclose(pf);
		}
		if (m_bEclipse)
		{
			m_strStartJarPath =  DEFAULT_EQUINOX_STARTUP;
			//CString _strBridgeJavaClass = _T("org/eclipse/equinox/launcher/JNIBridge");
			//_strBridgeJavaClass.Replace(_T("."), _T("/"));
			//USES_CONVERSION;
			m_strBridgeJavaClass = "org/eclipse/equinox/launcher/JNIBridge";// T2A(_strBridgeJavaClass);
			jarFile = findStartupJar();
			if (jarFile != nullptr)
			{
				m_bLoadEclipseDelay = true;
				EclipseInit();
				if (::IsWindow(m_hMainWnd) == false)
				{
					if (m_nAppType== TANGRAM_APP_ECLIPSE)
						::PostQuitMessage(0);
					else
						m_nAppType = TANGRAM_APP_WILLCLOSE;
				}
			}
			else
				m_bEclipse = false;
		}
	}
	return S_OK;
}

STDMETHODIMP CTangram::InitCLRApp(BSTR strInitXml, LONGLONG* llHandle)
{
	LoadCLR();
	CTangramXmlParse m_Parse;
	if (m_Parse.LoadXml(OLE2T(strInitXml)))
	{
		CString strLib = m_strAppPath + m_Parse.attr(_T("libname"), _T(""));
		CString strObjName = m_strAppPath + m_Parse.attr(_T("objname"), _T(""));
		CString strFunctionName = m_strAppPath + m_Parse.attr(_T("functionname"), _T(""));
		if (strLib != _T("") && strObjName != _T("") && strFunctionName != _T(""))
		{
			DWORD dwRetCode = 0;
			HRESULT hrStart = m_pClrHost->ExecuteInDefaultAppDomain(
				strLib,
				strObjName,
				strFunctionName,
				strInitXml,
				&dwRetCode);
			*llHandle = (LONGLONG)dwRetCode;
		}
	}

	return S_OK;
}

//STDMETHODIMP CTangram::ReadTextFromWeb(BSTR bstrURLBase, BSTR bstrOrg, BSTR bstrRepo, BSTR bstrBranch, BSTR bstrFile, BSTR bstrTarget, LONGLONG hNotify)
//{
//	CString strKey = OLE2T(bstrTarget);
//	CString _strKey = _T(",");
//	_strKey += strKey;
//	_strKey += _T(",");
//	if (m_strAsynKeys.Find(_strKey) == -1)
//		m_strAsynKeys += _strKey;
//	else
//		return S_OK;
//
//	CString _strURL = OLE2T(bstrURLBase);
//	if (_strURL == _T(""))
//		_strURL = _T("https://raw.githubusercontent.com/");
//	CString s = _T("");
//	CString strOrg = OLE2T(bstrOrg);
//	CString strRepo = OLE2T(bstrRepo);
//	CString strBranch = OLE2T(bstrBranch);
//	CString strPath = OLE2T(bstrFile);
//	s.Format(_T("%s/%s/%s/%s"), strOrg, strRepo, strBranch, strPath);
//	s.Replace(_T("//"), _T("/"));
//	s.Replace(_T("//"), _T("/"));
//	_strURL += s;
//	CString strFile = m_strAppDataPath;
//	CString strFile2 = m_strProgramFilePath + _T("\\tangram\\");
//	strFile2 += m_strExeName;
//	strFile2 += _T("\\");
//	strFile2 += strKey;
//	strFile += s;
//	strFile.Replace(_T("/"), _T("\\"));
//
//	BOOL bExists = ::PathFileExists(strFile);
//	BOOL bExists2 = false;
//	if (bExists == false)
//	{
//		s.Replace(_T("/"), _T("\\"));
//		CString strDir = m_strAppDataPath;
//		int nPos = s.Find(_T("\\"));
//		while (nPos != -1)
//		{
//			CString s1 = s.Left(nPos + 1);
//			s = s.Mid(nPos + 1);
//			strDir += s1;
//			if (::PathIsDirectory(strDir) == false)
//			{
//				::SHCreateDirectory(nullptr, strDir);
//			}
//			nPos = s.Find(_T("\\"));
//		}
//		bExists2 = ::PathFileExists(strFile2);
//	}
//	if (bExists)
//	{
//		strFile2 = strFile;
//		bExists2 = true;
//	}
//	else if (bExists2 == false)
//	{
//		strFile2 = m_strAppPath + strKey;
//		bExists2 = ::PathFileExists(strFile2);
//	}
//
//	HWND hWnd = (HWND)hNotify;
//	if (bExists2)
//	{
//		if (hNotify == 0)
//		{
//			CTangramXmlParse m_Parse;
//			if (m_Parse.LoadFile(strFile2))
//			{
//				int nCount = m_Parse.GetCount();
//				for (int i = 0; i < nCount; i++)
//				{
//					CTangramXmlParse* pParse = m_Parse.GetChild(i);
//					CString strID = pParse->attr(_T("id"),_T(""));
//					CString strXml = pParse->GetChild(0)->xml();
//					if (strID == _T("xmlRibbon"))
//					{
//						CString strPath = m_strAppCommonDocPath + _T("OfficeRibbon\\") + m_strExeName + _T("\\ribbon.xml");
//						CTangramXmlParse m_Parse2;
//						if (m_Parse2.LoadXml(strXml))
//							m_Parse2.SaveFile(strPath);
//					}
//					if (strID == _T("tangramdesigner"))
//						m_strDesignerXml = strXml;
//					else
//					{
//						strID.MakeLower();
//						if (strID == _T("newtangramdocument"))
//						{
//							m_strNewDocXml = strXml;
//						}
//						else
//						{
//							m_mapValInfo[strID] = CComVariant(strXml);
//						}
//					}
//				}
//			}
//		}
//	}
//		
//	string_t strURL = conversions::to_string_t(_strURL.GetBuffer());
//	auto t = create_task([strURL, bExists, strFile, strKey, hWnd]
//	{
//		http_client client(strURL);
//		web::http::method m = methods::GET;
//		http_request request(m);
//	
//		try
//		{
//			client.request(request).then([bExists, strFile, strKey, hWnd](http_response response)
//			{
//				if (response.status_code() == status_codes::OK)
//				{
//					ATLTRACE(_T("CTangram::ReadTextFromWeb 2\n"));
//					streams::istream f = response.body();
//					if (f.is_valid())
//					{
//						try
//						{
//							file_buffer<uint8_t>::open(conversions::to_string_t(LPCTSTR(strFile)), ios::out).
//								then([bExists, f, strFile, strKey, hWnd](pplx::task<streams::streambuf<uint8_t>> pTask)
//							{
//								try
//								{
//									auto fileBuffer = std::make_shared<streams::streambuf<uint8_t>>();
//									*fileBuffer = pTask.get();
//									f.read_to_end(*fileBuffer).then([bExists, strFile, fileBuffer, strKey, hWnd](pplx::task<size_t> pTask2)
//									{
//										fileBuffer->close().then([bExists, strFile, strKey, hWnd]
//										{
//											if (bExists == false)
//											{
//												TangramFrameInfo* pTangramFrameInfo = new TangramFrameInfo;
//												pTangramFrameInfo->m_strKey = strKey;
//												pTangramFrameInfo->m_strXml = strFile;
//												::PostMessage(hWnd, WM_TANGRAMMSG, (WPARAM)pTangramFrameInfo, 20170929);
//											};
//										});
//									});							
//								}
//								catch (const pplx::task_canceled&)
//								{
//									cancel_current_task();
//								}
//								catch (const std::system_error& e)
//								{
//									const char* str = e.what();
//									std::cout << e.what();
//									cancel_current_task();
//								}
//							});
//						}
//						catch (const pplx::task_canceled&)
//						{
//							cancel_current_task();
//						}
//						catch (const std::system_error& )
//						{
//							cancel_current_task();
//						}
//					}
//				}
//			}).wait();
//			ATLTRACE(_T("CTangram::ReadTextFromWeb\n"));
//		}
//		catch (const std::exception &e)
//		{
//			std::cout << e.what();
//			//cancel_current_task();
//			//CString s = _T("");
//			//s.Format(_T("Error exception:%s\n"), e.what());
//			//ATLTRACE(_T("Error exception:%s\n"), e.what());
//		}
//		catch (const pplx::task_canceled&)
//		{
//			//cancel_current_task();
//		}
//		catch (const std::system_error& )
//		{
//			//cancel_current_task();
//		}
//	});
//
//	return S_OK;
//}

STDMETHODIMP CTangram::ReadTextFromWeb(BSTR bstrURLBase, BSTR bstrOrg, BSTR bstrRepo, BSTR bstrBranch, BSTR bstrFile, BSTR bstrTarget, LONGLONG hNotify)
{
	return S_OK;
}

void CTangram::ConnectDocTemplate(LPCTSTR strType, LPCTSTR strExt, void* pTemplate)
{
	m_mapTemplateInfo[strType] = (void*)pTemplate;
	m_mapTemplateInfo[strExt] = (void*)pTemplate;
}

ITangramDoc* CTangram::ConnectTangramDoc(ITangramAppProxy* AppProxy, LONGLONG docID, HWND hView, HWND hFrame, LPCTSTR strDocType)
{
	CString strID = strDocType;
	strID.Trim();
	strID.MakeLower();
	CTangramDoc* pDoc = nullptr;
	ITangramAppProxy* pProxy = (ITangramAppProxy*)AppProxy;
	if (docID&&strID != _T("") && ::IsWindow(hView))
	{
		CString s = _T(",");
		s += strID;
		s += _T(",");
		if (g_pTangram->m_strDocTemplateStrs.Find(s) == -1)
			g_pTangram->m_strDocTemplateStrs += s;
		pDoc = new CComObject<CTangramDoc>;
		pDoc->m_pAppProxy = AppProxy;
		pDoc->m_llDocID = docID;
		pDoc->m_strDocID = strID;
		pProxy->AddDoc(docID, pDoc);
		pDoc->m_pDocProxy = pProxy->m_pCurDocProxy;
		pDoc->m_pDocProxy->m_strDocID = strID;
		if (AppProxy->m_strCreatingFrameTitle != _T(""))
			pDoc->m_pDocProxy->m_strAppName = AppProxy->m_strCreatingFrameTitle;
		else
			pDoc->m_pDocProxy->m_strAppName = AppProxy->m_strProxyName;
		AppProxy->m_strCreatingFrameTitle = _T("");
		pDoc->m_pDocProxy->m_pDoc = pDoc;
		LRESULT lRes = ::SendMessage(hFrame, WM_TANGRAMMSG, 2016, 0);
		if (lRes == 0)
		{
			CTangramDocWnd* pWnd = new CTangramDocWnd();
			pWnd->SubclassWindow(hFrame);
			pWnd->m_hView = hView;
			CString strWndID = _T("default");
			auto it = pDoc->m_mapCompositor.find(strWndID);
			if (it == pDoc->m_mapCompositor.end())
			{
				pWnd->m_pDocFrame = new CTangramDocFrame();
				pWnd->m_pDocFrame->m_strWndID = strWndID;
				pWnd->m_pDocFrame->m_pTangramDoc = pDoc;
				pDoc->m_mapCompositor[pWnd->m_pDocFrame->m_strWndID] = pWnd->m_pDocFrame;
			}
			else
			{
				pWnd->m_pDocFrame = it->second;
			}
			pWnd->m_pDocFrame->m_mapWnd[hFrame] = pWnd;

			HWND hPWnd = ::GetParent(hFrame);
			if (::GetWindowLong(hFrame, GWL_EXSTYLE)&WS_EX_MDICHILD)
			{
				::PostMessage(hFrame, WM_TANGRAMMSG, (WPARAM)hFrame, (LPARAM)::GetParent(hPWnd));
			}
			else
			{
				g_pTangram->m_mapMDTFrame[hFrame] = pWnd;
				::PostMessage(hFrame, WM_TANGRAMMSG, (WPARAM)hFrame, 0);
			}
		}
	}
	return (ITangramDoc*)pDoc;
}

__declspec(dllexport) ITangram* __stdcall  GetTangram()
{
	return static_cast<ITangram*>(g_pTangram);
}

__declspec(dllexport) CTangramImpl* __stdcall  GetTangramImpl(ITangram** pTangram)
{
	*pTangram = static_cast<ITangram*>(g_pTangram);
	return static_cast<CTangramImpl*>(g_pTangram);
}

__declspec(dllexport) void __stdcall  FreeCLR()
{
	if (g_pTangram&& g_pTangram->m_pClrHost)
	{
		OutputDebugString(_T("------------------Begin Stop CLR------------------------\n"));
		HRESULT hr = g_pTangram->m_pClrHost->Stop();
		ASSERT(hr == S_OK);
		if (hr == S_OK)
		{
			OutputDebugString(_T("------------------Stop CLR Successed!------------------------\n"));
		}
		DWORD dw = g_pTangram->m_pClrHost->Release();
		ASSERT(dw == 0);
		if (dw == 0)
		{
			g_pTangram->m_pClrHost = nullptr;
			OutputDebugString(_T("------------------ClrHost Release Successed!------------------------\n"));
		}
		OutputDebugString(_T("------------------End Stop CLR------------------------\n"));
	}
}

__declspec(dllexport) void __stdcall  SetMainDllLoader(CTangramMainDllLoader* pLoader)
{
	if (pLoader)
		pLoader->LaunchEx(g_pTangram);
	if (::IsWindow(g_pTangram->m_hMainWnd))
	{
		::DestroyWindow(g_pTangram->m_hMainWnd);
	}
	switch (g_pTangram->m_nAppType)
	{
	case TANGRAM_APP_BROWSER:
		if(g_pTangram->m_pTangramDelegate->m_pJVM==nullptr)
			::PostQuitMessage(0);
		break;
	case TANGRAM_APP_WILLCLOSE:
		::PostQuitMessage(0);
		break;
	}
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
	JNIEnv* env = nullptr;
	if (vm->GetEnv(reinterpret_cast<void**>(&env), g_pTangram->m_nJVMVersion) != JNI_OK) {
		return -1;
	}
	g_pTangram->InitJNIForTangram();
	////FULL_CLASS_NAME是个Java类名字，定义了对应java类的全名（要把包名中的点(.)_替换成斜杠(/)）
	//clazz = env->FindClass(FULL_CLASS_NAME);
	//LOGDBG("register method, method count:%d", gsMethodCount);
	////注册JNI函数
	//env->RegisterNatives(clazz, gsNativeMethods,
	//	gsMethodCount);
	////必须返回一个JNI_VERSION_1_1以上（不含）的版本号，否则直接加载失败
	return g_pTangram->m_nJVMVersion;
}

BOOL CTangram::InitJNIForTangram()
{
	if (m_bTangramJniInit == TRUE)
		return FALSE;
	JNIEnv * _pJVMenv = nullptr;
	if (m_pTangramDelegate->m_pJVMenv)
		_pJVMenv = m_pTangramDelegate->m_pJVMenv;
	else
	{
		JNI_GetCreatedJavaVMs_ GetJavaVM = (JNI_GetCreatedJavaVMs_)::GetProcAddress(::GetModuleHandle(_T("jvm.dll")), "JNI_GetCreatedJavaVMs");
		if (GetJavaVM != nullptr){
			JavaVM*  pVM = nullptr;
			jsize nSize = 1;
			jsize nCount = 0;
			jint nRet = GetJavaVM(&pVM, nSize, &nCount);
			if (nRet == 0){
				ASSERT(pVM != nullptr);
				if (pVM->GetEnv(reinterpret_cast<void**>(&_pJVMenv), g_pTangram->m_nJVMVersion) != JNI_OK) {
					return FALSE;
				}
			}
			else{
				TRACE(_T("GetVM Failed\n"));
			}
		}
	}
	if(_pJVMenv){
		CString strJavaJniPath = m_strAppPath + _T("TangramJniInfo.xml");
		CTangramXmlParse m_Parse;
		if (!(::PathFileExists(strJavaJniPath)&&m_Parse.LoadFile(strJavaJniPath))){
			auto it = m_mapValInfo.find(_T("tangramjniinfo"));
			if (it != m_mapValInfo.end()){
				if (m_Parse.LoadXml(it->second.bstrVal) == false)
					return FALSE;
			}
			else
				return FALSE;
		}
		int nCount = m_Parse.GetCount();
		if (nCount == 0)
			return FALSE;
		jclass systemClass = NULL;
		jmethodID loadMethod = NULL;
		systemClass = _pJVMenv->FindClass("java/lang/System");
		try
		{
			if (systemClass != NULL) {
				loadMethod = _pJVMenv->GetStaticMethodID(systemClass, "load", "(Ljava/lang/String;)V");
				if (loadMethod != NULL){
					for (int j = 0; j < nCount; j++){
						CTangramXmlParse* pParse = m_Parse.GetChild(j);
						CString strLib = pParse->text();
						bool bExists = true;
						if (::PathFileExists(strLib) == false){
							CString _strLib = strLib;
							strLib = m_strAppPath + _T("tangramjni\\") + strLib;
							if (::PathFileExists(strLib) == false){
								strLib = m_strProgramFilePath + _T("tangram\\tangramjni\\") + _strLib;
								if (::PathFileExists(strLib) == false)
									bExists = false;
							}
						}
						if (bExists){
							wchar_t* _strLib = strLib.GetBuffer();
							jstring jarFileString = newJavaString(_pJVMenv, _strLib);
							strLib.ReleaseBuffer();
							_pJVMenv->CallStaticVoidMethod(systemClass, loadMethod, jarFileString);
							if (jarFileString != NULL)
								_pJVMenv->DeleteLocalRef(jarFileString);
						}
					}
				}
			}
		}
		catch (...)
		{
		}
		if (_pJVMenv->ExceptionOccurred()) {
			_pJVMenv->ExceptionDescribe();
			_pJVMenv->ExceptionClear();
		}
	}
	return FALSE;
}

void CTangram::ChromeTabCreated(CChromeTab* pTab)
{
	ATLTRACE(_T("Create Chrome Tab :%x\n"), pTab);
}

void CTangram::OnRenderProcessCreated(CChromeRenderProcess* pProcess)
{

}

CChromeBrowserBase* CTangram::GetChromeBrowserBase(HWND hHostWnd)
{
	CBrowserWnd* pPWnd = nullptr;
	auto it2 = m_mapBrowserWnd.find(hHostWnd);
	if (it2 != m_mapBrowserWnd.end())
	{
		pPWnd = (CBrowserWnd*)it2->second;
		return pPWnd->m_pBrowser;
	}
	return nullptr;
}

void CTangram::OnDocumentOnLoadCompleted(CChromeRenderFrameHostBase* pFrameHostBase, HWND hHtmlWnd, void* pVoid)
{
	CChromeRenderFrameHostBase* pHost = (CChromeRenderFrameHostBase*)pFrameHostBase;

	HWND hPWnd = ::GetParent(hHtmlWnd);
	auto it = g_pTangram->m_mapHtmlWnd.find(hHtmlWnd);
	if (it != g_pTangram->m_mapHtmlWnd.end())
	{
		((CHtmlWnd*)it->second)->m_pChromeRenderFrameHost = pFrameHostBase;
		// Set m_pProxy to CChromeRenderFrameHostProxyBase
		// TODO: Not work
		pFrameHostBase->m_pProxy = (CChromeRenderFrameHostProxyBase*)it->second;
		if (pVoid)
		{
		}
		else
		{
			// case 2
			::PostMessage(hHtmlWnd, WM_TANGRAMMSG, 20190115, 0);
		}
	}
}

void CTangram::ChromeChildProcessCreated(
	CChromeChildProcessHostImpl*
	pChromeChildProcessHostImpl)
{

}

void CTangram::OnSubBrowserWndCreated(HWND hParent, HWND hBrowser)
{
	m_hParent = NULL;
	LRESULT lRes = ::SendMessage(::GetParent(hBrowser), WM_TANGRAMGETNODE, 0, (LPARAM)hBrowser);
}

CString CTangram::GetProcessPath(const char* _ver, CString process_type)
{
	if (g_pTangram == nullptr)
		return _T("");
	CString strRet = _T("");
	strRet.Format(_T("%stangramhelper.exe"), m_strAppPath, process_type);
	//strRet.Format(_T("%stangram%s.exe"), m_strAppPath, process_type);
	if (::PathFileExists(strRet))
		return strRet;
	USES_CONVERSION;
	strRet.Format(_T("%s%s\\tangramhelper.exe"), m_strAppPath, A2W(_ver), process_type);
	//strRet.Format(_T("%s%s\\tangram%s.exe"), m_strAppPath, A2W(_ver), process_type);
	if (::PathFileExists(strRet))
		return strRet;
	return _T("");
}

CString CTangram::GetSchemeBaseName()
{
	return m_strExeName.MakeLower();
}
