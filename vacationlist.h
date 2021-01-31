#ifndef VACATIONLIST_H
#define VACATIONLIST_H

#include<QWidget>
#include<QListWidget>
#include<container.h>
#include<vacationlistitem.h>


class VacationList: public QListWidget{
private:
    Q_OBJECT
    QWidget* parent;
public:
    VacationList(QWidget* =nullptr);
    void addVacation(Vacation *);
    VacationListItem* currentItem() const;
    void removeVacation(VacationListItem*);
};

#endif // VACATIONLIST_H
