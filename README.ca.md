# C++ Modules

**La piscina de C++ de 42: des de classes i sobrecàrrega d'operadors fins a templates i la STL.**

[English](README.md) · **Català** · [Español](README.es.md)

`Part del Common Core de 42 Barcelona` · `Rang 4-5` · `C++98` · `OOP` · `STL`

---

## Descripció

Els mòduls de C++ són una sèrie d'exercicis curts que introdueixen C++ pas a pas, sempre amb l'estàndard C++98 i compilats amb `-Wall -Wextra -Werror -std=c++98`. Cada mòdul se centra en un tema i cada exercici és un programa petit amb el seu propi `Makefile`.

## Què ensenya

- **Programació orientada a objectes**: classes, constructors, destructors i la Forma Canònica Ortodoxa.
- **Herència i polimorfisme**, funcions virtuals i classes abstractes.
- **Excepcions** i gestió d'errors.
- **Templates**, contenidors, iteradors i els algorismes de la STL.
- Triar el contenidor adequat per a cada problema (`map`, `stack`, `vector`, `deque`).

## Com funciona

Cada carpeta `CPP_Module_XX` conté els exercicis d'un mòdul (`00`, `01`, ...). La taula mostra què treballa cada mòdul.

| Mòdul | Tema | Exercicis d'aquest repositori |
|:--:|:--|:--|
| 02 | Forma Canònica Ortodoxa, sobrecàrrega d'operadors, números de coma fixa | Classe `Fixed` pas a pas, `Point` i la prova de punt dins d'un triangle (BSP) |
| 03 | Herència | `ClapTrap`, `ScavTrap`, `FragTrap` i `DiamondTrap` (herència múltiple i el problema del diamant) |
| 04 | Polimorfisme, classes abstractes, còpies profundes | `Animal`, `Dog`, `Cat`, `WrongAnimal`, `Brain` |
| 05 | Excepcions | `Bureaucrat`, `Form` / `AForm`, els tres formularis concrets i `Intern` |
| 06 | Casts de C++ | `ScalarConverter` (`static_cast`), `Serializer` (`reinterpret_cast`), identificació de tipus (`dynamic_cast`) |
| 07 | Templates | `swap` / `min` / `max`, `iter`, la plantilla de classe `Array` |
| 08 | Contenidors, iteradors i algorismes | `easyfind`, `Span`, `MutantStack` |
| 09 | La STL a la pràctica | `BitcoinExchange` (`std::map` i CSV), calculadora `RPN` (`std::stack`), `PmergeMe` (ordenació merge-insert de Ford-Johnson) |

<sub>Els mòduls 00 i 01 encara no estan pujats a aquest repositori.</sub>

## Compilar i executar

```bash
git clone https://github.com/acarranz-dev/cpp-modules.git
cd cpp-modules/CPP_Module_09/01      # each exercise has its own Makefile
make
./rpn "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

## Estructura del projecte

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

[Més projectes al meu perfil](https://github.com/acarranz-dev)
