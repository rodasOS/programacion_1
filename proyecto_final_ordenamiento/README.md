# Proyecto final · Ordenamiento y búsqueda

Programa que genera **100,000 enteros aleatorios**, permite ordenarlos con el método elegido (muestra vector y tiempo) y buscar un valor con dos algoritmos. Análisis completo de tiempos en `RESULTADOS.md`.

| Archivo | Qué es |
|---------|--------|
| `proyecto_final.cpp` | Programa principal: menú, 6 ordenamientos, 2 búsquedas, benchmark |
| `radix_rapido.cpp` | Radix Sort aislado con nombres descriptivos (para explicarlo) |
| `RESULTADOS.md` | Tabla de tiempos y conclusiones |

## Algoritmos

| Ordenamiento | Complejidad |
|--------------|-------------|
| Radix Sort (LSD, base 256) | O(n·k) |
| Quick Sort (mediana de 3) | O(n log n) |
| Merge Sort | O(n log n), estable |
| Heap Sort | O(n log n) |
| Shell Sort (Ciura) | ~O(n^1.3) |
| Burbuja | O(n²) |

| Búsqueda (vector ordenado) | Complejidad |
|----------------------------|-------------|
| Binaria | O(log n) |
| Interpolación | O(log log n) en datos uniformes |

## Temas que se practican

Vectores · punteros a función (tabla de algoritmos del menú) · recursión (quick/merge) · `<chrono>` para medir tiempo · `<random>` · complejidad algorítmica.

## Ejecutar

```bash
g++ -O2 -std=c++17 proyecto_final.cpp -o proyecto_final
./proyecto_final               # menú
./proyecto_final --benchmark   # comparación de algoritmos
```
