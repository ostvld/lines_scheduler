#include "core_fake.hpp"
#include "integrity_library.h"
#include "qstringliteral.h"

#include <QQmlContext>
#include <QQmlEngine>
#include <QtQuickTest>

class Setup : public QObject
{
    Q_OBJECT

public:
    Setup() { }

public slots:
    void qmlEngineAvailable(QQmlEngine* engine)
    {
        engine->rootContext()->setContextProperty("myContextProperty", QVariant(true));

        auto core = new CoreFake::Proxy(engine);
        core->libraryRegistration();

        IntegrityLibrary::init(engine);
    }
};

QUICK_TEST_MAIN_WITH_SETUP(mytest, Setup)

#include "tst_qmltest.moc"
