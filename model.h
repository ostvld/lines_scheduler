#ifndef MODEL_H
#define MODEL_H

#include <QObject>
//#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <memory>

#include "database.h"


class Model : public QStandardItemModel
{
    Q_OBJECT
public:
    // Перечисляем все роли, которые будут использоваться в TableView


    // объявляем конструктор класса
    explicit Model(QObject *parent = 0);

    ~Model() override;

    // Переопределяем метод, который будет возвращать данные
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    Q_INVOKABLE void setVal(int objId, int val);


    Q_INVOKABLE void setCurrentObjectId(const int &objId);
    Q_INVOKABLE void setLineValueByName(const int &objId, const QString &name, const double &val);

    Q_INVOKABLE void saveAll();
    Q_INVOKABLE void revertAll();
    Q_INVOKABLE void addNew();
    Q_INVOKABLE int maxVal() const;



signals:
    void dataChanged();
    void dataSaveOrRevert();

public slots:
    void slotInfo(const QString& str);

protected:
    void select();

protected:
    /* хешированная таблица ролей для колонок.
     * Метод используется в дебрях базового класса QAbstractItemModel,
     * от которого наследован класс QSqlQueryModel
     * */
    QHash<int, QByteArray> roleNames() const override;
    std::shared_ptr<DataBase> database;
    int rowCountFromBase;
};

#endif // MODEL_H
