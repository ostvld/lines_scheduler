#include "model.h"


enum Roles {
    ObjId  = Qt::UserRole + 1,    
    Line1From ,
    Line1To ,
    Line2MWFrom ,
    Line2MWTo ,
    Line2MarsFrom ,
    Line2MarsTo ,
    Line2CrispFrom ,
    Line2CrispTo ,
    Line3MWFrom ,
    Line3MWTo ,
    Line3MarsFrom ,
    Line3MarsTo ,
    Line3SNKFrom ,
    Line3SNKTo,
    MaxLineValue
};

Model::Model(QObject *parent) :
    QStandardItemModel(parent)
  , rowCountFromBase (0)
{
    database = std::make_shared<DataBase>();
    auto roles = roleNames();

    for (int iter = Roles::ObjId ; iter < Roles::MaxLineValue+1 ; ++iter)
    {
        qDebug() << "roles" << iter << roles[iter] << iter - Roles::ObjId;
    }

    this->select();
}

Model::~Model()
{
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    // Определяем номер колонки, адрес так сказать, по номеру роли
    int columnId = role - (Qt::UserRole+1) ;

    QHash<int, QByteArray> roles = roleNames();
    qDebug() << "Model::data" << role << roles [role] << columnId;
    // Создаём индекс с помощью новоиспечённого ID колонки
    QModelIndex modelIndex = this->index(index.row(), columnId);

    /* И с помощью уже метода data() базового класса
     * вытаскиваем данные для таблицы из модели
     * */
    return QStandardItemModel::data(modelIndex, Qt::DisplayRole);
}

void Model::setVal(int objId, int val)
{
    qDebug() << "Model::setVal "<< objId << val;
}

void Model::setCurrentObjectId(const int &objId)
{
    qDebug() << "Model::setCurrentObjectId" << objId;
}

void Model::setLineValueByName(const int &objId, const QString &name, const double &val)
{
    qDebug() << "Model::setFirsValueByName" << objId << name<< val;

    auto roles = roleNames();
    int role = 0;

    for (int iter = Roles::ObjId ; iter < Roles::MaxLineValue+1 ; ++iter)
    {
        if( name == roles[iter])
        {
            qDebug() << "roles" << iter << roles[iter] << iter - Roles::ObjId;
            role = iter - Roles::ObjId;
            break;
        }
    }

    if(0 != role)
    {
        for (int rows = 0 ; rows < this->rowCount() ; ++rows)
        {
            QStandardItem *objIt = this->item(rows,  0);
            int id = objIt->data(Qt::DisplayRole).toInt();
            if(objId == id)
            {
                QStandardItem *valIt = this->item(rows,  role) ;
                valIt->setData(val, Qt::DisplayRole);
                qDebug() <<"Model::setFirsValueByName" << rows <<  valIt->data(Qt::DisplayRole);
                break;
            }
        }
    }

    emit dataChanged();
}



