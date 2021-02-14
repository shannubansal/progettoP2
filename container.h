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
        ~Nodo();

    };

    Nodo* nClone(Nodo*);
    static void deleteNodi(Nodo*);
    static typename Container<T>::Nodo* copy(const Nodo* &, const Nodo* &, Container<T>::Nodo * &);
    void increaseSize();
    void decreaseSize();

    Nodo* last;
    Nodo* first;
    unsigned int size;

public:

    Container();
    Container(const Container&);
    ~Container();
    Container<T>& operator=(const Container&);

    bool isEmpty() const;

    void pushback(const T&);
    void pushfront(const T&);
    void popfront();
    void popback();

    void emptyContainer();
    bool searchNode(const T&);

    void remove(const T&);
    bool empty() const;
    void sostituisciNodo(const T& oldV, const T& newV);

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

    Iterator begin() const;
    Iterator end() const;


};


//implementazione funzioni Nodo

template<class T>
Container<T>::Nodo::Nodo(const T& t, Nodo* n) : info(t), next(n) {}

template<class T>
Container<T>::Nodo::~Nodo() {
    if (next) delete next;
}


template<class T>
typename Container<T>::Nodo* Container<T>::nClone(Container<T>::Nodo* n)
{
    if(!n)
        return nullptr;



    if(!n->next)
        return last = new Nodo(n->info);



    return new Nodo(n->info, nClone(n->next));


}

template<class T>
typename Container<T>::Nodo* Container<T>::copy(const Container<T>::Nodo * &inizio, const Container<T>::Nodo * &fine, Container<T>::Nodo * &last) {
    if (inizio->next == fine) return last = new Nodo(fine->info);
    Nodo* p = new Nodo(inizio->info, copy(inizio->next, fine, last));
    return p;
}


template<class T>
void Container<T>::deleteNodi(Container<T>::Nodo* n)
{
    if (n) deleteNodi(n->next);
    delete n;
}




//implementazione funzioni Container


template<class T>
Container<T>::Container() : last(nullptr), first(nullptr), size(0) {}

template<class T>
Container<T>::Container(const Container& i):  first(nClone(i.first)), last(nullptr), size(i.size) {}

template<class T>
Container<T>& Container<T>::operator=(const Container<T>& c) {
    if (this != &c) {
        if(first){
            delete first;
        }
        first = nClone(c.first);
        size=c.size;
    }

    return *this;
}

template<class T>
Container<T>::~Container (){
    if (first) delete first;
}


template<class T>
void Container<T>::emptyContainer(){
    while(!isEmpty())
        popfront();
}

template<class T>
bool Container<T>::isEmpty() const{
    return (first==nullptr);
}


template<class T>
typename Container<T>::Iterator Container<T>::begin() const{
    Container<T>::Iterator aux;
    aux.ptr = first;
    return aux;


}

template<class T>
typename Container<T>::Iterator Container<T>::end() const{
    Container<T>::Iterator aux;
    aux.ptr = nullptr;
    return aux;
}

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




template<class T>
bool Container<T>::searchNode(const T& i){
    bool found=false;

    if(first->info == i){
        found=true;
    }else if(last->info== i){
        found=true;
    }else{

        Nodo* tmp=first;

        while((tmp->next!=nullptr) && !found){
            if(tmp->info == i)
                found=true;
            else
                tmp=tmp->next;
        }
    }
    return found;
}


template<class T>
void Container<T>::sostituisciNodo(const T& oldV, const T& newV){
    bool done = false;
    if(this->searchNode(oldV)){
        if(first->info == oldV){
            first->info = newV;
            done = true;
        }
        if(last->info==oldV){
            last->info = newV;
            done = true;
        }

        Nodo* cur=first;


        while(cur->next && !done){
            if(cur->info == oldV){
                cur->info = newV;
                done = true;
            }
            else
                cur=cur->next;
        }


    }

}

template<class T>
void Container<T>::remove(const T &i)
{
    if(!(this->isEmpty()) && searchNode(i) == true){
        if(getSize()==1 && first->info==i){
            popfront();
            return;
        }else if(getSize()>1 && first->info ==i ){

            popfront();
        }else{
            Nodo*cur=first->next;
            Nodo*pre=first;

            while(!(cur->info == i)){
                cur=cur->next;
                pre=pre->next;
            }

            if(cur->info==last->info){
                pre->next=nullptr;
                last=pre;
                delete cur;
                decreaseSize();
            }else{
                Nodo*elim=cur;
                pre->next=cur->next;
                elim->next=nullptr;
                delete elim;
                decreaseSize();
            }
        }
    }
    return;
}






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

#endif // CONTAINER_H

