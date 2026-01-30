#ifndef SEARCHABLE_BAG_HPP
#define SEARCHABLE_BAG_HPP

#include "bag.hpp"

template <typename T>
class SearchableBag : public Bag<T> {
public:
    virtual ~SearchableBag() {}
    
    // Search for an item in the bag
    // Returns pointer to the item if found, nullptr otherwise
    virtual T* search(const T& item) = 0;
    virtual const T* search(const T& item) const = 0;
};

#endif
