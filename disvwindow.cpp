#include "disvwindow.h"

disVWindow::disVWindow(QWidget *parent) : QWidget(parent),
  vacationTypeE(new QLabel(this)), nameE(new QLabel(this)), placeE(new QLabel(this)),
  countryE(new QLabel(this)), weeksE(new QLabel(this)), starsE (new QLabel(this)),
     bedsE(new QLabel(this)), roomsE(new QLabel(this)), maxCapE(new QLabel(this)), maxVisE(new QLabel(this)),
     dateE(new QLabel(this)), basePriceE(new QLabel(this)), dailyFeeE(new QLabel(this)), visitorsFeeE(new QLabel(this)),
     hotelTypeE(new QLabel(this)), bungalowTypeE(new QLabel(this)), tentTypeE(new QLabel(this)),
     ACE(new QLabel(this)), cleaningServE(new QLabel(this)), tentAvailableE(new QLabel(this)),
     finalPriceE(new QLabel(this)), commissionE(new QLabel(this)), priceAndFeesE(new QLabel(this)),
     visitorsE(new QLabel(this)), peopleE(new QLabel(this))

{

    setWindowTitle("Vacation Details");
        wrapDLayout= new QHBoxLayout(this);
        setMinimumSize(700,600);
        setLayout(wrapDLayout);
        centralSxLayout=new QVBoxLayout();
        centralDxLayout=new QVBoxLayout();

        centralSxLayout->addWidget(vacationTypeE);

        vacationTypeE->setMaximumHeight(40);
        wrapDLayout->addLayout(centralSxLayout);

//common details sx
     QFormLayout *vacationInfoLayout = new QFormLayout();
     QLabel *nameELabel=new QLabel("Name: ");
     vacationInfoLayout->addRow(nameELabel, nameE);
     QLabel *placeELabel=new QLabel("Place: ");
     vacationInfoLayout->addRow(placeELabel, placeE);
     QLabel *countryELabel=new QLabel("Country: ");
     vacationInfoLayout->addRow(countryELabel, countryE);
     QLabel *dateELabel=new QLabel("Date: ");
     vacationInfoLayout->addRow(dateELabel, dateE);
     QLabel *basePriceELabel=new QLabel("Starting Price: ");
     vacationInfoLayout->addRow(basePriceELabel, basePriceE);
     QLabel *weeksELabel=new QLabel("Weeks: ");
     vacationInfoLayout->addRow(weeksELabel, weeksE);
     vacationInfoG= new QGroupBox("General Info: ",this);
     vacationInfoG->setMinimumWidth(350);
     vacationInfoG->setLayout(vacationInfoLayout);
     centralSxLayout->addWidget(vacationInfoG);

//hotel sx

     QFormLayout *hotelInfoLayout = new QFormLayout();
     QLabel *starsELabel=new QLabel("Stars: ");
     hotelInfoLayout ->addRow(starsELabel, starsE);

     QLabel *hotelTypeELabel=new QLabel("Service: ");
     hotelInfoLayout->addRow(hotelTypeELabel, hotelTypeE);

     QLabel *bedsELabel=new QLabel("Beds: ");
     hotelInfoLayout ->addRow(bedsELabel, bedsE);

     hotelInfoG= new QGroupBox("Hotel Info: ",this);
     hotelInfoG->setLayout(hotelInfoLayout);

     centralSxLayout->addWidget(hotelInfoG);


//flat sx

     QFormLayout *flatInfoLayout= new QFormLayout();
     QLabel *ACELabel=new QLabel("AC: ");
     flatInfoLayout->addRow(ACELabel, ACE);

     QLabel *roomsELabel=new QLabel("Rooms: ");
     flatInfoLayout->addRow(roomsELabel, roomsE);

     flatInfoG= new QGroupBox("Flat Info: ",this);
     flatInfoG->setLayout(flatInfoLayout);

     centralSxLayout->addWidget(flatInfoG);



//camping dx
    QFormLayout *campingInfoLayout = new QFormLayout();
    QLabel *maxCapELabel=new QLabel("Max Capacity: ");
    campingInfoLayout ->addRow(maxCapELabel, maxCapE);

    QLabel *dailyFeeELabel=new QLabel("Daily Fee: ");
    campingInfoLayout->addRow(dailyFeeELabel, dailyFeeE);

    QLabel *visitorsFeeELabel=new QLabel("Visitors Fee: ");
    campingInfoLayout ->addRow(visitorsFeeELabel, visitorsFeeE);

    QLabel *visitorsELabel=new QLabel("Visitors: ");
    campingInfoLayout->addRow(visitorsELabel, visitorsE);

    QLabel *peopleELabel=new QLabel("People: ");
    campingInfoLayout->addRow(peopleELabel, peopleE);


    QLabel *priceAndFeesELabel=new QLabel("Camping Total: ");
    campingInfoLayout ->addRow(priceAndFeesELabel, priceAndFeesE);


    campingInfoG= new QGroupBox("General Camping Info: ",this);
    campingInfoG->setLayout(campingInfoLayout);

    centralDxLayout->addWidget(campingInfoG);
    wrapDLayout->addLayout(centralDxLayout);


//bungalow dx
    QFormLayout *bungalowInfoLayout = new QFormLayout();
    QLabel *maxVisELabel=new QLabel("Max Visitors: ");
    bungalowInfoLayout->addRow(maxVisELabel, maxVisE);


    QLabel *bungalowTypeELabel=new QLabel("Bungalow Type: ");
    bungalowInfoLayout->addRow(bungalowTypeELabel, bungalowTypeE);

    QLabel *cleaningServELabel=new QLabel("Cleaning Service: ");
    bungalowInfoLayout->addRow(cleaningServELabel, cleaningServE);


    bungalowInfoG= new QGroupBox("Bungalow Info: ",this);
    bungalowInfoG->setLayout(bungalowInfoLayout);

    centralDxLayout->addWidget(bungalowInfoG);


//pitch dx
    QFormLayout *pitchInfoLayout = new QFormLayout();
    QLabel *tentAvailableELabel=new QLabel("Tent: ");
    pitchInfoLayout->addRow(tentAvailableELabel, tentAvailableE);

    QLabel *tentTypeELabel=new QLabel("Tent Type: ");
    pitchInfoLayout->addRow(tentTypeELabel, tentTypeE);

    pitchInfoG= new QGroupBox("Pitch Info: ",this);
    pitchInfoG->setLayout(pitchInfoLayout);

    centralDxLayout->addWidget(pitchInfoG);

//bottoni e edit
    QFormLayout *pricesLayout = new QFormLayout();
    QLabel *finalPriceELabel=new QLabel("Final Price: ");
    pricesLayout->addRow(finalPriceELabel, finalPriceE);

    QLabel *commissionELabel=new QLabel("Commission: ");
    pricesLayout->addRow(commissionELabel, commissionE);

    pricesGroup= new QGroupBox("Prices Info: ",this);
    pricesGroup->setLayout(pricesLayout);

    centralDxLayout->addWidget(pricesGroup);

    buttonsDLayout= new QHBoxLayout();
   // calc= new QPushButton("Calculate",this);
    cancel= new QPushButton("Cancel",this);

   // buttonsDLayout->addWidget(calc);
    buttonsDLayout->addWidget(cancel);
    buttonsGroup= new QGroupBox(this);
    buttonsGroup->setLayout(buttonsDLayout);
    centralDxLayout->addWidget(buttonsGroup);

    connect(cancel,SIGNAL(clicked()),this,SLOT(close()));

}

