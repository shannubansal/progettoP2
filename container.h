#ifndef CONTAINER_H
#define CONTAINER_H
#include "deepPtr.h"
#include <iostream>
using namespace std;

template<class T>
class Container {
private:


    class Nodo {
    public:
        T info;
        Nodo* next;
        Nodo(const &T, nodo* n=nullptr);
        Nodo(const Nodo&);
        ~Nodo();
        void deleteNodi();
    };

    Nodo* first;
    Nodo* last;
public:
    Container() {}
    Container(const T&);
    Container(const Container&);
    ~Container() {}
    Container& operator=(const Container&);
    static Nodo*copy(Nodo*, Nodo*&);

    bool isEmpty() const;
    void insert();
    void remove();
    void empty();

    class Iterator {
      friend class Container<T>;
      Nodo* ptr;
    public:
      Iterator();
      Iterator(Nodo*);
      Iterator& operator=(const Iterator&);

      bool operator ==(const Iterator&) const;
      bool operator !=(const Iterator&) const;

      T& operator *() const;
      T* operator ->() const;
      Iterator& operator ++();
      Iterator& operator ++(int);
    };


  class ConstIterator {
      friend class Container<T>;
      const Nodo* cptr;
    public:
      ConstIterator();
      ConstIterator(Nodo*);
      ConstIterator& operator=(const ConstIterator&);
      bool operator ==(ConstIterator&) const;
      bool operator !=(ConstIterator&) const;

      const T& operator *() const;
      const T* operator ->() const;

      ConstIterator& operator ++();
      ConstIterator operator ++(int);
    };




    ConstIterator begin() const;
    ConstIterator end() const;
    const T& operator [](ConstIterator&) const;


    Iterator begin() const;
    Iterator end() const;
    T& operator [](const Iterator&) const;



};


//implementazione funzioni nodo

template<class T>
typename Container<T>::nodo* Container<T>::copy(Nodo * pri, Nodo *& ult)
{
    if (pri == nullptr)
    {
        ult = nullptr;
        return nullptr;
    }
    Nodo* p = new Nodo(pri->info, copy(pri->next, ult));
    if(pri->next == nullptr) ult = p;
    return p;
}


template<class T>
void Container<T>::nodo::deleteNodi()//cancella ricorsivamente tutti i nodi della lista
{
    if (next) next->deleteNodi();
    delete this;
}




//implementazione funzioni Container


template<class T>
Container<T>::Container() : first(nullptr), last(nullptr) {}

template<class T>
Container<T>::Container(const T& i): first(new Nodo(T)) {last=first;}

template<class T>
Container<T>::Container(const Container & q) : first(copy(q.first, last)) {}

template<class T>
Container<T>::~Container (){
    this->emptyContainer();
}


template<class T>
void Container<T>::emptyContainer(){

    if (first!= nullptr && first){
            first->deleteNodi();
            first = nullptr;
        }

}


template<class T>
bool Container<T>:: isEmpty() const{
    return (first==nullptr);
}

//implementazione funzioni Iterator

template<class T>
Container<T>::Iterator:: Iterator() : ptr(nullptr){}

template<class T>
Container<T>::Iterator:: Iterator(Nodo* n) : ptr(n) {}

template<class T>
const T& Container<T>::Iterator:: operator*() const {
      return ptr->info;
    }

template<class T>
const T* Container<T>::Iterator:: operator->() const {
  return &(ptr->info);
}

template<class T>
T& Container<T>::Iterator:: operator*(){
    return ptr->info;
}

template<class T>
T* Container<T>::Iterator :: operator->(){
    return &(ptr->info);
}

template<class T>
typename Container<T>::Iterator& Container<T>::Iterator::operator++() {
    if(ptr) ptr=ptr->next;
          return *this;
}

template<class T>
bool Container<T>::Iterator:: operator==(const Iterator& x) const {
  return ptr==x.ptr;
}

template<class T>
bool Container<T>::Iterator:: operator!=(const Iterator& x) const {
  return ptr!=x.ptr;
}

template<class T>
typename Container<T>::Iterator & Container<T>::Iterator:: operator=(const Iterator& i){
    if(this!=&i)
        ptr=i.ptr;
    return *this;
}

//implementazione funzioni ConstIterator
template<class T>
Container<T>::ConstIterator::ConstIterator(nodo * p) : cptr(p) {}

template<class T>
Container<T>::ConstIterator::ConstIterator() : cptr(nullptr) {}

template<class T>
typename Container<T>::ConstIterator & Container<T>::ConstIterator::operator=(const ConstIterator & cit)
{
    cptr=cit.cptr;
    return *this;
}

template<class T>
typename Container<T>::ConstIterator& Container<T>::ConstIterator::operator++()
{
    if(cptr) cptr=cptr->next;
    return *this;

}
template<class T>
typename Container<T>::ConstIterator& Container<T>::ConstIterator::operator++(int)
{
    Iteratore tmp=*this;
    if(cptr) cptr=cptr->next;
    return tmp;

}

template<class T>
const T & Container<T>::ConstIterator::operator*() const
{
    return cptr->info;
}

template<class T>
const T * Container<T>::ConstIterator::operator->() const
{
    return &(cptr->info);
}

template<class T>
bool Container<T>::ConstIterator::operator==(const ConstIterator& cit)
{
    return cptr == cit.cptr;
}

template<class T>
bool Container<T>::ConstIterator::operator!=(const ConstIterator& cit)
{
    return cptr != cit.cptr;
}


#endif // CONTAINER_H

