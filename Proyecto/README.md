# Proyecto · Parser de `datos2026.csv`

Proyecto de zona (15 puntos). El enunciado completo está en `examen.md`; el set de datos (5,000 líneas) en `datos2026.csv`.

## Qué hace `proyecto.cpp`

Carga el CSV en un arreglo de 5,000 structs `Venta` (`idVendedor`, `Nombre_vendedor`, `mesVenta`, `anioVenta`, `montoVenta`) y ofrece un menú:

| Opción | Función | Parámetros |
|--------|---------|------------|
| 1 | `calcularSuma` | `idVendedor`, `anio` |
| 2 | `calcularPromedio` | `idVendedor`, `anio` |
| 3 | `vendedorMayorVentas` | `anio` |
| 4 | `vendedorMenorVentas` | `anio` |
| 5 | `imprimirDatosVendedor` | `idVendedor` |

## Idea clave: el `0` como comodín

| `idVendedor` | `anio` | Resultado |
|:---:|:---:|-----------|
| 0 | 0 | Todo el set de datos |
| 0 | X | Todos los vendedores en el año X |
| Y | 0 | El vendedor Y en todos los años |
| Y | X | El vendedor Y en el año X |

```cpp
bool matchId   = (idVendedor == 0) || (ventas[i].idVendedor == idVendedor);
bool matchAnio = (anio == 0)       || (ventas[i].anioVenta  == anio);
```

`acumularPorVendedor()` agrupa totales por vendedor y la reutilizan las funciones de mayor y menor.

## Temas del curso que aplica

structs · arreglos · funciones con parámetros · menú `do-while` + `switch` · archivos (`ifstream`, `getline`, `stringstream`, `stoi`/`stod`) · `iomanip`.

## Ejecutar

```bash
cd Proyecto
g++ proyecto.cpp -o proyecto && ./proyecto
```

`datos2026.csv` debe estar en la carpeta desde la que se ejecuta. La entrega incluía además un video explicativo (`link_video.txt`).

> `proyecto_Mario_Sales/proyecto.cpp` es una copia idéntica de este archivo (carpeta de entrega).
