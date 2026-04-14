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