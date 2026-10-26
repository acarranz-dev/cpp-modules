# C++ Modules

**La piscina de C++ de 42: desde clases y sobrecarga de operadores hasta templates y la STL.**

[English](README.md) · [Català](README.ca.md) · **Español**

`Parte del Common Core de 42 Barcelona` · `Rango 4-5` · `C++98` · `OOP` · `STL`

---

## Descripción

Los módulos de C++ son una serie de ejercicios cortos que introducen C++ paso a paso, siempre con el estándar C++98 y compilados con `-Wall -Wextra -Werror -std=c++98`. Cada módulo se centra en un tema y cada ejercicio es un programa pequeño con su propio `Makefile`.

## Qué enseña

- **Programación orientada a objetos**: clases, constructores, destructores y la Forma Canónica Ortodoxa.
- **Herencia y polimorfismo**, funciones virtuales y clases abstractas.
- **Excepciones** y gestión de errores.
- **Templates**, contenedores, iteradores y los algoritmos de la STL.
- Elegir el contenedor adecuado para cada problema (`map`, `stack`, `vector`, `deque`).

## Cómo funciona

Cada carpeta `CPP_Module_XX` contiene los ejercicios de un módulo (`00`, `01`, ...). La tabla muestra qué trabaja cada módulo.

| Módulo | Tema | Ejercicios de este repositorio |
|:--:|:--|:--|
| 02 | Forma Canónica Ortodoxa, sobrecarga de operadores, números de coma fija | Clase `Fixed` paso a paso, `Point` y la prueba de punto dentro de un triángulo (BSP) |
| 03 | Herencia | `ClapTrap`, `ScavTrap`, `FragTrap` y `DiamondTrap` (herencia múltiple y el problema del diamante) |
| 04 | Polimorfismo, clases abstractas, copias profundas | `Animal`, `Dog`, `Cat`, `WrongAnimal`, `Brain` |
| 05 | Excepciones | `Bureaucrat`, `Form` / `AForm`, los tres formularios concretos e `Intern` |
| 06 | Casts de C++ | `ScalarConverter` (`static_cast`), `Serializer` (`reinterpret_cast`), identificación de tipos (`dynamic_cast`) |
| 07 | Templates | `swap` / `min` / `max`, `iter`, la plantilla de clase `Array` |
| 08 | Contenedores, iteradores y algoritmos | `easyfind`, `Span`, `MutantStack` |
| 09 | La STL en la práctica | `BitcoinExchange` (`std::map` y CSV), calculadora `RPN` (`std::stack`), `PmergeMe` (ordenación merge-insert de Ford-Johnson) |

<sub>Los módulos 00 y 01 todavía no están subidos a este repositorio.</sub>

## Compilar y ejecutar

```bash
git clone https://github.com/acarranz-dev/cpp-modules.git
cd cpp-modules/CPP_Module_09/01      # each exercise has its own Makefile
make
./rpn "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

## Estructura del proyecto

```
cpp-modules/
├── CPP_Module_02/   00 01 02 03
├── CPP_Module_03/   00 01 02 03
├── CPP_Module_04/   00 01 02 03
├── CPP_Module_05/   00 01 02 03
├── CPP_Module_06/   00 01 02
├── CPP_Module_07/   00 01 02
├── CPP_Module_08/   00 01 02
└── CPP_Module_09/   00 01 02
```

---

[Más proyectos en mi perfil](https://github.com/acarranz-dev)
