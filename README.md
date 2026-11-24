# Programación 1 · C++

Repositorio con el código, ejercicios y proyectos del curso de Programación 1 (C++). Cada carpeta de clase tiene su propio `README.md` con el temario, los conceptos clave y qué hace cada archivo.

## Ruta de aprendizaje

| Clase | Tema central | Qué se aprende |
|-------|--------------|----------------|
| [Clase 1](clase%201/README.md) | Ciclos y centinela | `while`, acumuladores, mayor/menor |
| [Clase 2](clase%202/README.md) | Estructuras (`struct`) | Definir structs, acceder con `.`, structs anidados, cadenas `char[]` |
| [Clase 3](clase%203/README.md) | Arreglos de structs | Registros múltiples, máximo por índice, totales, filtros |
| [Clase 4](clase%204/README.md) | Procedimientos | Funciones `void`, prototipos, variables globales vs locales |
| Clase 5 | *(no hay carpeta en el repo)* | — |
| [Clase 6](clase%206/README.md) | Funciones con retorno | Parámetros por valor, `return`, `static`, `to_string` |
| [Clase 7](clase%207/README.md) | Paso por referencia | `&`, intercambio de valores, menús `do-while` + `switch`, burbuja |
| [Clase 8](clase%208/README.md) | Arreglos y vectores como parámetros | Qué se modifica y qué no según cómo se pasa |
| [Clase 9](Clase%209%20-%20Sobrecarga/README.md) | Sobrecarga de funciones | Mismo nombre, distintos parámetros; sobrecarga con structs y arreglos |

> **¿Empezando?** Cada carpeta de clase trae un `Ejercicios_Previos.md` con 5 ejercicios ligeros para llegar al tema con soltura. Empieza por la [previa de la Clase 1](clase%201/Ejercicios_Previos.md).

El tema se va **acumulando**: las estructuras (clases 2-3) se combinan con funciones (4-6), luego con referencias y vectores (7-8), y la sobrecarga (9) se aplica sobre todo lo anterior.

## Material de estudio y evaluación

| Carpeta | Contenido |
|---------|-----------|
| [Examenes/](Examenes/README.md) | Temario de examen, ejercicios resueltos al estilo del parcial y guía de qué estudiar |
| [Repaso/](Repaso/README.md) | Repaso de estructuras (ejemplo resuelto + plantillas por completar) |
| [Repaso_Segundo_Parcial/](Repaso_Segundo_Parcial/README.md) | Lectura de archivos CSV y reportes (tema del segundo parcial) |
| [Proyecto/](Proyecto/README.md) | Proyecto de zona: parser de `datos2026.csv` con menú de reportes |
| [proyecto_final_ordenamiento/](proyecto_final_ordenamiento/README.md) | Proyecto final: ordenamiento y búsqueda sobre 100,000 enteros |

## Mapa de temas

```
Variables / ciclos ──► struct ──► arreglos de struct ──► funciones ──► referencias (&)
                                                                          │
              archivos (CSV) ◄── vectores ◄── arreglos como parámetro ◄──┘
                    │
              sobrecarga ──► proyectos (parser CSV, ordenamientos)
```

## Cómo compilar y ejecutar

```bash
g++ -std=c++17 archivo.cpp -o programa
./programa
```

Algunos archivos leen CSV/TXT con rutas relativas: ejecútalos **desde su propia carpeta**.

## Notas de organización

- Los nombres de carpeta se respetaron tal como estaban para no romper referencias.
- Cada `.cpp` empieza con un comentario que indica **clase, tema, conceptos y cómo compilarlo**.
- Los binarios compilados no se versionan.
