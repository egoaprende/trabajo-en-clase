#include <iostream>

using namespace std;

//Definicion de la estructura del modo
struct Nodo {
	int dato;               //Datos del nodo (un entero)
	Nodo* siguiente;        //Apuntador al siguiente nodo
	
	//Constructor para inicializar el nodo
	Nodo(int valor) {
		dato = valor;
		siguiente = nullptr;
	}
};

//Clase que maneja la lista enlazada
class ListaEnlazada {
private:
    Nodo* cabeza;      //Puntero a la cabeza de la lista
public:
    //Constructor para inicializar la lista
    ~ListaEnlazada() {
    	cabeza = nullptr;
    
    //Destructor para liberar memoria
    	Nodo* temp;
    	while (cabeza != nullptr) {
    		temp = cabeza;
    		cabeza = cabeza->siguiente;
    		delete temp;
		}
	}	
	// Metodo para agregar un nodo al final de la lista
	void agergarAlFinal (int valor) {
		Nodo* nuevoNodo  = new Nodo(valor);
		if (cabeza == nullptr) {
			cabeza == nuevoNodo;
		}else {
			Nodo* temp = cabeza;
			while (temp->siguiente != nullptr) {
				temp = temp->siguiente;
			}
			temp->siguiente = nuevoNodo;
		}
	}
	
	//Metodo para mostar todos los elementos de la lista
	void mostrar() {
		Nodo* temp = cabeza;
		if (temp == nullptr) {
			cout << "La lista está vacia." << endl;
			return;
		}
		while (temp != nullptr) {
			cout << temp->dato << " ";
			temp = temp->siguiente;
		}
		cout << endl;
	}
	
	//Metodo para eliminiar un nodo con valor especifico
	void eliminar(int valor) {
		Nodo* temp = cabeza;
		Nodo* anterior = nullptr;
		
		//Si el valor a eliminar esta en la cabeza
		if(temp != nullptr && temp->dato == valor) {
			cabeza = temp->siguiente;
			delete temp;
			cout << "Valor " << valor << " eliminado." << endl;
			return;
		}
		
		//Buscar el valor a eliminar
		while (temp != nullptr && temp->dato != valor) {
			anterior = temp;
			temp = temp->siguiente;
		}
		
		//Si el valor no esta en la lista
		if(temp == nullptr) {
			cout << "Valor no encontrado. " << endl;
			return;
		}
		
		// Desenlazar el nodo
		anterior->siguiente = temp->siguiente;
		delete temp;
		cout << "Valor " << valor << " eliminado." << endl;
	}

    void ordenarBurbuja(){
        if(cabeza == nullptr || cabeza-> siguiente == nullptr){
            return;
        }
        bool intercambiado;
        do{
            Nodo* temp = cabeza;
            intercambiado = false;
            while(temp != nullptr && temp-> siguiente != nullptr){
                if(temp-> dato > temp -> siguiente -> dato){
                    int tempDato = temp ->dato;
                    temp->dato =temp ->siguiente -> dato;
                    temp-> siguiente ->dato = tempDato;
                    intercambiado = true;
                }
                temp=temp->siguiente;
            }
        }while (intercambiado);
    }
};




int main() {
	ListaEnlazada lista;
	int opcion, valor;
	
	do {
		//Mostrar menú de opicones
		cout << "\nMENU DE ACCIONES: " << endl;
		cout << "1. Agregar un numero al final" << endl;
		cout << "2. Eliminar un numero" << endl;
		cout << "3. Mostrar lista" << endl;
		cout << "4. Salir" << endl;
		cout << "5. Ordenar" << endl;
		cout << "Seleccione una opcion (1-5): ";
		cin >> opcion;
		
		switch (opcion) {
			case 1:
				//Agregar un numero al final
				cout << "Ingrese el valor a agregar: ";
				cin >> valor;
				lista.agergarAlFinal(valor);
				break;
				
			case 2:
				//Eliminar un numero
				cout << " Ingrese le valor a eliminar:";
                cin >> valor;
                lista.eliminar(valor);
                break;
            case 3:
            cout<<"lista actual";
            lista.mostrar();
            break;
            
            case 4:
                cout<<"saliendo del programa."<<endl;
                break;

            case 5:
            lista.ordenarBurbuja();
            cout<<"La lista se ordeno..."<<endl;
            break;
            default:
            cout<<"Opcion no valida. por favor, intente de nuevo"<<endl;
		}
	}while (opcion != 4);

}