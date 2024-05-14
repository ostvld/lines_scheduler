#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

/* Директивы имен таблицы, полей таблицы и базы данных */
#define DATABASE_HOSTNAME   "ExampleDataBase"
//#define DATABASE_NAME       "DataBase.db"

#define TABLE                   "TableExample"
#define TABLE_DATE              "date"
#define TABLE_TIME              "time"
#define TABLE_MESSAGE           "message"
#define TABLE_RANDOM            "random"

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();
    /* Методы для непосредственной работы с классом
     * Подключение к базе данных и вставка записей в таблицу
     * */
    bool createTable();
    bool createDBVersion();
    bool inserIntoTable(int it);

private:
    /* Внутренние методы для работы с базой данных
     * */
    void connectToDataBase();
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();

private:
    // Сам объект базы данных, с которым будет производиться работа
    QSqlDatabase    db;
    QString dbname;
    QString tableName;
};

#endif // DATABASE_H
