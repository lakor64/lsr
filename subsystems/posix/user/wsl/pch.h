/*
 * PROJECT:     MiniPSX Subsystem for Linux Launcher
 * LICENSE:     LGPL-2.1+ (https://spdx.org/licenses/LGPL-2.1+)
 * PURPOSE:     Precompiled header
 * COPYRIGHT:   Copyright 2024 Christian Rendina <pizzaiolo100@proton.me>
*/

#pragma once

#define STRICT
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

// wsl api
#include <wslclient_h.h>
#include <wslapi_h.h>

#include <cstdio>
