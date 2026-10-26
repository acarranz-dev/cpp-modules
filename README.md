# C++ Modules

**The 42 C++ piscine: from classes and operator overloading to templates and the STL.**

**English** · [Català](README.ca.md) · [Español](README.es.md)

`Part of the 42 Barcelona Common Core` · `Rank 4-5` · `C++98` · `OOP` · `STL`

---

## Description

The C++ modules are a series of short exercises that introduce C++ step by step, always in the C++98 standard and compiled with `-Wall -Wextra -Werror -std=c++98`. Each module focuses on one topic and every exercise is a small program with its own `Makefile`.

## What it teaches

- **Object-oriented programming**: classes, constructors, destructors and the Orthodox Canonical Form.
- **Inheritance and polymorphism**, virtual functions and abstract classes.
- **Exceptions** and error handling.
- **Templates**, containers, iterators and the algorithms of the STL.
- Choosing the right container for each problem (`map`, `stack`, `vector`, `deque`).

## How it works

Each folder `CPP_Module_XX` contains the exercises of one module (`00`, `01`, ...). The table shows what each module covers.

| Module | Topic | Exercises in this repository |
|:--:|:--|:--|
| 02 | Orthodox Canonical Form, operator overloading, fixed-point numbers | `Fixed` class step by step, `Point` and the point-in-triangle test (BSP) |
| 03 | Inheritance | `ClapTrap`, `ScavTrap`, `FragTrap` and `DiamondTrap` (multiple inheritance and the diamond problem) |
| 04 | Polymorphism, abstract classes, deep copies | `Animal`, `Dog`, `Cat`, `WrongAnimal`, `Brain` |
| 05 | Exceptions | `Bureaucrat`, `Form` / `AForm`, the three concrete forms and `Intern` |
| 06 | C++ casts | `ScalarConverter` (`static_cast`), `Serializer` (`reinterpret_cast`), type identification (`dynamic_cast`) |
| 07 | Templates | `swap` / `min` / `max`, `iter`, the `Array` class template |
| 08 | Containers, iterators and algorithms | `easyfind`, `Span`, `MutantStack` |
| 09 | The STL in practice | `BitcoinExchange` (`std::map` and CSV), `RPN` calculator (`std::stack`), `PmergeMe` (Ford-Johnson merge-insert sort) |

<sub>Modules 00 and 01 are not uploaded to this repository yet.</sub>

## Build and run

```bash
git clone https://github.com/acarranz-dev/cpp-modules.git
cd cpp-modules/CPP_Module_09/01      # each exercise has its own Makefile
make
./rpn "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

## Project structure

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

[More projects on my profile](https://github.com/acarranz-dev)
