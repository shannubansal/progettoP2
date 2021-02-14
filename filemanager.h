#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QDebug>
#include <container.h>
#include "vacation.h"
#include <QFile>
#include <QApplication>
#include "xmlwriter.h"
#include "xmlreader.h"



class FileManager
{
    QFile *file;
public:
    FileManager();
    void saveAsXML(Container<DeepPtr<Vacation>>*);
    Container<DeepPtr<Vacation>>* loadXML();


};

#endif // FILEMANAGER_H
