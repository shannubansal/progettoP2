#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMenuBar>
#include<QMainWindow>
#include <QWidget>
#include<QVBoxLayout>
#include<QGroupBox>
#include<QHBoxLayout>
#include<QFormLayout>
#include<QLineEdit> //per input
#include<QPushButton>
// per mostrare i record #include<QListWidget>
// per messaggi che impediscono i completamento di azioni proibite #include<QMessageBox>
#include<QCloseEvent>
#include<QPalette>//se vogliamo colorare i QPushButtons


class mainWindow : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *wrapLayout, *filtersLayout, *listLayout;
    QHBoxLayout *windowActionsLayout, *centralLayout, *listActionsLayout;
    //mainWindowMenu* menuBar;
    QGroupBox *filters, *windowActions, *listActions, *listGroup, *centralGroup;



    QPushButton *loadB, *saveB, *quitB, *advancedSearchB;//actions
    QPushButton *hotelFilterB, *flatFilterB, *campingFilterB, *bungalowFilterB, *pitchFilterB, *removeFilterB;//filters
    QPushButton *displayB, *modifyB, *deleteB;
    //void closeEvent(QCloseEvent*) override;

public:
    explicit mainWindow(QWidget *parent = nullptr);

signals:
    void signalHotelFilterB();
    void signalFlatsFilterB();
    void signalCampingFilterB();
    void signalBungalowFilterB();
    void signalPitchFilterB();
    void signalAdvancedSearchB();
    void signalLoadB();
    void signalSaveB();
    void signalQuitB();



public slots:
};

#endif // MAINWINDOW_H
