# Clase 8 · Ejercicios previos

**Objetivo:** manejar `vector` y arreglos en el `main` antes de la [Clase 8](README.md) (pasarlos a funciones).
**Tiempo:** ~30 min · **Dificultad:** ⭐⭐ · Necesitas `#include <vector>`

---

## 1. Vector dinámico
Pide cuántos números ingresar (`n`), léelos con `push_back` en un `vector<int>` y muestra cuántos hay con `.size()` y sus valores.

## 2. Duplicar un arreglo
Con `int a[5] = {1, 2, 3, 4, 5};` multiplica cada elemento por 2 con un `for` y muéstralo.

## 3. ¿Se copia el vector?
```cpp
vector<int> a = {1, 2, 3};
vector<int> b = a;
b[0] = 99;
cout << a[0] << " " << b[0];
```
<details><summary>Respuesta</summary>

`1 99`: `b = a` crea una **copia** independiente.
</details>

## 4. Suma y promedio
Lee 6 números en un `vector<double>` y calcula suma y promedio usando `.size()`.

## 5. Buscar un valor
Dado un `vector<int>`, pide un número y muestra en qué posición está, o `-1` si no existe.

---

**Te prepara para:** recorrer con `.size()`, entender copias de vector y la lógica de búsqueda. Anterior: [previa Clase 7](../clase%207/Ejercicios_Previos.md) · Siguiente: [Clase 8](README.md) → [previa Clase 9](../Clase%209%20-%20Sobrecarga/Ejercicios_Previos.md)
