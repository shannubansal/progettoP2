
#include<modvwindow.h>

modVWindow::modVWindow(QWidget *parent) : addVWindow(parent){
    setWindowTitle("Modify Vacation");
}


modVWindow::~modVWindow(){
    if(this->v){
        delete this->v;
    }
}

void modVWindow::resetModVWindow(){
    this->v=nullptr;
    this->resetFields();
}


Vacation* modVWindow::getVacationFromW(){
    return this->v;
}


void modVWindow::setVacation(Vacation* i){
    this->v=i;
}

void modVWindow::slotInsert(){
    emit signalModV();
}


void modVWindow::fillInFieldsMod(VacationListItem * j){
    Vacation* i=j->getItem();
    Hotel*h=dynamic_cast<Hotel*>(i);
    Flat*f=dynamic_cast<Flat*>(i);
    Bungalow*b=dynamic_cast<Bungalow*>(i);
    Pitch*p=dynamic_cast<Pitch*>(i);

    //vacation details
    nameE->clear();
    nameE->setText(QString::fromStdString(i->getName()));

    placeE->clear();
    placeE->setText(QString::fromStdString(i->getPlace()));

    countryE->clear();
    countryE->setText(QString::fromStdString(i->getCountry()));

    dateE->clear();
    dateE->setDate(i->getDate());

    basePriceE->clear();
    basePriceE->setValue(i->getBasePrice());

    weeksE->clear();
    weeksE->setText(QString::fromStdString(std::to_string(i->getWeeks())));

    if(h){
        getVacationCombo()->setCurrentIndex(1);
        typeEnablingCombo(1);

        starsE->clear();
        starsE->setText(QString::fromStdString(std::to_string(h->getStars())));


        hotelTypeE->setCurrentIndex(Hotel::convertServToI(h->getType()));

        bedsE->clear();
        bedsE->setText(QString::fromStdString(std::to_string(h->getBeds())));

    }else if(f){
        getVacationCombo()->setCurrentIndex(2);
        typeEnablingCombo(2);

        ACE->setChecked(f->hasAC());

        roomsE->clear();
        roomsE->setText(QString::fromStdString(std::to_string(f->getRooms())));

    }else if(b){
        getVacationCombo()->setCurrentIndex(3);
        typeEnablingCombo(3);

        maxCapE->clear();
        maxCapE->setText(QString::fromStdString(std::to_string(b->getMaxCapacity())));
        dailyFeeE->clear();
        dailyFeeE->setValue(b->getDailyFee());
        visitorsFeeE->clear();
        visitorsFeeE->setValue(b->getVisitorsFee());

        maxVisE->clear();
        maxVisE->setText(QString::fromStdString(std::to_string(b->getMaxVisitors())));


        bungalowTypeE->setCurrentIndex(Bungalow::convertBungToI(b->getBungalowType()));//noooooooooooooooooooooooooooooo

        cleaningServE->setChecked(b->getCleaningServ());

    }else if(p){
        getVacationCombo()->setCurrentIndex(4);
        typeEnablingCombo(4);

        maxCapE->clear();
        maxCapE->setText(QString::fromStdString(std::to_string(p->getMaxCapacity())));
        dailyFeeE->clear();
        dailyFeeE->setValue(p->getDailyFee());
        visitorsFeeE->clear();
        visitorsFeeE->setValue(p->getVisitorsFee());

        tentAvailableE->setChecked(p->getTentAvailable());


        tentTypeE->setCurrentIndex(Pitch::convertTentToI(p->getTent()));

    }

}





