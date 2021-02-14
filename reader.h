#ifndef READER_H
#define READER_H
#include <QXmlStreamReader>
class Vacation;
class Camping;

class Bungalow;
class Flat;
class Hotel;
class Pitch;

class Reader
{
public:
    Reader();
    virtual Vacation* read() =0;
};

#endif // READER_H
