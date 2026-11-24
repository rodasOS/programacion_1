/*
 * REPASO - Ejemplo RESUELTO: modelo para los ejercicios de estructuras.
 * Patron completo: registrar -> mostrar -> maximo por indice -> promedio -> filtrar > promedio.
 * Usalo como guia para resolver ejercicios_basicos_struct.cpp y ejercicio1_libros.cpp.
 */

/*
    EJEMPLO RESUELTO: REGISTRO DE MASCOTAS
    ========================================
    Este es un ejemplo completo para que veas cómo resolver los ejercicios
*/

#include<iostream>
using namespace std;

const int totalMascotas = 3;

struct Mascota {
    char nombre[20];
    char tipo[15];  // Perro, Gato, etc.
    int edad;
    float peso;
};

int main() {
    Mascota mascotas[totalMascotas];
    int indiceMasVieja = 0;
    float pesoTotal = 0;
    
    cout << "=== REGISTRO DE MASCOTAS ===" << endl << endl;
    
    // 1. Registrar las mascotas
    for (int i = 0; i < totalMascotas; i++) {
        cout << "--- Mascota #" << i+1 << " ---" << endl;
        cout << "Nombre: ";
        cin >> mascotas[i].nombre;
        cout << "Tipo (Perro/Gato/etc): ";
        cin >> mascotas[i].tipo;
        cout << "Edad (en años): ";
        cin >> mascotas[i].edad;
        cout << "Peso (en kg): ";
        cin >> mascotas[i].peso;
        cout << endl;
        
        pesoTotal += mascotas[i].peso;
        
        // Buscar la mascota más vieja
        if (mascotas[i].edad > mascotas[indiceMasVieja].edad) {
            indiceMasVieja = i;
        }
    }
    
    // 2. Mostrar todas las mascotas
    cout << "\n=== LISTA DE MASCOTAS REGISTRADAS ===" << endl;
    for (int i = 0; i < totalMascotas; i++) {
        cout << "\nMascota #" << i+1 << endl;
        cout << "Nombre: " << mascotas[i].nombre << endl;
        cout << "Tipo: " << mascotas[i].tipo << endl;
        cout << "Edad: " << mascotas[i].edad << " años" << endl;
        cout << "Peso: " << mascotas[i].peso << " kg" << endl;
    }
    
    // 3. Mostrar la mascota más vieja
    cout << "\n=== MASCOTA MAS VIEJA ===" << endl;
    cout << "Nombre: " << mascotas[indiceMasVieja].nombre << endl;
    cout << "Edad: " << mascotas[indiceMasVieja].edad << " años" << endl;
    
    // 4. Calcular y mostrar peso promedio
    float pesoPromedio = pesoTotal / totalMascotas;
    cout << "\n=== ESTADISTICAS ===" << endl;
    cout << "Peso promedio: " << pesoPromedio << " kg" << endl;
    
    // 5. Mostrar mascotas con peso mayor al promedio
    cout << "\nMascotas con peso mayor al promedio:" << endl;
    for (int i = 0; i < totalMascotas; i++) {
        if (mascotas[i].peso > pesoPromedio) {
            cout << "- " << mascotas[i].nombre << " (" << mascotas[i].peso << " kg)" << endl;
        }
    }
    
    return 0;
}
