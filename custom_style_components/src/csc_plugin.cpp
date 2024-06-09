#include "UnifiedDesignPlugin.h"

#include "UDSCommon.h"
#include <QDebug>

void UnifiedDesignPlugin::registerTypes(const char *uri)
{
    UDSCommon::registerTypes(uri);

    qDebug() << "UDS plugin register types done";
}

void UnifiedDesignPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    Q_UNUSED(uri)

    UDSCommon::initEngine(engine);

    qDebug() << "UDS plugin initialize engine done";
}
