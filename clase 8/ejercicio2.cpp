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
