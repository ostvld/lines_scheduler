#pragma once

#include "core.hpp"
#include <QObject>
#include <QString>
namespace CoreFake {
class Proxy : public Core::Proxy {
  Q_OBJECT
public:
  Proxy(QObject *parent = nullptr) : Core::Proxy(parent) {}

  Q_INVOKABLE QString coreVersion();

  void libraryRegistration() override;
};
} // namespace core
