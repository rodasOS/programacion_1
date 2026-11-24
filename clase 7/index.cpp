/*
 * CLASE 7 - Paso de parametros por referencia (&)
 * TEMA: diferencia entre paso por valor y paso por referencia con un intercambio (swap).
 *
 * Conceptos:
 *   - sinReferencia(int n1, int n2): trabaja con COPIAS, el intercambio no sale de la funcion.
 *   - intercambio(int &n1, int &n2): '&' hace que n1/n2 sean OTROS NOMBRES de las variables
 *     originales, asi que el intercambio SI se refleja en main.
 *   - Se necesita una variable temporal (temp) para no perder el primer valor.
 *
 * Prueba: el main llama a sinReferencia (valores no cambian). Descomenta intercambio(n1, n2)
 * para ver el cambio real. Llamarlo dos veces vuelve a los valores originales.
 *
 * Compilar: g++ index.cpp -o index && ./index
 */

#include <iostream>
using namespace std;

void intercambio(int &n1, int &n2) {
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void sinReferencia(int n1, int n2) {
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

int main() {
    int n1 = 10, n2 = 20;

    cout<< "Valores iniciales. \n n1 = " << n1 << ", n2 = " << n2 << endl;

    sinReferencia(n1, n2);
    //intercambio(n1, n2);
    //intercambio(n1, n2);

    cout<< "Valores despues del intercambio. \n n1 = " << n1 << ", n2 = " << n2 << endl;

    return 0;
}