#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include<QVBoxLayout>
#include<QGroupBox>
#include<QHBoxLayout>
#include<QFormLayout>
#include<QLineEdit>
#include<QPushButton>
#include<QListWidget>
#include<QMessageBox>
#include<QCloseEvent>
#include<QPalette>//se vogliamo colorare i QPushButtons

#include<vacationlist.h>
#include<model.h>


class mainWindow : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *wrapLayout, *filtersLayout, *listLayout;
    QHBoxLayout *windowActionsLayout, *centralLayout, *listActionsLayout;
    QGroupBox *filters, *windowActions, *listActions, *listGroup, *centralGroup;

    QPushButton *loadB, *saveB, *quitB, *advancedSearchB;//actions
    QPushButton *hotelFilterB, *flatFilterB, *campingFilterB, *bungalowFilterB, *pitchFilterB, *removeFilterB;//filters
    QPushButton *addB, *displayB, *modifyB, *deleteB;
    //void closeEvent(QCloseEvent*) override;
    VacationList* vListView;

public:
    explicit mainWindow(QWidget *parent = nullptr);
    VacationList* getVacationListW();
    void showInfoItem(const QStringList);
    bool isSelected() const;
    void showVacationInfo(const QStringList);
    void closeEvent(QCloseEvent*) override;


signals:
    void signalHotelFilterB();
    void signalFlatFilterB();
    void signalCampingFilterB();
    void signalBungalowFilterB();
    void signalPitchFilterB();
    void signalRemoveFilterB();
    void signalAdvancedSearchB();
    void signalLoadB();
    void signalSaveB();
    void signalQuitB();


    void signalOpenInsert();
    void signalOpenModify();
    void signalOpenDisplay();

    void signalRemoveVacation();




public slots:
};

#endif // MAINWINDOW_H
