# Copyright 2014 <chaishushan{AT}gmail.com>. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

TEMPLATE = lib
CONFIG  += dll release
CONFIG  -= embed_manifest_exe embed_manifest_dll
QT      += gui widgets qml quick
TARGET   = goqml

DESTDIR = $${PWD}
INCLUDEPATH += .

HEADERS += ./connector.h
SOURCES += ./connector.cpp

HEADERS += ./govalue.h
SOURCES += ./govalue.cpp

HEADERS += ./govaluetype.h
SOURCES += ./govaluetype.cpp

HEADERS += ./idletimer.h
SOURCES += ./idletimer.cpp

HEADERS += ./goqml.h
HEADERS += ./goqml_private.h
SOURCES += ./goqml.cpp
DEF_FILE+= ./goqml.def
