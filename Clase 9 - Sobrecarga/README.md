# Clase 9 · Sobrecarga de funciones

**Tema:** varias funciones con el **mismo nombre** y distinta lista de parámetros. El compilador elige la versión según cantidad y tipo de argumentos.

```cpp
int    suma(int a, int b);             // suma(10, 20)
double suma(double a, double b);       // suma(2.5, 1.3)
int    suma(int a, int b, int c);      // suma(1, 2, 3)
```

> **Regla de oro:** el tipo de retorno **no** distingue sobrecargas.

| Archivo | Qué ilustra |
|---------|-------------|
| `index.cpp` | Introducción: `suma` con 2 ints, 2 doubles y 3 ints |
| `calcular_area.cpp` | `area` para cuadrado (1 param), rectángulo (2 int) y triángulo (2 double) |
| `Ejercicio 1.cpp` | Conversor de unidades: sobrecarga **por struct** (`Celsius`, `Fahrenheit`, `Metros`) |
| `Ejercicio 2.cpp` | `sumar` y `promedio` sobre arreglos `int[]` y `double[]` |
| `ejercicio_3.cpp` | Calculadora con las 4 operaciones en versión entera y decimal |

## Conceptos útiles

- Envolver tipos iguales en **structs distintos** permite sobrecargar (`calcular(Celsius)` vs `calcular(Fahrenheit)`).
- `const int arr[]` promete no modificar el arreglo.
- `static_cast<double>(a) / b` evita la división entera.
- `sizeof(arr)/sizeof(arr[0])` o `std::size(arr)` (C++17) dan la cantidad de elementos.
- `fixed` + `setprecision(n)` (`<iomanip>`) controlan decimales.

## Correcciones aplicadas

- `Ejercicio 2.cpp`: `size(enteros) / sizeof(...)` daba tamaño 1 y resultados incorrectos.
- `Ejercicio 1.cpp`: `<windows.h>` protegido con `#ifdef _WIN32` para compilar también en Linux.

**Anterior:** [Clase 8](../clase%208/README.md) · **Práctica de examen:** [Examenes/](../Examenes/README.md)
