// Copyright 2014 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// +build ingore

package main

import (
	"fmt"
	"os"

	qml "github.com/chai2010/qml.go"
)

func main() {
	if err := qml.Run(run); err != nil {
		fmt.Fprintf(os.Stderr, "error: %v\n", err)
		os.Exit(1)
	}
}

func run() error {
	engine := qml.NewEngine()
	engine.On("quit", func() { os.Exit(0) })

	component, err := engine.LoadString("hello.qml", qmlHello)
	if err != nil {
		return err
	}
	window := component.CreateWindow(nil)
	window.Show()
	window.Wait()
	return nil
}

const qmlHello = `
import QtQuick 2.0

Rectangle {
	id: page
	width: 320; height: 240
	color: "lightgray"

	Text {
		id: helloText
		text: "Hello world!"
		y: 30
		anchors.horizontalCenter: page.horizontalCenter
		font.pointSize: 24; font.bold: true
	}
}
`
