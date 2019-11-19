#pragma once
#include <atlstr.h>

typedef struct tagMessage
{
	CString m_strSourceFrameName;
	CString m_strSourceLayerName;
	CString m_strSourceNodeName;

	CString m_strChannel;
	CString m_strArg1;
	CString m_strArg2;

	tagMessage(CString strFrameName, CString strLayerName, CString strNodeName, CString strChannel, CString strArg1, CString strArg2)
	{
		m_strSourceFrameName = strFrameName;
		m_strSourceLayerName = strLayerName;
		m_strSourceNodeName = strNodeName;
		m_strChannel = strChannel;
		m_strArg1 = strArg1;
		m_strArg2 = strArg2;
	}

	tagMessage(CString strFrameName, CString strLayerName, CString strNodeName)
	{
		m_strSourceFrameName = strFrameName;
		m_strSourceLayerName = strLayerName;
		m_strSourceNodeName = strNodeName;
	}

	void setArguments(CString strChannel, CString strArg1, CString strArg2)
	{
		m_strChannel = strChannel;
		m_strArg1 = strArg1;
		m_strArg2 = strArg2;
	}

} Message;