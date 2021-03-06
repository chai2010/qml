:: Copyright 2014 <chaishushan{AT}gmail.com>. All rights reserved.
:: Use of this source code is governed by a BSD-style
:: license that can be found in the LICENSE file.

@echo off

cd %~dp0
setlocal

:: NMake: goqgl_3_3core.dll
qmake
nmake clean
nmake release

:: MinGW: generate libgoqgl_3_3core.a
dlltool -dllname goqgl_3_3core.dll --def goqgl.def --output-lib libgoqgl_3_3core.a

:: install
copy goqgl_3_3core.dll %QTDIR%\bin
