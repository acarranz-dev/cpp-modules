#include <vector>
#include <iostream>
#include <stack>
#include <list>
#include <algorithm>
#include "easyFind.hpp"

int main(){
	std::cout << "Vector Test" << std::endl;
	std::vector<int> vec;
	vec.push_back(0);
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	std::cout << "Number 0 is in array: ";
	try{
		std::vector<int>::iterator it = easyfind(vec, 0);
		std::cout << *it << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "Number 20 is in array: ";
	try{
		std::vector<int>::iterator it = easyfind(vec, 20);
		std::cout << *it << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "Number 50 is in array: ";
	try{
		std::vector<int>::iterator it = easyfind(vec, 50);
		std::cout << *it << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "list Test" << std::endl;
	std::list<int> list;
	list.push_back(0);
	list.push_back(10);
	list.push_back(20);
	list.push_back(30);

	std::cout << "Number 0 is in array: ";
	try{
		std::list<int>::iterator it = easyfind(list, 0);
		std::cout << *it << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "Number 20 is in array: ";
	try{
		std::list<int>::iterator it = easyfind(list, 20);
		std::cout << *it << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "Number 50 is in array: ";
	try{
		std::list<int>::iterator it = easyfind(list, 50);
		std::cout << *it << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}



	std::cout << "Deque Test" << std::endl;
	std::deque<int> deq;
	deq.push_back(0);
	deq.push_back(10);
	deq.push_back(20);
	deq.push_back(30);

	std::cout << "Number 0 is in array: ";
	try{
		std::deque<int>::iterator it = easyfind(deq, 0);
		std::cout << *it << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "Number 20 is in array: ";
	try{
		std::deque<int>::iterator it = easyfind(deq, 20);
		std::cout << *it << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "Number 50 is in array: ";
	try{
		std::deque<int>::iterator it = easyfind(deq, 50);
		std::cout << *it << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}
