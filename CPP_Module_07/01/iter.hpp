#pragma once

#include <iostream>

template <typename T, typename Func>
void iter(T *ptr, size_t size, Func func){
	for (size_t i = 0; i < size; i++)
		func(ptr[i]);
}

template <typename T>
void imprimir(T elemento){
	std::cout << elemento << " ";
}

template <typename U>
void printMayus(U elemnto){
	for (int i = 0; i < elemnto[i]; i++)
		std::cout << static_cast<char>(toupper(elemnto[i]));
}

