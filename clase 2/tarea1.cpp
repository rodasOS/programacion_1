/*
 * CLASE 2 - Tarea 1: estructuras anidadas
 * TEMA: un struct dentro de otro struct (Cliente contiene un Auto).
 *
 * Conceptos:
 *   - Acceso encadenado: cliente1.autoAdquirido.marca  (variable . campo . subcampo).
 *   - Todos los datos se piden con cin >> sobre arreglos char: NO admiten espacios.
 *     (para nombres compuestos usar cin.getline como en main.cpp de esta clase).
 *
 * Compilar: g++ tarea1.cpp -o tarea1 && ./tarea1
 */

//Realizar un programa utilziando estructuras el cual debe mostrar en pantalla los datos de
//un cliente y  un vehículo que adquirió, estos valores deben ingresarse desde el teclado.
#include<iostream>

using namespace std;

struct Auto {
    char marca[20];
    int numSerie;
    char placa[10];
};

struct Cliente {
    char nombre[30];
    char apellido[30];
    char nacionalidad[20];
    int edad;
    Auto autoAdquirido; // struct anidado: un Cliente 'tiene un' Auto
}cliente1;

int main() {
    cout << "Ingrese el nombre del cliente: " << endl;
    cin >> cliente1.nombre;
    cout << "Ingrese el apellido del cliente: " << endl;
    cin >> cliente1.apellido;
    cout << "Ingrese la nacionalidad del cliente: " << endl;
    cin >> cliente1.nacionalidad;
    cout << "Ingrese la edad del cliente: " << endl;
    cin >> cliente1.edad;
    cout << "Ingrese la marca del auto adquirido: " << endl;
    cin >> cliente1.autoAdquirido.marca;
    cout << "Ingrese el numero de serie del auto adquirido: " << endl;
    cin >> cliente1.autoAdquirido.numSerie;
    cout << "Ingrese la placa del auto adquirido: " << endl;
    cin >> cliente1.autoAdquirido.placa;

    cout << "\nDatos del Cliente:" << endl;
    cout << "Nombre: " << cliente1.nombre << endl;
    cout << "Apellido: " << cliente1.apellido << endl;
    cout << "Nacionalidad: " << cliente1.nacionalidad << endl;
    cout << "Edad: " << cliente1.edad << endl;
    cout << "Auto Adquirido: " << cliente1.autoAdquirido.marca << endl;
    cout << "Numero de Serie: " << cliente1.autoAdquirido.numSerie << endl;
    cout << "Placa: " << cliente1.autoAdquirido.placa << endl;

    return 0;
}