void Model::saveAll()
{
    qDebug() <<  "Model::saveAll" << rowCountFromBase << this->rowCount();


    for(int iterUpdate = 0 ; iterUpdate < rowCountFromBase ; ++iterUpdate)
    {
        qDebug() <<  "Model::saveAll iterInsert row" << iterUpdate;
        QModelIndex index = this->index(iterUpdate, 0);
        auto text = index.data(Roles::ObjId).toString();
        qDebug() <<  "Model::saveAll iterUpdate" << text;
        text = index.data(Roles::Line1To).toString();
        qDebug() <<  "Model::saveAll iterUpdate" << text;
        text = index.data(Roles::Line1To).toString();
        qDebug() <<  "Model::saveAll iterUpdate" << text;

        QSqlQuery query;
        QString supdate =
                "UPDATE tableName"
                " SET Line1From = " +index.data(Roles::Line1From).toString()+
                ", Line1To = " +index.data(Roles::Line1To).toString()+
                ", Line2MWFrom = " +index.data(Roles::Line2MWFrom).toString()+
                ", Line2MWTo = " +index.data(Roles::Line2MWTo).toString()+
                ", Line2MarsFrom = " +index.data(Roles::Line2MarsFrom).toString()+
                ", Line2MarsTo = " +index.data(Roles::Line2MarsTo).toString()+
                ", Line2CrispFrom = "+index.data(Roles::Line2CrispFrom).toString()+
                ", Line2CrispTo = "+index.data(Roles::Line2CrispTo).toString()+
                ", Line3MWFrom = "+index.data(Roles::Line3MWFrom).toString()+
                ", Line3MWTo = "+index.data(Roles::Line3MWTo).toString()+
                ", Line3MarsFrom = "+index.data(Roles::Line3MarsFrom).toString()+
                ", Line3MarsTo = "+index.data(Roles::Line3MarsTo).toString()+
                ", Line3SNKFrom = "+index.data(Roles::Line3SNKFrom).toString()+
                ", Line3SNKTo = "+index.data(Roles::Line3SNKTo).toString()+
                " WHERE ObjId = " + index.data(Roles::ObjId).toString()+
                ";"
                ;

         qDebug() <<"Model::saveAll " << supdate;

        if (!query.exec(supdate))
        {
            qDebug() <<"UnaЫe to update а tablе" ;
        }
    }


    for(int iterInsert = rowCountFromBase ; iterInsert < this->rowCount() ; ++iterInsert)
    {
        qDebug() <<  "Model::saveAll iterInsert row" << iterInsert;
        QModelIndex index = this->index(iterInsert, 0);
        auto text = index.data(Roles::ObjId).toString();
        qDebug() <<  "Model::saveAll iterInsert" << text;
        text = index.data(Roles::Line1To).toString();
        qDebug() <<  "Model::saveAll iterInsert" << text;
        text = index.data(Roles::Line1To).toString();
        qDebug() <<  "Model::saveAll iterInsert" << text;

        QSqlQuery query;
        QString supdate =
                "INSERT INTO tableName ("
//                "ObjId"
                " Week"
                ", MaxLineValue"
                ", Line1From"
                ", Line1To"
                ", Line2MWFrom"
                ", Line2MWTo"
                ", Line2MarsFrom"
                ", Line2MarsTo"
                ", Line2CrispFrom"
                ", Line2CrispTo"
                ", Line3MWFrom"
                ", Line3MWTo"
                ", Line3MarsFrom"
                ", Line3MarsTo"
                ", Line3SNKFrom"
                ", Line3SNKTo"
                ")"
                "VALUES ("
//                    + index.data(Roles::ObjId).toString()+
                    " 0"
                    ", "+ index.data(Roles::MaxLineValue).toString()+
                    ", "+ index.data(Roles::Line1From).toString()+
                    ", " +index.data(Roles::Line1To).toString()+
                    ", " +index.data(Roles::Line2MWFrom).toString()+
                    ", " +index.data(Roles::Line2MWTo).toString()+
                    ", " +index.data(Roles::Line2MarsFrom).toString()+
                    ", " +index.data(Roles::Line2MarsTo).toString()+
                    ", " +index.data(Roles::Line2CrispFrom).toString()+
                    ", " +index.data(Roles::Line2CrispTo).toString()+
                    ", " +index.data(Roles::Line3MWFrom).toString()+
                    ", " +index.data(Roles::Line3MWTo).toString()+
                    ", " +index.data(Roles::Line3MarsFrom).toString()+
                    ", " +index.data(Roles::Line3MarsTo).toString()+
                    ", " +index.data(Roles::Line3SNKFrom).toString()+
                    ", " +index.data(Roles::Line3SNKTo).toString()+
                    ");"
                ;

         qDebug() <<"Model::saveAll " << supdate;

        if (!query.exec(supdate))
        {
            qDebug() <<"UnaЫe INSERT INTO tableName" ;
        }
    }
    emit dataSaveOrRevert();
}

