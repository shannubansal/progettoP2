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
    DeepPtr& operator=(const DeepPtr&);//modifica
    bool operator !=(const DeepPtr&) const;
    ~DeepPtr();

    T& operator *() const;
    T* operator ->() const;
    operator bool() const;

    bool operator ==(const DeepPtr&) const;



    T* release();
    void reset(T*);
    void swap(DeepPtr<T>&);


    T* get() const;


};

template<class T>
DeepPtr<T>::DeepPtr(T* p ) : ptr(p ? p->clone() : nullptr) {}

template <class T>
DeepPtr<T>::DeepPtr(const DeepPtr& p){
      if(p.ptr==nullptr)
          ptr=nullptr;
      else
          ptr=((p.ptr)->clone());
}

template<class T>
DeepPtr<T>::~DeepPtr() {
   if (ptr) delete ptr;
}


template <class T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr& p){
    if(this != &p){
        if(ptr) delete ptr;
        ptr = p.ptr == nullptr ? nullptr : (p.ptr)->clone();

    }

    return *this;
}

template<class T>
T& DeepPtr<T>::operator *() const{
    return *ptr;
}

template<class T>
T* DeepPtr<T>::operator ->() const {
    return ptr;
}

template<class T>
DeepPtr<T>::operator bool() const {
    return get() != nullptr;
}

template<class T>
bool DeepPtr<T>::operator== (const DeepPtr& p) const {
    return *ptr == *(p.ptr);
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
    ptr = p->clone();
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



