#pragma once

#include "RuntimeDelegate.h"

namespace Boot
{
	class WebRuntimeDelegate : public RuntimeDelegate
	{
	public:
		WebRuntimeDelegate();
		virtual ~WebRuntimeDelegate() {};

		CString GetName() override;

	private:
		CString m_strUserDataPathCompanyName;
		CString m_strUserDataPathProductName;
	};
}