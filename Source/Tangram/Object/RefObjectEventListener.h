#pragma once

namespace Object
{
	class RefObjectEvent;

	class RefObjectEventListener
	{
	public:
		RefObjectEventListener() {};
		virtual ~RefObjectEventListener() {};

		virtual void OnEventHandle(CString strEventType, RefObjectEvent* pEvent) = 0;
	};
}