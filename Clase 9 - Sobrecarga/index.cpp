/*
 * CLASE 9 - Sobrecarga de funciones: introduccion
 * TEMA: varias funciones con el MISMO nombre y distinta lista de parametros.
 *
 * El compilador elige la version segun la cantidad y el tipo de los argumentos:
 *   suma(10, 20)          -> int suma(int, int)
 *   suma(20.5, 10.3)      -> double suma(double, double)
 *   suma(10, 20, 30)      -> int suma(int, int, int)
 *
 * Regla de oro: el tipo de retorno NO distingue sobrecargas.
 *
 * Compilar: g++ index.cpp -o index && ./index
 */

#include <iostream>
#include <iomanip>
using namespace std;

int suma(int num1, int num2) {
    return num1 + num2;
}

double suma(double num1, double num2) {

    return num1 + num2;
}

int suma(int num1, int num2, int num3) {
    return num1 + num2 + num3;
}

int main() {
    //cout << fixed <<  setprecision(2);

    // Primera función (int, int)
    cout << suma(10, 20) << endl;

    // Segunda Función
    cout << suma(20.512341, 10.312312) << endl;

    // Tercera función
    cout << suma(10, 20, 30) << endl;
    return 0;
}