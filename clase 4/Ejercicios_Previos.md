# Clase 4 · Ejercicios previos

**Objetivo:** notar la repetición de código y el alcance (global/local) antes de la [Clase 4](README.md) (procedimientos).
**Tiempo:** ~30 min · **Dificultad:** ⭐⭐

---

## 1. Código repetido
Imprime tres veces una línea de 20 signos `=` (usa un `for` y escribe el bloque **tres veces** en el `main`).
🤔 ¿Qué incomoda de repetirlo? Un procedimiento evita eso.

## 2. Secciones con comentarios
Escribe un programa que pida dos números, calcule su promedio y lo muestre, dividido con comentarios `// PEDIR`, `// PROCESAR`, `// MOSTRAR`.
Más adelante cada sección será un procedimiento.

## 3. Predice el alcance
```cpp
int total = 0;
int main() {
    total = 5;
    {
        int total = 100;
        total++;
    }
    cout << total;
}
```
<details><summary>Respuesta</summary>

`5`: la `total` de dentro de las llaves es otra variable (local al bloque); el `total++` no toca la global.
</details>

## 4. Orden de ejecución
Sin ejecutar, predice la salida (aún no has visto funciones: solo léelo):
```cpp
void a() { cout << "A "; }
void b() { cout << "B "; }
int main() { b(); a(); b(); }
```
<details><summary>Respuesta</summary>

`B A B `: las funciones se ejecutan en el orden en que se **llaman**, no en el que se declaran.
</details>

## 5. Menú con switch
En el `main`, muestra `1. Sumar  2. Restar  0. Salir`, lee la opción, pide dos números y muestra el resultado con un `switch`.

---

**Te prepara para:** separar un programa en pasos, entender qué variable vive dónde y el orden de las llamadas. Anterior: [previa Clase 3](../clase%203/Ejercicios_Previos.md) · Siguiente: [Clase 4](README.md) → [previa Clase 6](../clase%206/Ejercicios_Previos.md)
