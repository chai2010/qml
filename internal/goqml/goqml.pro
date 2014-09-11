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


# MOC HACK
# HEADERS += ./connector.h
# HEADERS += ./govalue.h
# HEADERS += ./idletimer.h
SOURCES += ./moc_all.cpp

SOURCES += ./connector.cpp
SOURCES += ./govalue.cpp
SOURCES += ./govaluetype.cpp
SOURCES += ./idletimer.cpp

HEADERS += ./goqml.h
HEADERS += ./goqml_private.h
SOURCES += ./goqml.cpp
DEF_FILE+= ./goqml.def
