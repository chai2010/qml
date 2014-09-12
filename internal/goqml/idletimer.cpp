
#include "idletimer.h"

#if defined(_MSC_VER)
#	include <Windows.h>
#endif

void idleTimerInit(int32_t *gui_idle_run) {
	IdleTimer::singleton()->init(gui_idle_run);
}

void idleTimerStart() {
	QMetaObject::invokeMethod(IdleTimer::singleton(), "start", Qt::QueuedConnection);
}

void IdleTimer::timerEvent(QTimerEvent *event) {
#if defined(_MSC_VER)
	MemoryBarrier();
#else
	__sync_synchronize();
#endif
	if(*gui_idle_run_ > 0) {
		hookIdleTimer();
	} else {
		timer.stop();
	}
}