int Model::maxVal() const
{
    return 14;
}

void Model::revertAll()
{
    qDebug() <<  "Model::revertAll" << "\n";
    this->clear();
    rowCountFromBase=0;
    this->select();
    emit dataSaveOrRevert();
}

void Model::addNew()
{
    int rows = this->rowCount();
    QModelIndex lastIndex = this->index(rows-1, 0);
    int newObjId=lastIndex.data(Roles::ObjId).toInt()+1;
    qDebug() <<  "Model::addNew" << rows<< "\n";
    QModelIndex index = this->index(rows, 0);
    this->insertRow(rows,index);
    this->setData(this->index(rows, 0, index), newObjId);
    this->setData(this->index(rows, Roles::Line1From-Roles::ObjId, index),0);
    this->setData(this->index(rows, Roles::Line1To-Roles::ObjId, index), 0);
    this->setData(this->index(rows, Roles::Line2MWFrom-Roles::ObjId, index), 0);
    this->setData(this->index(rows, Roles::Line2MWTo-Roles::ObjId, index), 0);
    this->setData(this->index(rows, Roles::Line2MarsFrom-Roles::ObjId, index), 0);
    this->setData(this->index(rows, Roles::Line2MarsTo-Roles::ObjId, index), 0);
    this->setData(this->index(rows, Roles::Line2CrispFrom-Roles::ObjId, index),0);
    this->setData(this->index(rows, Roles::Line2CrispTo-Roles::ObjId, index), 0);
    this->setData(this->index(rows, Roles::Line3MWFrom-Roles::ObjId, index), 0);
    this->setData(this->index(rows, Roles::Line3MWTo-Roles::ObjId, index),0);
    this->setData(this->index(rows, Roles::Line3MarsFrom-Roles::ObjId, index), 0);
    this->setData(this->index(rows, Roles::Line3MarsTo-Roles::ObjId, index), 0);
    this->setData(this->index(rows, Roles::Line3SNKFrom-Roles::ObjId, index), 0);
    this->setData(this->index(rows, Roles::Line3SNKTo-Roles::ObjId, index), 0);
    this->setData(this->index(rows, Roles::MaxLineValue-Roles::ObjId, index), this->maxVal());
    rows = this->rowCount();
    int col = this->columnCount();
    qDebug() <<  "Model::addNew2" << rows << col << "\n";
    emit dataChanged();
}

void Model::slotInfo(const QString &str)
{
    qDebug() << "Model::slotInfo" << str;
//    qDebug() << "slotInfo" << str << this->index(0,0).data(Roles::ObjId).toInt() << this->index(0,0).data(Roles::Line1From).toString();

}

