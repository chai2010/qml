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
	component, err := engine.LoadFile("dynamicscene.qml")
	if err != nil {
		return err
	}

	win := component.CreateWindow(nil)
	win.Show()
	win.Wait()

	return nil
}
