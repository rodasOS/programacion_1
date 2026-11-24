/*
 * CLASE 3 - Ejercicio 2: inventario de productos
 * TEMA: arreglo de structs, acumulador de totales y filtrado por condicion.
 *
 * Patrones:
 *   - Acumulador: valorTotalInventario += precio * cantidad dentro del ciclo.
 *   - Maximo por indice: indiceProductoMasCaro.
 *   - Filtro: un segundo for que imprime solo los productos con cantidad < 5.
 *
 * Compilar: g++ ejercicio2.cpp -o ejercicio2 && ./ejercicio2
 */

/*
    Crear un sistema básico de inventario utilizando estructuras en C++

    Requisitos:
    - Definir la estructura Producto con los siguientes campos:
        - int codigo
        - string nombre
        - float precio
        - int cantidad
        - float valorTotal
    - El programa debe:
    1. Permitir registrar 10 productos
    2. Calcular automáticamente el valor total (precio * cantidad)
    3. Mostrar el producto más caro 
    4. Mostrar el valor total general del inventario
    5. Mostrar productos con cantidad menor a 5

    Nota: Debe utilizar vectores de tipo estructura producto
*/

#include<iostream>

using namespace std;

const int totalProductos = 10; // Cambiar a la cantidad desea de productos

struct Producto {
    int codigo;
    char nombre[30];
    float precio;
    int cantidad;
    float valorTotal;
}productos[totalProductos];

int main() {
    float valorTotalInventario = 0;
    int indiceProductoMasCaro = 0;

    for (int i = 0; i < totalProductos; i++) {
        cout << "Ingrese el codigo del producto " << i+1 << ": " << endl;
        cin >> productos[i].codigo;
        cout << "Ingrese el nombre del producto: " << endl;
        cin >> productos[i].nombre;
        cout << "Ingrese el precio del producto: " << endl;
        cin >> productos[i].precio;
        cout << "Ingrese la cantidad del producto: " << endl;
        cin >> productos[i].cantidad;

        productos[i].valorTotal = productos[i].precio * productos[i].cantidad;
        valorTotalInventario += productos[i].valorTotal;

        if (productos[i].precio > productos[indiceProductoMasCaro].precio) {
            indiceProductoMasCaro = i;
        }
    }

    cout << "\nProducto mas caro:" << endl;
    cout << "Codigo: " << productos[indiceProductoMasCaro].codigo << endl;
    cout << "Nombre: " << productos[indiceProductoMasCaro].nombre << endl;
    cout << "Precio: " << productos[indiceProductoMasCaro].precio << endl;

    cout << "\nValor total del inventario: Q" << valorTotalInventario << endl;

    cout << "\nProductos con cantidad menor a 5:" << endl;
    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].cantidad < 5) {
            cout << "Codigo: " << productos[i].codigo << ", Nombre: " << productos[i].nombre 
                 << ", Cantidad: " << productos[i].cantidad << endl;
        }
    }

    return 0;
}