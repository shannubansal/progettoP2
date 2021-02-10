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
    //connect(addV, SIGNAL(signalInsert()), this, SLOT(/*da definire*/));



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
