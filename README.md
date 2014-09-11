Go bindings for Qt5/QML
=======================

PkgDoc: [http://godoc.org/github.com/chai2010/qml.go](http://godoc.org/github.com/chai2010/qml.go)

Install
=======

Install `Go1.4` and `Qt5` and `GCC` or `MinGW` ([download here](http://tdm-gcc.tdragon.net/download)) at first.
Then run these commands in `GCC` or `MSVC` environment:

1. set `$(QTDIR)` and add `$(QTDIR)/bin` to `$(PATH)` 
2. `go get -d github.com/chai2010/qml.go`
3. `go generate` and `go install`
4. `go run hello.go`

Example
=======

```Go
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
```

Screenshots
===========

**Hello**

[![](https://raw.githubusercontent.com/chai2010/qml.go/master/screenshot/windows/hello.jpg)](https://github.com/chai2010/qml.go/blob/master/examples/hello/main.go)

**Particle**

[![](https://raw.githubusercontent.com/chai2010/qml.go/master/screenshot/windows/particle.jpg)](https://github.com/chai2010/qml.go/blob/master/examples/particle/main.go)

BUGS
====

Report bugs to <chaishushan@gmail.com>.

Thanks!
