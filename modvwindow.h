#ifndef MODVWINDOW_H
#define MODVWINDOW_H


#include<QObject>
#include<QWidget>
#include<mainwindow.h>
#include<addvwindow.h>
#include<model.h>
#include<vacation.h>
#include<container.h>


class modVWindow: public addVWindow{
   Q_OBJECT

private:
    Vacation* v;

public:
    explicit modVWindow(QWidget *parent = nullptr);
    ~modVWindow();
    void resetModVWindow();
    Vacation* getVacationFromW();
    void setVacation(Vacation *);
    void fillInFieldsMod(VacationListItem* v);


signals:
    void signalModV();

public slots:
    void slotInsert() override;
};

#endif // MODVWINDOW_H
