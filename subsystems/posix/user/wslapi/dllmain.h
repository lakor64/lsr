/*
 * PROJECT:     MiniPSX Subsystem for Linux API
 * LICENSE:     LGPL-2.1+ (https://spdx.org/licenses/LGPL-2.1+)
 * PURPOSE:     ATL Module definition
 * COPYRIGHT:   Copyright 2024 Christian Rendina <pizzaiolo100@proton.me>
*/
class CWSLAPIModule : public ATL::CAtlDllModuleT<CWSLAPIModule>
{
public :
	DECLARE_LIBID(LIBID_WSLApi)
};

extern class CWSLAPIModule _AtlModule;
