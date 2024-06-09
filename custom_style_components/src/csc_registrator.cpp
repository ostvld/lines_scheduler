#include "csc_registrator.h"

#include <QtQml/QtQml>



CSCRegistrator::~CSCRegistrator()
{
}


void CSCRegistrator::registerTypes(const char* uri)
{
    qmlRegisterType(QUrl("qrc:/CSC/BigProgressBar.qml"), uri, 1, 0, "CSCBigProgressBar");
    qmlRegisterType(QUrl("qrc:/CSC/CSCButton.qml"), uri, 1, 0, "CSCButton");
    qmlRegisterType(QUrl("qrc:/CSC/CustomRangeSlider.qml"), uri, 1, 0, "CSCCustomRangeSlider");
    qmlRegisterType(QUrl("qrc:/CSC/HederButton.qml"), uri, 1, 0, "CSCHederButton");
    qmlRegisterType(QUrl("qrc:/CSC/LabelRightBorder.qml"), uri, 1, 0, "CSCLabelRightBorder");
}

void CSCRegistrator::initEngine(QQmlEngine *engine)
{
}
