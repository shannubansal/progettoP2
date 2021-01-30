#include "controller.h"

controller::controller(QObject*parent): QObject(parent), m(new model()),  view(new mainWindow()){

     connect(view,SIGNAL(signalQuitB()),this,SLOT(slotCloseEverything()));



    view->show();
}


controller::~controller(){
    delete m;
}


void controller::slotCloseEverything(){
    //if er chiudere tutte le parti di vista
    //chiudere addV
    //chiudere ModV
    //chiudere disV
    //chiudere advSearchV

    this->view->close();
}
