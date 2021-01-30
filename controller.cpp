#include "controller.h"

controller::controller(QObject*parent): QObject(parent), m(new model()),  view(new mainWindow()){





    view->show();
}


controller::~controller(){
    delete m;
}
