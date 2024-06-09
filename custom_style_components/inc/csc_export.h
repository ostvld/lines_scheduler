#pragma once

#include <QtCore/qglobal.h>

#ifndef CSC_STATIC_BUILD
#ifdef CSC_BUILD
#define CSC_EXPORT Q_DECL_EXPORT
#else
#define CSC_EXPORT Q_DECL_IMPORT
#endif
#else
#define CSC_EXPORT
#endif
