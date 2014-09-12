#ifndef GOQML_CONNECTOR_H
#define GOQML_CONNECTOR_H

#include "goqml_private.h"

#include <QObject>
#include <QMetaMethod>

class QQmlEngine;

class Connector : public QObject
{
	Q_OBJECT

public:
	static Connector* New(
		QObject *sender, QMetaMethod method,
		QQmlEngine *engine, void *func, int argsLen
	);
	virtual ~Connector() {
		hookSignalDisconnect(func);
	}

public slots:
	virtual void invoke() {
		panicf("should never get called");
	}

protected:
	Connector(QObject *sender, QMetaMethod method, QQmlEngine *engine, void *func, int argsLen)
		:QObject(sender), engine(engine), method(method), func(func), argsLen(argsLen) {}

	QQmlEngine *engine;
	QMetaMethod method;
	void *func;
	int argsLen;
};

class PlainObject : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString plainType READ getPlainType)
	Q_PROPERTY(void *plainAddr READ getPlainAddr)

	QString plainType;
	void *plainAddr;

public:
	PlainObject(QObject *parent = 0): QObject(parent) {};

	PlainObject(const char *plainType, void *plainAddr, QObject *parent = 0)
		: QObject(parent), plainType(plainType), plainAddr(plainAddr) {};

	QString getPlainType() { return plainType; };
	void *getPlainAddr() { return plainAddr; };
};

#endif // GOQML_CONNECTOR_H

