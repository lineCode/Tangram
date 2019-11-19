#pragma once

namespace Boot
{
	class RuntimeDelegate
	{
	public:
		RuntimeDelegate() {};
		virtual ~RuntimeDelegate() {};
		
		virtual CString GetName() = 0;
		virtual bool IsAvailable() = 0;
		bool IsStarted();

		virtual void Start() = 0;

	protected:
		bool m_bStarted = false;
	};
}