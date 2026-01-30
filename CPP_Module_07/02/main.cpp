#include "Array.hpp"

int main(){

	Array<int> a1;
	Array<int> a2(5);
	Array<std::string> strArray(3);
	strArray[0] = "Andreu";
	strArray[1] = "Carranza";
	strArray[2] = "Gibert";
	for(int i = 0; i < 5; i++)
		a2[i] = i;
	Array<int> a3(a2);

	std::cout << "A1 array: " << std::endl;
	a1.print();
	std::cout << std::endl;
	std::cout << "A2 array" << std::endl;
	a2.print();
	std::cout << std::endl;
	std::cout << "A3 array" << std::endl;
	a3.print();
	std::cout << std::endl;
	std::cout << "strArray" << std::endl;
	strArray.print();
	std::cout << std::endl;

	try{
		std::cout << "a1[0]: " << a1[0] << std::endl;
	}catch( const std::exception& e){
		std::cerr <<"Error: " << e.what() << std::endl;
	}
	try{
		std::cout << "a2[4]: " << a2[4] << std::endl;
	}catch( const std::exception& e){
		std::cerr <<"Error: " << e.what() << std::endl;
	}
	try{
		std::cout << "a3[4]: " << a3[4] << std::endl;
	}catch( const std::exception& e){
		std::cerr <<"Error: " << e.what() << std::endl;
	}
	try{
		std::cout << "strArray[0]: " << strArray[0] << std::endl;
	}catch( const std::exception& e){
		std::cerr <<"Error: " << e.what() << std::endl;
	}
	try{
		std::cout << "strArray[6]: " << strArray[6] << std::endl;
	}catch( const std::exception& e){
		std::cerr <<"Error: " << e.what() << std::endl;
	}

	std::cout << "a1 size : " << a1.size() << std::endl;
	std::cout << "a2 size : " << a2.size() << std::endl;
	std::cout << "a3 size : " << a3.size() << std::endl;
	std::cout << "strArray size : " << strArray.size() << std::endl;
}
