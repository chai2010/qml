
#include "connector.h"

namespace {

struct ConnectorImpl: Connector {
	ConnectorImpl(
		QObject *sender, QMetaMethod method,
		QQmlEngine *engine, void *func, int argsLen
	): Connector(sender, method, engine, func, argsLen) {
		//
	}

	int qt_metacall(QMetaObject::Call c, int idx, void **a) {
		if (c == QMetaObject::InvokeMetaMethod && idx == metaObject()->methodOffset()) {
			DataValue args[MaxParams];
			QObject *plain = NULL;
			for (int i = 0; i < argsLen; i++) {
				int paramType = method.parameterType(i);
				if (paramType == 0 && a[1 + i] != NULL) {
					const char *typeName = method.parameterTypes()[i].constData();
					void *addr = a[1 + i];
					if (typeName[strlen(typeName)-1] == '*') {
						addr = *(void **)addr;
					}
					plain = new PlainObject(typeName, addr, plain);
					QVariant var = QVariant::fromValue((QObject *)plain);
					packDataValue(&var, &args[i]);
				} else {
					QVariant var(method.parameterType(i), a[1 + i]);
					packDataValue(&var, &args[i]);
				}
			}
			hookSignalCall(engine, func, args);
			if (plain != NULL) {
					delete plain;
			}
			return -1;
		}
		return Connector::qt_metacall(c, idx, a);
	}
};

} // namespace {

// static
Connector* Connector::New(
	QObject *sender, QMetaMethod method,
	QQmlEngine *engine, void *func, int argsLen
) {
	return new ConnectorImpl(sender, method, engine, func, argsLen);
}
