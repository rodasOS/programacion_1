/*
    Crear un programa en c++ que incluya procedimientos necesarios para el ingreso de 3 notas, calcular el 
    promedio y finalmente indicar si el estudiante aprobó o no aprobó el curso, sabiendo que se aprueba con 
    una nota >= 61 puntos
*/

#include<iostream>

using namespace std;

float nota1, nota2, nota3, promedio;

void pedirDatos();
void calcularPromedio();
void mostrarResultado();

int main() {
    cout << "Inicio del programa" << endl;

    pedirDatos();
    calcularPromedio();
    mostrarResultado();

    return 0;
}

void pedirDatos() {
    cout << "Ingrese la nota 1: ";
    cin >> nota1;
    cout << "Ingrese la nota 2: ";
    cin >> nota2;
    cout << "Ingrese la nota 3: ";
    cin >> nota3;
}

void calcularPromedio() {
    promedio = (nota1 + nota2 + nota3) / 3;
}

void mostrarResultado() {
    cout << "El promedio es: " << promedio << endl;
    if (promedio >= 61) {
        cout << "El estudiante aprobo el curso." << endl;
    } else {
        cout << "El estudiante no aprobo el curso." << endl;
    }
}