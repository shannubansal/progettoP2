#ifndef ADDVWINDOW_H
#define ADDVWINDOW_H

#include <QObject>
#include <QWidget>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGroupBox>
#include<QLineEdit>
#include<QDateEdit>
#include<QDoubleSpinBox>
#include<QComboBox>
#include<QCheckBox>
#include<QFormLayout>
#include<QLabel>
#include<QPushButton>
#include<vacation.h>
#include<combovacation.h>


class addVWindow: public QWidget{
 Q_OBJECT
protected:

    QHBoxLayout *addWrapLayout, *buttonsLayout;
    QVBoxLayout *addLeftLayout, *addRightLayout;
    comboVacation* vacationType;
    QLineEdit *nameE, *placeE, *countryE, *weeksE, *starsE, *bedsE, *roomsE, *maxCapE, *maxVisE;
    QDateEdit *dateE;
    QDoubleSpinBox *basePriceE, *dailyFeeE, *visitorsFeeE;
    QComboBox *hotelTypeE, *bungalowTypeE, *tentTypeE;
    QCheckBox *ACE, *cleaningServE, *tentAvailableE;
    QGroupBox *addLeftGroup, *addRightGroup;//main layouts
    QGroupBox *vacationInfoGroup, *hotelInfoGroup, *flatInfoGroup, *campingInfoGroup,
    *bungalowInfoGroup, *pitchInfoGroup, *buttonsGroup;//box info per ogni classe
    QPushButton *insertB, *addQuitB;
signals:
    void signalDisableCombo(int);
    void signalInsert();
public:
    addVWindow(QWidget* parent= nullptr);

    QLineEdit *getNameE() const;
    QLineEdit *getPlaceE() const;
    QLineEdit *getCountryE() const;
    QLineEdit *getWeeksE() const;
    QLineEdit *getStarsE() const;
    QLineEdit *getBedsE() const;
    QLineEdit *getRoomsE() const;
    QLineEdit *getMaxCapE() const;
    QLineEdit *getMaxVisE() const;


    QDateEdit *getDateE() const;
    QDoubleSpinBox *getBasePriceE() const;
    QDoubleSpinBox *getDailyFeeE() const;
    QDoubleSpinBox *getVisitorsFeeE() const;

    QComboBox *getHotelTypeE() const;
    QComboBox *getTentTypeE() const;
    QComboBox *getBungalowTypeE() const;

    QCheckBox *getACE() const;
    QCheckBox *getCleaningServE() const;
    QCheckBox *getTentAvailableE() const;

    QPushButton *getInsertB() const;

    comboVacation *getVacationCombo() const;


public slots:

    void typeEnablingCombo(int) const;
    virtual void slotInsert();

    void enableTentTypeE();

    void resetFields() const;

};

#endif // ADDVWINDOW_H
