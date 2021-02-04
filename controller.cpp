#include "controller.h"

controller::controller(QObject*parent): QObject(parent), m(new model()),  view(new mainWindow()){

    connect(view,SIGNAL(signalQuitB()),this,SLOT(slotCloseEverything()));
     //filters
    connect(view,SIGNAL(signalHotelFilterB()),this,SLOT(slotHotelFilter()));
    connect(view,SIGNAL(signalFlatFilterB()),this,SLOT(slotFlatFilter()));
    connect(view,SIGNAL(signalCampingFilterB()),this,SLOT(slotCampingFilter()));
    connect(view,SIGNAL(signalBungalowFilterB()),this,SLOT(slotBungalowFilter()));
    connect(view,SIGNAL(signalPitchFilterB()),this,SLOT(slotPitchFilter()));
    connect(view, SIGNAL(signalRemoveFilterB()), this, SLOT(slotRemoveFilter()));



    view->show();
    updateVacationListW(false);
}


controller::~controller(){
    delete m;
}



void controller::slotHotelFilter(){//da fare per tutti i filtri
    m->filterHotels();
    updateVacationListW(true);
}

void controller::slotFlatFilter(){//da fare per tutti i filtri
    m->filterFlats();
    updateVacationListW(true);
}

void controller::slotCampingFilter(){//da fare per tutti i filtri
    m->filterCamping();
    updateVacationListW(true);
}

void controller::slotBungalowFilter(){//da fare per tutti i filtri
    m->filterBungalows();
    updateVacationListW(true);
}

void controller::slotPitchFilter(){//da fare per tutti i filtri
    m->filterPitches();
    updateVacationListW(true);
}

void controller::slotRemoveFilter(){
    updateVacationListW(false);
}

void controller::slotCloseEverything(){
    //if er chiudere tutte le parti di vista
    //chiudere addV
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
