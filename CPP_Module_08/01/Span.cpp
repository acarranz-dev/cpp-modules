#include "Span.hpp"
#include <climits>
#include <algorithm>

Span::Span(): _arr(0), _size(0) {}

Span::Span(const Span &other): _arr(other._arr), _size(other._size) {}

Span::Span(unsigned int size): _arr(0), _size(size) {}

Span &Span::operator=(const Span &other){
	if (this != &other){
		_size = other._size;
		_arr = other._arr;
	}
	return *this;
}

Span::~Span(){}

const char *Span::OutOfRangeException::what() const throw(){
	return "the array is completed";
}

const char *Span::OnlyOneMemberException::what() const throw(){
	return "Need minimum two elemnts to calculate short and long span";
}

void Span::addNumber(int n){
	if (_arr.size() < _size)
		_arr.push_back(n);
	else
		throw OutOfRangeException();
}

int Span::shortestSpan() const {
	if (_size < 2)
		throw OnlyOneMemberException();
	std::vector<int> sorted = _arr;
	std::sort(sorted.begin(),sorted.end());
	int shortSpan = sorted[1] - sorted[0];
	for (size_t i = 0; i <  sorted.size() - 1; i++){
		int temp = sorted[i + 1] - sorted[i];
		if (temp < shortSpan)
			shortSpan = temp;
	}
	return shortSpan;
}

int Span::longestSpan() const {
	if (_size < 2)
		throw OnlyOneMemberException();
	std::vector<int> sorted = _arr;
	std::sort(sorted.begin(),sorted.end());
	return sorted[sorted.size() - 1] - sorted[0];
}
