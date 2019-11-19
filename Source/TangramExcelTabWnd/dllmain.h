// dllmain.h : Declaration of module class.

class CTangramApp : 
	public CWinApp, 
	public ITangramWindowProvider
{
public:
	CTangramApp();
	virtual ~CTangramApp();

	BOOL InitInstance();

	// ITangramWindowProvider Methods:
	virtual HWND Create(HWND hParentWnd, IWndNode* pNode);
	virtual CString GetNames();
	virtual CString GetTags(CString strName);
};

extern CTangramApp theApp;
