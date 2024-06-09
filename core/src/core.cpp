#include "core.hpp"
#include "model.h"

#include <QtQml/QtQml>

namespace Core {
QString Proxy::coreVersion()
{
    return QString { "0.1.0.0" };
}

void Proxy::setInfo(const QString &str){
    qDebug() << Q_FUNC_INFO << str;
}

void Proxy::libraryRegistration()
{
    qmlRegisterType<Core::Proxy>("CoreProxy", 0, 1, "CoreProxy");
    qmlRegisterType<Model>("CoreProxy", 0, 1, "Model");
}


} // namespace Core
