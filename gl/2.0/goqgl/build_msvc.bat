:: Copyright 2014 <chaishushan{AT}gmail.com>. All rights reserved.
:: Use of this source code is governed by a BSD-style
:: license that can be found in the LICENSE file.

@echo off

cd %~dp0
setlocal

:: NMake: goqgl_2_0.dll
qmake
nmake clean
nmake release

:: MinGW: generate libgoqgl_2_0.a
dlltool -dllname goqgl_2_0.dll --def goqgl.def --output-lib libgoqgl_2_0.a

:: install
copy goqgl_2_0.dll %QTDIR%\bin
