
#ifndef GOQML_GOVALUE_H_
#define GOQML_GOVALUE_H_

#include "goqml_private.h"

// Unfortunatley we need access to private bits, because the
// whole dynamic meta-object concept is sadly being hidden
// away, and without it this package wouldn't exist.
#include "./private/qmetaobject_p.h"

#include <QQuickPaintedItem>
#include <QPainter>

class GoValueMetaObject;

QMetaObject *metaObjectFor(GoTypeInfo *typeInfo);

class GoValue : public QObject
{
	Q_OBJECT

public:
	GoAddr *addr;
	GoTypeInfo *typeInfo;

	GoValue(GoAddr *addr, GoTypeInfo *typeInfo, QObject *parent);
	virtual ~GoValue();

	void activate(int propIndex);

private:
	GoValueMetaObject *valueMeta;
};

class GoPaintedValue : public QQuickPaintedItem
{
	Q_OBJECT

public:
	GoAddr *addr;
	GoTypeInfo *typeInfo;

	GoPaintedValue(GoAddr *addr, GoTypeInfo *typeInfo, QObject *parent);
	virtual ~GoPaintedValue();

	void activate(int propIndex);

	virtual void paint(QPainter *painter);

private:
	GoValueMetaObject *valueMeta;
};

#endif // GOQML_GOVALUE_H_

