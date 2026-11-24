/*
 * CLASE 6 - Repaso 3: varias funciones con retorno
 * TEMA: sumar() y restar() devuelven int; ademas imprimen un mensaje cada vez que se llaman.
 * Cada llamada se ejecuta en el orden en que aparece en main (primero 'Sumando...',
 * luego 'Restando...'), y los resultados se imprimen despues.
 *
 * Compilar: g++ repaso3.cpp -o repaso3 && ./repaso3
 */

#include <iostream>
using namespace std;

int sumar(int a, int b) {
    cout << "Sumando..." << endl;
    return a + b;
}

int restar(int a, int b) {
    cout << "Restando..." << endl;
    return a - b;
}

int main() {
    int suma = sumar(2, 3);
    int resta = restar(10, 5);
    
    cout << suma << endl;
    cout << resta << endl;
    return 0;
}
