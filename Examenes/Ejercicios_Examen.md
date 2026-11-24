> Volver al [índice de exámenes](README.md) · [README principal](../README.md)

# Ejercicios de Examen — Programación 1
### Enfoque principal: Sobrecarga de Funciones · C++

---

> **Cómo leer este documento**
> - Cada ejercicio indica su **nivel de dificultad** (⭐ fácil · ⭐⭐ medio · ⭐⭐⭐ difícil).
> - Los ejercicios marcados con 🔑 son los más probables en un examen real basándonos en lo visto en clase.
> - Al final de cada ejercicio hay una sección **Qué evalúa** para que sepas exactamente en qué te debes enfocar.

---

## ¿Qué es la Sobrecarga de Funciones?

La **sobrecarga** permite tener **varias funciones con el mismo nombre** dentro del mismo programa, siempre que sus **parámetros sean diferentes** (ya sea en cantidad, tipo, o ambos). El compilador decide cuál versión usar según los argumentos que le pases.

```cpp
// Tres funciones llamadas "suma" — el compilador elige la correcta automáticamente
int    suma(int a, int b)             { return a + b; }
double suma(double a, double b)       { return a + b; }
int    suma(int a, int b, int c)      { return a + b + c; }
```

> **Regla de oro:** El compilador NO distingue dos funciones solo por su tipo de retorno.
> `int f(int x)` y `double f(int x)` generan un **error de compilación**.

---

## SECCIÓN 1 — Sobrecarga de Funciones

---

### Ejercicio 1 · ⭐ · 🔑
#### "Identificar versiones válidas de sobrecarga"

Dado el siguiente conjunto de declaraciones, indica cuáles forman una sobrecarga **válida** y cuáles generarían un **error de compilación**. Justifica cada respuesta.

```cpp
// Grupo A
int calcular(int x);
double calcular(double x);
calcular(int x, int y);           // (a)

// Grupo B
int procesar(int a, int b);
int procesar(int a, int b, int c);
double procesar(int a, int b);    // (b)

// Grupo C
void mostrar(string s);
void mostrar(int n);
void mostrar(double d);           // (c)

// Grupo D
int operar(int a, double b);
int operar(double a, int b);      // (d)
```

**Respuestas esperadas:**

| Grupo | ¿Válida? | Razón |
|-------|----------|-------|
| A | ❌ | `(a)` no tiene tipo de retorno — error de sintaxis |
| B | ❌ | `(b)` difiere solo en retorno, no en parámetros |
| C | ✅ | Cada versión recibe un tipo diferente |
| D | ✅ | El orden de tipos es diferente (`int,double` vs `double,int`) |

> **Qué evalúa:** Comprensión de las reglas de sobrecarga. El punto más común de error es creer que cambiar el tipo de retorno es suficiente.

---

### Ejercicio 2 · ⭐ · 🔑
#### "Sobrecarga básica de conversión"

Escribe un programa en C++ que tenga una función sobrecargada llamada `convertir()` con las siguientes versiones:

1. Recibe un valor en **metros** (`double`) y retorna su equivalente en **centímetros**.
2. Recibe un valor en **kilogramos** (`double`) y una bandera `bool esPeso` (siempre `true`) y retorna el equivalente en **libras** (1 kg = 2.205 libras).
3. Recibe una temperatura en **Celsius** (`int`) y retorna su equivalente en **Fahrenheit** (`double`).  
   Fórmula: `F = (C * 9.0/5.0) + 32`

El `main` debe llamar a las tres versiones y mostrar los resultados.

**Salida esperada (ejemplo):**
```
5.0 metros = 500.0 centimetros
70.0 kg    = 154.35 libras
25 Celsius = 77.0 Fahrenheit
```

**Plantilla de inicio:**
```cpp
#include <iostream>
using namespace std;

// Escribe tus 3 versiones de convertir() aquí


int main() {
    cout << convertir(5.0) << endl;
    cout << convertir(70.0, true) << endl;
    cout << convertir(25) << endl;
    return 0;
}
```

