#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QWidget>

#include<model.h>
#include<mainwindow.h>

class controller: public QObject{
        Q_OBJECT

public:
    controller(QObject *parent = nullptr);
    ~controller();
    void updateVacationListW(bool userFiltered);

public slots:

    void slotHotelFilter();

    void slotFlatFilter();
    void slotCampingFilter();
    void slotBungalowFilter();
    void slotPitchFilter();
    void slotRemoveFilter();
    /*


    void slotAdvancedSearch();
    void slotLoadB();
    void slotSaveB();

    void OpenInsertVacation() const;
    void signalOpenModify();
    void signalOpenDisplay();
     * */
    void slotCloseEverything();

private:
     model* m;
     mainWindow* view;
};

#endif // CONTROLLER_H
