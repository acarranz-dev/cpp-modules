#include "Bureaucrat.hpp"

int main(){
	try {
		Bureaucrat b1;
		Bureaucrat b2("Andreu", 34);
		Bureaucrat b3("Pol", 1);
		Bureaucrat b4("Ferran", 149);
		Bureaucrat b5;

		b5 = b4;

		b4.gradeTooLow();
		b4.gradeTooLow();

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		std::cout << b4 << std::endl;
		std::cout << b5 << std::endl;

	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
