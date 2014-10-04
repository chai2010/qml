# Copyright 2014 <chaishushan{AT}gmail.com>. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

TEMPLATE = lib
CONFIG  += dll release
CONFIG  -= embed_manifest_exe embed_manifest_dll
QT      += opengl gui
TARGET   = goqgl_3_0

DESTDIR = $${PWD}
INCLUDEPATH += ..

HEADERS += ../funcs.h
SOURCES += ../funcs.cpp

DEF_FILE+= ./goqgl.def
