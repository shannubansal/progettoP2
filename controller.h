#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>


#include<model.h>
#include<mainwindow.h>
#include<addvwindow.h>
#include<modvwindow.h>
#include<disvwindow.h>
#include <vector>
#include <QVector>

using namespace::std;

class controller: public QObject{
        Q_OBJECT

public:
    explicit controller(QObject *parent = nullptr);
    ~controller();
    void updateVacationListW(bool userFiltered);
    void error1();
    void error2();
    void errorDate();
    void errorTent();

public slots:

    void slotHotelFilter();
    void slotFlatFilter();
    void slotCampingFilter();
    void slotBungalowFilter();
    void slotPitchFilter();
    void slotRemoveFilter();

    void slotOpenInsertVacation() const;
    void slotOpenModify();
    void slotOpenDisplay();
    void slotInsertVacation();
    void slotModifyVacation();
    void slotRemoveVacation();
    /*


    void slotAdvancedSearch();//nope
    void slotLoadB();
    void slotSaveB();



    void slotOpenDisplay();
     * */
    void slotCloseEverything();

private:
     model* m;
     mainWindow* view;
     addVWindow* addV;
     modVWindow* modV;
     vector<disVWindow*> disVWins;
};

#endif // CONTROLLER_H
