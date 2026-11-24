# Exámenes · Temario y práctica

## Documentos

| Archivo | Contenido |
|---------|-----------|
| [Ejercicios_Examen.md](Ejercicios_Examen.md) | 11 ejercicios + 4 preguntas conceptuales + 1 integrador, enfocados en **sobrecarga**. Marca con 🔑 los más probables |
| [Ejercicios_Elaborados.md](Ejercicios_Elaborados.md) | 7 ejercicios largos al estilo del parcial: struct + menú + funciones definidas + restricciones |
| [Proyecto](../Proyecto/README.md) | Proyecto de zona (parser de CSV): su enunciado está en `Proyecto/examen.md` |

## Temas importantes y dónde repasarlos

Ordenados por cuánto aparecen en los ejercicios de examen.

| # | Tema | Qué suelen pedir | Repasar en | Práctica |
|---|------|------------------|------------|----------|
| 1 | **Sobrecarga de funciones** | Identificar sobrecargas válidas, predecir qué versión se llama, sobrecargar con structs y arreglos | [Clase 9](../Clase%209%20-%20Sobrecarga/README.md) | Examen Ej. 1-6, 10, Integrador |
| 2 | **Structs + arreglos de structs** | Registrar N elementos, máximo por índice, acumular, filtrar | [Clase 3](../clase%203/README.md), [Repaso](../Repaso/README.md) | Examen Ej. 9; Elaborados 1-7 |
| 3 | **Menú con funciones** (`do-while` + `switch`) | Una función por opción, opción "HACER TODO", validaciones | [Clase 7](../clase%207/README.md) | Todos los Elaborados |
| 4 | **Paso por valor / referencia** | Predecir salida, `swap`, contador por referencia | [Clase 7](../clase%207/README.md), [Clase 8](../clase%208/README.md) | Examen Ej. 7-8, Pregunta C |
| 5 | **Arreglos vs vectores como parámetro** | Qué se modifica y qué no | [Clase 8](../clase%208/README.md) | Examen Ej. 6, Pregunta C |
| 6 | **Archivos y parseo de texto** | Leer CSV/TXT, partir con `getline`/`stringstream`, guardar con delimitador | [Repaso Segundo Parcial](../Repaso_Segundo_Parcial/README.md), [Proyecto](../Proyecto/README.md) | Examen Ej. 11; Elaborados 6 |
| 7 | **Ordenamiento (burbuja)** | Ordenar un arreglo, ranking de mayor a menor | [Clase 7](../clase%207/README.md) | Elaborados 6-7 |
| 8 | **Procedimientos y retorno** | Prototipos, `void` vs `return`, `static` | [Clase 4](../clase%204/README.md), [Clase 6](../clase%206/README.md) | Examen Ej. 8 |

## Reglas que más se confunden

1. **El tipo de retorno no sobrecarga:** `int f(int)` y `double f(int)` → error de compilación.
2. `area(4, 5)` vs `area(4.0, 5.0)` llaman versiones distintas por el **tipo** de los argumentos.
3. Un arreglo se pasa siempre "por referencia"; un `vector` por valor se **copia**.
4. `cin >>` sobre `char[]` o `string` se detiene en el espacio; para líneas usa `getline`.
5. Todo lo que va después de un `return` no se ejecuta.
6. En división entera usa `static_cast<double>` para conservar decimales.

## Plantilla mental para un ejercicio tipo parcial

```
1. Leer el enunciado y listar: struct, funciones, opciones del menú, restricciones.
2. Declarar struct y arreglo (const int N).
3. Escribir una función por opción del menú; "HACER TODO" solo llama a las demás.
4. main = do { mostrar menú; leer opción; switch } while (opción != salir);
5. Validar: rangos, duplicados, división entre cero, "no encontrado".
```

## Plan de estudio sugerido

1. Repasar los READMEs de las clases 3, 7, 8 y 9 (en ese orden).
2. Resolver `Ejercicios_Examen.md` Sección 1 (sobrecarga) sin mirar las respuestas.
3. Resolver 2-3 ejercicios de `Ejercicios_Elaborados.md` completos, con menú y validaciones.
4. Repasar archivos con [Repaso Segundo Parcial](../Repaso_Segundo_Parcial/README.md).
