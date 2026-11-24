/*
 * CLASE 6 - Repaso 2: concatenar texto y numero
 * TEMA: string + string + to_string(numero). Un int no se puede sumar directo a un string;
 * hay que convertirlo con to_string(). Salida: HolaMundo5
 *
 * Compilar: g++ repaso2.cpp -o repaso2 && ./repaso2
 */

#include <iostream>
using namespace std;

string unir(string a, string b) {
    return a + b + to_string(5);
}

int main() {
    cout << unir("Hola", "Mundo") << endl;
    return 0;
}
