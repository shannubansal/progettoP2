#include "filemanager.h"
#include <QMessageBox>
FileManager::FileManager() : file (new QFile()){}

void FileManager::saveAsXML(Container<DeepPtr<Vacation>> * cont) {
    XMLWriter xml;

    file->setFileName(qApp->applicationDirPath() + "/Vacations.xml");
        if(file->exists()) cout << "Source for writing Vacations does exist";
        else {
            cout << "Source for writing Vacations does not exist, attempting to create";
            //CREARE FILE XML STANDARD VUOTO
            QFile empty(qApp->applicationDirPath() + "/Vacations.xml");
        }
        if(!file->open(QIODevice::WriteOnly | QIODevice::Text)){
            cout<<"Error while writing Vacations.xml\n";
            QMessageBox msgbox(QMessageBox::Warning, "Error while writing Vacations.xml\n", "Can NOT write Vacations.xml\n", QMessageBox::Ok);
            msgbox.exec();
        }
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
}

Container<DeepPtr<Vacation>> * FileManager::loadXML() {
    cout<<"fileManagerXML";
    Container<DeepPtr<Vacation>>* cont = new Container<DeepPtr<Vacation>>();
    XMLReader xml;

    file->setFileName(qApp->applicationDirPath() + "/Vacations.xml");

    if(!file->open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox msgbox(QMessageBox::Warning, "Error while reading Vacations.xml\n", "Vacations.xml does not exist\n", QMessageBox::Ok);
        msgbox.exec();

        return new Container<DeepPtr<Vacation>>();
    }

    xml.setDevice(file);
    if (xml.readNextStartElement() && xml.name() == "Vacations")
        while (xml.readNextStartElement()) {
            DeepPtr<Vacation> d(xml.read());
            cont->pushback(d);
            cout<<endl<<42<<endl;
        }

    xml.clear(); // sarebbe da fare nenl distruttore
    file->close();

    return cont;
}


