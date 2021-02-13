#include "xmlwriter.h"

XMLWriter::XMLWriter() {
}


void XMLWriter::writeGeneralInfo(const Vacation &v) {
    writeStartElement(QString::fromStdString((v.getTipo())));
    writeTextElement("Name", QString::fromStdString((v.getName())));
    writeTextElement("Place", QString::fromStdString((v.getPlace())));
    writeTextElement("Country", QString::fromStdString((v.getCountry())));
    writeTextElement("Date", v.getDate().toString());
    writeTextElement("BasePrice", QString::number((v.getBasePrice())));
    writeTextElement("Weeks", QString::number((v.getWeeks())));


}

void XMLWriter::writeCampingInfo(const Camping& c) {
    writeTextElement("MaxCapacity", QString::number((c.getMaxCapacity())));
    writeTextElement("DailyFee", QString::number((c.getDailyFee())));
    writeTextElement("VisitorsFee", QString::number((c.getVisitorsFee())));
}

void XMLWriter::write(const Bungalow &b) {
    writeGeneralInfo(b);
    writeCampingInfo(b);

    writeTextElement("MaxVisitors", QString::number((b.getMaxVisitors())));
    writeTextElement("MaxVisitors", QString::fromStdString((Bungalow::convertBungToString(b.getBungalowType()))));
    writeTextElement("CleaningService", b.getCleaningServ() ? "Yes" : "No");


    writeEndElement();

}

void XMLWriter::write(const Flat &f) {
    writeGeneralInfo(f);
    writeTextElement("Rooms", QString::number((f.getRooms())));
    writeTextElement("AC", f.hasAC() ? "Yes" : "No");

    writeEndElement();
}
void XMLWriter::write(const Hotel &h) {
    writeGeneralInfo(h);
    writeTextElement("Stars", QString::number((h.getStars())));
    writeTextElement("Type", QString::fromStdString((Hotel::convertServToString(h.getType()))));
    writeTextElement("Beds", QString::number((h.getBeds())));

    writeEndElement();
}

void XMLWriter::write(const Pitch &p) {
    writeGeneralInfo(p);

    writeEndElement();


}

/*void XMLWriter::write(const Vacation &v) {


    cout<<"XMLVacation"<<endl;
    write(writer, v);
}*/

