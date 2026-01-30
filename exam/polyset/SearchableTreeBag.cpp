#include "SearchableTreeBag.hpp"

template <typename T>
SearchableTreeBag<T>::SearchableTreeBag(): ArrayBag<T>(){}

template <typename T>
SearchableTreeBag<T>::SearchableTreeBag(const SearchableTreeBag<T> &other) : ArrayBag<T>(other){}

template <typename T>
SearchableTreeBag<T> &SearchableTreeBag<T>::operator=(const SearchableTreeBag<T> &other){
	if (this != &other)
		ArrayBag<T>::operator=(other);
	return *this;
}

template <typename T>
SearchableTreeBag<T>::~SearchableTreeBag(){}

template <typename T>
void SearchableTreeBag<T>::add(const T &item){
	ArrayBag<T>::add(item)
}

template <typename T>
void SearchableTreeBag<T>::remove(const T &item){
	ArrayBag<T>::remove(item);
}

template <typename T>
bool SearchableTreeBag<T>::contains(const T &item) const{
	return ArrayBag<T>::contains(item);
}

template <typename T>
int SearchableTreeBag<T>::size() const{
	return ArrayBag<T>::size();
}

template <typename T>
bool SearchableTreeBag<T>::isEmpty() const {
	return ArrayBag<T>::isEmpty();
}

template <typename T>
void SearchableTreeBag<T>::clear(){
	ArrayBag<T>::clear();
}

template <typename T>
T *SearchableTreeBag<T>::search(const T &item){
	for (size_t i = 0;  i < this->itemCount; i++){
		if (this->items[i] == item)
			return &(this->items[i]);
	}
	return NULL;
}

template <typename T>
const T *SearchableTreeBag<T>::search(const T &item) const{
	for (size_t i = 0;  i < this->itemCount; i++){
		if (this->items[i] == item)
			return &(this->items[i]);
	}
	return NULL;
}
