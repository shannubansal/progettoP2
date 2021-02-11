#include "controller.h"

controller::controller(QObject*parent): QObject(parent), m(new model()),  view(new mainWindow()), addV(new addVWindow()) {

    connect(view,SIGNAL(signalQuitB()),this,SLOT(slotCloseEverything()));
     //filters
    connect(view,SIGNAL(signalHotelFilterB()),this,SLOT(slotHotelFilter()));
    connect(view,SIGNAL(signalFlatFilterB()),this,SLOT(slotFlatFilter()));
    connect(view,SIGNAL(signalCampingFilterB()),this,SLOT(slotCampingFilter()));
    connect(view,SIGNAL(signalBungalowFilterB()),this,SLOT(slotBungalowFilter()));
    connect(view,SIGNAL(signalPitchFilterB()),this,SLOT(slotPitchFilter()));
    connect(view, SIGNAL(signalRemoveFilterB()), this, SLOT(slotRemoveFilter()));
    connect(view, SIGNAL(signalOpenInsert()), this, SLOT(openInsertVacation()));
    connect(addV, SIGNAL(signalInsert()), this, SLOT(slotInsertVacation()));



    view->show();
    updateVacationListW(false);
}


controller::~controller(){
    delete m;
}



void controller::slotHotelFilter(){
    m->filterHotels();
    updateVacationListW(true);
}

void controller::slotFlatFilter(){
    m->filterFlats();
    updateVacationListW(true);
}

void controller::slotCampingFilter(){
    m->filterCamping();
    updateVacationListW(true);
}

void controller::slotBungalowFilter(){
    m->filterBungalows();
    updateVacationListW(true);
}

void controller::slotPitchFilter(){
    m->filterPitches();
    updateVacationListW(true);
}

void controller::slotRemoveFilter(){
    updateVacationListW(false);
}

void controller::openInsertVacation() const{
    addV->resetFields();
    addV->show();
}

void controller::slotCloseEverything(){
    if(this->addV!=nullptr && this->addV->isVisible()){
        this->addV->close();
    }
    //if er chiudere tutte le parti di vista

    //chiudere ModV
    //chiudere disV
    //chiudere advSearchV

    this->view->close();
}


void controller::updateVacationListW(bool useFiltered)
{
    view->getVacationListW()->clear();

    Container<DeepPtr<Vacation>> ::Iterator it;


    Container<DeepPtr<Vacation>>* listaTemp;
    if(!useFiltered){
        listaTemp= this->m->mGetListVacations();
    }
    else{
        listaTemp = this->m->mGetListVacationsFiltered();
    }

    if(!listaTemp->isEmpty()){
        for(it=listaTemp->begin(); it!=listaTemp->end(); ++it){
           if((*it).get() != nullptr){
               view->getVacationListW()->addVacation((*it).get());

            }
         }
    }
}

//errors
void controller::error1(){
    QMessageBox msgBox;
    msgBox.setWindowTitle("Error");
    msgBox.setText("Make sure every field is filled in");
    msgBox.exec();
}
void controller::error2(){
    QMessageBox msgBox;
    msgBox.setWindowTitle("Error");
    msgBox.setText("Make sure to select the vacation type");
    msgBox.exec();
}

void controller::errorDate(){
    QMessageBox msgBox;
    msgBox.setWindowTitle("Error");
    msgBox.setText("The selected date is not valid");
    msgBox.exec();
}

void controller::errorTent(){
    QMessageBox msgBox;
    msgBox.setWindowTitle("Error");
    msgBox.setText("Make sure to select the available tent type");
    msgBox.exec();
}


