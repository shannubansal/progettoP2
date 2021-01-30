#include "vacationlistitem.h"

VacationListItem::VacationListItem(DeepPtr<Vacation>* i, QWidget* p): item(i), parent(p){
    updateItem();

}


void VacationListItem::updateItem(){
    setText(QString::fromStdString((item->get()->getTipo())));//temporaneo, bisogna creare un
    //get infoda fare display sulla lista
}


DeepPtr<Vacation>* VacationListItem::getItem(){
    return this->item;
}
