#include <iostream>
#include <vector>
using namespace std;

// 🔹 Arreglo clásico (se pasa como referencia automáticamente)
void modificarArreglo(int arr[], int tamano) {
    for (int i = 0; i < tamano; i++) {
        arr[i] *= 2;
    }
}

// 🔹 Vector por valor (NO modifica el original)
void modificarVectorValor(vector<int> v) {
    int n = static_cast<int>(v.size());
    for (int i = 0; i < n; i++) {
        v[i] *= 2;
    }

    cout << "Dentro de modificarVectorValor: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// 🔹 Vector por referencia (SÍ modifica el original)
void modificarVectorReferencia(vector<int> &v) {
    int n = static_cast<int>(v.size());
    for (int i = 0; i < n; i++) {
        v[i] *= 2;
    }
}

int main() {
    // 🔸 Arreglo clásico
    int arreglo[5] = {1, 2, 3, 4, 5};

    // 🔸 Vector
    vector<int> numeros = {1, 2, 3, 4, 5};

    cout << "Original arreglo: ";
    for (int i = 0; i < 5; i++) {
        cout << arreglo[i] << " ";
    }

    cout << "\nOriginal vector: ";
    int cantidadNumeros = static_cast<int>(numeros.size());
    for (int i = 0; i < cantidadNumeros; i++) {
        cout << numeros[i] << " ";
    }

    cout << "\n\n--- Modificando ---\n";

    modificarArreglo(arreglo, 5);
    modificarVectorValor(numeros);
    modificarVectorReferencia(numeros);

    cout << "\n--- Resultados finales ---\n";

    cout << "Arreglo: ";
    for (int i = 0; i < 5; i++) {
        cout << arreglo[i] << " ";
    }

    cout << "\nVector: ";
    for (int i = 0; i < cantidadNumeros; i++) {
        cout << numeros[i] << " ";
    }

    return 0;
}
