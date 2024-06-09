#pragma once

#include <QObject>
#include <QString>
namespace Core {
class Proxy : public QObject {
  Q_OBJECT
public:
  Proxy(QObject *parent = nullptr) : QObject(parent) {}

  Q_INVOKABLE QString coreVersion();

  virtual void libraryRegistration();
};
} // namespace core
