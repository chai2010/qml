
#ifndef GOQML_IDLE_TIMER_H_
#define GOQML_IDLE_TIMER_H_

#include "goqml_private.h"

#include <QBasicTimer>
#include <QThread>
#include <QDebug>

class IdleTimer : public QObject
{
	Q_OBJECT

public:
	static IdleTimer *singleton() {
		static IdleTimer singleton;
		return &singleton;
	}

	void init(int32_t *gui_idle_run) {
		this->gui_idle_run_ = gui_idle_run;
	}

	Q_INVOKABLE void start() {
		timer.start(0, this);
	}

protected:
	void timerEvent(QTimerEvent *event);

private:
	int32_t* gui_idle_run_;
	QBasicTimer timer;    
};

#endif	// GOQML_IDLE_TIMER_H_

