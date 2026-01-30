#include "vect2.hpp"

int main(){
	vect2 vec(2,4);
	vect2 vec1;
	vect2 vec2(1,1);
	vect2 vec3(2,2);


	try{
	std::cout << vec[0] << std::endl;
	std::cout << vec[1] << std::endl;
	vec1 = vec * 3;
	std::cout << vec1 << std::endl;
	vec1 = vec1 - vec2;
	std::cout << vec1 << std::endl;
	vec1 = vec1 + vec3;
	std::cout << vec1 << std::endl;


	}catch(std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

}