//add Vacation
void controller::slotInsertVacation(){

    int i= addV->getVacationCombo()->currentIndex();
    Vacation* tmp=nullptr;

    QMessageBox msgBox1;
    msgBox1.setWindowTitle("Confirm");
    msgBox1.setText("Vacation successfully added");

    QMessageBox msgBox2;
    msgBox2.setWindowTitle("Error");

    switch(i){
    case 0:
    {
      emit error2();
      return;
    }
    case 1:{//hotel
        Hotel*h=new Hotel();
        h->setName(addV->getNameE()->text().toStdString());
        h->setPlace(addV->getPlaceE()->text().toStdString());
        h->setCountry(addV->getCountryE()->text().toStdString());
        h->setDateVacation(addV->getDateE()->date().year(), addV->getDateE()->date().month(), addV->getDateE()->date().day());
        h->setBasePrice(addV->getBasePriceE()->value());
        h->setWeeks(addV->getWeeksE()->text().toUInt());

        h->setStars(addV->getStarsE()->text().toUInt());
        h->setType(Hotel::convertServToEnum(addV->getHotelTypeE()->currentText().toStdString()));
        h->setBeds(addV->getBedsE()->text().toUInt());


        if((addV->getDateE()->date()) < QDate::currentDate()){
                emit errorDate();
                return;
        }

        tmp=h;
        break;
    }
    case 2://flat
    {
        Flat* f=new Flat();
        f->setName(addV->getNameE()->text().toStdString());
        f->setPlace(addV->getPlaceE()->text().toStdString());
        f->setCountry(addV->getCountryE()->text().toStdString());
        f->setDateVacation(addV->getDateE()->date().year(), addV->getDateE()->date().month(), addV->getDateE()->date().day());
        f->setBasePrice(addV->getBasePriceE()->value());
        f->setWeeks(addV->getWeeksE()->text().toUInt());

        f->setAC(addV->getACE()->isChecked());
        f->setRooms(addV->getRoomsE()->text().toUInt());

        if((addV->getDateE()->date()) < QDate::currentDate()){
                emit errorDate();
                return;
        }
        tmp=f;
        break;
    }
    case 3://bungalow
    {
        Bungalow* b=new Bungalow();
        b->setName(addV->getNameE()->text().toStdString());
        b->setPlace(addV->getPlaceE()->text().toStdString());
        b->setCountry(addV->getCountryE()->text().toStdString());
        b->setDateVacation(addV->getDateE()->date().year(), addV->getDateE()->date().month(), addV->getDateE()->date().day());
        b->setBasePrice(addV->getBasePriceE()->value());
        b->setWeeks(addV->getWeeksE()->text().toUInt());

        b->setMaxCapacity(addV->getMaxCapE()->text().toUInt());
        b->setDailyFee(addV->getDailyFeeE()->value());
        b->setVisitorsFee(addV->getVisitorsFeeE()->value());

        b->setMaxVisitors(addV->getMaxVisE()->text().toUInt());
        b->setBungalowType(Bungalow::convertBungtoEnum(addV->getBungalowTypeE()->currentText().toStdString()));
        b->setCleaningServ(addV->getCleaningServE()->isChecked());



        if((addV->getDateE()->date()) < QDate::currentDate()){
                emit errorDate();
                return;
        }
        tmp=b;
        break;

    }
    case 4://pich
    {

        Pitch* p= new Pitch();

        p->setName(addV->getNameE()->text().toStdString());
        p->setPlace(addV->getPlaceE()->text().toStdString());
        p->setCountry(addV->getCountryE()->text().toStdString());
        p->setDateVacation(addV->getDateE()->date().year(), addV->getDateE()->date().month(), addV->getDateE()->date().day());
        p->setBasePrice(addV->getBasePriceE()->value());
        p->setWeeks(addV->getWeeksE()->text().toUInt());

        p->setMaxCapacity(addV->getMaxCapE()->text().toUInt());
        p->setDailyFee(addV->getDailyFeeE()->value());
        p->setVisitorsFee(addV->getVisitorsFeeE()->value());

        p->setTentAvailable(addV->getTentAvailableE()->isChecked());
        p->setTent(Pitch::convertTentToEnum(addV->getTentTypeE()->currentText().toStdString()));

        if((addV->getDateE()->date()) < QDate::currentDate()){
                emit errorDate();
                return;
        }

        if((addV->getTentAvailableE()->isChecked()) && (Pitch::convertTentToEnum(addV->getTentTypeE()->currentText().toStdString())== Pitch::none)){
                emit errorTent();
                return;
        }



        tmp=p;
        break;
    }

    }

    if(tmp!=nullptr){
        m->addToContainer(tmp);
        this->updateVacationListW(false);
        addV->close();
        msgBox1.exec();
    }else{
        msgBox2.setText("Error");
        msgBox2.exec();
    }
    }
