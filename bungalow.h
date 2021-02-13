#ifndef BUNGALOW_H
#define BUNGALOW_H
#include<camping.h>
using std::string;


class Bungalow: public Camping{


public:
    enum bungalowType {standard=0, suite=1, deluxe=2};
    Bungalow(string="", string="", string="", int=2020, int=1, int=1, double=0.0, unsigned int=1,
             unsigned int=1, double=0.0, double=0.0, unsigned int=4, bungalowType=bungalowType::standard, bool=false);
    virtual ~Bungalow() =default;
    virtual Bungalow* clone() const override;
    virtual double calcFinalPrice() const override;
    virtual double calcCommission() const override;
    virtual double getPriceAndFees(unsigned int=1, unsigned int=0) const override;
    virtual string getTipo() const override;
    virtual string getInfo() const override;

    //void print() const override();
    static string convertBungToString (const bungalowType& );
    static bungalowType convertBungtoEnum(const string&);
    static int convertBungToI (const bungalowType& l);

    unsigned int getMaxVisitors() const;
    bungalowType getBungalowType() const;
    bool getCleaningServ() const;
    virtual bool  operator==(const Vacation&) const override;


    void setMaxVisitors(unsigned int mV);
    void setBungalowType(bungalowType bT);
    void setCleaningServ(bool cS);

    void saveOnFile(Writer&);

private:
    unsigned int maxVisitors;
    bungalowType bType;
    bool cleaningService;
};
std::ostream& operator<<(std::ostream&, const Bungalow&);
#endif // BUNGALOW_H
