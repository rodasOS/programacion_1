#include<iostream>

using namespace std;

//progarmaa que solicite notas al usuario hasta llegar a la nota -1
//resultado cual es la nota más alta y cual es la más baja

int main() {
    float nota, mayor = 0, menor = 0;

    cout << "Ingrese la primera nota" << endl;
    cin >> nota;

    while (nota > -1 && nota < 101) {
        if (nota > mayor) {
            mayor = nota;
        }
        else if (nota < menor) {
            menor = nota;
        } 
        
        cout << "Ingrese la siguiente nota" << endl;
        cin >> nota;
    }
    
    cout << "La nota mayor es: " << mayor << endl;
    cout << "La nota menor es: " << menor << endl;

    return 0;
}
