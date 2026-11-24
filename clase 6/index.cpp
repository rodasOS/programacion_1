/*
 * CLASE 6 - Funciones con valor de retorno y parametros
 * TEMA: funciones que reciben parametros POR VALOR y devuelven un resultado con return.
 *
 * Conceptos:
 *   - Firma: tipoRetorno nombre(tipo param, ...);
 *   - Los parametros son COPIAS: cambiar 'descuento' dentro de calculo() no cambia el
 *     de main (para eso existe el paso por referencia, clase 7).
 *   - El resultado se captura: descuento = calculo(descuento, 100);
 *
 * Compilar: g++ index.cpp -o index && ./index
 */

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