#ifndef CONTAINER_H
#define CONTAINER_H
#include "deepPtr.h"
#include <iostream>
using namespace std;


template<class T>
class Container {
    friend class Iterator;
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


    static typename Container<T>::Nodo* copy(const Nodo* &, const Nodo* &, Container<T>::Nodo * &);
    void increaseSize();
    void decreaseSize();

    Nodo* last;
    Nodo* first;
    unsigned int size;

public:

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
    void pushfront(const T&);
    void popfront();
    void popback();
    void emptyContainer();
    Nodo* trovanodo(const T&);
    void remove(const T&);
    bool empty() const;
    void sostituisciNodo(const T& oldNodo, const T& newNodo);

    unsigned int getSize() const;

    class Iterator {
        friend class Container<T>;
        Nodo* ptr;
    public:

      bool operator ==(const Iterator&) const;
      bool operator !=(const Iterator&) const;

      T& operator *() const;
      T* operator ->() const;
      Iterator& operator ++();
      Iterator operator ++(int);
    };

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




//    ConstIterator cbegin() const;
//    ConstIterator cend() const;
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
typename Container<T>::Nodo* Container<T>::copy(const Container<T>::Nodo * &inizio, const Container<T>::Nodo * &fine, Container<T>::Nodo * &last) {
    if (inizio->next == fine) return last = new Nodo(fine->info);
    Nodo* p = new Nodo(inizio->info, copy(inizio->next, fine, last));
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
Container<T>::Container() : last(nullptr), first(nullptr), size(0) {}

template<class T>
Container<T>::Container(const Container& i): last(nullptr), first(copy(i.first,i.last, last)), size(i.size) {}

template<class T>
Container<T>& Container<T>::operator=(const Container<T>& c) {
    if (this != &c) {
        delete this;
        first = Container<T>::copy(c.first, c.last, last);
        size=c.size;
    }

    return *this;
}

template<class T>
Container<T>::~Container (){
    if (first) delete first;
//    this->emptyContainer();
}


template<class T>
void Container<T>::emptyContainer(){
    while(!isEmpty()) {
        popfront();
        cout<<"1 ";
    }
}

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

//template<class T>
//typename Container<T>::ConstIterator Container<T>::cbegin() const{
//    cout<<" cBegin ";
//    typename Container<T>::ConstIterator aux;
//    aux.ptr = first;
//    return aux;
//}

//template<class T>
//typename Container<T>::ConstIterator Container<T>::cend() const{
//    cout<<" cend ";
//    Container<T>::ConstIterator aux;
//    aux.ptr = nullptr;
//    return aux;
//}

template<class T>
void Container<T>::pushback(const T&t){
    Nodo* q=new Nodo(t);
    if(!first) {
        first=last=q;
    }
    else {
        last->next=q;
        last=last->next;
    }
    increaseSize();
}

template<class T>
void Container<T>::pushfront(const T&t){
    Nodo* q=new Nodo(t, first);
    if(!first)
        last = q;

    first = q;

    increaseSize();
}

template<class T>
void Container<T>::popfront() {
    if (first) {
        if (first != last) {
            Nodo* q = first;
            first = first->next;
            q->next = nullptr;
            delete q;
        }
        else {
            delete first;
            first = last = nullptr;
        }
        decreaseSize();
    }
}

template<class T>
void Container<T>::popback() {
    if (last) {
        Nodo* q = first;
        if (first != last) {
            for (; q->next!=last;) q=q->next;
            delete last;
            last = q;
            last->next = nullptr;
        }
        else {
            delete first;
        }

        decreaseSize();
    }
}


template<class T>
unsigned int Container<T>::getSize() const {
    return size;
}


template<class T>
void Container<T>::increaseSize() {
    ++size;
}

template<class T>
void Container<T>::decreaseSize() {
    --size;
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
T& Container<T>::Iterator::operator*() const {
      return ptr->info;
    }

template<class T>
T* Container<T>::Iterator::operator->() const {
  return &(ptr->info);
}

template<class T>
typename Container<T>::Iterator& Container<T>::Iterator::operator++() {
    if(ptr) ptr=ptr->next;
          return *this;
}

template<class T>
typename Container<T>::Iterator Container<T>::Iterator::operator++(int) {
    Container<T>::Iterator aux;
    ptr = ptr->next;
    return aux;
}

template<class T>
bool Container<T>::Iterator::operator==(const Iterator& x) const {
  return ptr==x.ptr;
}

template<class T>
bool Container<T>::Iterator::operator!=(const Iterator& x) const {
  return ptr!=x.ptr;
}

//template<class T>
//T& Container<T>::Iterator::operator [](const Iterator& it) const {
//    return *it;
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