> **Qué evalúa:** Capacidad de diseñar firmas de función distintas para un mismo nombre. Ojo en que `convertir(double)` y `convertir(int)` sí son diferentes para el compilador.

---

### Ejercicio 3 · ⭐⭐ · 🔑
#### "Calculadora con sobrecarga completa"

Escribe las siguientes funciones sobrecargadas para una calculadora:

| Función | Parámetros | Retorna |
|---------|-----------|---------|
| `operar` | `int a, int b, char op` | `int` resultado de la operación |
| `operar` | `double a, double b, char op` | `double` resultado |

Las operaciones válidas son: `+`, `-`, `*`, `/`.  
Para la división, valida que el divisor no sea cero (muestra mensaje y retorna `0`).

Luego en `main`:
- Pide al usuario dos números y una operación.
- Detecta si los números son enteros o decimales (puedes leerlos como `double` y verificar si tienen parte decimal) y llama a la versión correcta.
- Muestra el resultado.

**Ejemplo de ejecución:**
```
Ingresa el primer numero: 10
Ingresa el segundo numero: 3
Operacion (+, -, *, /): /
Resultado: 3   (version entera)

Ingresa el primer numero: 10.5
Ingresa el segundo numero: 3.0
Operacion (+, -, *, /): *
Resultado: 31.5  (version decimal)
```

> **Qué evalúa:** Sobrecarga por tipo de dato + manejo básico de errores + decisión de cuál versión invocar.

---

### Ejercicio 4 · ⭐⭐ · 🔑
#### "Área de figuras geométricas"

Basándote en el ejercicio `calcular_area.cpp` de la Clase 9, amplía el sistema para calcular el área de **cuatro figuras**, todas usando el mismo nombre de función `area()`:

| Versión | Parámetros | Figura | Fórmula |
|---------|-----------|--------|---------|
| 1 | `int lado` | Cuadrado | `lado²` |
| 2 | `int base, int altura` | Rectángulo | `base × altura` |
| 3 | `double base, double altura` | Triángulo | `base × altura / 2` |
| 4 | `double radio` | Círculo | `π × radio²` (usa `3.14159`) |

**Código principal a completar:**

```cpp
int main() {
    int opcion;
    cout << "1. Cuadrado\n2. Rectangulo\n3. Triangulo\n4. Circulo\n";
    cin >> opcion;

    switch(opcion) {
        case 1: {
            int l; cout << "Lado: "; cin >> l;
            cout << "Area: " << area(l) << endl; break;
        }
        case 2: {
            int b, h; cout << "Base y Altura: "; cin >> b >> h;
            cout << "Area: " << area(b, h) << endl; break;
        }
        case 3: {
            double b, h; cout << "Base y Altura: "; cin >> b >> h;
            cout << "Area: " << area(b, h) << endl; break;  // ← misma llamada que caso 2, ¿por qué funciona?
        }
        case 4: {
            double r; cout << "Radio: "; cin >> r;
            cout << "Area: " << area(r) << endl; break;
        }
    }
    return 0;
}
```

**Pregunta adicional (teórica):** En los casos 2 y 3 la llamada `area(b, h)` es idéntica. ¿Por qué el compilador sabe cuál versión usar?

> **Respuesta:** Porque en el caso 2, `b` y `h` son `int`, y en el caso 3 son `double`. El compilador resuelve la sobrecarga según el **tipo estático** de los argumentos.

> **Qué evalúa:** Sobrecarga con diferentes cantidades Y tipos de parámetros. La pregunta adicional prueba comprensión conceptual.

---

### Ejercicio 5 · ⭐⭐ · 🔑
#### "Sobrecarga con estructuras"

Define las siguientes estructuras:

