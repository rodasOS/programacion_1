/*
 * CLASE 2 - Estructuras (struct) - introduccion
 * TEMA: definir un struct, declarar una variable de ese tipo y acceder a sus campos con '.'.
 *
 * Conceptos:
 *   - struct agrupa datos de distinto tipo bajo un solo nombre (marca + numSerie).
 *   - 'auto1' se declara justo despues de la llave: es una variable global del tipo Auto.
 *   - char marca[20] es una cadena estilo C: guarda maximo 19 letras + el '\0' final.
 *   - cin >> lee solo hasta el primer espacio; cin.getline(destino, tam, '\n') lee la linea
 *     completa, incluyendo espacios (ej. "Toyota Corolla").
 *
 * Compilar: g++ main.cpp -o main && ./main
 */

#include<iostream>

using namespace std;

struct Auto {
    char marca[20];
    int numSerie;
}
auto1;


int main() {
    cout << "Ingresar la marca del auto: "<<endl;
    // cin >> auto1.marca;   <- solo leeria la primera palabra
    // getline lee hasta 20 caracteres o hasta el salto de linea:
    cin.getline(auto1.marca, 20, '\n');
    cout << "Ingresar el numero de serie del auto: "<<endl;
    cin >> auto1.numSerie;
    cout << "La marca del auto es: " << auto1.marca << endl;
    cout << "El numero de serie del auto es: " << auto1.numSerie << endl;
    return 0;
}