#ifndef UNIFIEDDESIGNPLUGIN_H
#define UNIFIEDDESIGNPLUGIN_H

#include <QQmlExtensionPlugin>

class QQmlEngine;

class UnifiedDesignPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "ru.stc-spb.design.system/1.0")

public:
	void registerTypes(const char *uri);
    void initializeEngine(QQmlEngine *engine, const char *uri);
};

#endif // UNIFIEDDESIGNPLUGIN_H
