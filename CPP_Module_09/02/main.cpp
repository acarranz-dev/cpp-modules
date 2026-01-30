#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>

int main(int argc, char **argv){
    if (argc != 2){
        std::cerr << "Uso: ./PmergeMe \"números separados por espacios\"" << std::endl;
        return 1;
    }

    try{
        std::string input = argv[1];
        PmergeMe pmerge(input);

    }catch(const std::exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
