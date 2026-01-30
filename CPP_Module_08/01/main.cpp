#include "Span.hpp"

int main(){
	Span arr(5);

	for(unsigned int i = 0; i < 15; i++){
		try{
			arr.addNumber(i * i);
		}
		catch(const std::exception &e){
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	std::cout << "shortposition: 1" << std::endl;
	try{
		std::cout <<"Test shortPosition: " << arr.shortestSpan() << std::endl;
	}
	catch(const std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "longPosition: 16 " << std::endl;
	try{
		std::cout << "test longPosition: " << arr.longestSpan() << std::endl;
	}
	catch(const std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	Span b(1);

	try{
		std::cout << b.longestSpan() << std::endl;
	}
	catch(const std::exception &e){
		std::cout << "Error: " <<e.what() << std::endl;
	}
	Span arr1(1);


}

// 0 1 4 9 16 25 36 49 64 81
