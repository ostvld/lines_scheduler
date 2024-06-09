#include "integrity_registrator.h"

#include <QtQml/QtQml>

void IntegrityRegistrator::initEngine(QQmlEngine* engine)
{
}

IntegrityRegistrator::~IntegrityRegistrator()
{
}


void IntegrityRegistrator::registerTypes(const char* uri)
{
    // Регистрация C++ объектов
    qmlRegisterType(QUrl("qrc:/qml/IntegrityView.qml"), uri, 1, 0, "IntegrityView");
}
