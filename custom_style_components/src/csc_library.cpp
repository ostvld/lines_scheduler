#include "csc_library.h"

#include "csc_registrator.h"

#include <QtQml/QtQml>


void CSCLibrary::initLibrary(QQmlEngine* engine)
{
#if defined CSC_STATIC_BUILD
    // Инициализация ресурсов при статической сборке
    Q_INIT_RESOURCE(custom_components_res);
#endif

    // Указываем путь где искать модуль
    engine->addImportPath(":/");

    CSCRegistrator::registerTypes("CSC");
    CSCRegistrator::initEngine(engine);
}
