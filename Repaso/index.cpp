/*
 * REPASO - Struct con valores por defecto e inicializacion con llaves
 * TEMA: campos con valor por defecto (nombre = "X") y inicializacion en orden:
 * Estudiante e = { "Mario", "Sales", 19, "12345" };
 * Notese que 'nombre' es string (C++) y 'apellido'/'carne' son char[] (estilo C).
 *
 * Compilar: g++ -std=c++17 index.cpp -o index && ./index
 */

#include<iostream>

using namespace std;

struct Estudiante {
    string nombre = "X";
    char apellido[10] = "X";
    int edad;
    char carne[6];
};

int main() {
    Estudiante primerEstudiante = {
        "Mario",
        "Sales",
        19,
        "12345"
    };

    cout<<primerEstudiante.nombre<<endl;
    cout<<primerEstudiante.apellido<<endl;
    cout<<primerEstudiante.edad<<endl;
    cout << "Hola Mundo!" << endl;
    return 0;
}