void Model::select()
{
    QSqlQuery query;
    QString src = "SELECT "
                              "ObjId,"
                              "Week,"
                              "MaxLineValue,"
                              "Line1From ,"
                              "Line1To,"
                              "Line2MWFrom,"
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
                              " FROM tableName" ;
    if ( !query.exec(src))
    {
        qDebug() << "Model::Model" << query.lastError().text();
        return ;
    }
    QSqlRecord rec = query.record();


    QModelIndex ind = this->index(0, 0);
    this->insertColumns(0,  1+ Roles::MaxLineValue-Roles::ObjId, ind);
    while (query.next()){
        int rowsCount = this->rowCount();
        QModelIndex index = this->index(rowsCount, 0);
        this->insertRow(rowsCount,index);
        this->setData(this->index(rowsCount, 0, index), query.value(rec.indexOf("ObjId")).toInt());
        auto Line1From = rec.indexOf("Line1From");
        this->setData(this->index(rowsCount, Roles::Line1From-Roles::ObjId, index), query.value(Line1From).toDouble());
        this->setData(this->index(rowsCount, Roles::Line1To-Roles::ObjId, index), query.value(rec.indexOf("Line1To")).toDouble());
        this->setData(this->index(rowsCount, Roles::Line2MWFrom-Roles::ObjId, index), query.value(rec.indexOf("Line2MWFrom")).toDouble());
        this->setData(this->index(rowsCount, Roles::Line2MWTo-Roles::ObjId, index), query.value(rec.indexOf("Line2MWTo")).toDouble());
        this->setData(this->index(rowsCount, Roles::Line2MarsFrom-Roles::ObjId, index), query.value(rec.indexOf("Line2MarsFrom")).toDouble());
        this->setData(this->index(rowsCount, Roles::Line2MarsTo-Roles::ObjId, index), query.value(rec.indexOf("Line2MarsTo")).toDouble());
        this->setData(this->index(rowsCount, Roles::Line2CrispFrom-Roles::ObjId, index), query.value(rec.indexOf("Line2CrispFrom")).toDouble());
        this->setData(this->index(rowsCount, Roles::Line2CrispTo-Roles::ObjId, index), query.value(rec.indexOf("Line2CrispTo")).toDouble());
        this->setData(this->index(rowsCount, Roles::Line3MWFrom-Roles::ObjId, index), query.value(rec.indexOf("Line3MWFrom")).toDouble());
        this->setData(this->index(rowsCount, Roles::Line3MWTo-Roles::ObjId, index), query.value(rec.indexOf("Line3MWTo")).toDouble());
        this->setData(this->index(rowsCount, Roles::Line3MarsFrom-Roles::ObjId, index), query.value(rec.indexOf("Line3MarsFrom")).toDouble());
        this->setData(this->index(rowsCount, Roles::Line3MarsTo-Roles::ObjId, index), query.value(rec.indexOf("Line3MarsTo")).toDouble());
        this->setData(this->index(rowsCount, Roles::Line3SNKFrom-Roles::ObjId, index), query.value(rec.indexOf("Line3SNKFrom")).toDouble());
        this->setData(this->index(rowsCount, Roles::Line3SNKTo-Roles::ObjId, index), query.value(rec.indexOf("Line3SNKTo")).toDouble());
        this->setData(this->index(rowsCount, Roles::MaxLineValue-Roles::ObjId, index), query.value(rec.indexOf("MaxLineValue")).toDouble());

        qDebug() << "Model::Model select" << this->rowCount() << this->columnCount();
    }

    QModelIndex index = this->index(0, 0);
    auto text = index.data(Roles::ObjId).toString();
    qDebug() << "Model::Model select ObjId" << text;
    auto Line1Fromtext = index.data(Roles::Line1From).toDouble();
    qDebug() << "Model::Model select Line1From" << Line1Fromtext;

    text = index.data(Roles::MaxLineValue).toString();
    qDebug() << "Model::Model select MaxLineValue" << text;

    rowCountFromBase = this->rowCount();
    qDebug() << "Model::Model select rowCount" << rowCountFromBase;
}

QHash<int, QByteArray> Model::roleNames() const {
    /* То есть сохраняем в хеш-таблицу названия ролей
     * по их номеру
     * */
    QHash<int, QByteArray> roles;
    roles[ObjId]="ObjId";
    roles[Line1From]="Line1From";
    roles[Line1To]="Line1To";
    roles[Line2MWFrom]="Line2MWFrom";
    roles[Line2MWTo]="Line2MWTo";
    roles[Line2MarsFrom]="Line2MarsFrom";
    roles[Line2MarsTo]="Line2MarsTo";
    roles[Line2CrispFrom]="Line2CrispFrom";
    roles[Line2CrispTo]="Line2CrispTo";
    roles[Line3MWFrom]="Line3MWFrom";
    roles[Line3MWTo]="Line3MWTo";
    roles[Line3MarsFrom]="Line3MarsFrom";
    roles[Line3MarsTo]="Line3MarsTo";
    roles[Line3SNKFrom]="Line3SNKFrom";
    roles[Line3SNKTo]="Line3SNKTo";
    roles[MaxLineValue]="MaxLineValue";
    return roles;
}
