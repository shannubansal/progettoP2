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
        Nodo(const &T, Nodo* n=nullptr);
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

    void pushback(const T&);
    void emptyContainer();
/*    bool trovanodo(const T&);
    void remove(const T&);
    bool empty() const;
    void sostituisciNodo(const T& oldNodo, const T& newNodo);
*/

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


//implementazione funzioni Nodo

template<class T>
typename Container<T>::Nodo* Container<T>::copy(Nodo * pri, Nodo *& ult)
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
void Container<T>::Nodo::deleteNodi()//cancella ricorsivamente tutti i nodi della lista
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


template<class T>
typename Container<T>::Iterator Container<T>::begin() const{
    return Iterator(first);
}

template<class T>
typename Container<T>::Iterator Container<T>::end() const{
    return Iterator(nullptr);
}

template<class T>
typename Container<T>::ConstIterator Container<T>::begin() const{
    return ConstIterator(first);
}


template<class T>
typename Container<T>::ConstIterator Container<T>::begin() const{
    return ConstIterator(nullptr);
}


template<class T>
void database<T>:: pushback(const T&t){
    Nodo*q=new Nodo(t);
    if(!first) {
        first=last=q;
    }
    else {
        last->next=q;
        last=last->next;
    }
}


/*
template<class T>
bool database<T>::trovaNodo(const T& i){
    bool trovato=false;

    if(first->info == i)
        trovato=true;
    if(last->info==i)
        trovato=true;

    Nodo* scorri=first;

    while(scorri->next && !trovato){
        if(scorri->info == i)
            trovato=true;
        else
            scorri=scorri->next;
    }
    return trovato;
}

template<class T>
void database<T>::sostituisciNodo(const T& oldNodo, const T& newNodo){

    if(this->trovaNodo(oldNodo)){
        if(first->info == oldNodo)
            first->info = newNodo;
        if(last->info==oldNodo)
            last->info = newNodo;

        Nodo* scorri=first;

        bool done = false;
        while(scorri->next && !done){
            if(scorri->info == oldNodo){
                scorri->info = newNodo;
                done = true;
            }
            else
                scorri=scorri->next;
        }

        delete oldNodo;
    }

}


template<class T>
void database<T>::remove(const T &i)
{
    if(trovaNodo(i) == true){
    //caso 1
        if(first->info == i){
            Nodo*elim=first;
            first=first->next;
            elim->next=nullptr;
            delete elim;
            conta_nodi--;
        }

        else{
            Nodo*scorri=first->next;
            Nodo*prec=first;

            while(scorri->info != i){
                scorri=scorri->next;
                prec=prec->next;
            }
            //caso 2
            if(scorri->info==last->info){
                prec->next=nullptr;
                last=prec;
                delete scorri;
                conta_nodi--;
            }
            //caso 3
            else{
                Nodo*elim=scorri;
                prec->next=scorri->next;
                elim->next=nullptr;
                delete elim;
                conta_nodi--;
            }
        }
    }
    return;
}

*/

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
Container<T>::ConstIterator::ConstIterator(Nodo * p) : cptr(p) {}

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
    Iterator tmp=*this;
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

