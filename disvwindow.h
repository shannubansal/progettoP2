#ifndef DISVWINDOW_H
#define DISVWINDOW_H

#include<mainwindow.h>
#include<model.h>
#include<vacation.h>
#include<container.h>
#include<QWidget>
#include<QLabel>


class disVWindow: public QWidget {
public:
    disVWindow(QWidget *parent=nullptr);
    void fillLabels(VacationListItem* va);
    QLineEdit* getVisitorsE() const;
    QLineEdit* getPeopleE() const;
    Vacation* getDisVacationFromW();
    void setDisVacation(Vacation *);

signals:
    //void signalCalc() const;
private:
    Vacation* v;
    QHBoxLayout *wrapDLayout, *buttonsDLayout;
    QVBoxLayout *centralSxLayout, *centralDxLayout;
    QGroupBox *vacationInfoG, *hotelInfoG, *flatInfoG, *campingInfoG,
    *bungalowInfoG, *pitchInfoG, *pricesGroup, *buttonsGroup;
    QLabel *vacationTypeE, *nameE, *placeE, *countryE, *weeksE, *starsE, *bedsE, *roomsE, *maxCapE, *maxVisE,
     *dateE, *basePriceE, *dailyFeeE, *visitorsFeeE,*hotelTypeE, *bungalowTypeE, *tentTypeE,
    *ACE, *cleaningServE, *tentAvailableE, *finalPriceE, *commissionE, *priceAndFeesE;
    QLabel * visitorsE, *peopleE;
    QPushButton *cancel /**calc*/;

public slots:
    //void slotCalc();
};

#endif // DISVWINDOW_H
