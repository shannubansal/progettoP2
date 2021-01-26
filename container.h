#ifndef CONTAINER_H
#define CONTAINER_H
#include "deepPtr.h"
#include <iostream>
using namespace std;

template<class T>
class Container;

template<class T>
class Iterator_base {
  friend class Container<T>;
  friend class Container<const T>;

  typename Container<T>::Nodo* ptr;
public:
//  Iterator_base();
//  Iterator_base(const typename Container<T>::Nodo *);
//  Iterator_base& operator=(const Iterator_base&);

  bool operator ==(const Iterator_base&) const;
  bool operator !=(const Iterator_base&) const;

  T& operator *() const;
  T* operator ->() const;
  Iterator_base& operator ++();
  Iterator_base& operator ++(int);
};


template<class T>
class Container {
    friend class Iterator_base<T>;
    friend class Iterator_base<const T>;
private:

    class Nodo {
    public:
        T info;
        Nodo* next;

        Nodo(const T&, Nodo* =nullptr);
//        Nodo(const Nodo&);

        ~Nodo();
//        void deleteNodi();
    };


    static typename Container<T>::Nodo* copy(const Nodo*, const Nodo* &);

    Nodo* last;
    Nodo* first;

public:

    typedef Iterator_base<T> Iterator;
    typedef Iterator_base<const T> ConstIterator;


    Container();
//    Container(int, const T&);
    Container(const Container&);
    ~Container();
    Container& operator=(const Container&);

    bool isEmpty() const;
//    void insert();
//    void remove();
//    void empty();

    void pushback(const T&);
//    void emptyContainer();
/*    bool trovanodo(const T&);
    void remove(const T&);
    bool empty() const;
    void sostituisciNodo(const T& oldNodo, const T& newNodo);
*/




//  class ConstIterator {
//      friend class Container<T>;
//      const Nodo* cptr;
//    public:
//      ConstIterator();
//      ConstIterator(Nodo*);
//      ConstIterator& operator=(const ConstIterator&);
//      bool operator ==(ConstIterator&) const;
//      bool operator !=(ConstIterator&) const;

//      const T& operator *() const;
//      const T* operator ->() const;

//      ConstIterator& operator ++();
//      ConstIterator operator ++(int);
//    };




    ConstIterator cbegin() const;
    ConstIterator cend() const;
//    const T& operator [](const ConstIterator&) const;


    Iterator begin() const;
    Iterator end() const;
//    T& operator [](const Iterator&) const;


};


//implementazione funzioni Nodo

template<class T>
Container<T>::Nodo::Nodo(const T& t, Nodo* n) : info(t), next(n) {}

//template<class T>
//Container<T>::Nodo::Nodo(const Nodo& n) : info(n.info), next(0){}

template<class T>
Container<T>::Nodo::~Nodo() {if (next) delete next;}

template<class T>
typename Container<T>::Nodo* Container<T>::copy(const Container<T>::Nodo * pri, const Container<T>::Nodo * &ult) {
    if (!pri) return ult = new Nodo(pri->info);
    Nodo* p = new Nodo(pri->info, copy(pri->next, ult));
    return p;
}


//template<class T>
//void Container<T>::Nodo::deleteNodi()//cancella ricorsivamente tutti i nodi della lista
//{
//    if (next) next->deleteNodi();
//    delete this;
//}




//implementazione funzioni Container


template<class T>
Container<T>::Container() : last(nullptr), first(nullptr) {}

template<class T>
Container<T>::Container(const Container& i): first(copy(i.first,i.last)) {}

template<class T>
Container<T>& Container<T>::operator=(const Container<T>& c) {
    if (this != &c) {
        delete this;
        first = Container<T>::copy(c.first, c.last);
    }

    return *this;
}

template<class T>
Container<T>::~Container (){
    if (first) delete first;
    last = nullptr;
//    this->emptyContainer();
}


//template<class T>
//void Container<T>::emptyContainer(){

//    if (first){
//            first->deleteNodi();
//            first = nullptr;
//        }

//}


template<class T>
bool Container<T>::isEmpty() const{
    return (first==nullptr);
}


template<class T>
typename Container<T>::Iterator Container<T>::begin() const{
    cout<<" Begin ";
    Container<T>::Iterator aux;
    aux.ptr = first;
    return aux;
}

template<class T>
typename Container<T>::Iterator Container<T>::end() const{
    cout<<" end ";
    Container<T>::Iterator aux;
    aux.ptr = nullptr;
    return aux;
}

template<class T>
typename Container<T>::ConstIterator Container<T>::cbegin() const{
    cout<<" cBegin ";
    typename Container<T>::ConstIterator aux;
    aux.ptr = first;
    return aux;
}

template<class T>
typename Container<T>::ConstIterator Container<T>::cend() const{
    cout<<" cend ";
    Container<T>::ConstIterator aux;
    aux.ptr = nullptr;
    return aux;
}

template<class T>
void Container<T>::pushback(const T&t){
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

//template<class T>
//Iterator_base<T>::Iterator_base() : ptr(nullptr){}

//template<class T>
//Iterator_base<T>::Iterator_base(const typename Container<T>::Nodo *n) : ptr(n) {}

template<class T>
T& Iterator_base<T>::operator*() const {
      return ptr->info;
    }

template<class T>
T* Iterator_base<T>::operator->() const {
  return &(ptr->info);
}

template<class T>
Iterator_base<T>& Iterator_base<T>::operator++() {
    if(ptr) ptr=ptr->next;
          return *this;
}

template<class T>
bool Iterator_base<T>:: operator==(const Iterator_base& x) const {
  return ptr==x.ptr;
}

template<class T>
bool Iterator_base<T>:: operator!=(const Iterator_base& x) const {
  return ptr!=x.ptr;
}

//template<class T>
//Iterator_base<T>& Iterator_base<T>:: operator=(const Iterator_base& i){
//    if(this!=&i)
//        ptr=i.ptr;
//    return *this;
//}

//implementazione funzioni ConstIterator
//template<class T>
//Container<T>::ConstIterator::ConstIterator(Nodo * p) : cptr(p) {}

//template<class T>
//Container<T>::ConstIterator::ConstIterator() : cptr(nullptr) {}

//template<class T>
//typename Container<T>::ConstIterator & Container<T>::ConstIterator::operator=(const ConstIterator & cit)
//{
//    cptr=cit.cptr;
//    return *this;
//}

//template<class T>
//typename Container<T>::ConstIterator& Container<T>::ConstIterator::operator++()
//{
//    if(cptr) cptr=cptr->next;
//    return *this;

//}
//template<class T>
//typename Container<T>::ConstIterator& Container<T>::ConstIterator::operator++(int)
//{
//    Iterator tmp=*this;
//    if(cptr) cptr=cptr->next;
//    return tmp;

//}

//template<class T>
//const T & Container<T>::ConstIterator::operator*() const
//{
//    return cptr->info;
//}

//template<class T>
//const T * Container<T>::ConstIterator::operator->() const
//{
//    return &(cptr->info);
//}

//template<class T>
//bool Container<T>::ConstIterator::operator==(const ConstIterator& cit)
//{
//    return cptr == cit.cptr;
//}

//template<class T>
//bool Container<T>::ConstIterator::operator!=(const ConstIterator& cit)
//{
//    return cptr != cit.cptr;
//}


#endif // CONTAINER_H

