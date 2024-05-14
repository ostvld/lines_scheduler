#ifndef MODELMEDIATOR_H
#define MODELMEDIATOR_H

#include <QObject>
#include <QStringListModel>


class ModelMediator : public QObject
{
    Q_OBJECT
public:
    explicit ModelMediator(QObject *parent = nullptr);
};

#endif // MODELMEDIATOR_H
