# Polyset Exercise - Base Files

## Archivos Proporcionados (NO modificar):

- `bag.hpp` - Clase abstracta base para bolsas
- `searchable_bag.hpp` - Clase abstracta para bolsas con búsqueda
- `array_bag.hpp` / `array_bag.cpp` - Implementación de bag con array
- `tree_bag.hpp` / `tree_bag.cpp` - Implementación de bag con árbol BST
- `shame.en.txt` - Explicación de conceptos de bag y set
- `main.cpp` - Archivo de prueba
- `Makefile` - Para compilar el proyecto

## Archivos que DEBES Crear:

### Primera Parte:
1. **searchable_array_bag.hpp** - Header de SearchableArrayBag
2. **searchable_array_bag.cpp** - Implementación (si es necesario)
3. **searchable_tree_bag.hpp** - Header de SearchableTreeBag
4. **searchable_tree_bag.cpp** - Implementación (si es necesario)

### Segunda Parte:
5. **set.hpp** - Header de la clase Set
6. **set.cpp** - Implementación (si es necesario)

## Requisitos:

✅ Todas las clases deben estar en **Forma Canónica Ortodoxa**:
- Constructor por defecto
- Destructor
- Constructor de copia
- Operador de asignación

✅ No olvides los **const** donde sean necesarios

✅ El `main.cpp` debe compilar sin errores con tu código

## Compilación:

```bash
make
./polyset_test
```

## Conceptos Clave:

**SearchableArrayBag:**
- Hereda de `ArrayBag<T>`
- Implementa `SearchableBag<T>`
- Debe implementar el método `search()`

**SearchableTreeBag:**
- Hereda de `TreeBag<T>`
- Implementa `SearchableBag<T>`
- Debe implementar el método `search()`

**Set:**
- Envuelve un `SearchableBag<T>*`
- Previene duplicados al insertar
- Usa `search()` para verificar si un elemento ya existe

## Diferencias:

**Bag (Bolsa):**
```
{1, 2, 2, 3, 3, 3} ← Permite duplicados
```

**Set (Conjunto):**
```
{1, 2, 3} ← NO permite duplicados
```

¡Buena suerte!
