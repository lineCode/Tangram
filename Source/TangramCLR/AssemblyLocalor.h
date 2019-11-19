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

#pragma once

using namespace System;
using namespace System::Reflection;
using namespace System::Collections::Generic;

public ref class AssemblyLocalor
{
	static Dictionary<String^, Assembly^>^ assemblies;

public:

	static void Init()
	{
		assemblies = gcnew Dictionary<String^, Assembly^>();
		AppDomain::CurrentDomain->AssemblyLoad += gcnew AssemblyLoadEventHandler(CurrentDomain_AssemblyLoad);
		AppDomain::CurrentDomain->AssemblyResolve += gcnew ResolveEventHandler(CurrentDomain_AssemblyResolve);

	}

	static Assembly^ CurrentDomain_AssemblyResolve(Object^ sender, ResolveEventArgs^ args)
	{
		Assembly^ assembly = nullptr;
		assemblies->TryGetValue(args->Name, assembly);
		return assembly;
	}

	static void CurrentDomain_AssemblyLoad(Object^ sender, AssemblyLoadEventArgs^ args)
	{
		Assembly^ assembly = args->LoadedAssembly;
		assemblies[assembly->FullName] = assembly;
	}

};