#include <iostream>
#include "whatever.hpp"

int main( void ) {
int a = 2;
int b = 3;
std::string a1 = "Andreu";
std::string a2 = "Carranza";
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::cout << "min( a1, a2 ) = " << ::min( a1, a2 ) << std::endl;
std::cout << "max( a1, a2 ) = " << ::max( a1, a2 ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}
