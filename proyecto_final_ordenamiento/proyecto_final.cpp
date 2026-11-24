/*
 * PROYECTO FINAL - ordenamiento y busqueda sobre 100,000 enteros
 * Temas: radix, quick, merge, heap, shell y burbuja; busqueda binaria e interpolacion;
 * medicion de tiempos con <chrono>; punteros a funcion (tabla ALGS) para el menu.
 * Resultados y analisis: RESULTADOS.md. Guia de la carpeta: README.md.
 */

// Proyecto final - Busqueda y Ordenamientos
// Compilar: g++ -O2 -std=c++17 proyecto_final.cpp -o proyecto_final
// Uso:      ./proyecto_final            (menu interactivo)
//           ./proyecto_final --benchmark (compara todos los algoritmos)
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <vector>
using namespace std;
using Clock = chrono::steady_clock;

const int N = 100000;

// ---------- Generacion ----------
vector<int> generarVector(int n, unsigned seed = random_device{}()) {
    mt19937 gen(seed);
    uniform_int_distribution<int> dist(1, 1000000);
    vector<int> v(n);
    for (int &x : v) x = dist(gen);
    return v;
}

// ---------- Ordenamientos ----------

// 1. Radix sort LSD (base 256, 4 pasadas). O(n*k). El mas rapido para enteros.
void radixSort(vector<int> &v) {
    size_t n = v.size();
    vector<uint32_t> a(n), b(n);
    for (size_t i = 0; i < n; i++) a[i] = (uint32_t)v[i] ^ 0x80000000u; // soporta negativos
    size_t cnt[4][256] = {};
    for (size_t i = 0; i < n; i++)
        for (int p = 0; p < 4; p++) cnt[p][(a[i] >> (8 * p)) & 255]++;
    for (int p = 0; p < 4; p++) {
        // si todos comparten el mismo byte, la pasada no hace falta
        if (cnt[p][(a[0] >> (8 * p)) & 255] == n) continue;
        size_t pos = 0;
        for (int d = 0; d < 256; d++) { size_t c = cnt[p][d]; cnt[p][d] = pos; pos += c; }
        for (size_t i = 0; i < n; i++) b[cnt[p][(a[i] >> (8 * p)) & 255]++] = a[i];
        a.swap(b);
    }
    for (size_t i = 0; i < n; i++) v[i] = (int)(a[i] ^ 0x80000000u);
}

// 2. Quick sort: mediana de 3, insercion en particiones pequenas, recursion sobre la parte menor.
static void insercion(int *a, int lo, int hi) {
    for (int i = lo + 1; i <= hi; i++) {
        int k = a[i], j = i - 1;
        while (j >= lo && a[j] > k) { a[j + 1] = a[j]; j--; }
        a[j + 1] = k;
    }
}
static void quick(int *a, int lo, int hi) {
    while (hi - lo > 16) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < a[lo]) swap(a[mid], a[lo]);
        if (a[hi] < a[lo]) swap(a[hi], a[lo]);
        if (a[hi] < a[mid]) swap(a[hi], a[mid]);
        int p = a[mid], i = lo, j = hi;
        while (i <= j) {
            while (a[i] < p) i++;
            while (a[j] > p) j--;
            if (i <= j) swap(a[i++], a[j--]);
        }
        if (j - lo < hi - i) { quick(a, lo, j); lo = i; }
        else { quick(a, i, hi); hi = j; }
    }
    insercion(a, lo, hi);
}
void quickSort(vector<int> &v) { if (v.size() > 1) quick(v.data(), 0, (int)v.size() - 1); }

// 3. Merge sort con buffer auxiliar unico e insercion en bloques pequenos. O(n log n) garantizado y estable.
static void mergeRec(int *a, int *tmp, int lo, int hi) {
    if (hi - lo < 16) { insercion(a, lo, hi); return; }
    int mid = lo + (hi - lo) / 2;
    mergeRec(a, tmp, lo, mid);
    mergeRec(a, tmp, mid + 1, hi);
    if (a[mid] <= a[mid + 1]) return; // ya ordenado
    memcpy(tmp + lo, a + lo, (mid - lo + 1) * sizeof(int));
    int i = lo, j = mid + 1, k = lo;
    while (i <= mid && j <= hi) a[k++] = (a[j] < tmp[i]) ? a[j++] : tmp[i++];
    while (i <= mid) a[k++] = tmp[i++];
}
void mergeSort(vector<int> &v) {
    if (v.size() < 2) return;
    vector<int> tmp(v.size());
    mergeRec(v.data(), tmp.data(), 0, (int)v.size() - 1);
}

