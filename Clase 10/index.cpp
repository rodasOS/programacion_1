#include <iostream>
#include <fstream>

using namespace std;

struct Persona{
    int id;
    string nombre;
    string correo;
}clientes[2];

void ingresoDatos(Persona cliente[2]) {
    for(int i=0;i<2;i++)
    {
        cout<<"Ingrese id: ";
        cin>>cliente[i].id;
        cin.ignore();
        cout<<"Ingrese nombre: ";
        getline(cin,cliente[i].nombre);
        cout<<"Ingrese correo: ";
        getline(cin,cliente[i].correo);
    }
}

void imprimirDatos(Persona cliente[2]) {
    cout<<"*** Datos del Cliente ***" <<endl;
    for(int i=0;i<2;i++)
    {
        cout<<"ID: "<<cliente[i].id << endl;
        cout<<"NOMBRE: "<<cliente[i].nombre << endl;
        cout<<"CORREO: "<<cliente[i].correo << endl;

    }
}

void archivarDatos(Persona cliente[2]) {
    ofstream archivo;
    archivo.open("cliente_2026.txt",ios::out);
    if(archivo.fail()) {
        cout<<"Error al crear el archivo..."<<endl;
        return;
    }

    archivo<<"*** Datos del cliente ***" << endl;

    for(int i=0;i<2;i++) {
        archivo<<"ID: "<<cliente[i].id << endl;
        archivo<<"NOMBRE: "<<cliente[i].nombre << endl;
        archivo<<"CORREO: "<<cliente[i].correo << endl;
    }

    archivo.close();
}

void leerDatos(Persona cliente[2]) {
    ifstream archivo;

    string texto;

    archivo.open("c://temp//cliente_2026.txt",ios::in);

    while (!archivo.eof())
    {
        getline(archivo,texto);
        cout<<texto<<endl;
    }

    archivo.close();

}

void agregarDatos(Persona cliente[2]) {
    ofstream archivo;
    archivo.open("c://temp//cliente_2026.txt",ios::app);

    if(!archivo.is_open())
        cout<<"Error al abrir el archivo."<< endl;
    else
    {
        for(int i=0;i<2;i++)
        {
            archivo<<"ID: "<<cliente[i].id << endl;
            archivo<<"NOMBRE: "<<cliente[i].nombre << endl;
            archivo<<"CORREO: "<<cliente[i].correo << endl;
        }

        archivo.close();
    }

}

int main() {
    ingresoDatos(clientes);
    imprimirDatos(clientes);
    archivarDatos(clientes);

    return 0;
}
