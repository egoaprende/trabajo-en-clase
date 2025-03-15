#include <cstdlib>
#include <iostream>
#include <fstream>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

string nombre, auxnombre, semestre, edad;
int clave=0, auxclave=0;
char grupo[10];
char opca;
bool encontrado=false;

void altas()
{
    ofstream escritura;
    ifstream consulta;

    do{
        escritura.open("alumnos.txt", ios::out | ios::app);
        consulta.open("alumnos.txt", ios::in);

        if(escritura.is_open() && consulta.is_open()){


            bool repetido=false;
            cout<<"\n";
            cout<<"\t Ingresa la clave del alumno:  ";
            cin>>auxclave;

            consulta>>clave;
            while(!consulta.eof()){
                consulta>>nombre>>semestre>>grupo>>edad;
                if(auxclave==clave){
                    cout<<"\t\tYa existe la clave del alumno...\n";
                    repetido=true;
                    break;
                }
                consulta>>clave;
            }

            if(repetido==false){
                cout<<"\t ingresa el nombre del alumno:  ";
                cin>>nombre;
                cout<<"\t ingrea el semestre del alumno:   ";
                cin>>semestre;
                cout<<"\t ingresa el grupo del alumno:   ";
                cin>>grupo;
                cout<<"\t ingresa el edad del alumno:   ";
                cin>>edad;

                escritura<<auxclave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
                cout<<"\n\t Registro agregado...\n";
            }
            
            cout<<"\n\tDeseas ingresar otro alumno? (S/N): ";
            cin>>opca;
        }else{
            cout<<"el archivo no se pudo abrir \n";
        }

        escritura.close();
        consulta.close();

    }while( opca=='S' or opca=='s');

};

void bajas()
{
    ofstream aux;
    ifstream lectura;

    encontrado=false;

    aux.open("auxiliar.txt", ios::out);
    lectura.open("alumnos.txt", ios::in);

    if (aux.is_open() && lectura.is_open()){

        cout<<"\n";
        cout<<"\tIngresa la clave del alumno que deseas eliminar: ";
        cin>>auxclave;

        lectura>>clave;
        while(!lectura.eof()){
            lectura>>nombre>>semestre>>grupo>>edad;
            if(auxclave==clave){
                encontrado=true;
                cout<<"\n";
                cout<<"\tClave:      "<<clave<<endl;
                cout<<"\tnombre:      "<<nombre<<endl;
                cout<<"\tsemestere:      "<<semestre<<endl;
                cout<<"\tgrupo:      "<<grupo<<endl;
                cout<<"\tedad:      "<<edad<<endl;
                cout<<"\t___________________________________\n\n";
                cout<<"\tRealmente deseas eliminar el registro actual (S/N)?---> ";
                cin>>opca;

                if( opca=='S' or opca=='s'){
                    cout<<"\n\n\t\tRegistro eliminado...\n\n\t\t\a";
                }else{
                    aux<<clave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
                }

            }else{
                aux<<clave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
            }
            lectura>>clave;
        }
    }else{
        cout<<"\n\tEl archivo no se pudo abrir \n";
    }

    if(encontrado==false){
            cout<<"\n\tNo se encontro ningun registro con la clave:  "<<auxclave<<"\n\n\t\t";
    }
aux.close();
lectura.close();
remove("alumnos.txt");
rename("auxiliar.txt","alumnos.txt");
}

void consultas()
{
    ifstream lectura;
    lectura.open("laumnos.txt",ios::out | ios::in);
    if(lectura.is_open()){
        lectura>>clave;
        while(!lectura.eof()){
            lectura>>nombre>>semestre>>grupo>>edad;
            cout<<"\n";
            cout<<"\tClave      "<<clave<<endl;
            cout<<"\tNombre      "<<nombre<<endl;
            cout<<"\tSemestre      "<<semestre<<endl;
            cout<<"\tGrupo      "<<grupo<<endl;
            cout<<"\tEdad      "<<edad<<endl;

            cout<<"\t_________________________";
        }
    }
}

