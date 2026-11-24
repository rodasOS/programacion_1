# Clase 7 · Paso por referencia

**Tema:** `&` para que una función modifique las variables del llamador.

| Archivo | Qué hace |
|---------|----------|
| `index.cpp` | Compara `sinReferencia` (copias, no intercambia) vs `intercambio` (`&`, sí intercambia) |
| `ejercicio2.cpp` | Menú `do-while` + `switch` con funciones: ingreso, ordenar (burbuja), imprimir, salir |

## Conceptos clave

```cpp
void intercambio(int &n1, int &n2) {   // n1 y n2 SON las variables originales
    int temp = n1; n1 = n2; n2 = temp;
}
```

| Paso | Se modifica el original |
|------|--------------------------|
| `int x` (valor) | No |
| `int &x` (referencia) | Sí |
| `int arr[]` | Sí (los arreglos se pasan por dirección) |

**Burbuja:** compara vecinos y los intercambia; cada pasada deja el mayor al final.

El menú de `ejercicio2.cpp` es el **modelo de los ejercicios de examen** (ver [Examenes/](../Examenes/README.md)).

**Anterior:** [Clase 6](../clase%206/README.md) · **Siguiente:** [Clase 8](../clase%208/README.md)
