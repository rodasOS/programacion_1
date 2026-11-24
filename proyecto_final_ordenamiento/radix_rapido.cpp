/*
 * Radix Sort aislado (version didactica con nombres largos). Ver proyecto_final.cpp
 * para la version integrada al menu y RESULTADOS.md para la comparacion de tiempos.
 */

// Solo el algoritmo Radix Sort (sin generacion de numeros)
// Compilar: g++ -std=c++11 radix_rapido.cpp -o radix_rapido
#include <chrono>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

// Radix Sort LSD base 256: ordena byte por byte (4 pasadas). Soporta negativos.
void radixSort(vector<int> &numeros) {
    auto tiempoInicio = chrono::steady_clock::now();

    size_t cantidad = numeros.size();
    vector<uint32_t> origen(cantidad), destino(cantidad);

    // Invertir el bit de signo hace que los negativos queden antes que los positivos
    for (size_t i = 0; i < cantidad; i++)
        origen[i] = (uint32_t)numeros[i] ^ 0x80000000u;

    // conteo[byte][valor] = cuantos numeros tienen ese valor (0-255) en ese byte
    size_t conteo[4][256] = {};
    for (size_t i = 0; i < cantidad; i++)
        for (int byte = 0; byte < 4; byte++)
            conteo[byte][(origen[i] >> (8 * byte)) & 255]++;

    for (int byte = 0; byte < 4; byte++) {
        // Si todos los numeros tienen el mismo valor en este byte, la pasada no cambia nada
        if (conteo[byte][(origen[0] >> (8 * byte)) & 255] == cantidad) continue;

        // Convertir los conteos en posiciones de inicio de cada grupo
        size_t posicion = 0;
        for (int valor = 0; valor < 256; valor++) {
            size_t cuantos = conteo[byte][valor];
            conteo[byte][valor] = posicion;
            posicion += cuantos;
        }

        // Colocar cada numero en su grupo segun el valor de este byte
        for (size_t i = 0; i < cantidad; i++) {
            int valorDelByte = (origen[i] >> (8 * byte)) & 255;
            destino[conteo[byte][valorDelByte]++] = origen[i];
        }
        origen.swap(destino);
    }

    // Deshacer la inversion del bit de signo y devolver el resultado
    for (size_t i = 0; i < cantidad; i++)
        numeros[i] = (int)(origen[i] ^ 0x80000000u);

    auto tiempoFin = chrono::steady_clock::now();
    chrono::duration<double, milli> duracionMs = tiempoFin - tiempoInicio;
    cout << "Tiempo: " << duracionMs.count() << " ms\n";
}

int main() {
    vector<int> numeros = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(numeros);
}
