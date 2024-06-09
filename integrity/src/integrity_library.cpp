#include "integrity_library.h"

#include "integrity_registrator.h"

#include <QtQml/QtQml>

void IntegrityLibrary::init(QQmlEngine *engine) {
#if defined integrity_STATIC_BUILD
  // Инициализация ресурсов при статической сборке
  Q_INIT_RESOURCE(IntegrityDesignRes);
#endif

  // Указываем путь где искать модуль
  engine->addImportPath(":/");
  //    UnifiedDesignLibrary::initLibrary(engine);
  CSCLibrary::initLibrary(engine);
  IntegrityRegistrator::registerTypes("Integrity");
  IntegrityRegistrator::initEngine(engine);
}
