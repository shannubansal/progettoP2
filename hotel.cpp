#include "hotel.h"

Hotel::Hotel(string n, string p, string c, int y, int m, int d, double bP, unsigned int w, unsigned int s, Hotel::serviceType ty,
             unsigned int b): Vacation(n, p, c, y, m, d, bP, w), stars(s), type(ty), beds(b){}


Hotel* Hotel::clone() const{
    return new Hotel(*this);
}

double Hotel::calcFinalPrice() const{
    double price= getBasePrice();
    if(getType()==Hotel::serviceType::halfboard){
        price += (price *0.2);
    }else if(getType()==Hotel::serviceType::allinclusive){
        price += (price *0.5);
    };
    price+=(price*0.3*getBeds());
    return price;
}

/*
Flat::print() const{
 //funzione stampa I/O presumibimente
}
*/

double Hotel::calcCommission() const{
    return calcFinalPrice()*0.08;
}


string Hotel::getTipo() const{
    return "Hotel";
}

string Hotel::getInfo() const{
    string s="";
    string stars="";
    for(int i=0; i<getStars(); i++){
        stars.append("*");
    }
    return s.append(Vacation::getInfo())
            .append("\nStarRating: ")
            .append(stars)
            .append("\nService: " +convertServToString(getType()))
            .append("\nBeds: "+ std::to_string(getBeds()));
}



int Hotel::getStars() const{
    return stars;
}

Hotel::serviceType Hotel::getType() const{
    return type;
}

int Hotel::getBeds() const{
    return beds;
}



void Hotel::setStars(int s){
    stars=s;
}

void Hotel::setType(serviceType ty){//da controllare dove mettere
    type=ty;
}

void Hotel::setBeds(int b){
    beds=b;
}

string Hotel::convertServToString(const Hotel::serviceType & l){
    if(l==Hotel::serviceType::overnight){
        return "Overnight";
    }else if(l==Hotel::serviceType::halfboard){
        return "Halfboard";
    }else if(l==Hotel::serviceType::allinclusive){
        return "Allinclusive";
    }else{
        return "Overnight";
    }

}

int Hotel::convertServToI(const Hotel::serviceType&l){
    if(l==Hotel::serviceType::overnight){
        return 0;
    }else if(l==Hotel::serviceType::halfboard){
        return 1;
    }else if(l==Hotel::serviceType::allinclusive){
        return 2;
    }else{
        return 0;
    }

}

bool  Hotel::operator==(const Hotel& h) const {
    return Vacation::operator==(h) && getTipo() == h.getTipo() &&  getStars() == h.getStars() && getType() == h.getType() && getBeds() == h.getBeds();
}

Hotel::serviceType Hotel::convertServToEnum(const string & str){
   if(str=="Overnight" ){
       return Hotel::serviceType::overnight;
   }else if (str=="Halfboard"){
       return Hotel::serviceType::halfboard;
   }else if(str=="Allinclusive"){
       return Hotel::serviceType::allinclusive;
   }else{
       return Hotel::serviceType::overnight;
   }
}



std::ostream& operator<<(std::ostream& os, const Hotel& h) {

    return operator<< (os, static_cast<const Vacation&>(h))
                   << "\nStars: " << h.getStars()
                   << "\nService: " << Hotel::convertServToString(h.getType())
                   <<"\nBeds: "<<h.getBeds();
}

