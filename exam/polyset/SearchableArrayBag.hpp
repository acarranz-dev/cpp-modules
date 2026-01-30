#ifndef SEARCHABLEARRAYBAG_HPP
#define SEARCHABLEARRAYBAG_HPP

#include <iostream>
#include "array_bag.hpp"
#include "searchable_bag.hpp"

template  <typename T>
class SearchableArrayBag : public ArrayBag<T>, public  SearchableBag<T>{
public:
	SearchableArrayBag();
	SearchableArrayBag(const SearchableArrayBag &other);
	SearchableArrayBag &operator=(const SearchableArrayBag &other);
	virtual ~SearchableArrayBag();

    virtual void add(const T& item);
    virtual void remove(const T& item);
    virtual bool contains(const T& item) const;
    virtual int size() const;
    virtual bool isEmpty() const;
    virtual void clear();

	T* search(const T& item);
	const T* search(const T& item) const;
};

#endif
