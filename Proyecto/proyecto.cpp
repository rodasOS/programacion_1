/*
 * PROYECTO (15 pts de zona) - Parser de datos2026.csv  |  enunciado completo: examen.md
 *
 * Que hace: carga 5,000 ventas del CSV en un arreglo de structs y ofrece un menu con:
 *   1. calcularSuma(id, anio)        2. calcularPromedio(id, anio)
 *   3. vendedorMayorVentas(anio)     4. vendedorMenorVentas(anio)
 *   5. imprimirDatosVendedor(id)
 *
 * Idea clave de diseño: el valor 0 funciona como COMODIN ('todos'):
 *   id = 0, anio = 0  -> todo el set de datos
 *   id = 0, anio = X  -> todos los vendedores en el anio X
 *   id = Y, anio = 0  -> el vendedor Y en todos los anios
 *   id = Y, anio = X  -> el vendedor Y en el anio X
 * Se implementa con: bool match = (param == 0) || (campo == param);
 *
 * acumularPorVendedor() agrupa las ventas por vendedor (total por id) y es reutilizada
 * por mayor/menor, evitando repetir codigo.
 *
 * Detalles tecnicos: arreglos 'static' para no saturar la pila (5000 elementos),
 * salto del encabezado y de lineas vacias, delimitador ','.
 * Requiere datos2026.csv en la carpeta desde donde se ejecuta.
 *
 * Compilar: g++ proyecto.cpp -o proyecto && ./proyecto
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 5000;

struct Venta {
    int idVendedor;
    string Nombre_vendedor;
    int mesVenta;
    int anioVenta;
    double montoVenta;
};

// Lee y parsea datos2026.csv hacia el arreglo; retorna cantidad de registros cargados.
int leerCSV(Venta ventas[], const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo: " << nombreArchivo << endl;
        return 0;
    }

    string linea;
    getline(archivo, linea); // saltar encabezado

    int count = 0;
    while (getline(archivo, linea) && count < MAX) {
        if (linea.empty()) continue;
        stringstream ss(linea);
        string token;

        getline(ss, token, ','); ventas[count].idVendedor = stoi(token);
        getline(ss, token, ','); ventas[count].Nombre_vendedor = token;
        getline(ss, token, ','); ventas[count].mesVenta = stoi(token);
        getline(ss, token, ','); ventas[count].anioVenta = stoi(token);
        getline(ss, token, ','); ventas[count].montoVenta = stod(token);

        count++;
    }

    archivo.close();
    return count;
}

// Suma de ventas filtrada por idVendedor y/o anio.
// Usar 0 en cualquier parametro significa "todos".
double calcularSuma(Venta ventas[], int n, int idVendedor, int anio) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        bool matchId   = (idVendedor == 0) || (ventas[i].idVendedor == idVendedor);
        bool matchAnio = (anio == 0)        || (ventas[i].anioVenta  == anio);
        if (matchId && matchAnio) {
            suma += ventas[i].montoVenta;
        }
    }
    return suma;
}

// Promedio de ventas filtrado por idVendedor y/o anio.
double calcularPromedio(Venta ventas[], int n, int idVendedor, int anio) {
    double suma = 0;
    int    count = 0;
    for (int i = 0; i < n; i++) {
        bool matchId   = (idVendedor == 0) || (ventas[i].idVendedor == idVendedor);
        bool matchAnio = (anio == 0)        || (ventas[i].anioVenta  == anio);
        if (matchId && matchAnio) {
            suma += ventas[i].montoVenta;
            count++;
        }
    }
    if (count == 0) return 0;
    return suma / count;
}

// Acumula totales por vendedor para el anio dado (0 = todos los anios).
// Llena los arreglos ids, nombres, totales y retorna cuantos vendedores distintos hay.
int acumularPorVendedor(Venta ventas[], int n, int anio,
                        int ids[], string nombres[], double totales[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (anio != 0 && ventas[i].anioVenta != anio) continue;

        bool encontrado = false;
        for (int j = 0; j < count; j++) {
            if (ids[j] == ventas[i].idVendedor) {
                totales[j] += ventas[i].montoVenta;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            ids[count]     = ventas[i].idVendedor;
            nombres[count] = ventas[i].Nombre_vendedor;
            totales[count] = ventas[i].montoVenta;
            count++;
        }
    }
    return count;
}

// Vendedor con MAYORES ventas. anio = 0 considera todos los anios.
void vendedorMayorVentas(Venta ventas[], int n, int anio) {
    static int    ids[MAX];
    static string nombres[MAX];
    static double totales[MAX];

    int count = acumularPorVendedor(ventas, n, anio, ids, nombres, totales);
    if (count == 0) { cout << "Sin datos para ese anio." << endl; return; }

    int maxIdx = 0;
    for (int i = 1; i < count; i++)
        if (totales[i] > totales[maxIdx]) maxIdx = i;

    cout << fixed << setprecision(2);
    cout << "Vendedor con MAYORES ventas";
    if (anio != 0) cout << " en " << anio;
    cout << ":\n"
         << "  ID: "     << ids[maxIdx]
         << " | Nombre: " << nombres[maxIdx]
         << " | Total: "  << totales[maxIdx] << endl;
}

// Vendedor con MENORES ventas. anio = 0 considera todos los anios.
void vendedorMenorVentas(Venta ventas[], int n, int anio) {
    static int    ids[MAX];
    static string nombres[MAX];
    static double totales[MAX];

    int count = acumularPorVendedor(ventas, n, anio, ids, nombres, totales);
    if (count == 0) { cout << "Sin datos para ese anio." << endl; return; }

    int minIdx = 0;
    for (int i = 1; i < count; i++)
        if (totales[i] < totales[minIdx]) minIdx = i;

    cout << fixed << setprecision(2);
    cout << "Vendedor con MENORES ventas";
    if (anio != 0) cout << " en " << anio;
    cout << ":\n"
         << "  ID: "     << ids[minIdx]
         << " | Nombre: " << nombres[minIdx]
         << " | Total: "  << totales[minIdx] << endl;
}

// Imprime ID y Nombre del vendedor indicado.
void imprimirDatosVendedor(Venta ventas[], int n, int idVendedor) {
    for (int i = 0; i < n; i++) {
        if (ventas[i].idVendedor == idVendedor) {
            cout << "ID: " << ventas[i].idVendedor
                 << " | Nombre: " << ventas[i].Nombre_vendedor << endl;
            return;
        }
    }
    cout << "Vendedor con ID " << idVendedor << " no encontrado." << endl;
}

int main() {
    static Venta ventas[MAX];
    int n = leerCSV(ventas, "datos2026.csv");

    if (n == 0) {
        cout << "No se cargaron datos." << endl;
        return 1;
    }

    cout << "Registros cargados: " << n << endl;

    int opcion;
    do {
        cout << "\n========= MENU =========" << endl;
        cout << "1. Suma de ventas" << endl;
        cout << "2. Promedio de ventas" << endl;
        cout << "3. Vendedor con mayores ventas" << endl;
        cout << "4. Vendedor con menores ventas" << endl;
        cout << "5. Datos de un vendedor (ID y Nombre)" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        int id, anio;
        switch (opcion) {
            case 1:

                cout << "ID Vendedor (0 = todos): "; cin >> id;
                cout << "Anio       (0 = todos): "; cin >> anio;
                cout << fixed << setprecision(2);
                cout << "Suma de ventas: " << calcularSuma(ventas, n, id, anio) << endl;
            break;
            case 2:
                cout << "ID Vendedor (0 = todos): "; cin >> id;
                cout << "Anio       (0 = todos): "; cin >> anio;
                cout << fixed << setprecision(2);
                cout << "Promedio de ventas: " << calcularPromedio(ventas, n, id, anio) << endl;
            break;
            case 3:
                cout << "Anio (0 = todos): "; cin >> anio;
                vendedorMayorVentas(ventas, n, anio);
            break;
            case 4:
                cout << "Anio (0 = todos): "; cin >> anio;
                vendedorMenorVentas(ventas, n, anio);
            break;
            case 5:
                cout << "ID Vendedor: "; cin >> id;
                imprimirDatosVendedor(ventas, n, id);
            break;
            default:
                cout << "Opcion no valida" << endl;
        }

    } while (opcion != 0);

    return 0;
}
