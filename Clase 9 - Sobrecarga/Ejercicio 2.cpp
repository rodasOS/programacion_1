/*
 * CLASE 9 - Ejercicio 2 (nota): sobrecarga con arreglos
 * TEMA: sumar() y promedio() sobrecargadas para int[] y double[].
 *
 * Conceptos:
 *   - 'const' en el arreglo: la funcion promete no modificarlo.
 *   - Un arreglo pasado a una funcion pierde su tamano -> se envia 'tam' aparte.
 *   - static_cast<double>(...) evita la division entera (promedio de ints).
 *   - Tamano de un arreglo en el sitio donde se declara:
 *       sizeof(arr) / sizeof(arr[0])   -> bytes totales / bytes de un elemento
 *       std::size(arr)                 -> ya devuelve la CANTIDAD de elementos (C++17)
 *
 * Correccion aplicada: tamEnteros usaba size(enteros) / sizeof(enteros[0]); como size()
 * ya da la cantidad (5), dividir otra vez entre 4 daba 1 y la suma/promedio salian mal.
 *
 * Compilar: g++ -std=c++17 "Ejercicio 2.cpp" -o ejercicio2 && ./ejercicio2
 */

//
// Created by mario on 11/04/2026.
//

/*
 * Manejo de arreglos.
 * Crear funciones sobrecargadas para:
 *  Sumar un arreglo de enteros
 *  Sumar un arreglo de decimales
 *  Encontrar promedio
 */

#include <iostream>
#include <iomanip>

using namespace std;

int sumar(const int arreglo[], int tam) {
	int suma = 0;
	for (int i = 0; i < tam; i++) {
		suma += arreglo[i];
	}
	return suma;
}

double sumar(const double arreglo[], int tam) {
	double suma = 0.0;
	for (int i = 0; i < tam; i++) {
		suma += arreglo[i];
	}
	return suma;
}

double promedio(const int arreglo[], int tam) {
	if (tam == 0) return 0.0;
	return static_cast<double>(sumar(arreglo, tam)) / tam;
}

double promedio(const double arreglo[], int tam) {
	if (tam == 0) return 0.0;
	return sumar(arreglo, tam) / tam;
}

int main() {
	int enteros[] = {5, 10, 15, 20, 25};
	double decimales[] = {1.5, 2.75, 3.25, 4.0, 5.5};

	int tamEnteros = size(enteros); // std::size ya devuelve la cantidad de elementos
	int tamDecimales = sizeof(decimales) / sizeof(decimales[0]);

	cout << "Sizeof: "<< sizeof(enteros) << " bytes" << endl;
	cout << "Size: "<< size(enteros) << " elementos" << endl;

	cout << "Arreglo de enteros:" << endl;
	    cout << "Suma: " << sumar(enteros, tamEnteros) << endl;
	cout << "Promedio: " << fixed << setprecision(2)
		 << promedio(enteros, tamEnteros) << endl;

	cout << "\nArreglo de decimales:" << endl;
	cout << "Suma: " << fixed << setprecision(2)
		    << sumar(decimales, tamDecimales) << endl;
	cout << "Promedio: " << fixed << setprecision(2)
		 << promedio(decimales, tamDecimales) << endl;

	return 0;
}