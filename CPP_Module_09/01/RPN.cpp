#include "RPN.hpp"
#include <cstdlib>
#include <sstream>

RPN::RPN() {}

RPN::RPN(const RPN &other) : stack(other.stack){}

RPN &RPN::operator=(const RPN &other) {
	if(this != &other)
		stack = other.stack;
	return *this;
}

RPN::~RPN() {}

RPN::RPN(const std::string &input){
	std::istringstream iss(input);
	std::string token;
	std::stack<std::string> tempStack;
	while (iss >> token) {
		if (token.size() > 1)
			throw OneCharcaterException();
		tempStack.push(token);
	}
	while (!tempStack.empty()) {
		stack.push(tempStack.top());
		tempStack.pop();
	}
}

const char *RPN::OneCharcaterException::what() const throw(){
	return "Only accept one character in arguments";
}

const char *RPN::NotValidArgmunentException::what() const throw(){
	return "Not valid Arguments";
}

const char *RPN::NotValidExpresionException::what() const throw(){
	return "Not valid Expresion";
}

const char *RPN::DivisionZeroException::what() const throw(){
	return "Not posible divison 0";
}

void RPN::executeStack(){
	std::stack<float> operation;

	while (!stack.empty()){
		std::string token = stack.top();
		stack.pop();

		if (std::isdigit(token[0]))
			operation.push(std::atof(token.c_str()));
		else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'){
			if (operation.size() < 2)
				throw NotValidExpresionException();

			float a = operation.top();
			operation.pop();
			float b = operation.top();
			operation.pop();

			switch (token[0]){
			case '+':
				operation.push(b + a);
				break;
			case '-':
				operation.push(b - a);
				break;
			case '*':
				operation.push(b * a);
				break;
			case '/':
				if (a == 0)
					throw DivisionZeroException();
				operation.push(b / a);
				break;
			}
		}
		else
			throw NotValidArgmunentException();
	}

	if (operation.size() != 1)
		throw NotValidExpresionException();

	std::cout << operation.top() << std::endl;
}
