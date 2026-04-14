//
// Created by mario on 11/04/2026.
//

/* Ejercicio 1: Conversor de unidades
    Crear funciones sobrecargadas para convertir:
    Celsius -> Fahrenheit
    Fahrenheit -> Celsius
    Metros -> Kilometros
 */

#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

struct Celsius {
    double valor;
};

struct Fahrenheit {
    double valor;
};

struct Metros {
    double valor;
};

double calcular(Celsius celsius) {
    return (celsius.valor * 9.0 / 5.0) + 32.0; // Celsius a Fahrenheit
}

double calcular(Fahrenheit fahrenheit) {
    return (fahrenheit.valor - 32.0) * 5.0 / 9.0; // Fahrenheit a Celsius
}

double calcular(Metros metros) {
    return metros.valor / 1000.0; // Metros a Kilometros
}

int main() {
    SetConsoleOutputCP(65001);
    cout << setprecision(2) << fixed;

    double celsius, fahrenheit, metros;

    // De Celsius a Fahrenheit
    cout << "Ingrese la temperatura en Celsius: ";
    cin >> celsius;
    cout << celsius << " grados Celsius son " << calcular(Celsius{celsius}) << " grados Fahrenheit." << endl;

    // De Fahrenheit a Celsius
    cout << "Ingrese la temperatura en Fahrenheit: ";
    cin >> fahrenheit;
    cout << fahrenheit << " grados Fahrenheit son " << calcular(Fahrenheit{fahrenheit}) << " grados Celsius." << endl;

    // De Metros a Kilometros
    cout << "Ingrese la distancia en metros: ";
    cin >> metros;
    cout << metros << " metros son " << calcular(Metros{metros}) << " kilometros." << endl;

    return 0;
}

