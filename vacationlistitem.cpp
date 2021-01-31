#include "vacationlistitem.h"

VacationListItem::VacationListItem(Vacation* i, QWidget* p): item(i), parent(p){
   updateItem();

}


void VacationListItem::updateItem(){
    setText(QString::fromStdString((item->getTipo())));//temporaneo, bisogna creare un
    //get infoda fare display sulla lista
}


Vacation* VacationListItem::getItem(){
    return this->item;
}
