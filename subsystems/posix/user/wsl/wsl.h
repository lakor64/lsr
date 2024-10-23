/*
 * PROJECT:     MiniPSX Subsystem for Linux Launcher
 * LICENSE:     LGPL-2.1+ (https://spdx.org/licenses/LGPL-2.1+)
 * PURPOSE:     App definition
 * COPYRIGHT:   Copyright 2024 Christian Rendina <pizzaiolo100@proton.me>
*/
#pragma once

class CWSLLauncher
{
public:
	explicit CWSLLauncher();
	~CWSLLauncher();

	HRESULT Run();

private:
	HRESULT SendToInstaller(LPCWSTR lpCmdLine);
	HRESULT SendToClient(LPCWSTR lpCmdLine);
};
