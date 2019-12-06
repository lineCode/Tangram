# include "tangramcommon.h"

namespace TangramCommon
{
	CTangramImpl* g_pTangramImpl = nullptr;
	ITangramWindow::ITangramWindow()
	{
		if(g_pTangramImpl)
			g_pTangramImpl->m_pCreatingTangramWindow = this;
	}

	ITangramWindowProvider::~ITangramWindowProvider() 
	{
		if (::GetModuleHandle(L"tangramcore") != NULL&&g_pTangramImpl)
		{
			g_pTangramImpl->InsertTangramDataMap(0, m_strProviderID, nullptr);
		}
	}

	bool ITangramWindowProvider::TangramInit(CString strID)
	{
		strID.MakeLower().Trim();
		if (strID != _T("") && g_pTangramImpl == nullptr)
		{
			m_strProviderID = strID;
			HMODULE hModule = ::GetModuleHandle(_T("TangramCore.dll"));
			if (hModule) {
				typedef CTangramImpl* (__stdcall* GetTangramImpl)(ITangram**);
				GetTangramImpl _pTangramFunction;
				_pTangramFunction = (GetTangramImpl)GetProcAddress(hModule, "GetTangramImpl");
				ITangram* pTangram = nullptr;
				g_pTangramImpl = _pTangramFunction(&pTangram);
				m_strProviderID.MakeLower();
				g_pTangramImpl->InsertTangramDataMap(1, m_strProviderID, this);
				return true;
			}
		}
		return false;
	}
}
