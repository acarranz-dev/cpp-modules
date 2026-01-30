#include <iostream>
#include <cstddef>
#include "iter.hpp"


int main(){
	char arr[] = {'A', 'B', 'C'};
	iter(arr, 3, imprimir<char>);
	std::cout << std::endl;

	std::string str_arr[] = {"Andreu ","Carranza ","Gibert"} ;
	iter(str_arr, 3, imprimir<std::string>);
	std::cout << std::endl;
	iter(str_arr, 3, printMayus<std::string>);
	std::cout <<std::endl;


	int int_arr[] = {0, 1, 2, 3, 4 ,5};
	iter(int_arr, 5, imprimir<int>);
	std::cout << std::endl;

	float float_arr[] = {0.34f, 1.22f, 2.787f, 3.54f, 4.009f ,5.234234f};
	iter(float_arr, 5, imprimir<float>);
	std::cout <<std::endl;

	double double_arr[] = {0.34234, 1.2234523423, 2.78711144, 3.54008754, 4.00923566 ,5.234234574};
	iter(double_arr, 5, imprimir<double>);
	std::cout <<std::endl;



}
