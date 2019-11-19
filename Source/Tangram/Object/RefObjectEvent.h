#pragma once

#include <vector>

namespace Object
{
	class RefObjectEvent
	{
	public:
		RefObjectEvent() {};
		virtual ~RefObjectEvent() {};

		void AddParam(CString strParam);
		CString GetParam(uint32_t nIndex);
		size_t Count();

	private:
		vector<CString> m_vecParams;
	};
}