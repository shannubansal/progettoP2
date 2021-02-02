#include "vacationlistitem.h"

VacationListItem::VacationListItem(Vacation* i, QWidget* p): item(i), parent(p){
   updateItem();
   //ui->listWidget->setStyleSheet("QListWidget {padding: 10px;} QListWidget::item { margin: 10px; }");
   //per dello spacing decente tra gli item



}


void VacationListItem::updateItem(){
    setText(QString::fromStdString((item->getInfo())));//temporaneo, bisogna creare un
    //get info da fare display sulla lista
}


Vacation* VacationListItem::getItem(){
    return this->item;
}
