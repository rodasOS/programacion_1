# Clase 7 · Ejercicios previos

**Objetivo:** entender copia vs original, practicar el menú y la burbuja a mano antes de la [Clase 7](README.md) (paso por referencia).
**Tiempo:** ~35 min · **Dificultad:** ⭐⭐

---

## 1. Intercambio en el `main`
Con `a = 10` y `b = 20`, intercámbialos usando una variable `temp` y muestra el resultado.

## 2. Menú que se repite
Haz una mini calculadora con `do { ... } while (opcion != 0);` y un `switch` (1 suma, 2 resta, 3 multiplicación, 0 salir).

## 3. Burbuja en papel
Ordena `[4, 2, 5, 1]` de menor a mayor anotando el arreglo **al final de cada pasada** (compara vecinos y cambia si están al revés).
<details><summary>Respuesta</summary>

- Pasada 1: `[2, 4, 1, 5]`
- Pasada 2: `[2, 1, 4, 5]`
- Pasada 3: `[1, 2, 4, 5]`
</details>

## 4. Mayor y menor
Lee 10 enteros en un arreglo y muestra el mayor y el menor.

## 5. Copia vs alias
```cpp
int a = 3, b = a;
b = 9;
cout << a << " ";

int c = 3;
int &r = c;   // r es otro nombre de c
r = 9;
cout << c;
```
<details><summary>Respuesta</summary>

`3 9`: `b` es una copia; `r` es otro nombre de `c`. Esa idea es el paso por referencia.
</details>

---

**Te prepara para:** `&`, menús `do-while` + `switch` y ordenamiento. Anterior: [previa Clase 6](../clase%206/Ejercicios_Previos.md) · Siguiente: [Clase 7](README.md) → [previa Clase 8](../clase%208/Ejercicios_Previos.md)