// 4. Heap sort. O(n log n), sin memoria extra.
static void sift(int *a, int i, int n) {
    int x = a[i];
    while (true) {
        int c = 2 * i + 1;
        if (c >= n) break;
        if (c + 1 < n && a[c + 1] > a[c]) c++;
        if (a[c] <= x) break;
        a[i] = a[c]; i = c;
    }
    a[i] = x;
}
void heapSort(vector<int> &v) {
    int n = (int)v.size(), *a = v.data();
    for (int i = n / 2 - 1; i >= 0; i--) sift(a, i, n);
    for (int e = n - 1; e > 0; e--) { swap(a[0], a[e]); sift(a, 0, e); }
}

// 5. Shell sort con la secuencia de Ciura. ~O(n^1.3)
void shellSort(vector<int> &v) {
    static const int gaps[] = {1750, 701, 301, 132, 57, 23, 10, 4, 1};
    int n = (int)v.size();
    for (int g : gaps) {
        for (int i = g; i < n; i++) {
            int k = v[i], j = i;
            while (j >= g && v[j - g] > k) { v[j] = v[j - g]; j -= g; }
            v[j] = k;
        }
    }
}

// 6. Burbuja (solo para comparar; O(n^2))
void burbuja(vector<int> &v) {
    int n = (int)v.size();
    for (int i = 0; i < n - 1; i++) {
        bool cambio = false;
        for (int j = 0; j < n - 1 - i; j++)
            if (v[j] > v[j + 1]) { swap(v[j], v[j + 1]); cambio = true; }
        if (!cambio) break;
    }
}

// Referencia: std::sort (introsort)
void stdSort(vector<int> &v) { sort(v.begin(), v.end()); }

// ---------- Busquedas (sobre vector ORDENADO) ----------
// Devuelven la posicion o -1.
int busquedaBinaria(const vector<int> &v, int x, long long &pasos) {
    int lo = 0, hi = (int)v.size() - 1;
    pasos = 0;
    while (lo <= hi) {
        pasos++;
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == x) return mid;
        if (v[mid] < x) lo = mid + 1; else hi = mid - 1;
    }
    return -1;
}
int busquedaInterpolacion(const vector<int> &v, int x, long long &pasos) {
    int lo = 0, hi = (int)v.size() - 1;
    pasos = 0;
    while (lo <= hi && x >= v[lo] && x <= v[hi]) {
        pasos++;
        if (v[hi] == v[lo]) return v[lo] == x ? lo : -1;
        long long pos = lo + (long long)(x - v[lo]) * (hi - lo) / ((long long)v[hi] - v[lo]);
        if (v[pos] == x) return (int)pos;
        if (v[pos] < x) lo = (int)pos + 1; else hi = (int)pos - 1;
    }
    return -1;
}
int busquedaLineal(const vector<int> &v, int x, long long &pasos) {
    pasos = 0;
    for (int i = 0; i < (int)v.size(); i++) { pasos++; if (v[i] == x) return i; }
    return -1;
}

// ---------- Utilidades ----------
struct Algoritmo { const char *nombre; const char *complejidad; void (*fn)(vector<int> &); };
const Algoritmo ALGS[] = {
    {"Radix Sort (LSD, base 256)", "O(n*k)", radixSort},
    {"Quick Sort (mediana de 3)", "O(n log n) prom.", quickSort},
    {"Merge Sort (optimizado)", "O(n log n)", mergeSort},
    {"Heap Sort", "O(n log n)", heapSort},
    {"Shell Sort (Ciura)", "~O(n^1.3)", shellSort},
    {"Burbuja (solo comparacion)", "O(n^2)", burbuja},
};
const int NALGS = sizeof(ALGS) / sizeof(ALGS[0]);

double medirMs(void (*fn)(vector<int> &), vector<int> &v) {
    auto t0 = Clock::now();
    fn(v);
    return chrono::duration<double, milli>(Clock::now() - t0).count();
}

void imprimirVector(const vector<int> &v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << setw(8) << v[i];
        if ((i + 1) % 10 == 0) cout << '\n';
    }
    cout << '\n';
}

int leerEntero(const string &msg) {
    int x;
    while (true) {
        cout << msg;
        if (cin >> x) return x;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida.\n";
    }
}

