/*
 * CLASE 1 - Ciclo while con centinela
 * TEMA: entrada de datos, ciclo while, variables acumuladoras y condicionales.
 *
 * Conceptos:
 *   - Centinela: el ciclo termina cuando el usuario escribe un valor especial (-1).
 *   - Patron 'mayor/menor': se guarda el mejor valor visto hasta el momento.
 *   - Se lee ANTES del while (primera nota) y al FINAL de cada vuelta (siguiente nota).
 *
 * Correccion aplicada: 'menor' empezaba en 0 y nunca se actualizaba (ninguna nota < 0).
 * Ahora empieza en 100 (la nota maxima) y se usan dos 'if' independientes, porque una
 * primera nota puede ser a la vez la mayor y la menor.
 *
 * Compilar: g++ main.cpp -o main && ./main
 */

#include<iostream>

using namespace std;

//progarmaa que solicite notas al usuario hasta llegar a la nota -1
//resultado cual es la nota más alta y cual es la más baja

int main() {
    float nota, mayor = 0, menor = 100; // mayor parte de 0 y menor de 100: los extremos posibles

    cout << "Ingrese la primera nota" << endl;
    cin >> nota;

    while (nota > -1 && nota < 101) { // centinela: -1 (o fuera de 0-100) termina el ciclo
        if (nota > mayor) {
            mayor = nota;
        }
        if (nota < menor) { // 'if' (no 'else if'): una nota puede ser mayor y menor a la vez
            menor = nota;
        } 
        
        cout << "Ingrese la siguiente nota" << endl;
        cin >> nota;
    }
    
    cout << "La nota mayor es: " << mayor << endl;
    cout << "La nota menor es: " << menor << endl;

    return 0;
}
