#include "vacationlist.h"
#include<QScrollBar>


VacationList::VacationList(QWidget *p): parent(p){
    addScrollBarWidget(new QScrollBar(Qt::Orientation::Vertical, parent), Qt::AlignRight);

}


void VacationList::addVacation(DeepPtr<Vacation> * v){
    VacationListItem* i= new VacationListItem(v, parent);
    addItem(i);
}


VacationListItem* VacationList::currentItem() const{
    return static_cast<VacationListItem*>(QListWidget::currentItem());
}

void VacationList::removeVacation(VacationListItem* i) {
    removeItemWidget(i);
    delete i;
}
