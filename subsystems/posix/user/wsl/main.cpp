/*
 * PROJECT:     MiniPSX Subsystem for Linux Launcher
 * LICENSE:     LGPL-2.1+ (https://spdx.org/licenses/LGPL-2.1+)
 * PURPOSE:     App entrypoint
 * COPYRIGHT:   Copyright 2024 Christian Rendina <pizzaiolo100@proton.me>
*/
#include "pch.h"
#include "wsl.h"

CWSLLauncher _AtlModule;

int WINAPI wmain(int argc, wchar_t** argv)
{
	argc;
	argv;
	return _AtlModule.Run();
}
