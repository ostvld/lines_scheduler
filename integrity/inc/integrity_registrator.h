#pragma once

#include "inc/integrity_export.h"

class QQmlEngine;

class IntegrityRegistrator
{
public:
    ~IntegrityRegistrator();
    static void registerTypes(const char* uri);
    static void initEngine(QQmlEngine* engine);
};
