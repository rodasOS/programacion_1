> Volver al [índice de exámenes](README.md) · [README principal](../README.md)

# Ejercicios Elaborados — Programación 1
### Estilo de examen: enunciado detallado con funciones y menú definidos

---

> Cada ejercicio especifica exactamente:
> - La **estructura** de datos a usar
> - Las **funciones o procedimientos** que debes implementar
> - El **menú** que debe tener el programa
> - Las **reglas de negocio** que cada función debe respetar

---

## Ejercicio 1 — Sistema de Registro de Estudiantes

Crea un programa que maneje el registro de **10 estudiantes**. Cada estudiante tiene:
- Número de carnet (`int`)
- Nombre completo (`string`)
- Tres notas (`double`: nota1, nota2, nota3)
- Promedio (`double`) — se calcula automáticamente al ingresar las notas
- Estado (`string`): `"Aprobado"` si promedio >= 61, `"Reprobado"` si es menor

Implementa las siguientes funciones/procedimientos. **Cada opción del menú debe llamar a su función correspondiente:**

```
1. Ingreso de datos
       → Pide carnet, nombre y las 3 notas de cada estudiante
       → Calcula y guarda el promedio automáticamente
       → Asigna el estado según el promedio

2. Mostrar todos
       → Imprime una tabla con todos los estudiantes: carnet, nombre, promedio y estado

3. Mejor estudiante
       → Muestra el nombre y promedio del estudiante con el mayor promedio

4. Conteo aprobados / reprobados
       → Muestra cuántos estudiantes aprobaron y cuántos reprobaron

5. Buscar por carnet
       → Pide un carnet y muestra todos los datos del estudiante encontrado
       → Si no existe, muestra "Estudiante no encontrado"

6. HACER TODO (1 → 2 → 3 → 4)

7. Salir
```

**Restricciones:**
- Las notas deben estar entre 0 y 100. Si el usuario ingresa un valor fuera de ese rango, pídela de nuevo.
- El carnet no puede repetirse. Si se intenta ingresar un carnet ya registrado, muestra un mensaje de error y pide los datos del siguiente estudiante.

---

## Ejercicio 2 — Inventario de Productos con Sobrecarga

Crea un programa que maneje el inventario de una tienda con **8 productos**. Cada producto tiene:
- Código (`int`)
- Nombre (`string`)
- Precio unitario (`double`)
- Cantidad en bodega (`int`)
- Categoría (`string`): `"Electronico"`, `"Ropa"` o `"Alimento"`
- Valor total en inventario (`double`) — se calcula como `precio * cantidad`

Implementa las siguientes funciones. El menú debe tener estas opciones:

```
1. Registrar productos
       → Ingresa todos los datos; el valor total se calcula automáticamente

2. Mostrar inventario completo
       → Muestra todos los productos en una tabla ordenada

3. Buscar por código
       → Pide un código y muestra los datos del producto
       → Si no existe, muestra "Producto no encontrado"

4. Producto con mayor valor en inventario
       → Muestra el nombre y valor total del producto más valioso

5. Filtrar por categoría
       → Pide una categoría y lista todos los productos que pertenecen a ella

6. Valor total del inventario
       → Suma y muestra el valor total de todos los productos

7. HACER TODO (1 → 2 → 4 → 6)

8. Salir
```

**Sobrecarga requerida:** Implementa una función sobrecargada `mostrarProducto()`:
- `mostrarProducto(Producto p)` → muestra todos los campos del producto
- `mostrarProducto(Producto p, bool conValorTotal)` → si `conValorTotal` es `true`, también muestra el valor total calculado en ese momento (precio * cantidad)
- `mostrarProducto(string categoria, Producto lista[], int n)` → muestra solo los productos de esa categoría

**Restricción:** El código de producto no puede repetirse.

---

## Ejercicio 3 — Control de Parqueo

Crea un programa para administrar el parqueo de un edificio con capacidad para **15 vehículos**. Cada vehículo tiene:
- Placa (`string`)
- Propietario (`string`)
- Marca (`string`)
- Horas estacionado (`int`)
- Tarifa por hora (`double`): Q15.00 para motos, Q25.00 para carros, Q40.00 para camiones
- Tipo de vehículo (`string`): `"Moto"`, `"Carro"` o `"Camion"`
- Total a pagar (`double`) — se calcula como `horas * tarifa`

Implementa las siguientes funciones:

