#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{
    dbname="./DataBase.db";
    tableName="tableName";
    // Подключаемся к базе данных
    this->connectToDataBase();
    /* После чего производим наполнение таблицы базы данных
     * контентом, который будет отображаться в TableView
     * */

}

DataBase::~DataBase()
{
    this->closeDataBase();    
}

/* Методы для подключения к базе данных
 * */
void DataBase::connectToDataBase()
{
    /* Перед подключением к базе данных производим проверку на её существование.
     * В зависимости от результата производим открытие базы данных или её восстановление
     * */
     if(!QFile(dbname).exists()){
        this->restoreDataBase();
        this->createTable();
        this->createDBVersion();
        for(size_t iterRow = 1; iterRow > 0 ; --iterRow)
         {
             if(!this->inserIntoTable(0))
             {
                 return;
             }
         }
    } else {
        this->openDataBase();
    }
}

/* Методы восстановления базы данных
 * */
bool DataBase::restoreDataBase()
{

    if(!this->openDataBase()){
        qDebug() << "Не удалось восстановить базу данных";
        return false;
    }

   return true;
}

/* Метод для открытия базы данных
 * */
bool DataBase::openDataBase()
{
    /* База данных открывается по заданному пути
     * и имени базы данных, если она существует
     * */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(dbname);
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

/* Методы закрытия базы данных
 * */
void DataBase::closeDataBase()
{
    db.close();
}

/* Метод для создания таблицы в базе данных
 * */
bool DataBase::createTable()
{
    /* В данном случае используется формирование сырого SQL-запроса
     * с последующим его выполнением.
     * */
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE "+tableName+" ("
                            "ObjId INTEGER PRIMARY KEY AUTOINCREMENT, "
                            "Week INTEGER NOT NULL,"
                            "MaxLineValue INTEGER  NOT NULL,"
                            "Line1From DOUBLE NOT NULL,"
                            "Line1To DOUBLE NOT NULL,"
                            "Line2MWFrom DOUBLE,"
                            "Line2MWTo DOUBLE,"
                            "Line2MarsFrom DOUBLE,"
                            "Line2MarsTo DOUBLE,"
                            "Line2CrispFrom DOUBLE,"
                            "Line2CrispTo DOUBLE,"
                            "Line3MWFrom DOUBLE,"
                            "Line3MWTo DOUBLE,"
                            "Line3MarsFrom DOUBLE,"
                            "Line3MarsTo DOUBLE,"
                            "Line3SNKFrom DOUBLE,"
                            "Line3SNKTo DOUBLE"
                        " )"
                    )){
        qDebug() << "DataBase: error of create " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBase::createDBVersion()
{
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE DBVersion ("
                            "ObjId INTEGER PRIMARY KEY AUTOINCREMENT, "
                            "Version TEXT NOT NULL"
                        " )"
                    )){
        qDebug() << "DataBase: error of create " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    }

    QString queryText="INSERT INTO DBVersion (Version) VALUES (\"0.0.1\")";

    if(!query.exec( queryText )){
        qDebug() << "DataBase: error of create " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    }

    return true;
}

/* Метод для вставки записи в базу данных
 * */
bool DataBase::inserIntoTable( int it)
{
    QString queryText="INSERT INTO "+ tableName +" ( "
                                "Week,"
                                "MaxLineValue,"
                                "Line1From ,"
                                "Line1To"
                                ",Line2MWFrom,"
                                "Line2MWTo,"
                                "Line2MarsFrom,"
                                "Line2MarsTo,"
                                "Line2CrispFrom,"
                                "Line2CrispTo,"
                                "Line3MWFrom,"
                                "Line3MWTo,"
                                "Line3MarsFrom,"
                                "Line3MarsTo,"
                                "Line3SNKFrom,"
                                "Line3SNKTo"
                                " ) "
                                "VALUES ("
                                ":Week,"
                                ":MaxLineValue,"
                                ":Line1From ,"
                                ":Line1To"
                                ",:Line2MWFrom,"
                                ":Line2MWTo,"
                                ":Line2MarsFrom,"
                                ":Line2MarsTo,"
                                ":Line2CrispFrom,"
                                ":Line2CrispTo,"
                                ":Line3MWFrom,"
                                ":Line3MWTo,"
                                ":Line3MarsFrom,"
                                ":Line3MarsTo,"
                                ":Line3SNKFrom,"
                                ":Line3SNKTo"
                                ")";

    QSqlQuery query;
        query.prepare(queryText);
        query.bindValue(":Week",it);
        query.bindValue(":MaxLineValue", 14);
        query.bindValue(":Line1From",0);
        query.bindValue(":Line1To",0);
        query.bindValue(":Line2MWFrom",0);
        query.bindValue(":Line2MWTo",0);
        query.bindValue(":Line2MarsFrom",0);
        query.bindValue(":Line2MarsTo",0);
        query.bindValue(":Line2CrispFrom",0);
        query.bindValue(":Line2CrispTo",0);
        query.bindValue(":Line3MWFrom",0);
        query.bindValue(":Line3MWTo",0);
        query.bindValue(":Line3MarsFrom",0);
        query.bindValue(":Line3MarsTo",0);
        query.bindValue(":Line3SNKFrom",0);
        query.bindValue(":Line3SNKTo",0);

        if(query.exec()){
            return true;
        }

        qDebug() << "error insert into " << TABLE;
        qDebug() << query.lastError().text();
        return false;
}
