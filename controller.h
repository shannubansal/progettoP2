#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>


#include<model.h>
#include<mainwindow.h>
#include<addvwindow.h>
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

    void openInsertVacation() const;
    void slotInsertVacation();
    /*


    void slotAdvancedSearch();
    void slotLoadB();
    void slotSaveB();


    void signalOpenModify();
    void signalOpenDisplay();
     * */
    void slotCloseEverything();

private:
     model* m;
     mainWindow* view;
     addVWindow* addV;
};

#endif // CONTROLLER_H
