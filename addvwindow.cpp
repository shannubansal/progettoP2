#include "addvwindow.h"

addVWindow::addVWindow(QWidget* parent): QWidget(parent){

    setWindowTitle("Add Vacations");
    addWrapLayout= new QHBoxLayout(this);
    setMinimumSize(800,700);
    setLayout(addWrapLayout);
//layout left
    addLeftLayout= new QVBoxLayout();


    vacationType= new comboVacation(this);
    QLabel*mainType=new QLabel("Select vacation type:");
    mainType->setMaximumHeight(25);
    addLeftLayout->addWidget(mainType);
    addLeftLayout->addWidget(vacationType);

    addLeftGroup= new QGroupBox(this);
    addLeftGroup->setLayout(addLeftLayout);

    addWrapLayout->addWidget(addLeftGroup);

//form Vacation

    QFormLayout *vacationForm = new QFormLayout();
    nameE = new QLineEdit();
    nameE->setPlaceholderText("f.e. Hotel Relilax");
    vacationForm->addRow(tr("&Name:"), nameE);

    placeE = new QLineEdit();
    placeE->setPlaceholderText("f.e. Piazza Roma 19, Montegrotto");
    vacationForm->addRow(tr("&Place:"), placeE);

    countryE = new QLineEdit();
    countryE->setPlaceholderText("f.e. Italy");
    vacationForm->addRow(tr("&Country:"), countryE);

    dateE = (new QDateEdit(QDate::currentDate(),this));
    dateE->setCalendarPopup(true);
    vacationForm->addRow(tr("&Date:"), dateE);

    basePriceE= new QDoubleSpinBox();
    vacationForm->addRow(tr("&Starting Price:"), basePriceE);

    weeksE = new QLineEdit();
    weeksE->setPlaceholderText("f.e. 1");
    weeksE->setValidator(new QRegExpValidator(QRegExp("[0-9][0-9]")));
    vacationForm->addRow(tr("&Weeks:"), weeksE);

    vacationInfoGroup= new QGroupBox("General", this);
    vacationInfoGroup->setLayout(vacationForm);
    addLeftLayout->addWidget(vacationInfoGroup);

//form hotel

    QFormLayout *hotelForm = new QFormLayout();

    starsE = new QLineEdit();
    starsE->setPlaceholderText("f.e. 4");
    starsE->setValidator(new QRegExpValidator(QRegExp("[0-5][A-Z]")));
    hotelForm->addRow(tr("&Stars:"), starsE);

    hotelTypeE= new QComboBox(this);
    hotelTypeE->addItem("Overnight");
    hotelTypeE->addItem("Halfboard");
    hotelTypeE->addItem("Allinclusive");
    hotelForm->addRow(tr("&Service:"), hotelTypeE);

    bedsE = new QLineEdit();
    bedsE->setPlaceholderText("f.e. 4");
    bedsE->setValidator(new QRegExpValidator(QRegExp("[0-9][0-9]")));
    hotelForm->addRow(tr("&Beds:"), bedsE);


    hotelInfoGroup= new QGroupBox("Hotel", this);
    hotelInfoGroup->setLayout(hotelForm);
    addLeftLayout->addWidget(hotelInfoGroup);

//form flat
    QFormLayout *flatForm = new QFormLayout();


    roomsE = new QLineEdit();
    roomsE->setPlaceholderText("f.e. 3");
    roomsE->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]")));
    flatForm->addRow(tr("&Rooms:"), roomsE);

    ACE= new QCheckBox();
    flatForm->addRow(tr("&With AC:"), ACE);

    flatInfoGroup= new QGroupBox("Flat", this);
    flatInfoGroup->setLayout(flatForm);
    addLeftLayout->addWidget(flatInfoGroup);



//form camping

    QFormLayout *campingForm = new QFormLayout();

    maxCapE = new QLineEdit();
    maxCapE->setPlaceholderText("f.e. 3");
    maxCapE->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]")));
    campingForm->addRow(tr("&Max. Capacity:"), maxCapE);

    dailyFeeE= new QDoubleSpinBox();
    campingForm->addRow(tr("&Daily feee:"), dailyFeeE);

    visitorsFeeE= new QDoubleSpinBox();
    campingForm->addRow(tr("&Visitors daily fee:"), visitorsFeeE);

    campingInfoGroup= new QGroupBox("Camping", this);
    campingInfoGroup->setLayout(campingForm);

