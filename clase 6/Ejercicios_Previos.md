# Clase 6 · Ejercicios previos

**Objetivo:** pensar en *entradas → resultado* antes de la [Clase 6](README.md) (funciones con retorno y parámetros).
**Tiempo:** ~30 min · **Dificultad:** ⭐⭐

---

## 1. Leer una función
```cpp
int doble(int x) { return x * 2; }
// ¿qué vale doble(doble(3))?
```
<details><summary>Respuesta</summary>

`12`: `doble(3) = 6` y luego `doble(6) = 12`.
</details>

## 2. IVA
En el `main`, pide un monto y calcula el IVA (12%) y el total. Antes de programar, escribe en un comentario: **¿qué datos entran y qué dato sale?**

## 3. Descuento
Pide `precio` y `porcentaje` de descuento y muestra el precio final: `precio - (precio * porcentaje / 100)`.

## 4. Texto con números
Arma y muestra: `Hola Mario, tienes 20 anios` con `string` + `to_string(edad)` (el nombre y la edad vienen de variables).

## 5. ¿Cambia `n`?
```cpp
int f(int a) { a = a + 1; return a; }
int main() {
    int n = 5;
    f(n);
    cout << n << " ";
    n = f(n);
    cout << n;
}
```
<details><summary>Respuesta</summary>

`5 6`: `f(n)` trabaja con una copia y su resultado se descartó; en `n = f(n)` el retorno sí se guarda.
</details>

---

**Te prepara para:** parámetros por valor, `return` y capturar el resultado. Anterior: [previa Clase 4](../clase%204/Ejercicios_Previos.md) · Siguiente: [Clase 6](README.md) → [previa Clase 7](../clase%207/Ejercicios_Previos.md)
