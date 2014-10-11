:: Copyright 2014 <chaishushan{AT}gmail.com>. All rights reserved.
:: Use of this source code is governed by a BSD-style
:: license that can be found in the LICENSE file.

@echo off

cd %~dp0
setlocal

:: ----------------------------------------------------------------------------
:: mingw32-make: goqml.dll

qmake
mingw32-make clean
mingw32-make

:: ----------------------------------------------------------------------------

copy goqml.dll %QTDIR%\bin

:: ----------------------------------------------------------------------------
:: PAUSE

