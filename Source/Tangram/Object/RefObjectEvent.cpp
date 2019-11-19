#include "../stdafx.h"
#include "RefObjectEvent.h"

namespace Object
{
	void RefObjectEvent::AddParam(CString strParam)
	{
		m_vecParams.push_back(strParam);
	}

	CString RefObjectEvent::GetParam(uint32_t nIndex)
	{
		if (nIndex < m_vecParams.size())
		{
			return  m_vecParams.at(nIndex);
		}
		return _T("");
	}

	size_t RefObjectEvent::Count()
	{
		return m_vecParams.size();
	}
}