```
1. Registrar vehículo
       → Pide todos los datos del vehículo
       → Asigna la tarifa automáticamente según el tipo
       → Calcula el total a pagar

2. Mostrar todos los vehículos
       → Lista placa, propietario, tipo, horas y total a pagar

3. Buscar por placa
       → Pide una placa y muestra todos los datos del vehículo
       → Si no está registrado, muestra "Vehículo no encontrado"

4. Total recaudado
       → Suma y muestra el total a pagar de todos los vehículos registrados

5. Vehículo que más pagó
       → Muestra la placa, propietario y monto del vehículo con mayor pago

6. Listar por tipo
       → Pide el tipo (Moto/Carro/Camion) y lista los vehículos de ese tipo

7. Eliminar vehículo (checkout)
       → Pide una placa
       → Muestra el total a pagar de ese vehículo
       → Lo elimina del arreglo (desplaza los demás hacia arriba)

8. HACER TODO (1 → 2 → 4 → 5)

9. Salir
```

**Restricciones:**
- No se puede registrar dos vehículos con la misma placa.
- No se puede registrar más vehículos si el parqueo está lleno (15 vehículos).
- Las horas deben ser un número positivo mayor que 0.

---

## Ejercicio 4 — Gestión de Empleados con Sobrecarga

Crea un programa para gestionar **6 empleados** de una empresa. Existen dos tipos de empleados:

```cpp
struct EmpleadoFijo {
    int id;
    string nombre;
    string departamento;
    double salarioBase;
    int horasExtra;          // cada hora extra = salarioBase / 160 * 1.5
    double totalAPagar;      // se calcula automáticamente
};

struct EmpleadoTemporal {
    int id;
    string nombre;
    string agencia;
    double tarifaPorHora;
    int horasTrabajadas;
    double totalAPagar;      // tarifaPorHora * horasTrabajadas
};
```

El programa maneja **3 empleados fijos** y **3 empleados temporales** en arreglos separados.

Implementa las siguientes funciones:

```
1. Registrar empleados fijos
       → Pide los datos de los 3 empleados fijos
       → Calcula el totalAPagar automáticamente

2. Registrar empleados temporales
       → Pide los datos de los 3 empleados temporales
       → Calcula el totalAPagar automáticamente

3. Mostrar todos los empleados
       → Primero lista los fijos, luego los temporales
       → Muestra: id, nombre, tipo y total a pagar

4. Nómina total
       → Suma el totalAPagar de todos los empleados (fijos + temporales)
       → Muestra el resultado

5. Empleado mejor pagado
       → Compara todos los empleados (fijos y temporales) y muestra quién gana más

6. HACER TODO (1 → 2 → 3 → 4 → 5)

7. Salir
```

**Sobrecarga requerida:** Implementa estas funciones sobrecargadas:
- `calcularPago(EmpleadoFijo e)` → retorna `double` con el total a pagar
- `calcularPago(EmpleadoTemporal e)` → retorna `double` con el total a pagar
- `imprimirEmpleado(EmpleadoFijo e)` → imprime los datos del empleado fijo
- `imprimirEmpleado(EmpleadoTemporal e)` → imprime los datos del empleado temporal

---

## Ejercicio 5 — Biblioteca de Libros

Crea un programa para administrar los **12 libros** de una biblioteca. Cada libro tiene:
- ISBN (`int`)
- Título (`string`)
- Autor (`string`)
- Año de publicación (`int`)
- Género (`string`): `"Ciencia"`, `"Historia"`, `"Novela"` o `"Tecnologia"`
- Precio (`double`)
- Disponible (`bool`): `true` si está en estante, `false` si está prestado

Implementa las siguientes funciones:

```
1. Registrar libros
       → Ingresa todos los datos; todos inician como disponibles (true)

2. Mostrar todos los libros
       → Lista todos los libros con su estado (Disponible / Prestado)

3. Prestar libro
       → Pide un ISBN
       → Si el libro está disponible, cambia su estado a prestado (false)
       → Si ya está prestado, muestra "El libro ya está prestado"
       → Si no existe el ISBN, muestra "Libro no encontrado"

4. Devolver libro
       → Pide un ISBN
       → Cambia el estado del libro a disponible (true)
       → Si no existe el ISBN, muestra "Libro no encontrado"

5. Buscar por autor
       → Pide un nombre de autor y lista todos sus libros con su estado

6. Libros disponibles
       → Lista solo los libros con estado disponible (true)

7. Libro más antiguo
       → Muestra el título y año del libro con el año de publicación más antiguo

8. Estadísticas por género
       → Para cada género, muestra cuántos libros hay y cuántos están disponibles

9. HACER TODO (1 → 2 → 6 → 7)

10. Salir
```

