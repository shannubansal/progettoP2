#include "xmlreader.h"

XMLReader::XMLReader(){}

void XMLReader::readGeneralInfo(Vacation* v){

    if (readNextStartElement() && name() == ("Name"))
        v->setName(readElementText().toUtf8().constData());
    if (readNextStartElement() && name() == ("Place"))
        v->setPlace(readElementText().toUtf8().constData());
    if (readNextStartElement() && name() == ("Country"))
        v->setCountry(readElementText().toUtf8().constData());
    if (readNextStartElement() && name() == ("Date"))
        v->setDateVacation(QDate::fromString(readElementText()));
    if (readNextStartElement() && name() == ("BasePrice"))
        v->setBasePrice(readElementText().toDouble());
    if (readNextStartElement() && name() == ("Weeks"))
        v->setWeeks(readElementText().toInt());
}

void XMLReader::readCampingInfo(Camping * c){
    if (readNextStartElement() && name() == ("MaxCapacity"))
        c->setMaxCapacity(readElementText().toInt());
    if (readNextStartElement() && name() == ("DailyFee"))
        c->setDailyFee(readElementText().toDouble());
    if (readNextStartElement() && name() == ("VisitorsFee"))
        c->setVisitorsFee(readElementText().toDouble());
}

 DeepPtr<Vacation>* XMLReader::read() {
    DeepPtr<Vacation>* v = new DeepPtr<Vacation>;

//    if (readNextStartElement()){
            if (name() == ("Flat")){
                    Flat * f = new Flat();
                    readGeneralInfo(f);
                    if (readNextStartElement() && name() == ("Rooms"))
                        f->setRooms(readElementText().toInt());
                    if (readNextStartElement() && name() == ("AC"))
                        f->setAC(readElementText() == "Yes" ? true : false);

                    v->reset(f);
                    delete f;
            }
            else
                if (name() == ("Hotel")) {
                    Hotel* h = new Hotel();
                    readGeneralInfo(h);
                    if (readNextStartElement() && name() == ("Stars"))
                        h->setStars(readElementText().toInt());
                    if (readNextStartElement() && name() == ("Type")) {
                        if (readElementText() == "Overnight") h->setType(Hotel::serviceType::overnight);
                        else if (readElementText() == "Halfboard") h->setType(Hotel::serviceType::halfboard);
                        else if (readElementText() == "Allinclusive") h->setType(Hotel::serviceType::allinclusive);
                    }

                    if (readNextStartElement() && name() == ("Beds"))
                        h->setBeds(readElementText().toInt());

                    v->reset(h);
                    delete h;
                }
                else
                    if (name() == ("Pitch")) {
                        Pitch *p = new Pitch();
                        readGeneralInfo(p);
                        readCampingInfo(p);

                        if (readNextStartElement() && name() == ("TentAvailable"))
                            p->setTentAvailable(readElementText() == "Yes" ? true : false);
                        if (readNextStartElement() && name() == ("Type")) {
                            if (readElementText() == "Small") p->setTent(Pitch::tentType::small);
                            else if (readElementText() == "Medium") p->setTent(Pitch::tentType::medium);
                            else if (readElementText() == "Large") p->setTent(Pitch::tentType::large);
                            else p->setTent(Pitch::tentType::none);
                        }

                        v->reset(p);
                        delete p;
                    }
                    else
                        if (name() == ("Bungalow")) {
                            Bungalow *b = new Bungalow();
                            readGeneralInfo(b);
                            readCampingInfo(b);

                            if (readNextStartElement() && name() == ("MaxVisitors"))
                                b->setMaxVisitors(readElementText().toInt());

                            if (readNextStartElement() && name() == ("Type")) {
                                if (readElementText() == "Standard") b->setBungalowType(Bungalow::bungalowType::standard);
                                else if (readElementText() == "Suite") b->setBungalowType(Bungalow::bungalowType::suite);
                                else if (readElementText() == "Deluxe") b->setBungalowType(Bungalow::bungalowType::deluxe);
                                else b->setBungalowType(Bungalow::bungalowType::standard);
                            }
                            if (readNextStartElement() && name() == ("CleaningService"))
                                b->setCleaningServ(readElementText() == "Yes" ? true : false);

                            v->reset(b);
                            delete b;
                        }
//    }
    skipCurrentElement();

    return v;
}


