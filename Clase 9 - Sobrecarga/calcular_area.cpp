/*
 * CLASE 9 - Sobrecarga: area de figuras
 * TEMA: sobrecarga por cantidad de parametros (1 vs 2) y por tipo (int vs double).
 *
 *   area(int lado)               -> cuadrado   (lado * lado)
 *   area(int base, int altura)   -> rectangulo (base * altura)
 *   area(double b, double h)     -> triangulo  (b * h / 2)
 *
 * Trampa: area(4, 5) usa la version int (rectangulo) y area(4.0, 5.0) la de double
 * (triangulo): la MISMA forma de llamar da resultados distintos segun el TIPO.
 *
 * Compilar: g++ calcular_area.cpp -o calcular_area && ./calcular_area
 */

//
// Created by mario on 11/04/2026.
//

#include <iostream>
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
    int lado;
    cout<< "Ingrese lado";
    cin >> lado;

    cout << "Área cuadrada " << area(lado) << endl;
    cout << "Área rectángulo " << area(4, 5) << endl;
    cout << "Área triángulo" << area(4.0, 5.0) << endl;
}