**Restricción:** No se puede registrar dos libros con el mismo ISBN.

---

## Ejercicio 6 — Sistema de Ventas con Archivos *(Nivel Avanzado)*

Crea un programa de registro de ventas. Cada venta tiene:
- ID de venta (`int`, autoincremental — empieza en 1 y sube solo)
- Nombre del vendedor (`string`)
- Producto vendido (`string`)
- Cantidad (`int`)
- Precio unitario (`double`)
- Total (`double`) — se calcula como `cantidad * precio`
- Mes (`int`) y Año (`int`) de la venta

El programa debe manejar hasta **20 ventas** en un arreglo.

Implementa las siguientes funciones:

```
1. Registrar venta
       → Pide: nombre del vendedor, producto, cantidad, precio, mes y año
       → El ID se asigna automáticamente (autoincremental)
       → El total se calcula automáticamente

2. Mostrar todas las ventas
       → Lista todas las ventas con todos sus campos

3. Venta más alta
       → Muestra los datos de la venta con el mayor total

4. Total vendido por vendedor
       → Pide un nombre y suma todos los totales de ese vendedor
       → Si el vendedor no tiene ventas, muestra "Sin ventas registradas"

5. Ventas por mes
       → Pide un mes (número) y lista todas las ventas de ese mes

6. Ranking de vendedores
       → Agrupa las ventas por vendedor, suma sus totales y muestra
         la lista ordenada de mayor a menor (algoritmo burbuja)

7. Guardar en archivo
       → Guarda todas las ventas en "ventas_registro.txt" con el formato:
         ID|Vendedor|Producto|Cantidad|Precio|Total|Mes|Año

8. Leer desde archivo
       → Carga las ventas desde "ventas_registro.txt" al arreglo
       → Muestra cuántas ventas se cargaron

9. HACER TODO (1 → 2 → 3 → 6)

10. Salir
```

**Sobrecarga requerida:**
- `buscarVentas(string vendedor, ...)` → busca por nombre de vendedor
- `buscarVentas(int mes, ...)` → busca por mes
- `buscarVentas(int mes, int anio, ...)` → busca por mes Y año específicos

**Restricción:** La cantidad debe ser mayor que 0. El precio debe ser mayor que 0.

---

## Ejercicio 7 — Torneo de Jugadores *(Integrador completo)*

Crea un programa para administrar un torneo con **8 jugadores**. Cada jugador tiene:
- ID (`int`)
- Nombre (`string`)
- País (`string`)
- Puntos (`int`) — inicia en 0
- Victorias (`int`) — inicia en 0
- Derrotas (`int`) — inicia en 0
- Clasificado (`bool`): `true` si tiene más de 3 victorias, `false` si no

Implementa las siguientes funciones:

```
1. Registrar jugadores
       → Pide ID, nombre y país
       → Puntos, victorias, derrotas inician en 0
       → Clasificado inicia en false

2. Registrar resultado de partido
       → Pide los IDs de dos jugadores (ganador y perdedor)
       → Al ganador: suma 3 puntos y 1 victoria
       → Al perdedor: suma 0 puntos y 1 derrota
       → Actualiza el campo "Clasificado" de ambos jugadores

3. Mostrar tabla de posiciones
       → Lista todos los jugadores ordenados por puntos (mayor a menor)
       → Muestra: posición, nombre, país, puntos, victorias, derrotas, clasificado

4. Jugador líder
       → Muestra los datos del jugador con más puntos

5. Jugadores clasificados
       → Lista los jugadores con clasificado = true

6. Buscar jugador
       → Pide un ID y muestra todos sus datos

7. Estadísticas del torneo
       → Cantidad total de partidos jugados
       → Jugador con más victorias
       → Jugador con más derrotas
       → Promedio de puntos de todos los jugadores

8. HACER TODO (1 → 3 → 4 → 5)

9. Salir
```

**Sobrecarga requerida:**
- `registrarResultado(int idGanador, int idPerdedor, Jugador lista[], int n)` — versión normal
- `registrarResultado(int idGanador, int idPerdedor, int puntosBono, Jugador lista[], int n)` — versión con bono: suma `puntosBono` adicionales al ganador (para partidos especiales)

**Restricción:**
- No se puede registrar un partido entre un jugador y él mismo.
- Si un ID no existe en el torneo, muestra "Jugador no encontrado" y cancela el registro.

---

*Ejercicios generados para Programación 1 · Basados en el estilo de clase 7/ejercicio2.cpp*
