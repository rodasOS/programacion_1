//
// Created by mario on 11/04/2026.
//

#include <iostream>
#include <windows.h>
using namespace std;

int area(int lado) {
  return lado * lado;
}

int area(int base, int altura) {
    return base * altura;
}

double area(double base, double altura) {
    return (base * altura) / 2.0;
}

int main() {
    //setlocale(LC_ALL, "Spanish");
    SetConsoleOutputCP(65001);

    cout << "Área cuadrada " << area(4) << endl;
    cout << "Área rectángulo " << area(4, 5) << endl;
    cout << "Área triángulo" << area(4.0, 5.0) << endl;
}