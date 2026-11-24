# Clase 3 · Arreglos de estructuras

**Tema:** manejar muchos registros con un arreglo de structs. Es el patrón más repetido del curso.

| Archivo | Dominio | Cálculo especial |
|---------|---------|------------------|
| `ejercicio1.cpp` | 10 estudiantes | Promedio de 3 notas, aprobados/reprobados (>= 61) |
| `ejercicio2.cpp` | 10 productos | `valorTotal = precio * cantidad`, producto más caro, cantidad < 5 |
| `ejercicio3.cpp` | 20 vehículos | `totalPagar = horas * 10`, quién más pagó, modelo < 2015 |

## Receta (sirve para cualquier ejercicio de este tipo)

```cpp
const int total = 10;                 // 1. tamaño en un solo lugar
struct Estudiante { ...; float promedio; } estudiantes[total];   // 2. arreglo de structs

int indiceMayor = 0;                  // 3. guardar la POSICIÓN del mejor
for (int i = 0; i < total; i++) {
    // leer datos, calcular campos derivados
    if (estudiantes[i].promedio > estudiantes[indiceMayor].promedio) indiceMayor = i;
}
// 4. segundo for para mostrar / filtrar
```

Patrones: **acumulador** (`+=`), **máximo por índice**, **contador**, **filtro** con `if`.

**Anterior:** [Clase 2](../clase%202/README.md) · **Siguiente:** [Clase 4](../clase%204/README.md)
