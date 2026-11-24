/*
 * CLASE 4 - Procedimientos (funciones void)
 * TEMA: dividir un programa en procedimientos que no devuelven valor.
 *
 * Conceptos:
 *   - Prototipo: la declaracion 'void pedirDatos();' antes del main permite definir
 *     la funcion DESPUES del main.
 *   - Variables globales (num1, num2, total) comparten datos entre procedimientos.
 *   - Variable local (incremento) solo existe dentro de su funcion.
 *   - El main queda como 'indice' del programa: pedir -> procesar -> mostrar.
 *
 * Compilar: g++ index.cpp -o index && ./index
 */

#include <iostream>

using namespace std;

int num1 = 0, num2 = 0, total= 0;

void pedirDatos();
void sumar();
void mostrar();

int main() {
    cout << "Inicio del programa" << endl;

    pedirDatos();
    sumar();
    mostrar();
    return 0;
}

void pedirDatos() {
    cout << "Ingrese el numero 1: ";
    cin >> num1;
    cout << "Ingrese el numero 2: ";
    cin >> num2;
}

void sumar() {
    int incremento = 10; // variable local: desaparece al terminar sumar()
    total = num1 + num2 + incremento;
}

void mostrar(){
    cout << "El resultado es: " << total << endl;
}