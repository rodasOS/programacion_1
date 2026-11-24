/*
 * CLASE 8 - Ejercicio 3: mezcla de arreglo, vector por referencia e int por referencia
 * calcular(int arr[], vector<int> &v, int &res):
 *   - res = arr[0] + v[0]  -> 5 + 20 = 25 (se calcula ANTES de modificar).
 *   - arr[0] = 50          -> cambia el original (arreglo).
 *   - v[0] = 100           -> cambia el original (vector por referencia).
 * Salida: 25 50 100.
 *
 * Las declaraciones string prueba[5] y vector<string> pruebaVector solo muestran las
 * dos formas de declarar colecciones; no se usan en el calculo.
 *
 * Compilar: g++ ejercicio3.cpp -o ejercicio3 && ./ejercicio3
 */

#include <iostream>
#include <vector>
using namespace std;

void calcular(int arr[], vector<int> &v, int &res) {
    res = arr[0] + v[0];
    arr[0] = 50;
    v[0] = 100;
}

int main() {
    int a[2] = {5, 10};
    string prueba[5];
    vector<string> pruebaVector;
    vector<int> b = {20, 30};
    int r;

    calcular(a, b, r);

    cout << r << " " << a[0] << " " << b[0] << endl;

    return 0;
}
