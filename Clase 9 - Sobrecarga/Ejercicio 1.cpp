/*
 * CLASE 9 - Ejercicio 1 (nota): sobrecarga con structs
 * TEMA: como Celsius y Fahrenheit son ambos 'un double', se envuelven en structs distintos
 * para que calcular() pueda sobrecargarse por TIPO de struct.
 *
 *   calcular(Celsius)     -> Fahrenheit
 *   calcular(Fahrenheit)  -> Celsius
 *   calcular(Metros)      -> Kilometros
 *
 * Se construyen con llaves: calcular(Celsius{valor}).
 * <windows.h> y SetConsoleOutputCP solo existen en Windows; se protegieron con #ifdef _WIN32
 * para que el archivo tambien compile en Linux/macOS.
 *
 * Compilar: g++ "Ejercicio 1.cpp" -o ejercicio1 && ./ejercicio1
 */

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
#ifdef _WIN32
#include <windows.h> // solo Windows: permite imprimir acentos en la consola
#endif
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
#ifdef _WIN32
    SetConsoleOutputCP(65001); // UTF-8 en la consola de Windows
#endif
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

