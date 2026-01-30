#include "MutantStack.hpp"

int main(){
	MutantStack<int> arr;

	arr.push(20);
	arr.push(21);
	arr.push(22);
	arr.push(23);

	MutantStack<int>::iterator it = arr.begin();
	MutantStack<int>::iterator ite = arr.end();

	std::cout << "Elementos del stack orden ascendente:" << std::endl;
	while (it != ite){
		std::cout << *it << std::endl;
		it++;
	}
	it = arr.begin();
	--ite;
	std::cout << "Elementos del stack orden descendente:" << std::endl;
	while (ite != it){
		std::cout << *ite << std::endl;
		ite--;
	}
	std::cout << *ite << std::endl;
	return 0;
}
