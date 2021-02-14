#include "vacationlistitem.h"

VacationListItem::VacationListItem(Vacation* i, QWidget* p): item(i), parent(p){
   updateItem();
}


void VacationListItem::updateItem(){
    setText(QString::fromStdString((item->getInfo())));

}


Vacation* VacationListItem::getItem(){
    return this->item;
}
