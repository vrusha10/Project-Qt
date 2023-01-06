#pragma once

#include "AssetMdbmanagerserviceinterface.h"
#include<iostream>
#include<QSqlDatabase>
#include<QString>
class AssetMdbmanagerservice:public AssetMdbmanagerserviceinterface
{ 
private:
 AssetMdbmanagerservice();
   static AssetMdbmanagerservice *single;
//  QString Name,Type,Description,Manufacture,SrNo,Model,Owner,Condition,Location,Image,Site;
   bool IsConnected;
public:

    static AssetMdbmanagerservice *creatInstance();
    bool getData(QMap<QString,QString> sdata);
    bool isOpen() const;
    bool createTable(const QString&);
    bool dataExist(const QString& name) const;
    bool removeAllData();
    bool IsDBConnected();
      AssetMdbmanagerservice(bool connectStatus);
      ~AssetMdbmanagerservice();
  QSqlDatabase sd;
};


//Derived class Db






//    bool addPerson(const QString& name);
//    bool removePerson(const QString& name);
//        void printAllPersons() const;
