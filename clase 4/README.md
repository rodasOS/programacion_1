# Clase 4 · Procedimientos

> **Antes de empezar:** haz los [ejercicios previos](Ejercicios_Previos.md) (5 ejercicios ligeros, sin spoilers del tema).

**Tema:** dividir el programa en funciones `void` (procedimientos).

| Archivo | Qué hace |
|---------|----------|
| `index.cpp` | Pide dos números, los suma con un incremento local y muestra el total |
| `ejercicio2.cpp` | Pide 3 notas, calcula el promedio e indica si aprobó (>= 61) |

## Conceptos clave

- **Prototipo** antes del `main` para poder definir la función después.
- **Variables globales:** comparten datos entre procedimientos.
- **Variables locales:** viven solo dentro de su función.
- El `main` se lee como un índice: `pedirDatos(); calcular(); mostrar();`

```cpp
void pedirDatos();              // prototipo
int main() { pedirDatos(); ... }
void pedirDatos() { ... }       // definición
```

**Anterior:** [Clase 3](../clase%203/README.md) · **Siguiente:** [Clase 6](../clase%206/README.md) *(no hay clase 5 en el repo)*
