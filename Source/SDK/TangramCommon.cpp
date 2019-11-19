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
		if (::GetModuleHandle(L"tangramcore") != NULL)
		{
			auto it = g_pTangramImpl->m_mapTangramWindowProvider.find(m_strProviderID);
			if (it != g_pTangramImpl->m_mapTangramWindowProvider.end())
			{
				g_pTangramImpl->m_mapTangramWindowProvider.erase(it);
			}
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
				g_pTangramImpl->m_mapTangramWindowProvider[m_strProviderID] = this;
				return true;
			}
		}
		return false;
	}
}