//right layout
    addRightLayout= new QVBoxLayout();
    addRightLayout->addWidget(campingInfoGroup);
    addRightGroup= new QGroupBox(this);
    addRightGroup->setLayout(addRightLayout);

    addWrapLayout->addWidget(addRightGroup);



//form pitch
    QFormLayout *pitchForm=new QFormLayout();

    tentAvailableE= new QCheckBox();//checkbox che controlla il tipo di pitch
    pitchForm->addRow(tr("&Tent Available"), tentAvailableE);

    tentTypeE= new QComboBox(this);
    tentTypeE->addItem("None");
    tentTypeE->addItem("Small");
    tentTypeE->addItem("Medium");
    tentTypeE->addItem("Large");
    pitchForm->addRow(tr("&Tent Type"), tentTypeE);

    pitchInfoGroup= new QGroupBox("Pitch",this);
    pitchInfoGroup->setLayout(pitchForm);
    addRightLayout->addWidget(pitchInfoGroup);


//form bungalow
    QFormLayout *bungalowForm= new QFormLayout();

    maxVisE = new QLineEdit();
    maxVisE->setPlaceholderText("f.e. 5");
    maxVisE->setValidator(new QRegExpValidator(QRegExp("[1-2][0-9]")));
    bungalowForm->addRow(tr("&Max. Visitors Capacity:"), maxVisE);

    bungalowTypeE= new QComboBox(this);
    bungalowTypeE->addItem("Standard");
    bungalowTypeE->addItem("Suite");
    bungalowTypeE->addItem("Deluxe");
    bungalowForm->addRow(tr("&Bungalow Type"),bungalowTypeE);

    cleaningServE= new QCheckBox();
    bungalowForm->addRow(tr("&Cleaning Service available:"), cleaningServE);


    bungalowInfoGroup= new QGroupBox("Bungalow",this);
    bungalowInfoGroup->setLayout(bungalowForm);
    addRightLayout->addWidget(bungalowInfoGroup);


//buttons actions

    buttonsLayout= new QHBoxLayout();

    insertB= new QPushButton("Insert",this);
    insertB->setEnabled(false);
    addQuitB= new QPushButton("Cancel", this);
    buttonsLayout->addWidget(insertB);
    buttonsLayout->addWidget(addQuitB);

    buttonsGroup= new QGroupBox(this);
    buttonsGroup->setLayout(buttonsLayout);
    buttonsGroup->setMaximumHeight(100);
    addRightLayout->addWidget(buttonsGroup);



//disabilita
typeEnablingCombo(0);
 //enableTentTypeE();









//connect

    connect(addQuitB, SIGNAL(clicked()), this, SLOT(close()));
    connect(insertB, SIGNAL(clicked()), this, SLOT(slotInsert()));
    connect(vacationType, SIGNAL(activated(int)), this, SLOT(typeEnablingCombo(int)));

    connect(tentAvailableE, SIGNAL(clicked()), this, SLOT(enableTentTypeE()));





}



//get functions

QLineEdit* addVWindow::getNameE() const{
    return nameE;
}

QLineEdit* addVWindow::getPlaceE() const{
    return placeE;
}

QLineEdit* addVWindow::getCountryE() const{
    return countryE;
}

QLineEdit* addVWindow::getWeeksE() const{
    return weeksE;
}

QLineEdit* addVWindow::getStarsE() const{
    return starsE;
}

QLineEdit* addVWindow::getBedsE()  const{
    return bedsE;
}

QLineEdit* addVWindow::getRoomsE() const{
    return roomsE;
}

QLineEdit* addVWindow::getMaxCapE() const{
    return maxCapE;
}

QLineEdit* addVWindow::getMaxVisE() const{
    return maxVisE;
}

QDateEdit * addVWindow::getDateE() const{
    return dateE;
}

