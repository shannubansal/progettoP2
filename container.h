#ifndef CONTAINER_H
#define CONTAINER_H
//madonna cagna
template<class T>
class Container {

    class Nodo {
    public:
        T p;
        Nodo* next;
        Nodo();

        ~Nodo();
    };
public:
    Container();
    ~Container();


    void insert();
    void remove();
    void empty();

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

    class const_Iterator {
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

    const_Iterator& begin() const;
    const_Iterator& end() const;
    const T& operator [](const_Iterator&) const;

    Iterator& begin();
    Iterator& end();
    T& operator [](const Iterator&) const;

private:

    Nodo* first;

};
#endif // CONTAINER_H

