#include "core_fake.hpp"

#include <QtQml/QtQml>

namespace CoreFake {
QString Proxy::coreVersion()
{
    return QString { "0.1.0.0_fake" };
}

void Proxy::libraryRegistration()
{
    qmlRegisterType<CoreFake::Proxy>("CoreProxy", 0, 1, "CoreProxy");
}
} // namespace Core
