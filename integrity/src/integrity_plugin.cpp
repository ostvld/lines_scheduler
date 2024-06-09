#include "integrity_plugin.h"

#include "csc_registrator.h"
#include <QDebug>

void UnifiedDesignPlugin::registerTypes(const char *uri)
{
    CSCRegistrator.h::registerTypes(uri);

    qDebug() << "UDS plugin register types done";
}

void UnifiedDesignPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    Q_UNUSED(uri)

    CSCRegistrator.h::initEngine(engine);
}
