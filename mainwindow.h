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
#include<mainwindowmenu.h>

class mainWindow : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *wrapLayout;
    mainWindowMenu* menuBar;

    //void closeEvent(QCloseEvent*) override;
    QPushButton *prova;

public:
    explicit mainWindow(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // MAINWINDOW_H
