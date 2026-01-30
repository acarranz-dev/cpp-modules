#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array{
private:
	T *_arr;
	unsigned int _size;

public:
	Array(): _arr(NULL), _size(0) {}
	Array(unsigned int n): _size(n) {
		_arr = new T[_size];
	}
	Array(const Array &other):_size(other._size) {
		_arr = new T[_size];
		for(unsigned int i = 0; i < _size; i++){
			_arr[i] = other._arr[i];
		}
	}
	Array &operator=(const Array &other){
		if (this != &other){
			delete[] _arr;
			_arr = new T[other._size];
			for (unsigned int i = 0; i < _size; i++)
				_arr[i] = other._arr[i];
		}
		return *this;
	}
	~Array(){
		delete[] _arr;
	}
	class NotValidIndexException : public std::exception{
		const char *what() const throw(){
			return "Not vallid Index";
		}
	};

	T  &operator[](unsigned int n){
		if (n < _size)
			return _arr[n];
		else
			throw NotValidIndexException();
	}
	unsigned int size() const {
		return _size;
	}
	void print(){
		for(unsigned int i = 0; i < _size; i ++)
			std::cout << _arr[i] <<std::endl;
	}

};


#endif
