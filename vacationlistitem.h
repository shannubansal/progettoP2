#ifndef VACATIONLISTITEM_H
#define VACATIONLISTITEM_H

#include <QWidget>
#include <QListWidgetItem>
#include<container.h>
#include<vacation.h>
#include<model.h>

class VacationListItem: public QListWidgetItem{
private:
    DeepPtr<Vacation>* item;
    QWidget* parent;


public:
    VacationListItem(DeepPtr<Vacation>*, QWidget* =nullptr);
    DeepPtr<Vacation>* getItem();
    void updateItem();
};

#endif // VACATIONLISTITEM_H
