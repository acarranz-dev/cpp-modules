#include "SearchableArrayBag.hpp"

template <typename T>
SearchableArrayBag<T>::SearchableArrayBag(): ArrayBag<T>(){}

template <typename T>
SearchableArrayBag<T>::SearchableArrayBag(const SearchableArrayBag<T> &other) : ArrayBag<T>(other){}

template <typename T>
SearchableArrayBag<T> &SearchableArrayBag<T>::operator=(const SearchableArrayBag<T> &other){
	if (this != &other)
		ArrayBag<T>::operator=(other);
	return *this;
}

template <typename T>
SearchableArrayBag<T>::~SearchableArrayBag(){}

template <typename T>
void SearchableArrayBag<T>::add(const T &item){
	ArrayBag<T>::add(item)
}

template <typename T>
void SearchableArrayBag<T>::remove(const T &item){
	ArrayBag<T>::remove(item);
}

template <typename T>
bool SearchableArrayBag<T>::contains(const T &item) const{
	return ArrayBag<T>::contains(item);
}

template <typename T>
int SearchableArrayBag<T>::size() const{
	return ArrayBag<T>::size();
}

template <typename T>
bool SearchableArrayBag<T>::isEmpty() const {
	return ArrayBag<T>::isEmpty();
}

template <typename T>
void SearchableArrayBag<T>::clear(){
	ArrayBag<T>::clear();
}

template <typename T>
T *SearchableArrayBag<T>::search(const T &item){
	for (size_t i = 0;  i < this->itemCount; i++){
		if (this->items[i] == item)
			return &(this->items[i]);
	}
	return NULL;
}

template <typename T>
const T *SearchableArrayBag<T>::search(const T &item) const{
	for (size_t i = 0;  i < this->itemCount; i++){
		if (this->items[i] == item)
			return &(this->items[i]);
	}
	return NULL;
}
