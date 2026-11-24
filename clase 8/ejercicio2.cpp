/*
 * CLASE 8 - Ejercicio 2: login con contador por referencia
 * TEMA: int &intentos permite que login() modifique el contador de main
 * (mejora sobre clase 6/prueba.cpp, que usaba una variable global).
 * Resultado: 'Intentos fallidos: 5' (5 de las 6 llamadas fallan).
 *
 * Compilar: g++ ejercicio2.cpp -o ejercicio2 && ./ejercicio2
 */

#include <iostream>
using namespace std;

void login(string usuario, string password, int &intentos) {
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
    int intentos = 0;

    login("admin", "0000", intentos);
    login("admin", "0000", intentos);
    login("admin", "0000", intentos);
    login("admin", "0000", intentos);
    login("user", "1234", intentos);
    login("admin", "1234", intentos);

    cout << "Intentos fallidos: " << intentos << endl;

    return 0;
}
