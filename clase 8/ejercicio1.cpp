/*
 * CLASE 8 - Ejercicio 1: prediccion de salida (arreglo vs vector por valor)
 * modificar(int arr[], vector<int> v) asigna 100 a la posicion 0 de ambos.
 * Resultado: Arreglo: 100 (se modifica) / Vector: 1 (era una copia, no cambia).
 * Pregunta tipica de examen.
 *
 * Compilar: g++ ejercicio1.cpp -o ejercicio1 && ./ejercicio1
 */

#include <iostream>
#include <vector>
using namespace std;

void modificar(int arr[], vector<int> v) {
    arr[0] = 100;
    v[0] = 100;
}

int main() {
    int numeros[3] = {1, 2, 3};
    vector<int> vec = {1, 2, 3};

    modificar(numeros, vec);

    cout << "Arreglo: " << numeros[0] << endl;
    cout << "Vector: " << vec[0] << endl;

    return 0;
}
