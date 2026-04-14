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
    int incremento = 10;
    total = num1 + num2 + incremento;
}

void mostrar(){
    cout << "El resultado es: " << total << endl;
}