// ---------- Benchmark ----------
void benchmark(int corridas) {
    cout << "Benchmark: n=" << N << ", " << corridas << " corridas por algoritmo (mediana y mejor)\n\n";
    cout << left << setw(30) << "Algoritmo" << setw(20) << "Complejidad"
         << right << setw(14) << "Mediana(ms)" << setw(14) << "Mejor(ms)" << "  OK\n";
    vector<vector<int>> datos;
    for (int c = 0; c < corridas; c++) datos.push_back(generarVector(N, 1000 + c));
    {   // std::sort como referencia
        vector<double> t;
        bool ok = true;
        for (auto &d : datos) { vector<int> v = d; t.push_back(medirMs(stdSort, v)); ok &= is_sorted(v.begin(), v.end()); }
        sort(t.begin(), t.end());
        cout << left << setw(30) << "std::sort (referencia)" << setw(20) << "O(n log n)"
             << right << fixed << setprecision(3) << setw(14) << t[t.size() / 2] << setw(14) << t[0] << (ok ? "  si" : "  NO") << '\n';
    }
    for (int a = 0; a < NALGS; a++) {
        vector<double> t;
        bool ok = true;
        int reps = (a == NALGS - 1) ? min(corridas, 3) : corridas; // burbuja es lenta
        for (int c = 0; c < reps; c++) {
            vector<int> v = datos[c];
            t.push_back(medirMs(ALGS[a].fn, v));
            ok &= is_sorted(v.begin(), v.end());
        }
        sort(t.begin(), t.end());
        cout << left << setw(30) << ALGS[a].nombre << setw(20) << ALGS[a].complejidad
             << right << fixed << setprecision(3) << setw(14) << t[t.size() / 2] << setw(14) << t[0] << (ok ? "  si" : "  NO") << '\n';
    }
    // Busquedas: 1,000,000 consultas sobre el vector ordenado
    vector<int> s = datos[0];
    radixSort(s);
    mt19937 gen(7);
    uniform_int_distribution<int> d(1, 1000000);
    const int Q = 1000000;
    vector<int> qs(Q);
    for (int &q : qs) q = d(gen);
    cout << "\nBusquedas: " << Q << " consultas aleatorias sobre el vector ordenado\n";
    long long p; volatile long long sink = 0;
    auto t0 = Clock::now();
    for (int q : qs) sink = sink + busquedaBinaria(s, q, p);
    double tb = chrono::duration<double, milli>(Clock::now() - t0).count();
    t0 = Clock::now();
    for (int q : qs) sink = sink + busquedaInterpolacion(s, q, p);
    double ti = chrono::duration<double, milli>(Clock::now() - t0).count();
    t0 = Clock::now();
    for (int i = 0; i < 2000; i++) sink = sink + busquedaLineal(s, qs[i], p);
    double tl = chrono::duration<double, milli>(Clock::now() - t0).count() * (Q / 2000.0);
    cout << fixed << setprecision(2)
         << "  Binaria:        " << tb << " ms total (" << tb * 1e6 / Q << " ns/consulta)\n"
         << "  Interpolacion:  " << ti << " ms total (" << ti * 1e6 / Q << " ns/consulta)\n"
         << "  Lineal (est.):  " << tl << " ms total (" << tl * 1e6 / Q << " ns/consulta)\n";
}

// ---------- Menu ----------
int main(int argc, char **argv) {
    if (argc > 1 && string(argv[1]) == "--benchmark") { benchmark(argc > 2 ? atoi(argv[2]) : 15); return 0; }

    vector<int> original = generarVector(N), actual = original;
    bool ordenado = false;
    cout << "=== PROYECTO FINAL: BUSQUEDA Y ORDENAMIENTOS ===\n"
         << "Vector aleatorio de " << N << " enteros generado.\n";
    while (true) {
        cout << "\n--------- MENU ---------\n";
        for (int i = 0; i < NALGS; i++) cout << " " << i + 1 << ". Ordenar con " << ALGS[i].nombre << '\n';
        cout << " 7. Busqueda binaria\n 8. Busqueda por interpolacion\n"
             << " 9. Generar un vector nuevo\n10. Ver vector actual\n11. Comparar todos los algoritmos (benchmark)\n 0. Salir\n"
             << "Estado: " << (ordenado ? "ORDENADO" : "desordenado") << '\n';
        int op = leerEntero("Opcion: ");
        if (op == 0) break;
        if (op >= 1 && op <= NALGS) {
            actual = original;
            double ms = medirMs(ALGS[op - 1].fn, actual);
            ordenado = is_sorted(actual.begin(), actual.end());
            cout << "\nVector ordenado con " << ALGS[op - 1].nombre << ":\n";
            imprimirVector(actual);
            cout << fixed << setprecision(3) << ">>> Tiempo de ordenamiento: " << ms << " ms ("
                 << ms / 1000 << " s)  | verificado: " << (ordenado ? "correcto" : "ERROR") << '\n';
        } else if (op == 7 || op == 8) {
            if (!ordenado) { cout << "Primero ordene el vector (opciones 1-6).\n"; continue; }
            int x = leerEntero("Numero a buscar: ");
            long long pasos;
            auto t0 = Clock::now();
            int pos = op == 7 ? busquedaBinaria(actual, x, pasos) : busquedaInterpolacion(actual, x, pasos);
            double us = chrono::duration<double, micro>(Clock::now() - t0).count();
            if (pos >= 0) cout << "Encontrado en la posicion " << pos << " (indice, base 0)";
            else cout << "El numero " << x << " NO esta en el vector";
            cout << " | pasos: " << pasos << " | tiempo: " << us << " us\n";
        } else if (op == 9) {
            original = generarVector(N); actual = original; ordenado = false;
            cout << "Nuevo vector generado.\n";
        } else if (op == 10) imprimirVector(actual);
        else if (op == 11) benchmark(10);
        else cout << "Opcion invalida.\n";
    }
    return 0;
}
