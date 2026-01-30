#ifndef SPAN_HPP
#define  SPAN_HPP

#include <iostream>
#include <vector>
#include <cmath>


class Span{
private:
	std::vector<int> _arr;
	unsigned int	_size;
public:
	Span();
	Span(const Span &other);
	Span(unsigned int size);
	Span &operator=(const Span &other);
	~Span();
	class OutOfRangeException : public::std::exception{
		const char *what() const throw();
	};
	class OnlyOneMemberException : public::std::exception{
		const char *what() const throw();
	};
	void addNumber(int n);
	int shortestSpan() const;
	int longestSpan() const;
};


#endif
