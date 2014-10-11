// Copyright 2014 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// +build ingore

// go run qtenv.go -compiler=msvc
// go run qtenv.go -compiler=mingw
// go run qtenv.go -compiler=gcc
package main

import (
	"flag"
	"log"
	"os"
	"os/exec"
	"strings"
)

var (
	flagCompiler = flag.String("compiler", "msvc", "detect qt compiler (msvc|mingw|gcc)")
)

func main() {
	flag.Parse()

	out, err := exec.Command(`qmake`, `-query`, `QMAKE_SPEC`).Output()
	if err != nil {
		log.Fatal(err)
	}

	switch *flagCompiler {
	case "msvc":
		if strings.Contains(string(out), `win32-msvc`) {
			os.Exit(0)
		}
	case "mingw":
		if strings.Contains(string(out), `win32-g++`) {
			os.Exit(0)
		}
	case "gcc", "g++": // g++
		if strings.Contains(string(out), `g++`) {
			os.Exit(0)
		}
	default:
		log.Fatalf("unknow compiler: %s\n", *flagCompiler)
	}

	os.Exit(1) // Failed
}
