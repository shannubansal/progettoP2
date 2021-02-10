#include "combovacation.h"

comboVacation::comboVacation(QWidget* parent): QComboBox(parent){
    addItem("Vacation Type");
    addItem("Hotel");
    addItem("Flat");
    addItem("Bungalow");
    addItem("Pitch");

}
