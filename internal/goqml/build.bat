:: Copyright 2014 <chaishushan{AT}gmail.com>. All rights reserved.
:: Use of this source code is governed by a BSD-style
:: license that can be found in the LICENSE file.

@echo off

cd %~dp0
setlocal

:: ----------------------------------------------------------------------------
:: detect compiler

go run qtenv.go -compiler=msvc
if %errorlevel% == 0 (
	call build_msvc.bat
) else (
	call build_mingw.bat
)

:: ----------------------------------------------------------------------------
:: PAUSE

