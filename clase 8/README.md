# Clase 8 · Arreglos y vectores como parámetros

> **Antes de empezar:** haz los [ejercicios previos](Ejercicios_Previos.md) (5 ejercicios ligeros, sin spoilers del tema).

**Tema:** qué cambia en el original según cómo se pase cada estructura.

| Cómo se pasa | ¿Modifica el original? |
|--------------|------------------------|
| `int arr[]` | **Sí** |
| `vector<int> v` | No (copia) |
| `vector<int> &v` | **Sí** |

| Archivo | Qué hace |
|---------|----------|
| `index.cpp` | Demostración completa con los tres casos |
| `ejercicio1.cpp` | Predecir salida: arreglo cambia (100), vector por valor no (1) |
| `ejercicio2.cpp` | Login con contador por referencia (`int &intentos`) → 5 fallos |
| `ejercicio3.cpp` | Mezcla arreglo + vector por referencia + `int &`; salida `25 50 100` |

## Detalles

- Un arreglo clásico no conoce su tamaño dentro de la función → se envía aparte.
- Un `vector` conoce su tamaño con `.size()`.
- En `ejercicio3.cpp`, `res` se calcula **antes** de modificar `arr[0]` y `v[0]`.

**Anterior:** [Clase 7](../clase%207/README.md) · **Siguiente:** [Clase 9](../Clase%209%20-%20Sobrecarga/README.md)
