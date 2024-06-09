#pragma once

#include "csc_library.h"
#include "integrity_export.h"

#include <QLocale>
#include <QTranslator>

class QQmlEngine;


class Integrity_EXPORT IntegrityLibrary
{
public:
    static void init(QQmlEngine* engine);
};
