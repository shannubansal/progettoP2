#ifndef XMLMANAGER_H
#define XMLMANAGER_H
#include <QXmlStreamWriter>
#include <container.h>
#include "vacation.h"
#include <QFile>
#include <QApplication>
#include "xmlwriter.h"


class XMLManager
{
    QFile *file;
    Container<DeepPtr<Vacation>>* cont;
public:
    XMLManager(Container<DeepPtr<Vacation>>*);
    void saveAsXML();
};

#endif // XMLMANAGER_H
