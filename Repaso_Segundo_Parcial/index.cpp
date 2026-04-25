#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const int MAX = 100;

struct Venta {
    int id;
    string nombre;
    int mes;
    int anio;
    double monto;
};

int leerCSV(Venta ventas[], const string& nombreArchivo) {
    ifstream archivo;
    archivo.open(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo: " << nombreArchivo << endl;
        return 0;
    }

    string linea;
    getline(archivo, linea); // saltar encabezados

    int count = 0;
    while (getline(archivo, linea) && count < MAX) {
        stringstream ss(linea);
        string token;

        getline(ss, token, ';'); ventas[count].id     = stoi(token);
        getline(ss, token, ';'); ventas[count].nombre = token;
        getline(ss, token, ';'); ventas[count].mes    = stoi(token);
        getline(ss, token, ';'); ventas[count].anio   = stoi(token);
        getline(ss, token, ';'); ventas[count].monto  = stod(token);

        count++;
    }

    archivo.close();
    return count;
}

void imprimirDatos(Venta ventas[], int n) {
    cout << "\n=== Datos cargados ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "ID: " << ventas[i].id
             << " | Nombre: " << ventas[i].nombre
             << " | Mes: " << ventas[i].mes
             << " | Anio: " << ventas[i].anio
             << " | Monto: " << ventas[i].monto << endl;
    }
}

void quienVendioMas(Venta ventas[], int n) {
    if (n == 0) return;
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (ventas[i].monto > ventas[maxIdx].monto)
            maxIdx = i;
    }
    cout << "\n=== Quien vendio mas ===" << endl;
    cout << "Nombre: " << ventas[maxIdx].nombre
         << " | Monto: " << ventas[maxIdx].monto << endl;
}

void totalPorMesAnio(Venta ventas[], int n) {
    // Guarda meses/anios únicos ya procesados
    int meses[MAX], anios[MAX];
    int procesados = 0;

    cout << "\n=== Total de ventas por mes/anio ===" << endl;
    for (int i = 0; i < n; i++) {
        // Verificar si ya se procesó este mes/anio
        bool yaVisto = false;
        for (int j = 0; j < procesados; j++) {
            if (meses[j] == ventas[i].mes && anios[j] == ventas[i].anio) {
                yaVisto = true;
                break;
            }
        }
        if (yaVisto) continue;

        // Sumar todos los montos de ese mes/anio
        double total = 0;
        for (int k = 0; k < n; k++) {
            if (ventas[k].mes == ventas[i].mes && ventas[k].anio == ventas[i].anio)
                total += ventas[k].monto;
        }

        cout << "Mes: " << ventas[i].mes
             << " | Anio: " << ventas[i].anio
             << " | Total: " << total << endl;

        meses[procesados] = ventas[i].mes;
        anios[procesados] = ventas[i].anio;
        procesados++;
    }
}

void montoPromedio(Venta ventas[], int n) {
    if (n == 0) return;
    double suma = 0;
    for (int i = 0; i < n; i++)
        suma += ventas[i].monto;
    cout << "\n=== Monto promedio ===" << endl;
    cout << "Promedio: " << suma / n << endl;
}

void rankingVendedores(Venta ventas[], int n) {
    // Acumular montos por nombre
    string nombres[MAX];
    double totales[MAX];
    int count = 0;

    for (int i = 0; i < n; i++) {
        bool encontrado = false;
        for (int j = 0; j < count; j++) {
            if (nombres[j] == ventas[i].nombre) {
                totales[j] += ventas[i].monto;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            nombres[count] = ventas[i].nombre;
            totales[count] = ventas[i].monto;
            count++;
        }
    }

    // Ordenar por monto (burbuja descendente)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (totales[j] < totales[j + 1]) {
                double tmpD = totales[j]; totales[j] = totales[j+1]; totales[j+1] = tmpD;
                string tmpS = nombres[j]; nombres[j] = nombres[j+1]; nombres[j+1] = tmpS;
            }
        }
    }

    cout << "\n=== Ranking de vendedores ===" << endl;
    for (int i = 0; i < count; i++) {
        cout << (i + 1) << ". " << nombres[i]
             << " | Total: " << totales[i] << endl;
    }
}

int main() {
    Venta ventas[MAX];
    int n = leerCSV(ventas, "ventas.csv");

    if (n == 0) {
        cout << "No se cargaron datos." << endl;
        return 1;
    }

    cout << "Registros cargados: " << n << endl;

    imprimirDatos(ventas, n);
    quienVendioMas(ventas, n);
    totalPorMesAnio(ventas, n);
    montoPromedio(ventas, n);
    rankingVendedores(ventas, n);

    return 0;
}