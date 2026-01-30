#ifndef SearchableTreeBag_HPP
#define SearchableTreeBag_HPP

#include <iostream>
#include "array_bag.hpp"
#include "searchable_bag.hpp"

template  <typename T>
class SearchableTreeBag : public ArrayBag<T>, public  SearchableBag<T>{
public:
	SearchableTreeBag();
	SearchableTreeBag(const SearchableTreeBag &other);
	SearchableTreeBag &operator=(const SearchableTreeBag &other);
	virtual ~SearchableTreeBag();

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
