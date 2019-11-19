#pragma once

#include "tangram.h"
#include "atlbase.h"
#include "atlcom.h"
#include "atlstr.h"

namespace ChromePlus
{
#define TANGRAM_CONST_OPENFILE			19920612
#define TANGRAM_CONST_NEWDOC			19631222
#define TANGRAM_CONST_PANE_FIRST		20022017
#define TANGRAM_CHROME_APP_INIT			20190501
#define TANGRAM_CHROME_APP_INIT2		20190422
#define WM_TANGRAM_WEBNODEDOCCOMPLETE	(WM_USER + 0x00004001)
#define WM_OPENDOCUMENT					(WM_USER + 0x00004002)
#define WM_SPLITTERREPOSITION			(WM_USER + 0x00004003)
#define WM_ECLIPSEWORKBENCHCREATED		(WM_USER + 0x00004004)
#define WM_TABCHANGE					(WM_USER + 0x00004005)
#define WM_TANGRAMMSG					(WM_USER + 0x00004006)
#define WM_NAVIXTML						(WM_USER + 0x00004007)
#define WM_OFFICEOBJECTCREATED			(WM_USER + 0x00004008)
#define WM_MDICHILDMIN					(WM_USER + 0x00004009)
#define WM_TANGRAMAPPINIT				(WM_USER + 0x0000400a)
#define WM_TANGRAMAPPQUIT				(WM_USER + 0x0000400b)
#define WM_TANGRAMDATA					(WM_USER + 0x0000400c)
#define WM_DOWNLOAD_MSG					(WM_USER + 0x0000400d)
#define WM_TANGRAMNEWOUTLOOKOBJ			(WM_USER + 0x0000400e)
#define WM_TANGRAMACTIVEINSPECTORPAGE	(WM_USER + 0x0000400f)
#define WM_USER_TANGRAMTASK				(WM_USER + 0x00004010)
#define WM_SETWNDFOCUSE					(WM_USER + 0x00004011)
#define WM_UPLOADFILE					(WM_USER + 0x00004012)
#define WM_TANGRAMDESIGNMSG				(WM_USER + 0x00004013)
#define WM_INSERTTREENODE				(WM_USER + 0x00004014)
#define WM_REFRESHDATA					(WM_USER + 0x00004015)
#define WM_GETSELECTEDNODEINFO			(WM_USER + 0x00004016)
#define WM_TANGRAMDESIGNERCMD			(WM_USER + 0x00004017)
#define WM_TANGRAMGETTREEINFO			(WM_USER + 0x00004018)
#define WM_TANGRAMGETNODE				(WM_USER + 0x00004019)
#define WM_TANGRAMUPDATENODE			(WM_USER + 0x0000401a)
#define WM_TANGRAMSAVE					(WM_USER + 0x0000401b)
#define WM_MDICLIENTCREATED				(WM_USER + 0x0000401c)
#define WM_TGM_SETACTIVEPAGE			(WM_USER + 0x0000401d)
#define WM_TGM_SET_CAPTION				(WM_USER + 0x0000401e)	
#define WM_GETNODEINFO					(WM_USER + 0x0000401f)
#define WM_CREATETABPAGE				(WM_USER + 0x00004020)
#define WM_ACTIVETABPAGE				(WM_USER + 0x00004021)
#define WM_MODIFYTABPAGE				(WM_USER + 0x00004022)
#define WM_ADDTABPAGE					(WM_USER + 0x00004023)
#define WM_TANGRAMITEMLOAD				(WM_USER + 0x00003024)
#define WM_TANGRAMUCMAMSG				(WM_USER + 0x00004025)
#define WM_INITOUTLOOK					(WM_USER + 0x00004026)
#define WM_CONTROLBARCREATED			(WM_USER + 0x00004027)
#define WM_QUERYAPPPROXY				(WM_USER + 0x00004028)
#define WM_TANGRAMACTIVEPAGE			(WM_USER + 0x00004029)
#define WM_TANGRAMSETAPPTITLE			(WM_USER + 0x0000402a)
#define WM_LYNCIMWNDCREATED				(WM_USER + 0x0000402b)
#define WM_STOPTRACKING					(WM_USER + 0x0000402c)
#define WM_TANGRAMINIT					(WM_USER + 0x0000402d)
#define WM_VSSHOWPROPERTYGRID			(WM_USER + 0x0000402e)
#define WM_REMOVERESTKEY				(WM_USER + 0x0000402f)
#define WM_TANGRAMGETXML				(WM_USER + 0x00004030)
#define WM_CHROMEWEBCLIENTCREATED		(WM_USER + 0x00004031)
#define WM_CHROMERENDERERFRAMEHOSTINIT	(WM_USER + 0x00004032)
#define WM_BROWSERLAYOUT                (WM_USER + 0x00004034)
#define WM_CHROMEMSG	                (WM_USER + 0x00004035)

	class CTangramAppBrowser;
	class CTangramAppBrowserProxy;
	class CTangramChromeProcessProxy;

	class CTangramChromeBrowserProcessImpl
	{
	public:
		CTangramChromeBrowserProcessImpl()
		{
			m_pProxy = nullptr;
			m_pTangram = nullptr;
		};

		ITangram* m_pTangram;
		CTangramChromeProcessProxy* m_pProxy;
	};

	class CTangramChromeProcessProxy
	{
	public:
		CTangramChromeProcessProxy()
		{
			m_pImpl = nullptr;
			m_hActiveContentWnd = nullptr;
			m_pActiveTangramAppBrowser = nullptr;
		};

		virtual ~CTangramChromeProcessProxy()
		{

		}

		HWND								m_hActiveContentWnd;
		CTangramAppBrowser*					m_pActiveTangramAppBrowser;
		CTangramChromeBrowserProcessImpl*	m_pImpl;

		virtual void SandBoxProcessStarted(int nProcessType, DWORD ProcessID) {};
		virtual void ConnectBrowser(CTangramAppBrowser* pBrowser, HWND hContentWnd) {};
	};

	class CTangramAppBrowser
	{
	public:
		CTangramAppBrowser()
		{
			m_pProxy = nullptr;
		};

		virtual ~CTangramAppBrowser()
		{
		};

		CTangramAppBrowserProxy* m_pProxy;
	};

	class CTangramAppBrowserProxy
	{
	public:
		CTangramAppBrowserProxy()
		{
			m_pTangramAppBrowser = nullptr;
		};

		virtual ~CTangramAppBrowserProxy()
		{
		};

		CTangramAppBrowser* m_pTangramAppBrowser;

		virtual void UpdateContentRect(RECT& rc) {};
	};
}