QDoubleSpinBox* addVWindow::getBasePriceE() const{
    return basePriceE;
}

QDoubleSpinBox* addVWindow::getDailyFeeE() const{
    return dailyFeeE;
}

QDoubleSpinBox* addVWindow::getVisitorsFeeE() const{
    return visitorsFeeE;
}

QComboBox* addVWindow::getHotelTypeE() const{
    return hotelTypeE;
}

QComboBox* addVWindow::getTentTypeE() const{
    return tentTypeE;
}

QComboBox* addVWindow::getBungalowTypeE() const{
    return bungalowTypeE;
}

QCheckBox* addVWindow::getACE() const{
    return ACE;
}

QCheckBox* addVWindow::getCleaningServE() const{
    return cleaningServE;
}

QCheckBox* addVWindow::getTentAvailableE() const{
    return tentAvailableE;
}

QPushButton* addVWindow::getInsertB() const{
    return insertB;
}

comboVacation* addVWindow::getVacationCombo() const{
    return vacationType;
}


void addVWindow::slotInsert(){
    emit signalInsert();
}

void addVWindow::enableTentTypeE(){
    if(tentAvailableE->isChecked()){
        tentTypeE->setEnabled(true);
    }else{
        tentTypeE->setCurrentIndex(0);
        tentTypeE->setEnabled(false);
    }
}

void addVWindow::resetFields() const{
    ACE->setChecked(false);
    cleaningServE->setChecked(false);
    tentAvailableE->setChecked(false);


    vacationType->setCurrentIndex(0);
    typeEnablingCombo(0);
    hotelTypeE->setCurrentIndex(0);
    tentTypeE->setCurrentIndex(0);
    tentTypeE->setEnabled(false);
    bungalowTypeE->setCurrentIndex(0);

    basePriceE->setValue(0);
    dailyFeeE->setValue(0);
    visitorsFeeE->setValue(0);

    dateE->setDate(QDate::currentDate());

    nameE->setText("");
    placeE->setText("");
    countryE->setText("");
    weeksE->setText("1");
    starsE->setText("1");
    bedsE->setText("1");
    roomsE->setText("1");
    maxCapE->setText("1");
    maxVisE->setText("0");


}


void addVWindow::typeEnablingCombo(int i) const{
    switch (i) {
    case 1://hotel

        vacationInfoGroup->setEnabled(true);
        hotelInfoGroup->setEnabled(true);
        flatInfoGroup->setEnabled(false);

        campingInfoGroup->setEnabled(false);
        bungalowInfoGroup->setEnabled(false);
        pitchInfoGroup->setEnabled(false);
        insertB->setEnabled(true);

        break;

    case 2://flat
        vacationInfoGroup->setEnabled(true);
        hotelInfoGroup->setEnabled(false);
        flatInfoGroup->setEnabled(true);

        campingInfoGroup->setEnabled(false);
        bungalowInfoGroup->setEnabled(false);
        pitchInfoGroup->setEnabled(false);
        insertB->setEnabled(true);

        break;

    case 3://bungalow
        vacationInfoGroup->setEnabled(true);
        hotelInfoGroup->setEnabled(false);
        flatInfoGroup->setEnabled(false);

        campingInfoGroup->setEnabled(true);
        bungalowInfoGroup->setEnabled(true);
        pitchInfoGroup->setEnabled(false);
        insertB->setEnabled(true);

        break;

    case 4://pitch
        vacationInfoGroup->setEnabled(true);
        hotelInfoGroup->setEnabled(false);
        flatInfoGroup->setEnabled(false);

        campingInfoGroup->setEnabled(true);
        bungalowInfoGroup->setEnabled(false);
        pitchInfoGroup->setEnabled(true);
        insertB->setEnabled(true);

        break;

    case 0://none
        vacationInfoGroup->setEnabled(true);
        hotelInfoGroup->setEnabled(false);
        flatInfoGroup->setEnabled(false);

        campingInfoGroup->setEnabled(false);
        bungalowInfoGroup->setEnabled(false);
        pitchInfoGroup->setEnabled(false);
        insertB->setEnabled(false);

        break;
    }

}

