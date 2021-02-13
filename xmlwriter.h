#ifndef XMLWRITER_H
#define XMLWRITER_H
#include "writer.h"
#include "vacation.h"
#include "bungalow.h"
#include "hotel.h"
#include "flat.h"
#include "pitch.h"
#include <QXmlStreamWriter>
#include <QString>

class XMLWriter : public Writer, public QXmlStreamWriter
{
    void writeGeneralInfo(const Vacation&);
    void writeCampingInfo(const Camping&);
public:
    XMLWriter();

    virtual void write(const Bungalow&);
    virtual void write(const Flat&);
    virtual void write(const Hotel&);
    virtual void write(const Pitch&);
};

#endif // XMLWRITER_H
