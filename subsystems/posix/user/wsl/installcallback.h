/*
 * PROJECT:     MiniPSX Subsystem for Linux Launcher
 * LICENSE:     LGPL-2.1+ (https://spdx.org/licenses/LGPL-2.1+)
 * PURPOSE:     Installer callback
 * COPYRIGHT:   Copyright 2024 Christian Rendina <pizzaiolo100@proton.me>
*/
#pragma once

class CWSLInstallerCallback : public IWSLInstallEventCallback
{
public:
    explicit CWSLInstallerCallback() : m_refCount(1), m_bWaiting(true) {}

    STDMETHODIMP_(ULONG) AddRef() override
    {
        InterlockedIncrement(&m_refCount);
        return m_refCount;
    }

    STDMETHODIMP_(ULONG) Release() override
    {
        InterlockedDecrement(&m_refCount);
        return m_refCount;
    }

    STDMETHODIMP QueryInterface(REFIID riid, _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject)
    {
        if (IsEqualIID(riid, IID_IWSLInstallEventCallback))
        {
            *ppvObject = this;
            AddRef();
            return S_OK;
        }

        return E_NOINTERFACE;
    }

    STDMETHODIMP_(void) OnWslInstallEventInfo(
        /* [in] */ LPWSTR Status) override;

    STDMETHODIMP_(void) OnWslInstallProgress(
        /* [in] */ UINT CurrentProgress,
        /* [in] */ UINT TotalProgress) override;

    STDMETHODIMP_(void) OnWslInstallComplete(
        /* [in] */ HRESULT Result) override;

    bool IsWaiting() const { return m_bWaiting; }

private:
    ULONG m_refCount;
    bool m_bWaiting;
};
