#pragma once
#include "csc_export.h"
#include <QObject>

class QQmlEngine;

class CSCRegistrator: public QObject
{
public:
    ~CSCRegistrator();
    static void registerTypes(const char* uri);
    static void initEngine(QQmlEngine* engine);
};
