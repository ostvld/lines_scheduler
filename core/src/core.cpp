#include "core.hpp"

#include <QtQml/QtQml>

namespace Core {
QString Proxy::coreVersion()
{
    return QString { "0.1.0.0" };
}

void Proxy::libraryRegistration()
{
    qmlRegisterType<Core::Proxy>("CoreProxy", 0, 1, "CoreProxy");
}
} // namespace Core
