#ifndef ASSETMREPORT_H
#define ASSETMREPORT_H

#include <QDebug>
#include<QString>

class AssetMReport
{
public:
   AssetMReport();
   void pdfData(int,QString[]);  /*int,QString[]*/
   QString storedReport[200];

};

#endif // ASSETMREPORT_H
