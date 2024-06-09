#pragma once
#include "csc_export.h"

class QQmlEngine;

class CSCRegistrator
{
public:
    ~CSCRegistrator();
    static void registerTypes(const char* uri);
    static void initEngine(QQmlEngine* engine);
};
