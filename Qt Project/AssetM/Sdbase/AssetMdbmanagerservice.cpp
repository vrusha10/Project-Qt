#include "AssetMdbmanagerservice.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include<QMap>
QMap<QString,QString>smap;


AssetMdbmanagerservice *AssetMdbmanagerservice::single=nullptr;
AssetMdbmanagerservice::AssetMdbmanagerservice()
{
  createTable("DataBase.db");
}
AssetMdbmanagerservice::AssetMdbmanagerservice(bool connectStatus):IsConnected(connectStatus){

}

AssetMdbmanagerservice::~AssetMdbmanagerservice()
{

}


AssetMdbmanagerservice *AssetMdbmanagerservice::creatInstance()
{
   if(single==nullptr)
   {
       single=new AssetMdbmanagerservice();
       return single;
   }
   else
   {
       return single;
   }
}

bool AssetMdbmanagerservice::getData(QMap<QString, QString>storedata)
{
  bool sucess=false;
  smap=storedata;
  qDebug()<<"Data Store In sqldb";
  QString v[100];
    int p=0;
    QMap<QString,QString>::Iterator n;
    for(p,n=smap.begin();n!=smap.end();p++,n++)
    {
  //      qDebug()<<n.value();
        v[p]=n.value();
    }
 // qDebug()<<v[0];
  QString Name,Type,Description,SrNo,Model,Manufacture,Location,Site,Condition,Image,Owner;
  Name=storedata["Name"];
  Type=storedata["Type"];
  Description=storedata["Description"];
  SrNo=storedata["SerialNo"];
  Model=storedata["Model"];
  Manufacture=storedata["Manufacture"];
  Location=storedata["Location"];
  Site=storedata["Site"];
  Condition=storedata["Condition"];
  Image=storedata["Image"];
  Owner=storedata["Owner"];
  qDebug()<<Name<<Type<<Description<<SrNo<<Model<<Manufacture<<Location<<Site<<Condition<<Image<<Owner;


  QSqlQuery queryAdd;
  queryAdd.prepare("INSERT INTO AssetMInformation (Name,Type,Description,SrNo,Model,Manufacture,Location,Site,Condition,Image,Owner) values (:Name,:Type,:Description,:SrNo,:Model,:Manufacture,:Location,:Site,:Condition,:Image,:Owner)");
                       queryAdd.bindValue(":Name",Name);
                       queryAdd.bindValue(":Type",Type);
                       queryAdd.bindValue(":Description",Description);
                       queryAdd.bindValue(":SrNo",SrNo);
                       queryAdd.bindValue(":Model",Model);
                       queryAdd.bindValue(":Manufacture",Manufacture);
                       queryAdd.bindValue(":Location",Location);
                       queryAdd.bindValue(":Site",Site);
                       queryAdd.bindValue(":Condition",Condition);
                       queryAdd.bindValue(":Image",Image);
                       queryAdd.bindValue(":Owner",Owner);

            if(queryAdd.exec())
            {
                sucess = true;
            }
            else
            {
                qDebug() << "add AssetMInformation failed: " << queryAdd.lastError();
            }
            return sucess;
}



bool AssetMdbmanagerservice::isOpen() const
{
    return sd.isOpen();
}

bool AssetMdbmanagerservice::createTable(const QString &path)
{
    sd=QSqlDatabase::addDatabase("QSQLITE");
    sd.setDatabaseName(path);

    if(!sd.open())
    {
        qDebug()<<"error";
    }
    else
    {
        qDebug()<<"ok";
    }
    bool success = false;

    QSqlQuery query;

   query.prepare("CREATE TABLE AssetMInformation(Name TEXT,Type TEXT,Description TEXT,SrNo TEXT,Model TEXT,Manufacture TEXT,Location TEXT,Site TEXT,Condition TEXT,Image TEXT,Owner TEXT)");
    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'AssetMInformation': one might already exist.";
        success = false;
    }
    return success;
}



bool AssetMdbmanagerservice::dataExist(const QString& name) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT name FROM AssetMInformation WHERE name = (:name)");
    checkQuery.bindValue(":name", name);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "AssetMInformation exists failed: " << checkQuery.lastError();
    }
     qDebug()<<exists;
    return exists;
}

bool AssetMdbmanagerservice::removeAllData()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM AssetMInformation");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all AssetMInformation failed: " << removeQuery.lastError();
    }

    return success;
}

bool AssetMdbmanagerservice::IsDBConnected()
{
    return IsConnected;
}



/*********************No Used**********************/
//AssetMdbmanagerservice::~AssetMdbmanagerservice()
//{
//    if (sd.isOpen())
//    {
//        sd.close();
//    }
//}

//bool AssetMdbmanagerservice::createTable2()
//{
//    bool success = false;

//    QSqlQuery query;
//     query.prepare("CREATE TABLE AssertLocation(id INTEGER PRIMARY KEY, name TEXT);");
//    if (!query.exec())
//    {
//        qDebug() << "Couldn't create the table 'AssertLocation': one might already exist.";
//        success = false;
//    }

//    return success;
//}

//bool AssetMdbmanagerservice::addPerson(const QString& name)
//{
//    bool success = false;

//    if (!name.isEmpty())
//    {
//        QSqlQuery queryAdd;
//        queryAdd.prepare("INSERT INTO AssertInformation (name) VALUES (:name)");
//        queryAdd.bindValue(":name", name);

//        if(queryAdd.exec())
//        {
//            success = true;
//        }
//        else
//        {
//            qDebug() << "add AssertInformation failed: " << queryAdd.lastError();
//        }
//    }
//    else
//    {
//        qDebug() << "add AssertInformation failed: name cannot be empty";
//    }

//    return success;
//}

//bool AssetMdbmanagerservice::removePerson(const QString& name)
//{
//    bool success = false;

//    if (personExists(name))
//    {
//        QSqlQuery queryDelete;
//        queryDelete.prepare("DELETE FROM AssertInformation WHERE name = (:name)");
//        queryDelete.bindValue(":name", name);
//        success = queryDelete.exec();

//        if(!success)
//        {
//            qDebug() << "remove AssetMInformation failed: " << queryDelete.lastError();
//        }
//    }
//    else
//    {
//        qDebug() << "remove AssetMInformation failed: person doesnt exist";
//    }

//    return success;
//}

//void AssetMdbmanagerservice::printAllPersons() const
//{
//    qDebug() << "AssetMInformation in db:";
//    QSqlQuery query("SELECT * FROM AssetMInformation");
//    int idName = query.record().indexOf("name");
//    while (query.next())
//    {
//        QString name = query.value(idName).toString();
//        qDebug() << "===" << name;
//    }
//}

/*********************No Used**********************/
