#include<iostream>

using namespace std;

int calculo(int descuento, int total);

int main()
{
    int descuento = 10;
    descuento = calculo(descuento, 100  );

    cout<<"El total a pagar con el descuento aplicado es: " << descuento << endl;

    return 0;
}

int calculo(int descuento, int total)
{   
    int totalFinal = 0;
    totalFinal = total - (total * descuento / 100);
    return totalFinal;
}