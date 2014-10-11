:: Copyright 2014 <chaishushan{AT}gmail.com>. All rights reserved.
:: Use of this source code is governed by a BSD-style
:: license that can be found in the LICENSE file.

@echo off

cd %~dp0
setlocal

:: ----------------------------------------------------------------------------
:: Setup MSVC

:: VS2010
if not "x%VS100COMNTOOLS%" == "x" (
	echo Setup VS2010 Win64 ...
	call "%VS100COMNTOOLS%\..\..\VC\vcvarsall.bat" x86_amd64
	goto build
)

:: VS2012
if not "x%VS110COMNTOOLS%" == "x" (
	echo Setup VS2012 Win64 ...
	call "%VS110COMNTOOLS%\..\..\VC\vcvarsall.bat" x86_amd64
	goto build
)

:: VS2013
if not "x%VS120COMNTOOLS%" == "x" (
	echo Setup VS2013 Win64 ...
	call "%VS120COMNTOOLS%\..\..\VC\vcvarsall.bat" x86_amd64
	goto build
)

:build

:: ----------------------------------------------------------------------------
:: NMake: goqgl_2_1.dll

qmake
nmake clean
nmake release

:: ----------------------------------------------------------------------------
:: MinGW: generate libgoqgl_2_1.a

dlltool -dllname goqgl_2_1.dll --def goqgl.def --output-lib libgoqgl_2_1.a

:: ----------------------------------------------------------------------------
:: install

copy goqgl_2_1.dll %QTDIR%\bin

:: ----------------------------------------------------------------------------
:: END
