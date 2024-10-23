/*
 * PROJECT:     MiniPSX Subsystem for Linux Launcher
 * LICENSE:     LGPL-2.1+ (https://spdx.org/licenses/LGPL-2.1+)
 * PURPOSE:     Installer command line handler
 * COPYRIGHT:   Copyright 2024 Christian Rendina <pizzaiolo100@proton.me>
*/
#include "pch.h"
#include "wsl.h"
#include "installcallback.h"

HRESULT CWSLLauncher::SendToInstaller(LPCWSTR lpCmdLine)
{
	CWSLInstallerCallback* callback = new CWSLInstallerCallback();

	IWSLInstaller* inst;
	auto hr = CoCreateInstance(LIBID_WSLApi, nullptr, 0, IID_IWSLInstaller, (LPVOID*)&inst);
	if (FAILED(hr))
	{
		delete callback;
		return hr;
	}

	WSL_INSTALL_OPTIONS options = { 0 };
	options.ListDistributions = TRUE;
	options.DisableInbox = TRUE;

	hr = inst->InstallWsl(&options, callback, WSL_INSTALL_EVENTINFO_LEVEL_NORMAL);

	if (SUCCEEDED(hr))
	{
		while (callback->IsWaiting());
	}

	inst->Release();
	delete callback;
	return hr;
}
