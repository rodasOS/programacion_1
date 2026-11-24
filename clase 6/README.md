# Clase 6 · Funciones con retorno

> **Antes de empezar:** haz los [ejercicios previos](Ejercicios_Previos.md) (5 ejercicios ligeros, sin spoilers del tema).

**Tema:** funciones que reciben parámetros **por valor** y devuelven un resultado con `return`.

| Archivo | Qué ilustra |
|---------|-------------|
| `index.cpp` | `calculo(descuento, total)` devuelve el total con descuento |
| `prueba.cpp` | Login con un contador **global** de intentos fallidos |
| `repaso.cpp` | `return` termina la función: el código posterior nunca se ejecuta |
| `repaso2.cpp` | Concatenar `string` + `to_string(número)` |
| `repaso3.cpp` | Varias funciones con retorno (`sumar`, `restar`) |
| `repaso4.cpp` | Variable `static`: conserva su valor entre llamadas (1, 2, 3) |
| `test.cpp` | Fragmento: struct `Usuario` (sin `main`, no compila solo) |

## Conceptos clave

```cpp
int calculo(int descuento, int total) {   // recibe COPIAS
    return total - (total * descuento / 100);
}
descuento = calculo(descuento, 100);       // el resultado se captura
```

- Los parámetros por valor no modifican las variables originales → motivo de la [clase 7](../clase%207/README.md).
- `static int x = 0;` se inicializa **una sola vez**.

**Anterior:** [Clase 4](../clase%204/README.md) · **Siguiente:** [Clase 7](../clase%207/README.md)
