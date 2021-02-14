#ifndef XMLREADER_H
#define XMLREADER_H

#include "reader.h"
#include "deepPtr.h"
#include "vacation.h"
#include "bungalow.h"
#include "hotel.h"
#include "flat.h"
#include "pitch.h"
#include <QXmlStreamReader>
#include <QString>

class XMLReader : public Reader, public QXmlStreamReader
{
    void readGeneralInfo(Vacation *);
    void readCampingInfo(Camping *);
public:
    XMLReader();
    virtual DeepPtr<Vacation>* read();
};

#endif // XMLREADER_H
