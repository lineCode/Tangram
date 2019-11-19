#pragma once

#include "RuntimeDelegate.h"

namespace Boot
{
	class JVMRuntimeDelegate : public RuntimeDelegate
	{
	public:
		JVMRuntimeDelegate();
		virtual ~JVMRuntimeDelegate() {};

		CString GetName() override;
		bool IsAvailable() override;
		void Start() override;

	private:
		int m_nJVMVersion = 0;
		int m_nLaunchMode = -1;

		CString m_strStartJarPath;
		CString m_strBridgeJavaClass;
		CString m_strBridgeJavaClassPath;
	};
}