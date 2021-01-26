#ifndef DEEPPTR_H
#define DEEPPTR_H

#include <iostream>
using namespace std;

template<class T>
class DeepPtr {
  T* ptr;
public:
    //member function
    DeepPtr(T* =nullptr);
    DeepPtr(const DeepPtr&);
    DeepPtr<T>& operator=(const DeepPtr<T>&);
    ~DeepPtr();

    T& operator *() const;
    T* operator ->() const;
    operator bool() const; //controlla se get() != nullptr (permette all'utilizzatore di controllare lo stato del puntatore
                            // incapsulato. (Serve negli if: Se ogg di tipo DeepPtr => permette di fare if (ogg)
    bool operator ==(const DeepPtr&) const;

    //modifiers
    T* release(); //ritorna l'oggetto puntato e mette a NULL ptr
    void reset(T*); //delete dell'oggetto puntato da ptr e ptr punta a T* passato come parametro
    void swap(DeepPtr<T>&); //scambia il contenuto dei DeepPtr

    //observers
    T* get() const; //ritorna il puntatore all'oggetto contenuto


};

template<class T>
DeepPtr<T>::DeepPtr(T* p) : ptr(p){cout<<"ptr "<<ptr<<"endptr"<<endl;}

template <class T>
DeepPtr<T>::DeepPtr(const DeepPtr& p){
    cout<<"Dc";
      if(!p.ptr)
          ptr=nullptr;
      else
          ptr=p.ptr->clone();
}

template<class T>
DeepPtr<T>::~DeepPtr() {
   if (ptr) delete ptr;
}


template <class T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr& p){
    if(this != &p){
        if(ptr) delete ptr;
        ptr = p.ptr->clone();
    }
    cout<<"operator = deepPtr"<<endl;
    return *this;
}

template<class T>
T& DeepPtr<T>::operator *() const{
//    cout<<"operator * NON costante"<<endl;
    return *ptr;
}

template<class T>
T* DeepPtr<T>::operator ->() const {
    return ptr;
}

template<class T>
DeepPtr<T>::operator bool() const {
    cout <<"operator bool";
    return get() != nullptr;
}

template<class T>
bool DeepPtr<T>::operator== (const DeepPtr& p) const {
    return ptr == p.ptr;
}

template<class T>
T* DeepPtr<T>::release() {
    T* aux = ptr;
    ptr = nullptr;
    return aux;
}

template<class T>
void DeepPtr<T>::reset(T* p) {
    if (ptr) delete ptr;
    ptr = p;
}

template<class T>
void DeepPtr<T>::swap(DeepPtr<T>& p) {
    if (this != &p) {
        T* aux = ptr;
        ptr = p.ptr;
        p.ptr = aux;
    }
}

template<class T>
T* DeepPtr<T>::get() const {
    return ptr;
}


#endif // DEEPPTR_H



