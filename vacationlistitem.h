#ifndef VACATIONLISTITEM_H
#define VACATIONLISTITEM_H

#include <QWidget>
#include <QListWidgetItem>
#include<container.h>
#include<vacation.h>
#include<model.h>

class VacationListItem: public QListWidgetItem{
private:
    Vacation* item;
    QWidget* parent;


public:
    VacationListItem(Vacation*, QWidget* =nullptr);
    Vacation* getItem();
    void updateItem();
};

#endif // VACATIONLISTITEM_H
