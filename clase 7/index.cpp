#include <iostream>
using namespace std;

void intercambio(int &n1, int &n2) {
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

int main() {
    int n1 = 10, n2 = 20;

    cout<< "Valores iniciales. \n n1 = " << n1 << ", n2 = " << n2 << endl;

    intercambio(n1, n2);

    cout<< "Valores despues del intercambio. \n n1 = " << n1 << ", n2 = " << n2 << endl;

    return 0;
}