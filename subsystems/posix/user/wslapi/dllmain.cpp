/*
 * PROJECT:     MiniPSX Subsystem for Linux API
 * LICENSE:     LGPL-2.1+ (https://spdx.org/licenses/LGPL-2.1+)
 * PURPOSE:     DLL Entrypoint
 * COPYRIGHT:   Copyright 2024 Christian Rendina <pizzaiolo100@proton.me>
*/
#include "pch.h"
#include "wslapi_i.h"
#include "dllmain.h"

CWSLAPIModule _AtlModule;

// Punto di ingresso DLL
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
	return _AtlModule.DllMain(dwReason, lpReserved);
}
