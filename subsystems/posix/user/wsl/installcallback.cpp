/*
 * PROJECT:     MiniPSX Subsystem for Linux Launcher
 * LICENSE:     LGPL-2.1+ (https://spdx.org/licenses/LGPL-2.1+)
 * PURPOSE:     Installer callback
 * COPYRIGHT:   Copyright 2024 Christian Rendina <pizzaiolo100@proton.me>
*/
#include "pch.h"
#include "installcallback.h"

STDMETHODIMP_(void) CWSLInstallerCallback::OnWslInstallEventInfo(
    /* [in] */ LPWSTR Status)
{
    printf("Status: %S\n", Status);
}

STDMETHODIMP_(void) CWSLInstallerCallback::OnWslInstallProgress(
    /* [in] */ UINT CurrentProgress,
    /* [in] */ UINT TotalProgress)
{
    printf("Progress: %u / %u\n", CurrentProgress, TotalProgress);
}

STDMETHODIMP_(void) CWSLInstallerCallback::OnWslInstallComplete(HRESULT Result)
{
	printf("Result: %x\n", Result);
    m_bWaiting = false;
}
