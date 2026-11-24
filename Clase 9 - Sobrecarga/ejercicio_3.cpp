/*
 * CLASE 9 - Ejercicio 3 (nota): calculadora sobrecargada
 * TEMA: sumar/restar/multiplicar/dividir con version int y version double.
 *
 * Detalles importantes:
 *   - dividir(int, int) devuelve double para no perder los decimales (static_cast<double>).
 *   - Validacion de division entre cero con if (b == 0).
 *   - fixed + setprecision(2) (de <iomanip>) fijan 2 decimales al imprimir.
 *
 * Compilar: g++ ejercicio_3.cpp -o ejercicio_3 && ./ejercicio_3
 */

/*
 * Calculadora avanzada
 * Crear funciones sobrecarcadas para:
 *  Sumar
 *  Restar
 *  Multiplicar
 *  Dividir
 *  Con:
 *      enteros
 *      decimales
 */

#include <iostream>
#include <iomanip>

using namespace std;

// Operaciones con enteros
int sumar(int a, int b) {
	return a + b;
}

int restar(int a, int b) {
	return a - b;
}

int multiplicar(int a, int b) {
	return a * b;
}

double dividir(int a, int b) {
	if (b == 0) {
		cout << "Error: no se puede dividir entre 0 (enteros)." << endl;
		return 0;
	}
	return static_cast<double>(a) / b;
}

// Operaciones con decimales
double sumar(double a, double b) {
	return a + b;
}

double restar(double a, double b) {
	return a - b;
}

double multiplicar(double a, double b) {
	return a * b;
}

double dividir(double a, double b) {
	if (b == 0.0) {
		cout << "Error: no se puede dividir entre 0.0 (decimales)." << endl;
		return 0;
	}
	return a / b;
}

int main() {
	int aEntero, bEntero;
	double aDecimal, bDecimal;

	cout << "=== Calculadora Avanzada (Sobrecarga) ===" << endl;

	cout << "\nIngrese dos numeros enteros: ";
	cin >> aEntero >> bEntero;

	cout << "\nResultados con enteros:" << endl;
	cout << "Suma: " << sumar(aEntero, bEntero) << endl;
	cout << "Resta: " << restar(aEntero, bEntero) << endl;
	cout << "Multiplicacion: " << multiplicar(aEntero, bEntero) << endl;
	cout << "Division: " << dividir(aEntero, bEntero) << endl;

	cout << "\nIngrese dos numeros decimales: ";
	cin >> aDecimal >> bDecimal;

	cout << fixed << setprecision(2);
	cout << "\nResultados con decimales:" << endl;
	cout << "Suma: " << sumar(aDecimal, bDecimal) << endl;
	cout << "Resta: " << restar(aDecimal, bDecimal) << endl;
	cout << "Multiplicacion: " << multiplicar(aDecimal, bDecimal) << endl;
	cout << "Division: " << dividir(aDecimal, bDecimal) << endl;

	return 0;
}