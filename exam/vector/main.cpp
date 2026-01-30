#include <iostream>
#include "vect2.hpp"

int main() {
    // Crear vectores
    vect2 v1(3, 4);
    vect2 v2(1, 2);

    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;
    std::cout << std::endl;

    // Probar suma
    vect2 suma = v1 + v2;
    std::cout << "v1 + v2 = " << suma << std::endl;

    // Probar resta
    vect2 resta = v1 - v2;
    std::cout << "v1 - v2 = " << resta << std::endl;

    // Probar multiplicación por escalar
    vect2 mult = v1 * 2;
    std::cout << "v1 * 2 = " << mult << std::endl;

    // Probar multiplicación por escalar (orden inverso)
    vect2 mult2 = 3 * v2;
    std::cout << "3 * v2 = " << mult2 << std::endl;
    std::cout << std::endl;

    // Probar acceso por índice
    std::cout << "v1[0] = " << v1[0] << std::endl;
    std::cout << "v1[1] = " << v1[1] << std::endl;
    std::cout << std::endl;

    // Probar comparación
    vect2 v3(2, 2);
    vect2 v4 = v3 * 2;
    std::cout << "v3 = " << v3 << std::endl;
    std::cout << "v3 * 2 = " << v4 << std::endl;

    if (v4 == vect2(4, 4)) {
        std::cout << "v3 * 2 == vect2(4,4) es verdadero" << std::endl;
    }

    return 0;
}
