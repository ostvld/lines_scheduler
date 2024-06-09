#pragma once

#include "csc_export.h"

#include <QLocale>
#include <QTranslator>

class QQmlEngine;

///CustomStyleComponentsLibrary
class CSC_EXPORT CSCLibrary
{
public:
    static void initLibrary(QQmlEngine* engine);
};
