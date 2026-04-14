#include <iostream>
#include <vector>
using namespace std;

void modificar(int arr[], vector<int> v) {
    arr[0] = 100;
    v[0] = 100;
}

int main() {
    int numeros[3] = {1, 2, 3};
    vector<int> vec = {1, 2, 3};

    modificar(numeros, vec);

    cout << "Arreglo: " << numeros[0] << endl;
    cout << "Vector: " << vec[0] << endl;

    return 0;
}