Vacation* disVWindow::getDisVacationFromW(){
    return this->v;
}
void disVWindow::setDisVacation(Vacation* i){
    this->v=i;
}


void disVWindow::fillLabels(VacationListItem* va){
    Vacation* v=va->getItem();

    Hotel* h=dynamic_cast<Hotel*>(v);
    Flat*f=dynamic_cast<Flat*>(v);
    Bungalow* b= dynamic_cast<Bungalow*>(v);
    Pitch* p= dynamic_cast<Pitch*>(v);

    nameE->clear();
    nameE->setText(QString::fromStdString(v->getName()));
    placeE->clear();
    placeE->setText(QString::fromStdString(v->getPlace()));
    countryE->clear();
    countryE->setText(QString::fromStdString(v->getCountry()));
    dateE->clear();
    dateE->setText(v->getDate().toString("yyyy.MM.dd"));
    basePriceE->clear();
    basePriceE->setText(QString::fromStdString(std::to_string(v->getBasePrice())).append(" €"));
    weeksE->clear();
    weeksE->setText(QString::fromStdString(std::to_string(v->getWeeks())));
    commissionE->clear();
    commissionE->setText(QString::fromStdString( std::to_string(v->calcCommission())).append(" €"));
    finalPriceE->clear();
    finalPriceE->setText(QString::fromStdString( std::to_string(v->calcFinalPrice())).append(" €"));
    visitorsE->clear();
    visitorsE->setText("0");
    peopleE->clear();
    peopleE->setText("1");

    if(h){
       vacationTypeE->clear();
       vacationTypeE->setText(QString::fromStdString(h->getTipo()));
       hotelInfoG->setEnabled(true);
       flatInfoG->setEnabled(false);
       campingInfoG->setEnabled(false);
       bungalowInfoG->setEnabled(false);
       pitchInfoG->setEnabled(false);

       starsE->clear();
       starsE->setText(QString::fromStdString(std::to_string(h->getStars())));
       hotelTypeE->clear();
       hotelTypeE->setText(QString::fromStdString(Hotel::convertServToString(h->getType())));
       bedsE->clear();
       bedsE->setText(QString::fromStdString(std::to_string(h->getBeds())));
       visitorsE->clear();
       visitorsE->setText("0");
       peopleE->clear();
       peopleE->setText("0");

    }else if(f){
        vacationTypeE->clear();
        vacationTypeE->setText(QString::fromStdString(f->getTipo()));
        hotelInfoG->setEnabled(false);
        flatInfoG->setEnabled(true);
        campingInfoG->setEnabled(false);
        bungalowInfoG->setEnabled(false);
        pitchInfoG->setEnabled(false);

        ACE->clear();
        ACE->setText( QString::fromStdString(f->hasAC()? "Yes" : "No"));
        roomsE->clear();
        roomsE->setText(QString::fromStdString(std::to_string(f->getRooms())));
        visitorsE->clear();
        visitorsE->setText("0");
        peopleE->clear();
        peopleE->setText("0");

    }else if(b){
        vacationTypeE->clear();
        vacationTypeE->setText(QString::fromStdString(b->getTipo()));
        hotelInfoG->setEnabled(false);
        flatInfoG->setEnabled(false);
        campingInfoG->setEnabled(true);
        bungalowInfoG->setEnabled(true);
        pitchInfoG->setEnabled(false);

        maxCapE->clear();
        maxCapE->setText(QString::fromStdString(std::to_string(b->getMaxCapacity())));
        dailyFeeE->clear();
        dailyFeeE->setText(QString::fromStdString(std::to_string(b->getDailyFee())).append(" €"));
        visitorsFeeE->clear();
        visitorsFeeE->setText(QString::fromStdString(std::to_string(b->getVisitorsFee())).append(" €"));
        priceAndFeesE->clear();
        priceAndFeesE->setText(QString::fromStdString( std::to_string(b->getPriceAndFees())).append(" €"));

        maxVisE->clear();
        maxVisE->setText(QString::fromStdString(std::to_string(b->getMaxVisitors())));
        bungalowTypeE->clear();
        bungalowTypeE->setText(QString::fromStdString(Bungalow::convertBungToString(b->getBungalowType())));
        cleaningServE->clear();
        cleaningServE->setText( QString::fromStdString(b->getCleaningServ()? "Yes" : "No"));
        visitorsE->clear();
        visitorsE->setText("0");
        peopleE->clear();
        peopleE->setText("1");
    }else if(p){
        vacationTypeE->clear();
        vacationTypeE->setText(QString::fromStdString(p->getTipo()));
        hotelInfoG->setEnabled(false);
        flatInfoG->setEnabled(false);
        campingInfoG->setEnabled(true);
        bungalowInfoG->setEnabled(false);
        pitchInfoG->setEnabled(true);

        maxCapE->clear();
        maxCapE->setText(QString::fromStdString(std::to_string(p->getMaxCapacity())));
        dailyFeeE->clear();
        dailyFeeE->setText(QString::fromStdString(std::to_string(p->getDailyFee())));
        visitorsFeeE->clear();
        visitorsFeeE->setText(QString::fromStdString(std::to_string(p->getVisitorsFee())));
        priceAndFeesE->clear();
        priceAndFeesE->setText(QString::fromStdString( std::to_string(p->getPriceAndFees())).append(" €"));

        tentAvailableE->clear();
        tentAvailableE->setText( QString::fromStdString(p->getTentAvailable()? "Yes" : "No"));
        tentTypeE->clear();
        tentTypeE->setText(QString::fromStdString(Pitch::convertTentToString(p->getTent())));
        visitorsE->clear();
        visitorsE->setText("0");
        peopleE->clear();
        peopleE->setText("1");


    }

}