void buscar(){
    ifstream lectura;
    lectura.open("alumnos.txt",ios::out | ios::in);

    encontrado=false;

    if(lectura.is_open()){
        cout<<"\n\tIngrese la clave del alumno que deseas buscar: ";
        cin>>auxclave;

        lectura>>clave;
        while(!lectura.eof()){
            lectura>>nombre>>semestre>>grupo>>edad;
            if(auxclave=clave){
            cout<<"\n";
            cout<<"\tClave      "<<clave<<endl;
            cout<<"\tNombre      "<<nombre<<endl;
            cout<<"\tSemestre      "<<semestre<<endl;
            cout<<"\tGrupo      "<<grupo<<endl;
            cout<<"\tEdad      "<<edad<<endl;

            cout<<"\t_________________________";
            encontrado=true;
            break;
            }
            lectura>>clave;
        }
        if(encontrado=false){
            cout<<"\n\n\tNo hay registro con la clave: "<<auxclave<<"\n\n\t\t";
        }
    }else{
        cout<<"\n\tAun no se pudo abrir el archivo: ";
    }
    lectura.close();
}

void modificar (){
    ofstream aux;
    ifstream lectura;

    encontrado=false;

    aux.open("auxiliar.txt", ios::out);
    lectura.open("alumnos.txt", ios::in);

    if (aux.is_open() && lectura.is_open()){

        cout<<"\n";
        cout<<"\tIngresa la clave del alumno que deseas modificar: ";
        cin>>auxclave;

        lectura>>clave;
        while(!lectura.eof()){
            lectura>>nombre>>semestre>>grupo>>edad;
            if(auxclave==clave){
                encontrado=true;
                cout<<"\n";
                cout<<"\tClave:      "<<clave<<endl;
                cout<<"\tnombre:      "<<nombre<<endl;
                cout<<"\tsemestere:      "<<semestre<<endl;
                cout<<"\tgrupo:      "<<grupo<<endl;
                cout<<"\tedad:      "<<edad<<endl;
                cout<<"\t___________________________________\n\n";
                cout<<"\tingresal el nuevo nombre del alumno con la clave: "<<auxclave<<"\n\n\t---->";
                cin>>auxnombre;

                aux<<clave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
                cout<<"\n\t Registro modificado...\n";
            }else{
                aux<<clave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl; 
            }
            lectura>>clave;
        }

    }else{
        cout<<"\n\tEl archivo no se pudo abrir \n";
    }

    if(encontrado=false){
        cout<<"\n\tNo se encontro ningun registro con la clave "<<auxclave<<"\n\n\t\t\t";
    }
    aux.close();
    lectura.close();
    remove("alumnos.txt");
    rename("auxiliar.txt","alumos.txt");
}

int main()
{

    system ("color f0");
    int opc;

    do
    {
        system("cls");

        cout<<"\n\tManejo de archivos en c++\n\n";
        cout<<"\n\t1-Altas";
        cout<<"\n\t2-Bajas";
        cout<<"\n\t3-Consultas";
        cout<<"\n\t4-Buscar un registro";
        cout<<"\n\t5-Modificaciones";
        cout<<"\n\t6-salir";
        cout<<"\n\tEliga una opcion";
        cin>>opc;
        switch (opc)
        {
        case 1:{

            system("cls");
            altas();
            cout<<"\n\t\t";
            system("pause");
            break;
        }
        case 2:{

            system("cls");
            bajas();
            cout<<"\n\t\t";
            system("pause");
            break;
        }
        case 3:{

            system("cls");
            consultas();
            cout<<"\n\t\t";
            system("pause");
            break;
        }
        case 4:{

            system("cls");
            buscar();
            cout<<"\n\t\t";
            system("pause");
            break;
        }
        case 5:{

            system("cls");
            modificar();
            cout<<"\n\t\t";
            system("pause");
            break;
        }
        case 6:{
            cout<<"\n\n\tHa elegido salr... \n\n\t\t";system("pause");
            break;
        }
        default:{
            cout<<"\n\n\tHas elegiso una opcion inexistente....\n\n\t\t";system("pause");
            break;
        }
    }

    }while (opc!=6);

    system("cls");
    
    return 0;
}