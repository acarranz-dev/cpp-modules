#ifndef ARRAY_BAG_HPP
#define ARRAY_BAG_HPP

#include "bag.hpp"
#include <iostream>

template <typename T>
class ArrayBag : public Bag<T> {
protected:
    static const int DEFAULT_CAPACITY = 10;
    T* items;
    int itemCount;
    int maxItems;
    
    int getIndexOf(const T& target) const;
    
public:
    ArrayBag();
    ArrayBag(const ArrayBag<T>& other);
    virtual ~ArrayBag();
    ArrayBag<T>& operator=(const ArrayBag<T>& other);
    
    virtual void add(const T& item);
    virtual void remove(const T& item);
    virtual bool contains(const T& item) const;
    virtual int size() const;
    virtual bool isEmpty() const;
    virtual void clear();
    
    void display() const;
};

#include "array_bag.cpp"
#endif
