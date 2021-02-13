#include "filemanager.h"
#include <QMessageBox>
XMLManager::XMLManager(Container<DeepPtr<Vacation>> * c) : file (new QFile()), cont(c){}

void XMLManager::saveAsXML() {
    QXmlStreamWriter writer;
    XMLWriter xml;

    file->setFileName(qApp->applicationDirPath() + "/Vacations.xml");
        if(file->exists()) cout << "Source for writing Vacations does exist";
        else {
            cout << "Source for writing Vacations does not exist, attempting to create";
            //CREARE FILE XML STANDARD VUOTO
            QFile empty(qApp->applicationDirPath() + "/Vacations.xml");
        }
        if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
            cout<<"Error while writing Vacations.xml\n";

    xml.setDevice(file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();

    xml.writeStartElement("Vacations");

    for (auto it = cont->begin(); it != cont->end(); ++it) {
        it->get()->saveOnFile(xml);
    }

    xml.writeEndElement();
    xml.writeEndElement();
    xml.writeEndDocument();
    file->close();
//    file->commit();
}
