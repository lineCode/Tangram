#pragma once

#include <map>

namespace Boot
{
	class RuntimeDelegate;

	class Application
	{
	public:
		Application() {};
		virtual ~Application() {};

		static void Ready();

		static CString GetConfiguration(CString strKey);
		static void PutConfiguration(CString strKey, CString strValue);

		static CString GetWorkingPath();
		static CString GetExecutablePath();

		static void AddRuntimeDelegate(RuntimeDelegate* pRuntimeDelegate);

	private:
		bool m_bDevelopMode = false;
	};
}