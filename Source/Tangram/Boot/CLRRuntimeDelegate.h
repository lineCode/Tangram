#pragma once

#include "RuntimeDelegate.h"

namespace Boot
{
	class CLRRuntimeDelegate : public RuntimeDelegate
	{
	public:
		CLRRuntimeDelegate();
		virtual ~CLRRuntimeDelegate() {};

		CString GetName() override;
		void Start() override;

	private:
		bool m_bEnableProcessFormTabKey = false;

		ITangramCLRImpl* m_pCLRProxy;
		ICLRRuntimeHost* m_pClrHost;
	};
}