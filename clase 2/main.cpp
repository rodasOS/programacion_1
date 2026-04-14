#include<iostream>

using namespace std;

struct Auto {
    char marca[20];
    int numSerie;
}
auto1;


int main() {
    cout << "Ingresar la marca del auto: "<<endl;
    // cin >> auto1.marca;
    cin.getline(auto1.marca, 20, '\n');
    cout << "Ingresar el numero de serie del auto: "<<endl;
    cin >> auto1.numSerie;
    cout << "La marca del auto es: " << auto1.marca << endl;
    cout << "El numero de serie del auto es: " << auto1.numSerie << endl;
    return 0;
}