```cpp
struct Rectangulo { double base, altura; };
struct Circulo    { double radio; };
struct Triangulo  { double base, altura; };
```

Luego crea una función `calcularArea()` sobrecargada que reciba cada tipo de estructura y retorne el área como `double`.

```cpp
// Fórmulas:
// Rectangulo: base * altura
// Circulo:    3.14159 * radio * radio
// Triangulo:  base * altura / 2
```

En `main`, crea una variable de cada tipo, pide los datos al usuario y muestra las tres áreas.

**Extensión:** Agrega una función `describir()` sobrecargada que reciba cada estructura e imprima sus datos formateados:

```
Rectangulo: base=5.0, altura=3.0, area=15.0
Circulo:    radio=4.0, area=50.26
Triangulo:  base=6.0, altura=2.0, area=6.0
```

> **Qué evalúa:** Sobrecarga combinada con estructuras — tema central de la Clase 9 (Ejercicio 1 con estructuras Celsius/Fahrenheit/Metros).

---

### Ejercicio 6 · ⭐⭐⭐
#### "Sobrecarga de suma para arreglos y vectores"

Basándote en el `Ejercicio 2.cpp` de la Clase 9, implementa las siguientes versiones de `sumar()` y `promedio()`:

```
sumar(const int arr[], int n)       → retorna int
sumar(const double arr[], int n)    → retorna double
sumar(vector<int> v)                → retorna int
sumar(vector<double> v)             → retorna double

promedio(const int arr[], int n)    → retorna double
promedio(vector<double> v)          → retorna double
```

En `main`:
1. Declara `int nums[] = {3, 7, 2, 9, 1}` y un `vector<double> precios = {15.5, 20.0, 8.75}`.
2. Muestra la suma y promedio de cada colección usando las funciones sobrecargadas.
3. Muestra también el producto entre la suma entera y la suma decimal.

**Salida esperada:**
```
Suma enteros (arreglo):    22
Suma decimales (vector):   44.25
Promedio enteros:          4.40
Promedio decimales:        14.75
Producto de sumas:         973.5
```

> **Qué evalúa:** Sobrecarga con arreglos vs vectores + mezcla de tipos de retorno.

---

## SECCIÓN 2 — Funciones, Referencias y Paso de Parámetros

> Temas de soporte que pueden acompañar la sobrecarga en el examen.

---

### Ejercicio 7 · ⭐ · 🔑
#### "Paso por valor vs paso por referencia"

Dado el siguiente código, predice la salida **sin ejecutarlo**:

```cpp
#include <iostream>
using namespace std;

void duplicarValor(int x) {
    x = x * 2;
}

void duplicarRef(int &x) {
    x = x * 2;
}

int main() {
    int a = 10, b = 10;
    duplicarValor(a);
    duplicarRef(b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}
```

**Respuesta:**
```
a = 10    (no se modifica, fue por valor)
b = 20    (sí se modifica, fue por referencia)
```

**Extensión:** Escribe una función `intercambiar(int &x, int &y)` que intercambie dos variables **sin usar una tercera variable auxiliar** (pista: puedes usar XOR o suma/resta).

> **Qué evalúa:** Comprensión de referencias — tema clave de la Clase 7.

---

### Ejercicio 8 · ⭐⭐
#### "Login con contador por referencia"

Basándote en el `ejercicio2.cpp` de la Clase 8, escribe una función:

```cpp
bool login(string usuario, string password, int &intentos);
```

Reglas:
- Usuario correcto: `"admin"`, contraseña correcta: `"1234"`.
- La función incrementa `intentos` cada vez que se llama.
- Retorna `true` si las credenciales son correctas, `false` si no.

En `main`, usa un bucle que permita hasta **3 intentos**. Si se agotan, muestra `"Cuenta bloqueada"`.

**Salida esperada (ejemplo):**
```
Usuario: admin
Password: 0000
Credenciales incorrectas. Intentos: 1/3

Usuario: admin
Password: 1234
Acceso concedido en el intento 2.
```

