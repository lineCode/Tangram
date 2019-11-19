#include "../stdafx.h"
#include "JVMRuntimeDelegate.h"

#include <io.h>
#include "../eclipseUnicode.h"
#include "../eclipseJni.h"
#include "../eclipseCommon.h"

#include "Application.h"

extern _TCHAR* jarFile;
extern _TCHAR* findStartupJar();
extern int GetLaunchMode();

namespace Boot
{
	JVMRuntimeDelegate::JVMRuntimeDelegate()
	{
		m_nJVMVersion = JNI_VERSION_10;
		m_strStartJarPath = DEFAULT_EQUINOX_STARTUP;
		m_strBridgeJavaClass = _T("org.eclipse.equinox.launcher.JNIBridge");
		m_strBridgeJavaClassPath = m_strBridgeJavaClass;
		m_strBridgeJavaClassPath.Replace(_T("."), _T("/"));
		USES_CONVERSION;
		// m_strBridgeJavaClassPath = T2A(m_strBridgeJavaClassPath);
	}

	CString JVMRuntimeDelegate::GetName()
	{
		return _T("JVM");
	}

	bool JVMRuntimeDelegate::IsAvailable()
	{
		bool m_bEclipse = false;
		CString strplugins = Application::GetWorkingPath() + _T("plugins\\");
		if (::PathIsDirectory(strplugins)) {
			CString strPath = strplugins + _T("*.jar");
			_wfinddata_t fd;
			fd.attrib = FILE_ATTRIBUTE_DIRECTORY;
			intptr_t pf = _wfindfirst(strPath, &fd);
			if ((fd.attrib & FILE_ATTRIBUTE_DIRECTORY) == 0) {
				m_bEclipse = true;
			}
			else {
				while (!_wfindnext(pf, &fd)) {
					if ((fd.attrib & FILE_ATTRIBUTE_DIRECTORY) == 0) {
						m_bEclipse = true;
						break;
					}
				}
			}
			_findclose(pf);
		}
		return m_bEclipse;
	}

	void JVMRuntimeDelegate::Start()
	{
		if (m_nLaunchMode == -1)
			GetLaunchMode();
		if (m_nLaunchMode != -1) {
			jarFile = findStartupJar();
			m_bStarted = (jarFile != nullptr);
		}
	}
}