#include <QLocale>
#include <QTranslator>

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlContext>


#include "model.h"
#include "modelmediator.h"



int main(int argc,
         char **argv)
{
    QApplication app(argc, argv);

    qmlRegisterType<Model>("cpp.Model", 1, 0, "Model");

    QQmlApplicationEngine engine;
    QQmlComponent         comp(&engine, QUrl("qrc:/main.qml"));

    // Инициализируем базу данных
//    DataBase database;


        // Объявляем и инициализируем модель представления данных
//        Model *model = new Model();
        /* Поскольку Мы отнаследовались от QSqlQueryModel, то
         * для выборки данных нам необходимо выполнить SQL-запрос,
         * в котором мы выберем все необходимы поля из нужной нам таблицы
         * */
//        model->setQuery("SELECT "
//                          "ObjId,"
//                          "Week,"
//                          "MaxValue,"
//                          "Line1From ,"
//                          "Line1To,"
//                          "Line2MWFrom,"
//                          "Line2MWTo,"
//                          "Line2MarsFrom,"
//                          "Line2MarsTo,"
//                          "Line2CrispFrom,"
//                          "Line2CrispTo,"
//                          "Line3MWFrom,"
//                          "Line3MWTo,"
//                          "Line3MarsFrom,"
//                          "Line3MarsTo,"
//                          "Line3SNKFrom,"
//                          "Line3SNKTo"
//                          " FROM tableName" );


        /* А это уже знакомо из уроков по сигналам и слотам в QML
         * Помещаем полученную модель в контекст QML, чтобы была возможность
         * обращаться к модели по имени "myModel"
         * */
//        engine.rootContext()->setContextProperty("myModel", model);

//        engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//        engine.contextForObject()

//        QObject* pobj           =
                comp.create();
//        QObject* saveButton = pobj->findChild<QObject*>("SaveButton");
//        if (saveButton) {
//            QObject::connect(saveButton, SIGNAL(infoClicked(QString)),
//                             model, SLOT(slotInfo(QString))
//                            );
//        }

    return app.exec();
} // main
