#include <iostream>
#include <iomanip>
using namespace std;

int suma(int num1, int num2) {
    return num1 + num2;
}

double suma(double num1, double num2) {

    return num1 + num2;
}

int suma(int num1, int num2, int num3) {
    return num1 + num2 + num3;
}

int main() {
    //cout << fixed <<  setprecision(2);

    // Primera función
    cout << suma(10, 20) << endl;

    // Segunda Función
    cout << suma(20.512341, 10.312312) << endl;

    // Tercera función
    cout << suma(10, 20, 30) << endl;
    return 0;
}