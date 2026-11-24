/*
 * CLASE 3 - Ejercicio 3: control de parqueo
 * TEMA: mismo esquema que los ejercicios 1 y 2 con otro dominio (vehiculos).
 *
 * Patrones:
 *   - Campo calculado: totalPagar = horas * 10 (tarifa fija de Q10 por hora).
 *   - Acumulador de dinero (totalRecaudado) y maximo por indice (el que mas pago).
 *   - Filtro por anio de modelo (< 2015).
 *
 * Compilar: g++ ejercicio3.cpp -o ejercicio3 && ./ejercicio3
 */

/*
    Desarrolle un programa en c++ que administre la información de vehículos  en un parqueo.

    Requisitos:
     - Definir una estructura Vehículo con los siguientes campos:
        - string placa
        - string marca
        - int modelo
        - string propietario
        - float horas
        - float totalPagar
    - El programa debe:
        1. Permitir registrar 20 vehículos
        2. Cobrar Q10 por hora 
        3. Calcular automáticamente el total a pagar
        4. Mostrar el vehículo que más pagó
        5. Mostrar el total recaudado
        6. Mostrar vehículos modelo menor a 2015

    Nota: Debe utilizar vectores de tipo estructura vehículo
*/

#include<iostream>

using namespace std;

const int totalVehiculos = 20; // Cambiar a la cantidad de vehículos que se quiera manejar

struct Vehiculo {
    char placa[10];
    char marca[20];
    int modelo;
    char propietario[30];
    float horas;
    float totalPagar;
}vehiculos[totalVehiculos];


int main() {
    float totalRecaudado = 0;
    int indiceMayorPago = 0;

    for (int i = 0; i < totalVehiculos; i++) {
        cout << "Ingrese la placa del vehiculo #" << i+1 << ": " << endl;
        cin >> vehiculos[i].placa;
        cout << "Ingrese la marca del vehiculo: " << endl;
        cin >> vehiculos[i].marca;
        cout << "Ingrese el modelo del vehiculo: " << endl;
        cin >> vehiculos[i].modelo;
        cout << "Ingrese el nombre del propietario: " << endl;
        cin >> vehiculos[i].propietario;
        cout << "Ingrese las horas de parqueo: " << endl;
        cin >> vehiculos[i].horas;

        vehiculos[i].totalPagar = vehiculos[i].horas * 10; // Q10 por hora
        totalRecaudado += vehiculos[i].totalPagar;

        if (vehiculos[i].totalPagar > vehiculos[indiceMayorPago].totalPagar) {
            indiceMayorPago = i;
        }
    }

    cout << "\nVehiculo que mas pago:" << endl;
    cout << "Placa: " << vehiculos[indiceMayorPago].placa << endl;
    cout << "Marca: " << vehiculos[indiceMayorPago].marca << endl;
    cout << "Modelo: " << vehiculos[indiceMayorPago].modelo << endl;
    cout << "Propietario: " << vehiculos[indiceMayorPago].propietario << endl;
    cout << "Horas: " << vehiculos[indiceMayorPago].horas << endl;
    cout << "Total a Pagar: Q" << vehiculos[indiceMayorPago].totalPagar << endl;

    cout << "\nTotal Recaudado: Q" << totalRecaudado << endl;

    cout << "\nVehiculos modelo menor a 2015:" << endl;
    for (int i = 0; i < totalVehiculos; i++) {
        if (vehiculos[i].modelo < 2015) {
            cout << "Placa: " << vehiculos[i].placa << ", Marca: " << vehiculos[i].marca 
                 << ", Modelo: " << vehiculos[i].modelo 
                 << ", Propietario: " << vehiculos[i].propietario 
                 << ", Horas: " << vehiculos[i].horas << endl;
        }
    }

    return 0;
}