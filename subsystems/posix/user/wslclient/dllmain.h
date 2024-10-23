/*
 * PROJECT:     MiniPSX Subsystem for Linux Client
 * LICENSE:     LGPL-2.1+ (https://spdx.org/licenses/LGPL-2.1+)
 * PURPOSE:     ATL Module definition
 * COPYRIGHT:   Copyright 2024 Christian Rendina <pizzaiolo100@proton.me>
*/
class CWSLClientModule : public ATL::CAtlDllModuleT<CWSLClientModule>
{
public:
	DECLARE_LIBID(LIBID_WSLClient)
};

extern class CWSLClientModule _AtlModule;
