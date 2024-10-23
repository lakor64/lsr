/*
 * PROJECT:     MiniPSX Subsystem for Linux Client
 * LICENSE:     MIT (https://spdx.org/licenses/MIT)
 * PURPOSE:     DLL Entrypoint
 * COPYRIGHT:   Copyright 2024 Christian Rendina <pizzaiolo100@proton.me>
*/
#include "pch.h"
#include "wslclient_i.h"
#include "dllmain.h"

CWSLClientModule _AtlModule;

extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
	return _AtlModule.DllMain(dwReason, lpReserved);
}
