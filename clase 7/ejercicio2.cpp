/*
 * CLASE 7 - Ejercicio 2: menu con funciones y un arreglo como parametro
 * TEMA: menu do-while + switch, funciones que reciben un arreglo, ordenamiento burbuja.
 *
 * Conceptos:
 *   - Menu: do { ... switch(opcion) ... } while (opcion != 4);  -> se repite hasta Salir.
 *   - Un arreglo se pasa como (int vector[], int size): la funcion modifica el ORIGINAL
 *     (los arreglos se pasan por direccion, no por copia).
 *   - ordenar() = burbuja: compara pares vecinos y los intercambia; cada pasada deja el
 *     mayor al final, por eso el limite interno es size - 1 - i.
 *   - 'hacerTodo' compone otras funciones: ingreso -> ordenar -> imprimir.
 *
 * Este es el modelo de ejercicio que se usa en Ejercicios_Elaborados.md.
 *
 * Compilar: g++ ejercicio2.cpp -o ejercicio2 && ./ejercicio2
 */

/*
    crear un programa que envie como aprametro un verctor de 10 números enteros.
    Crear un menu en el main
        -> Ingreso de datos
        -> Ordenar
        -> imprimir
        -> Salir
    Cada opción debe ser implementada en una función o procedimiento 
*/

#include<iostream>
using namespace std;

void ingresoDatos(int vector[], int size) {
    cout << "Ingrese " << size << " numeros enteros: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> vector[i];
    }
}

void ordenar(int vector[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (vector[j] > vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}

void imprimir(int vector[], int size) {
    cout << "Vector ordenado: " << endl;
    for (int i = 0; i < size; i++) {
        cout << vector[i] << " ";
    }
    cout << endl;
}

void hacerTodo(int vector[], int size) {
    ingresoDatos(vector, size);
    ordenar(vector, size);
    imprimir(vector, size);
}

int main() {
    const int size = 10;
    int vector[size];
    int opcion;

    do { // el menu se repite hasta que se elige la opcion 4 (Salir)
        cout << "Menu: " << endl;
        cout << "1. Ingreso de datos" << endl;
        cout << "2. Ordenar" << endl;
        cout << "3. Imprimir" << endl;
        cout << "4. Salir" << endl;
        cout << "5. HACER TODO LO ANTERIOR" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingresoDatos(vector, size);
                break;
            case 2:
                ordenar(vector, size);
                break;
            case 3:
                imprimir(vector, size);
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            case 5:
                hacerTodo(vector, size);
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}