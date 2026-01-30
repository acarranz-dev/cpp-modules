#include "RPN.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "Error: Usage: ./rpn \"expression\"" << std::endl;
		return 1;
	}
	try {
		RPN rpn(argv[1]);
		rpn.executeStack();
	}
	catch (std::exception &e){
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
