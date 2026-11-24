/*
 * CLASE 6 - Repaso 4: variable static dentro de una funcion
 * TEMA: 'static int x = 0' se inicializa UNA sola vez y conserva su valor entre llamadas.
 * Salida: 1, 2, 3. Sin 'static' imprimiria 1, 1, 1 (la variable local se recrea).
 *
 * Compilar: g++ repaso4.cpp -o repaso4 && ./repaso4
 */

#include <iostream>
using namespace std;

int contador() {
    static int x = 0;
    x++;
    return x;
}

int main() {
    cout << contador() << endl;
    cout << contador() << endl;
    cout << contador() << endl;
    return 0;
}
