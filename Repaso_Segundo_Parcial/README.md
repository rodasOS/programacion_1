# Repaso Segundo Parcial · Archivos CSV

**Tema:** leer un archivo de texto, partirlo por delimitador y generar reportes.

| Archivo | Qué es |
|---------|--------|
| `index.cpp` | Lee `ventas.csv` y calcula: quién vendió más, total por mes/año, promedio y ranking |
| `ventas.csv` | Datos de ejemplo (separador `;`) |

## Flujo de lectura

```cpp
ifstream archivo(nombre);                 // 1. abrir
getline(archivo, linea);                  // 2. saltar encabezado
while (getline(archivo, linea)) {         // 3. una línea por vuelta
    stringstream ss(linea);
    getline(ss, token, ';');              // 4. partir por delimitador
    ventas[n].id = stoi(token);           // 5. convertir: stoi / stod
}
```

## Patrones de reporte

| Reporte | Técnica |
|---------|---------|
| Quién vendió más | Máximo por índice |
| Total por mes/año | Agrupar sin repetir: lista de "ya vistos" |
| Promedio | Acumulador / cantidad |
| Ranking | Acumular por nombre + burbuja descendente |

Ejecutar desde esta carpeta (`ventas.csv` se busca con ruta relativa). Es la base del [Proyecto](../Proyecto/README.md).
