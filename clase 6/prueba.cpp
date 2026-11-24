/*
 * CLASE 6 - Practica: login con contador GLOBAL
 * TEMA: parametros por valor + variable global como contador de intentos fallidos.
 *
 * Observacion: como login() no puede modificar variables de main por valor, el contador
 * tuvo que ser global. En clase 8 (ejercicio2.cpp) se reescribe con paso por referencia
 * (int &intentos), que es la forma recomendada.
 *
 * Compilar: g++ prueba.cpp -o prueba && ./prueba
 */

#include <iostream>
using namespace std;

int intentos = 0;

void login(string usuario, string password) {
    string userCorrecto = "admin";
    string passCorrecto = "1234";

    if (usuario == userCorrecto && password == passCorrecto) {
        cout << "Login exitoso\n";
    } else {
        cout << "Credenciales incorrectas\n";
        intentos++;
    }
}

int main() {
    login("admin", "0000");
    login("admin", "0000");
    login("admin", "0000");
    login("admin", "0000");
    login("user", "1234");
    login("admin", "1234");

    cout << "Intentos fallidos: " << intentos << endl;

    return 0;
}
