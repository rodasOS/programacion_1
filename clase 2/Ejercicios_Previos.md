# Clase 2 · Ejercicios previos

**Objetivo:** llegar a [Clase 2 (structs)](README.md) sintiendo *por qué* hace falta agrupar datos.
**Tiempo:** ~30 min · **Dificultad:** ⭐

---

## 1. Texto con espacios
Pide el nombre completo (ej. `Ana Maria Lopez`) con `getline(cin, nombre)` sobre un `string`. Muestra el texto, su longitud (`nombre.size()`) y la primera letra.
💡 Si antes usaste `cin >>`, agrega `cin.ignore();` antes del `getline`.

## 2. Arreglo al revés
Lee 5 enteros en un arreglo `int a[5]` y muéstralos en orden inverso.

## 3. Datos sueltos
Lee `nombre`, `edad` y `altura` de **una** persona en tres variables y muéstralas. Ahora hazlo para **dos** personas.
🤔 ¿Cuántas variables necesitaste? ¿Qué pasaría con 30 personas? (Eso resuelve el `struct`.)

## 4. Arreglos paralelos
Crea `string nombres[3]` y `int edades[3]`, léelos y muestra el nombre de la persona **mayor**.
💡 Guarda la **posición** del mayor, no solo su edad.

## 5. Predice la salida
```cpp
int a[4] = {10, 20, 30, 40};
cout << a[1] + a[3] << a[0];
```
<details><summary>Respuesta</summary>

`6010`: primero se imprime `20 + 40 = 60` y luego `a[0] = 10`, sin espacio entre ambos.
</details>

---

**Te prepara para:** agrupar datos relacionados, cadenas y acceso por posición. Anterior: [previa Clase 1](../clase%201/Ejercicios_Previos.md) · Siguiente: [Clase 2](README.md) → [previa Clase 3](../clase%203/Ejercicios_Previos.md)
