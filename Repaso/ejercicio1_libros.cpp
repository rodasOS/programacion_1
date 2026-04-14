/*
    EJERCICIO 1 - PLANTILLA: REGISTRO DE LIBROS
    =============================================
    
    Completa este ejercicio siguiendo los comentarios.
    Algunas partes ya están hechas para ayudarte.
*/

#include<iostream>
using namespace std;

const int totalLibros = 5;

struct Libro {
    int codigo;
    char titulo[50];
    char autor[30];
    int anio;
    float precio;
};

int main() {
    Libro libros[totalLibros];
    int indiceMasAntiguo = 0;
    float precioTotal = 0;
    
    cout << "=== REGISTRO DE LIBROS ===" << endl << endl;
    
    // TODO: Hacer un for para registrar los 5 libros
    // Pedir: codigo, titulo, autor, anio, precio
    // No olvides ir sumando los precios en precioTotal
    
    
    
    // TODO: Hacer un for para mostrar todos los libros
    
    
    
    // TODO: Hacer un for para encontrar el libro más antiguo (menor año)
    // Usa la variable indiceMasAntiguo para guardar la posición
    
    
    
    // TODO: Mostrar el libro más antiguo
    cout << "\n=== LIBRO MAS ANTIGUO ===" << endl;
    // Tu código aquí
    
    
    // TODO: Calcular y mostrar el precio promedio
    cout << "\n=== PRECIO PROMEDIO ===" << endl;
    // Tu código aquí
    
    
    return 0;
}
