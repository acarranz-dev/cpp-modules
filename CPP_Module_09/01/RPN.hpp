#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

class RPN {
private:
	std::stack<std::string> stack;

public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	RPN(const std::string &input);
	~RPN();

	class OneCharcaterException : public std::exception {
		const char *what() const throw();
	};
	class NotValidArgmunentException : public std::exception {
		const char *what() const throw();
	};
	class NotValidExpresionException : public std::exception {
		const char *what() const throw();
	};
	class DivisionZeroException : public std::exception {
		const char *what() const throw();
	};

	void executeStack();
};

#endif
