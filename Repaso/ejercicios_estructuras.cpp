/*
 * REPASO - Enunciados de practica de estructuras (6 ejercicios, solo texto).
 * Libros, empleados, vehiculos, celulares, peliculas y estudiantes con materias
 * (struct dentro de struct). No contiene codigo ejecutable.
 */

/*
    EJERCICIOS DE PRÁCTICA - ESTRUCTURAS EN C++
    ============================================
    
    EJERCICIO 1: REGISTRO DE LIBROS
    ---------------------------------
    Crear un programa que maneje una biblioteca simple.
    
    - Definir una estructura Libro con:
        - int codigo
        - char titulo[50]
        - char autor[30]
        - int anio
        - float precio
    
    - El programa debe:
        1. Registrar 5 libros
        2. Mostrar todos los libros
        3. Encontrar y mostrar el libro más antiguo
        4. Calcular el precio promedio de todos los libros
    
    
    EJERCICIO 2: REGISTRO DE EMPLEADOS
    ------------------------------------
    Crear un sistema simple de empleados.
    
    - Definir una estructura Empleado con:
        - char nombre[30]
        - int edad
        - float salario
        - int aniosServicio
    
    - El programa debe:
        1. Registrar 3 empleados
        2. Mostrar todos los empleados
        3. Calcular el salario total de todos los empleados
        4. Mostrar el empleado con más años de servicio
        5. Contar cuántos empleados tienen salario mayor a 1000
    
    
    EJERCICIO 3: REGISTRO DE VEHÍCULOS
    ------------------------------------
    Crear un programa para registrar vehículos.
    
    - Definir una estructura Vehiculo con:
        - char marca[20]
        - char modelo[20]
        - int anio
        - float kilometraje
        - float precio
    
    - El programa debe:
        1. Registrar 4 vehículos
        2. Mostrar todos los vehículos
        3. Encontrar el vehículo más caro
        4. Mostrar vehículos con menos de 50000 km
    
    
    EJERCICIO 4: TIENDA DE CELULARES
    ----------------------------------
    Crear un programa para gestionar celulares en una tienda.
    
    - Definir una estructura Celular con:
        - char marca[20]
        - char modelo[30]
        - float precio
        - int stock
        - float totalValor (precio * stock)
    
    - El programa debe:
        1. Registrar 5 celulares
        2. Calcular automáticamente el totalValor de cada celular
        3. Mostrar todos los celulares
        4. Mostrar el valor total del inventario
        5. Mostrar celulares con stock menor a 3 unidades
    
    
    EJERCICIO 5: REGISTRO DE PELÍCULAS
    ------------------------------------
    Crear un programa para registrar películas vistas.
    
    - Definir una estructura Pelicula con:
        - char titulo[50]
        - int anio
        - float calificacion (de 0 a 10)
        - int duracion (en minutos)
    
    - El programa debe:
        1. Registrar 5 películas
        2. Mostrar todas las películas
        3. Calcular la calificación promedio
        4. Mostrar la película mejor calificada
        5. Mostrar películas con duración mayor a 120 minutos
    
    
    EJERCICIO 6 (DESAFÍO): SISTEMA DE NOTAS CON MÚLTIPLES MATERIAS
    ----------------------------------------------------------------
    Crear un programa que registre estudiantes con múltiples materias.
    
    - Definir una estructura Materia con:
        - char nombre[30]
        - float nota
    
    - Definir una estructura EstudianteCompleto con:
        - char nombre[30]
        - int carnet
        - Materia materias[3]  // 3 materias por estudiante
        - float promedioGeneral
    
    - El programa debe:
        1. Registrar 2 estudiantes, cada uno con 3 materias
        2. Calcular el promedio general de cada estudiante
        3. Mostrar todos los datos
        4. Indicar qué estudiante tiene mejor promedio
*/
