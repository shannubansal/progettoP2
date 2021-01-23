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
        DeepPtr<T> info;
        Nodo* next;
        Nodo(const DeepPtr<T>& i, nodo* n=nullptr);
        Nodo(const Nodo&);
        ~Nodo();
        void deleteNodo();
    };
    Nodo* first;
    Nodo* last;
public:
    Container() {}
    Container(const Container&);
    ~Container() {}
    Container& operator=(const Container&);
    static Nodo*copia(Nodo*, Nodo*&);


    void insert();
    void remove();
    void empty();

    class Iterator {
      friend class Container<T>;
      Nodo* ptr;
    public:
      Iterator();
      Iterator(Nodo*);
      bool operator ==(const Iterator&) const;
      bool operator !=(const Iterator&) const;

      T& operator *() const;
      T* operator ->() const;
      Iterator& operator ++();
      Iterator& operator ++(int);
    };

 /*   class const_Iterator {
      friend class Container<T>;
      const Nodo* it;
    public:
      bool operator ==(const_Iterator&) const;
      bool operator !=(const_Iterator&) const;

      const T& operator *() const;
      const T* operator ->() const;

      Iterator& operator ++();
      Iterator operator ++(int);
    };

    const_Iterator& begin() const {cout<<"const iterator";};
    const_Iterator& end() const;
    const T& operator [](const_Iterator&) const;
*/


    Iterator& begin() const {cout<<"iterator";}
    Iterator& end() const;
    T& operator [](const Iterator&) const;



};


//implentazione funzioni nodo

template<class T>
typename Container<T>::nodo* Container<T>::copia(Nodo * pri, Nodo *& ult)
{
    if (pri == nullptr)
    {
        ult = nullptr;
        return nullptr;
    }
    Nodo* p = new Nodo(pri->info, copia(pri->next, ult));
    if(pri->next == nullptr) ult = p;
    return p;
}


template<class T>
void Container<T>::nodo::deleteNodo()//cancella ricorsivamente tutti i nodi della lista
{
    if (next) next->deleteNodo();
    delete this;
}




//implementazione funzioni Container


template<class T>
Container<T>::Container() : first(nullptr), last(nullptr) {}



template<class T>
Container<T>::Container(const Container & q) : first(copia(q.first, last)) {}





template<class T>
Container<T>::~Container (){
    this->emptyContainer();
}


template<class T>
void Container<T>::emptyContainer()
{

    if (first!= nullptr && first){
            first->deleteNodo();
            first = nullptr;
        }

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



#endif // CONTAINER_H

