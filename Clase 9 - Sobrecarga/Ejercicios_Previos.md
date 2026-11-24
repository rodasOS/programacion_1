# Clase 9 · Ejercicios previos

**Objetivo:** distinguir tipos (`int` vs `double`) y funciones con distinto número de parámetros antes de la [Clase 9](README.md) (sobrecarga).
**Tiempo:** ~30 min · **Dificultad:** ⭐⭐

---

## 1. División entera vs decimal
Predice qué imprime cada línea y luego compruébalo:
```cpp
cout << 7 / 2 << " ";
cout << 7.0 / 2 << " ";
cout << (double)7 / 2;
```
<details><summary>Respuesta</summary>

`3 3.5 3.5`: si ambos operandos son enteros, la división es entera.
</details>

## 2. Dos sumas con nombres distintos
Escribe `sumaEnteros(int, int)` y `sumaDecimales(double, double)` y llámalas desde `main`.
🤔 ¿No sería cómodo que ambas se llamaran `suma`? (Eso es la sobrecarga.)

## 3. Dos y tres parámetros
Escribe `sumar2(int a, int b)` y `sumar3(int a, int b, int c)`.

## 4. Conversiones silenciosas
```cpp
double d = 5 / 2;
int i = 3.9;
cout << d << " " << i;
```
<details><summary>Respuesta</summary>

`2 3`: `5 / 2` se calcula como entero (`2`) antes de asignarse a `double`, y asignar `3.9` a un `int` descarta los decimales.
</details>

## 5. Áreas con nombres distintos
Escribe `areaCuadrado(lado)`, `areaRectangulo(base, altura)` y `areaTriangulo(base, altura)`.
Luego piensa: ¿qué pasaría si las tres se llamaran `area`? ¿Qué distingue a rectángulo y triángulo, si ambas reciben dos números?

---

**Te prepara para:** el compilador eligiendo una versión según cantidad y tipo de argumentos. Anterior: [previa Clase 8](../clase%208/Ejercicios_Previos.md) · Siguiente: [Clase 9](README.md) → [Examenes/](../Examenes/README.md)
