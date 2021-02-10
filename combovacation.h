#ifndef COMBOVACATION_H
#define COMBOVACATION_H

#include<QComboBox>
#include <QWidget>

class comboVacation: public QComboBox{
    Q_OBJECT
public:
    comboVacation(QWidget* parent= nullptr);
};

#endif // COMBOVACATION_H
