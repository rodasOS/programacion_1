/*
 * CLASE 3 - Ejercicio 1: arreglo de estructuras (estudiantes)
 * TEMA: vector/arreglo de structs + recorrido con for + estadisticas basicas.
 *
 * Patrones que se repiten en toda la clase (y en los examenes):
 *   1. const int total = N;  -> el tamano se cambia en un solo lugar.
 *   2. Struct[total] global  -> un 'registro' por posicion del arreglo.
 *   3. Ciclo de ingreso que calcula campos derivados (promedio) al leer.
 *   4. 'indiceMayor': guardar la POSICION del mejor, no su valor.
 *   5. Contadores (aprobados / reprobados) dentro del mismo ciclo.
 *
 * Compilar: g++ ejercicio1.cpp -o ejercicio1 && ./ejercicio1
 */

/*
    Desarrollar un programa en c++ que permita registrar  estudiantes y calcular  su promedio final 

    Requisitos:
        - Definir una estructura Estudiante con los siguientes campos:
            - string nombre
            - int carnet
            - float nota1
            - float nota2
            - float nota3
            - float promedio
        - El programa debe:
            1. Permitir registrar 10 estudiantes
            2. Calcular automáticamente el promedio
            3. Mostrar todos los estudiantes 
            4. Mostrar el estudiante con el mayor promedio 
            5. Indicar cuantos aprobaron (promedio >=61) y cuantos reprobaron (promedio < 61)

    Nota: Debe utilizar vectores de tipo estructura estudiante
*/
#include<iostream>

using namespace std;

const int totalEstudiantes = 10; //Cambiar a la cantidad de estudiantes que se quiera manejar 

struct Estudiante {
    char nombre[30];
    int carnet;
    float nota1;
    float nota2;
    float nota3;
    float promedio;
}estudiantes[totalEstudiantes];

int main() {
    int indiceMayorPromedio = 0;
    int aprobados = 0;
    int reprobados = 0;

    for (int i = 0; i < totalEstudiantes; i++) {
        cout << "Ingrese el nombre del estudiante #" << i+1 << ": " << endl;
        cin >> estudiantes[i].nombre;
        cout << "Ingrese el carnet del estudiante: " << endl;
        cin >> estudiantes[i].carnet;
        cout << "Ingrese la nota 1: " << endl;
        cin >> estudiantes[i].nota1;
        cout << "Ingrese la nota 2: " << endl;
        cin >> estudiantes[i].nota2;
        cout << "Ingrese la nota 3: " << endl;
        cin >> estudiantes[i].nota3;

        estudiantes[i].promedio = (estudiantes[i].nota1 + estudiantes[i].nota2 + estudiantes[i].nota3) / 3;

        if (estudiantes[i].promedio > estudiantes[indiceMayorPromedio].promedio) {
            indiceMayorPromedio = i;
        }

        if (estudiantes[i].promedio >= 61) {
            aprobados++;
        } else {
            reprobados++;
        }
    }

    cout << "\nLista de Estudiantes:" << endl;
    for (int i = 0; i < totalEstudiantes; i++) {
        cout << "Nombre: " << estudiantes[i].nombre << ", Carnet: " << estudiantes[i].carnet 
             << ", Promedio: " << estudiantes[i].promedio << endl;
    }

    cout << "\nEstudiante con el mayor promedio:" << endl;
    cout << "Nombre: " << estudiantes[indiceMayorPromedio].nombre 
         << ", Carnet: " << estudiantes[indiceMayorPromedio].carnet 
         << ", Promedio: " << estudiantes[indiceMayorPromedio].promedio << endl;

    cout << "\nTotal de aprobados: " << aprobados << endl;
    cout << "Total de reprobados: " << reprobados << endl;

    return 0;
}