/*
 * PROJECT:     MiniPSX Subsystem for Linux Launcher
 * LICENSE:     LGPL-2.1+ (https://spdx.org/licenses/LGPL-2.1+)
 * PURPOSE:     Main application
 * COPYRIGHT:   Copyright 2024 Christian Rendina <pizzaiolo100@proton.me>
*/
#include "pch.h"
#include "wsl.h"

CWSLLauncher::CWSLLauncher()
{
	(void)CoInitializeEx(nullptr, COINIT_MULTITHREADED);
}

CWSLLauncher::~CWSLLauncher()
{
	CoUninitialize();
}

HRESULT CWSLLauncher::SendToClient(LPCWSTR lpCmdLine)
{
	IWSLClient* client;
	auto hr = CoCreateInstance(LIBID_WSLClient, nullptr, 0, IID_IWSLClient, (LPVOID*)&client);
	if (FAILED(hr))
	{
		return hr;
	}

	DWORD status;
	hr = client->Main(WSL_CLIENT_MODULE_MAIN, lpCmdLine, &status);
	client->Release();
	return hr;
}

HRESULT CWSLLauncher::Run()
{
	auto cmdline = GetCommandLineW();
	HRESULT hr = S_OK;

	if (FAILED(SendToClient(cmdline)))
	{
		hr = SendToInstaller(cmdline);
	}

	printf("RETURN: %x\n", hr);
	return hr;
}
