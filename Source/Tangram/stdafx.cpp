/********************************************************************************
*					Tangram Library - version 10.0.0							*
*********************************************************************************
* Copyright (C) 2002-2019 by Tangram Team.   All Rights Reserved.				*
*
* THIS SOURCE FILE IS THE PROPERTY OF TANGRAM TEAM AND IS NOT TO
* BE RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED
* WRITTEN CONSENT OF TANGRAM TEAM.
*
* THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS
* OUTLINED IN THE GPL LICENSE AGREEMENT.TANGRAM TEAM
* GRANTS TO YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE
* THIS SOFTWARE ON A SINGLE COMPUTER.
*
* CONTACT INFORMATION:
* mailto:tangramteam@outlook.com
* https://www.tangramteam.com
*
*
********************************************************************************/

// stdafx.cpp : source file that includes just the standard includes
// TangramDeskManager.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include "Browser.cpp"
#include "TangramXmlParse.cpp"
#include "TangramCoreEvents.cpp"

void DefaultExceptionProcess(JNIEnv *env)
{
	if (env->ExceptionOccurred() != 0) {
		env->ExceptionDescribe();
		env->ExceptionClear();
	}
}

void DefaultExceptionProcessEx(JNIEnv *env, _TCHAR* errorInfo)
{
	if (env->ExceptionOccurred() != 0) 
	{
		env->ExceptionDescribe();
		env->ExceptionClear();
		if (errorInfo != nullptr)
		{
			OutputDebugString(errorInfo);
		}
	}
}

void ThrowComFail(JNIEnv *env, const char* desc, jint hr)
{
	jclass failClass = env->FindClass("Tangram/COM/ComFailException");
	// call the constructor that takes hr and message
	jmethodID failCons =
		env->GetMethodID(failClass, "<init>", "(ILjava/lang/String;)V");
	if (!desc) {
		desc = "Java/COM Error";
	}
	jstring js = env->NewStringUTF(desc);
	jthrowable fail = (jthrowable)env->NewObject(failClass, failCons, hr, js);
	env->Throw(fail);
}

// if env's are different throw on the 1st env
int CheckEnv(JNIEnv *env1, JNIEnv *env2)
{
	if (env1 != env2) {
		jclass failClass = env1->FindClass("Tangram/COM/WrongThreadException");
		// call the constructor that takes hr and message
		jmethodID failCons =
			env1->GetMethodID(failClass, "<init>", "()V");
		env1->ThrowNew(failClass, "Wrong Thread");
		return 0;
	}
	return 1;
}


/* Get a _TCHAR* from a jstring, string should be released later with JNI_ReleaseStringChars */
const _TCHAR * JNI_GetStringChars(JNIEnv *env, jstring str) {
	const _TCHAR * result = NULL;
#ifdef UNICODE
	/* GetStringChars is not null terminated, make a copy */
	const _TCHAR * stringChars = (_TCHAR *)env->GetStringChars(str, 0);
	int length = env->GetStringLength(str);
	_TCHAR * copy = (_TCHAR *)malloc((length + 1) * sizeof(_TCHAR));
	_tcsncpy(copy, stringChars, length);
	copy[length] = _T('\0');
	env->ReleaseStringChars(str, (const jchar *)stringChars);
	result = copy;
#elif MACOSX
	/* Use UTF on the Mac */
	result = env->GetStringUTFChars(env, str, 0);
#else
	/* Other platforms, use java's default encoding */
	_TCHAR* buffer = NULL;
	if (string_class == NULL)
		string_class = env->FindClass(env, "java/lang/String");
	if (string_class != NULL) {
		if (string_getBytesMethod == NULL)
			string_getBytesMethod = env->GetMethodID(env, string_class, "getBytes", "()[B");
		if (string_getBytesMethod != NULL) {
			jbyteArray bytes = env->CallObjectMethod(env, str, string_getBytesMethod);
			if (!env->ExceptionOccurred()) {
				jsize length = env->GetArrayLength(env, bytes);
				buffer = malloc((length + 1) * sizeof(_TCHAR*));
				env->GetByteArrayRegion(env, bytes, 0, length, (jbyte*)buffer);
				buffer[length] = 0;
			}
			env->DeleteLocalRef(env, bytes);
		}
	}
	if (buffer == NULL) {
		env->ExceptionDescribe();
		env->ExceptionClear();
	}
	result = buffer;
#endif
	return result;
}

/* Release the string that was obtained using JNI_GetStringChars */
void JNI_ReleaseStringChars(JNIEnv *env, jstring s, const _TCHAR* data) {
#ifdef UNICODE
	free((_TCHAR*)data);
#elif MACOSX
	env->ReleaseStringUTFChars(env, s, data);
#else
	free((_TCHAR*)data);
#endif
}
