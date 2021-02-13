#ifndef WRITER_H
#define WRITER_H


class Vacation;
class Camping;

class Bungalow;
class Flat;
class Hotel;
class Pitch;

class Writer
{
protected:
public:
    Writer();
    virtual void write(const Bungalow&) =0;
    virtual void write(const Flat&) =0;
    virtual void write(const Hotel&) =0;
    virtual void write(const Pitch&) =0;

};

#endif // WRITER_H
