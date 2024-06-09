#pragma once

#include <QObject>
#include <QString>
namespace Core {
class Proxy : public QObject {
  Q_OBJECT
public:
  Proxy(QObject *parent = nullptr) : QObject(parent) {}

  Q_INVOKABLE QString coreVersion();

  Q_INVOKABLE void setInfo(const QString& str);

  virtual void libraryRegistration();
};
} // namespace core
