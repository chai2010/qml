// +build !windows

#include "./internal/goqml/capi.cpp"
#include "./internal/goqml/govalue.cpp"
#include "./internal/goqml/govaluetype.cpp"
#include "./internal/goqml/idletimer.cpp"
#include "./internal/goqml/connector.cpp"

#include "./internal/goqml/moc_all.cpp"

#ifdef _WIN32
#include "./internal/goqml/mmemwin.cpp"
#endif
