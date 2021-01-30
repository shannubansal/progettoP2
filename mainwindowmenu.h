#ifndef MAINWINDOWMENU_H
#define MAINWINDOWMENU_H

#include<QMenuBar>
#include<QObject>
#include<QWidget>

class mainWindowMenu: public QMenuBar{
    Q_OBJECT
    QWidget* parent;
    QMenu *menu;
    QAction* load;
    QAction* save;// or print
    QAction* quit;
public:
    mainWindowMenu(QWidget* = nullptr);
    QMenu *getMenu() const;
    QAction *getLoad() const;
    QAction *getSave() const;
    QAction *getQuit() const;

};

#endif // MAINWINDOWMENU_H
