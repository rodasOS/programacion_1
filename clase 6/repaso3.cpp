#include <iostream>
using namespace std;

int sumar(int a, int b) {
    cout << "Sumando..." << endl;
    return a + b;
}

int restar(int a, int b) {
    cout << "Restando..." << endl;
    return a - b;
}

int main() {
    int suma = sumar(2, 3);
    int resta = restar(10, 5);
    
    cout << suma << endl;
    cout << resta << endl;
    return 0;
}
