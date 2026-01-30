#ifndef ARRAY_BAG_CPP
#define ARRAY_BAG_CPP

#include "array_bag.hpp"

template <typename T>
ArrayBag<T>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY) {
    items = new T[maxItems];
}

template <typename T>
ArrayBag<T>::ArrayBag(const ArrayBag<T>& other) : itemCount(other.itemCount), maxItems(other.maxItems) {
    items = new T[maxItems];
    for (int i = 0; i < itemCount; i++) {
        items[i] = other.items[i];
    }
}

template <typename T>
ArrayBag<T>::~ArrayBag() {
    delete[] items;
}

template <typename T>
ArrayBag<T>& ArrayBag<T>::operator=(const ArrayBag<T>& other) {
    if (this != &other) {
        delete[] items;
        itemCount = other.itemCount;
        maxItems = other.maxItems;
        items = new T[maxItems];
        for (int i = 0; i < itemCount; i++) {
            items[i] = other.items[i];
        }
    }
    return *this;
}

template <typename T>
void ArrayBag<T>::add(const T& item) {
    if (itemCount < maxItems) {
        items[itemCount] = item;
        itemCount++;
    } else {
        // Resize array
        maxItems *= 2;
        T* newItems = new T[maxItems];
        for (int i = 0; i < itemCount; i++) {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
        items[itemCount] = item;
        itemCount++;
    }
}

template <typename T>
void ArrayBag<T>::remove(const T& item) {
    int index = getIndexOf(item);
    if (index != -1) {
        itemCount--;
        items[index] = items[itemCount];
    }
}

template <typename T>
bool ArrayBag<T>::contains(const T& item) const {
    return getIndexOf(item) != -1;
}

template <typename T>
int ArrayBag<T>::size() const {
    return itemCount;
}

template <typename T>
bool ArrayBag<T>::isEmpty() const {
    return itemCount == 0;
}

template <typename T>
void ArrayBag<T>::clear() {
    itemCount = 0;
}

template <typename T>
int ArrayBag<T>::getIndexOf(const T& target) const {
    for (int i = 0; i < itemCount; i++) {
        if (items[i] == target) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void ArrayBag<T>::display() const {
    std::cout << "ArrayBag contains " << itemCount << " items: ";
    for (int i = 0; i < itemCount; i++) {
        std::cout << items[i] << " ";
    }
    std::cout << std::endl;
}

#endif
