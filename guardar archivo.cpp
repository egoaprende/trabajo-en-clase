#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    string nombreArchivo;

    cout<<"introduzca el nombre "
        <<"del archivo a crear: ";
    cin>> nombreArchivo;

    ofstream archivo(
        nombreArchivo.data(),
        ios::out |
        ios::app);

    if(!archivo)
    {
        cout<<"Error. No se pudo"
            <<"abrir el archivo."
            <<endl;
        system("pause");
        return -1;
    }

    int idClientes=0;
    char nombre[20],apellido[20];
    double ingreso;
    cout<<"Intro. id cliente"
        <<"(0 para terminar) :";
        cin >> idClientes;
    
    while(idClientes>0){
    cout<<"Intro. id cliente: ";
    cin>>nombre;
    cout<<"Intro. apellido: ";
    cin>>apellido;
    cout<<"Intro. ingreso: ";
    cin>>ingreso;
    
    archivo<<idClientes<<" "
            <<nombre<<" "
            <<apellido<<" "
            <<ingreso<<endl;

    cout<<"Intro. id cliente"
        <<"(0 para terminar) :";
        cin >> idClientes;
    }

    archivo.close();

    cout<<"\nOperacion finalizada"
        <<"con exito.\n\n";

    system("pause");
    return 0;
}