> **Qué evalúa:** Paso por referencia para modificar una variable del llamador.

---

## SECCIÓN 3 — Estructuras

---

### Ejercicio 9 · ⭐⭐ · 🔑
#### "Registro de productos con búsqueda"

Define la estructura:

```cpp
struct Producto {
    int codigo;
    string nombre;
    double precio;
    int cantidad;
    double valorTotal;   // precio * cantidad
};
```

Escribe un programa que:
1. Declare un arreglo de 5 productos.
2. Pida los datos al usuario (el `valorTotal` se calcula automáticamente).
3. Muestre todos los productos.
4. Encuentre e imprima el producto más caro (mayor precio unitario).
5. Calcule e imprima la suma total de todos los `valorTotal`.
6. Liste los productos con `cantidad < 5`.

> **Qué evalúa:** Manejo de estructuras con arreglos — patrón repetido desde la Clase 3.

---

### Ejercicio 10 · ⭐⭐ · 🔑
#### "Estructuras + Funciones sobrecargadas"

Define:
```cpp
struct Empleado   { string nombre; double salario; int horasExtra; };
struct Contratado { string nombre; double tarifaPorHora; int horasTrabajadas; };
```

Escribe una función sobrecargada `calcularPago()`:
- `calcularPago(Empleado e)` → retorna `salario + (horasExtra * salario/160.0 * 1.5)`
- `calcularPago(Contratado c)` → retorna `tarifaPorHora * horasTrabajadas`

En `main`:
1. Crea 2 empleados y 2 contratados.
2. Muestra el pago de cada uno usando la misma función `calcularPago()`.
3. Indica quién recibe el pago total más alto entre los cuatro.

> **Qué evalúa:** Combina sobrecarga con estructuras — el examen puede pedir exactamente esto.

---

## SECCIÓN 4 — Manejo de Archivos

---

### Ejercicio 11 · ⭐⭐⭐
#### "Guardar y leer clientes en archivo"

Basándote en el `index.cpp` de la Clase 10, crea un programa con la estructura:

```cpp
struct Cliente {
    int id;
    string nombre;
    string correo;
    double saldo;
};
```

Funciones requeridas:
1. `guardarCliente(Cliente c, string archivo)` — agrega un cliente al final del archivo (modo append).
2. `leerClientes(string archivo)` — lee e imprime todos los clientes del archivo.
3. `buscarCliente(string archivo, int id)` — busca un cliente por su ID e imprime sus datos, o "No encontrado".

El archivo debe guardarse con el formato:
```
1|Mario Rodriguez|mario@email.com|1500.50
2|Ana Lopez|ana@email.com|3200.00
```

> **Qué evalúa:** Lectura/escritura de archivos de texto con delimitadores — tema de la Clase 10 y Repaso Segundo Parcial.

---

## SECCIÓN 5 — Preguntas Conceptuales

> Estas pueden aparecer como preguntas de opción múltiple o verdadero/falso.

---

### Pregunta A · ⭐
¿Cuál de las siguientes afirmaciones sobre la sobrecarga de funciones es **falsa**?

- a) Dos funciones pueden tener el mismo nombre si difieren en el tipo de sus parámetros.
- b) Dos funciones pueden tener el mismo nombre si difieren solo en el tipo de retorno.
- c) Dos funciones pueden tener el mismo nombre si difieren en la cantidad de parámetros.
- d) El compilador determina cuál versión usar en tiempo de compilación.

**Respuesta: b)** — Cambiar solo el tipo de retorno no es suficiente para sobrecargar.

---

### Pregunta B · ⭐
¿Qué imprime el siguiente código?

```cpp
#include <iostream>
using namespace std;

int f(int x)    { return x * 2; }
double f(double x) { return x * 3.0; }

int main() {
    cout << f(4) << endl;
    cout << f(2.5) << endl;
    cout << f(3.0) << endl;
    return 0;
}
```

