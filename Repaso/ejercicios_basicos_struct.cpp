/*
 * REPASO - Calentamiento con structs (por completar): Punto, Rectangulo, Persona, Cancion.
 */

/*
    EJERCICIOS DE CALENTAMIENTO - ESTRUCTURAS BÁSICAS
    ==================================================
    Ejercicios muy simples para familiarizarte con las estructuras
*/

#include<iostream>
using namespace std;

// ==================== EJERCICIO A ====================
// Crea una estructura llamada "Punto" con:
// - int x
// - int y
// Luego crea 2 puntos, asigna valores y muéstralos

// Tu código aquí:



// ==================== EJERCICIO B ====================
// Crea una estructura "Rectangulo" con:
// - float base
// - float altura
// - float area
// Crea 1 rectángulo, pide base y altura, calcula el área y muéstrala

// Tu código aquí:



// ==================== EJERCICIO C ====================
// Crea una estructura "Persona" con:
// - char nombre[30]
// - int edad
// Crea un array de 2 personas, pide los datos y muéstralos

// Tu código aquí:



// ==================== EJERCICIO D ====================
// Crea una estructura "Cancion" con:
// - char titulo[40]
// - char artista[30]
// - int duracion (en segundos)
// Registra 3 canciones y muestra cuál es la más larga

// Tu código aquí:



int main() {
    cout << "=== EJERCICIOS DE CALENTAMIENTO ===" << endl;
    cout << "Descomenta y completa cada ejercicio" << endl;
    
    // Ejemplo básico de cómo usar una estructura:
    struct Ejemplo {
        int numero;
        char letra;
    };
    
    Ejemplo miEjemplo;
    miEjemplo.numero = 42;
    miEjemplo.letra = 'A';
    
    cout << "\nEjemplo:" << endl;
    cout << "Numero: " << miEjemplo.numero << endl;
    cout << "Letra: " << miEjemplo.letra << endl;
    
    return 0;
}
