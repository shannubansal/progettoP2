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
public slots:
    void slotCloseEverything();
private:
     model* m;
     mainWindow* view;
};

#endif // CONTROLLER_H
