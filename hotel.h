#ifndef HOTEL_H
#define HOTEL_H
#include<vacation.h>
using std::string;


class Hotel: public Vacation
{

public:
    enum serviceType { overnight, halfboard, allinclusive};//forse valutare posizionamento diverso (qua serve per non
    //inquinare il namespace)

    Hotel(string="", string="", string="", int=2020, int=1, int=1, double=0.0, unsigned int=1, unsigned int=0, Hotel::serviceType=overnight, unsigned int=1);

    virtual ~Hotel() =default;
    virtual Hotel* clone() const override;
    double calcFinalPrice() const override;
    double calcCommission() const override;
    //virtual void print() const override();
    virtual string getTipo()const override;
    virtual string getInfo() const override;

    static string convertServToString (const serviceType& );
    static serviceType convertServToEnum(const string&);

    int getStars() const;
    serviceType getType() const;
    int getBeds() const;

    void setStars(int s);
    void setType(serviceType ty);
    void setBeds(int b);
private:
        unsigned int stars;
        serviceType type;
        unsigned int beds;


};
std::ostream& operator<<(std::ostream&, const Hotel&);
#endif // HOTEL_H
