#pragma once

#include <QtCore/qglobal.h>

#ifndef INTEGRITY_STATIC_BUILD
#ifdef INTEGRITY_BUILD
#define Integrity_EXPORT Q_DECL_EXPORT
#else
#define Integrity_EXPORT Q_DECL_IMPORT
#endif
#else
#define Integrity_EXPORT
#endif
