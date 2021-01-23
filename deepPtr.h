#ifndef DEEPPTR_H
#define DEEPPTR_H

#include <iostream>
using namespace std;

template<class T>
class DeepPtr {
  T* ptr;
public:
    //member function
    DeepPtr(T*);
    DeepPtr(const T&) =delete;
    DeepPtr& operator=(const DeepPtr&);
    ~DeepPtr();

    T& operator *() const;
    T* operator ->() const;
    operator bool() const; //controlla se get() != nullptr (permette all'utilizzatore di controllare lo stato del puntatore
                            // incapsulato. (Serve negli if: Se ogg di tipo DeepPtr => permette di fare if (ogg)
    bool operator ==() const;

    //modifiers
    T* release(); //ritorna l'oggetto puntato e mette a NULL ptr
    void reset(T*); //delete dell'oggetto puntato da ptr e ptr punta a T* passato come parametro
    void swap(DeepPtr&); //scambia il contenuto dei DeepPtr

    //observers
    T* get() const; //ritorna il puntatore all'oggetto contenuto


};

template<class T>
DeepPtr<T>::DeepPtr(T* p) : ptr(p){}

template<class T>
DeepPtr<T>::~DeepPtr() {
    delete ptr;
}

template<class T>
T& DeepPtr<T>::operator *() const {
    return *ptr;
}

template<class T>
T* DeepPtr<T>::operator ->() const {
    return ptr;
}

#endif // DEEPPTR_H



