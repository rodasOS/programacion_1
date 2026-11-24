/*
 * CLASE 6 - Repaso 1: return con string
 * TEMA: funcion que devuelve un string armado con concatenacion (+) y to_string().
 *
 * Trampa de examen: todo lo que esta DESPUES de un return NO se ejecuta. El
 * cout << "pepe" de crearSaludo() es codigo inalcanzable y nunca se imprime.
 *
 * Compilar: g++ repaso.cpp -o repaso && ./repaso
 */

#include <iostream>

using namespace std;

string crearSaludo(string nombre, int edad) {
    return "Hola que tal, " + nombre + " tu edad es: " + to_string(edad);
    cout<<"pepe";
}

int main() {

    string saludoWicho = crearSaludo("Wicho", 80);
    string saludoPepe = crearSaludo("Pepe", 60);

    cout<<saludoWicho<<endl;
    cout<<saludoPepe<<endl;
    cout<<crearSaludo("Aña", 10)<<endl;
    cout<<crearSaludo("Girasol", 15)<<endl;
    
    return 0;
}