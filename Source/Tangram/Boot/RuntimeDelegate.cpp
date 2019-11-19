#include "../stdafx.h"
#include "RuntimeDelegate.h"

namespace Boot
{
	bool RuntimeDelegate::IsStarted()
	{
		return m_bStarted;
	}
}