**Respuesta:**
```
8       (llama f(int))
7.5     (llama f(double))
9       (llama f(double), 3.0 es double)
```

---

### Pregunta C · ⭐⭐
Explica la diferencia entre:
- Pasar un arreglo a una función
- Pasar un `vector` a una función (por valor vs por referencia)

¿Cuándo se modifica el original y cuándo no?

**Respuesta esperada:**  
Un arreglo pasado a una función siempre actúa como si fuera por referencia (se pasa el puntero al primer elemento). Un vector pasado por valor crea una copia — los cambios no afectan el original. Para modificar el vector original, hay que pasarlo como `vector<int> &v`.

---

### Pregunta D · ⭐⭐
¿Puede una función sobrecargada llamar a otra versión de sí misma? Escribe un ejemplo donde:
- `suma(int a, int b, int c)` llame a `suma(int, int)` internamente.

**Respuesta:**
```cpp
int suma(int a, int b)         { return a + b; }
int suma(int a, int b, int c)  { return suma(a, b) + c; }  // ✅ válido
```

---

## EJERCICIO INTEGRADOR · ⭐⭐⭐ · 🔑
#### "Sistema de facturación con sobrecarga"

Este ejercicio combina todos los temas. Es el tipo de ejercicio que puede aparecer como examen completo.

**Enunciado:**

Crea un sistema de facturación para una tienda. Define:

```cpp
struct ProductoSimple  { string nombre; double precio; int cantidad; };
struct ProductoOferta  { string nombre; double precio; int cantidad; double descuento; };
struct ServicioHoras   { string descripcion; double tarifaHora; double horas; };
```

Implementa la función `calcularTotal()` sobrecargada para cada tipo:
- `ProductoSimple`: `precio * cantidad`
- `ProductoOferta`: `precio * cantidad * (1 - descuento/100)`
- `ServicioHoras`: `tarifaHora * horas`

Implementa también `imprimirItem()` sobrecargada para mostrar cada tipo con formato.

En `main`:
1. Crea 2 productos simples, 1 producto en oferta y 1 servicio.
2. Muestra cada ítem con su total usando las funciones sobrecargadas.
3. Suma todos los totales y muestra el **total de la factura**.
4. Guarda la factura en un archivo `factura.txt`.

**Salida esperada:**
```
===== FACTURA =====
[Producto] Camisa        x2  Q50.00 c/u    = Q100.00
[Producto] Pantalon      x1  Q120.00 c/u   = Q120.00
[Oferta]   Zapatos       x1  Q200.00 -20%  = Q160.00
[Servicio] Bordado            Q15/hr x 3hr = Q45.00
------------------
TOTAL:                                       Q425.00
```

> **Qué evalúa:** Sobrecarga de funciones + estructuras + archivos + lógica de cálculo. El ejercicio completo tal como aparecería en un examen final.

---

## Resumen de Temas y Dónde Aparecen en el Código

| Tema | Ejercicios | Archivos del proyecto |
|------|-----------|----------------------|
| Sobrecarga por tipo | 1, 2, 3 | `Clase 9/index.cpp`, `calcular_area.cpp` |
| Sobrecarga por cantidad | 1, 4 | `Clase 9/index.cpp` |
| Sobrecarga con structs | 5, 10, Integrador | `Clase 9/Ejercicio 1.cpp` |
| Sobrecarga con arreglos | 6 | `Clase 9/Ejercicio 2.cpp` |
| Paso por referencia | 7, 8 | `Clase 7/index.cpp`, `Clase 8/ejercicio2.cpp` |
| Estructuras + arreglos | 9 | `clase 3/ejercicio2.cpp` |
| Archivos de texto | 11, Integrador | `Clase 10/index.cpp` |

---

*Generado para el curso Programación 1 · Análisis basado en Clases 1–10 y material de repaso.*
