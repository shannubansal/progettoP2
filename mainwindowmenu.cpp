#include "mainwindowmenu.h"

mainWindowMenu::mainWindowMenu(QWidget* p): parent(p), load(new QAction ("Load Files", this)),
    save(new QAction("Save", this)), quit(new QAction("Quit", this)){



     QList<QAction*>actions;
     actions.push_back(save);
     actions.push_back(load);
     actions.push_back(quit);
     //menu->addActions(actions);
     actions.clear();

     addMenu(menu);
     addAction("save");
     //addAction(load);
    // addAction(quit);



     //connect(quit,SIGNAL(triggered()),parent,SLOT(close())); // da modificare con chiusura a cascata, magari overridando il close (per cancellare model e controller)



}



QMenu *mainWindowMenu::getMenu() const {
    return menu;
}
QAction *mainWindowMenu::getLoad() const{
    return load;
}

QAction *mainWindowMenu::getSave() const{
    return save;
}

QAction *mainWindowMenu::getQuit() const{
    return quit;
}
