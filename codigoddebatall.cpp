#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Habilidad {
    string nombre;
    int nivel;
    Habilidad* siguiente;
    Habilidad(string n, int lvl) : nombre(n), nivel(lvl), siguiente(nullptr) {}
};


class ListaHabilidades {
private:
    Habilidad* cabeza;
public:
    ListaHabilidades() : cabeza(nullptr) {
        agregarHabilidad("Ataque Basico", 1);
        agregarHabilidad("Defensa", 1);
    }
    ~ListaHabilidades() {
        while (cabeza) {
            Habilidad* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
    void agregarHabilidad(string nombre, int nivel) {
        Habilidad* nueva = new Habilidad(nombre, nivel);
        if (!cabeza) {
            cabeza = nueva;
        } else {
            Habilidad* temp=cabeza;
            while (temp->siguiente) {
                temp=temp->siguiente;
            }
            temp->siguiente= nueva;
        }
    }
    void eliminarHabilidad(string nombre) {
        Habilidad* temp =cabeza;
        Habilidad* prev= nullptr;
        while (temp && temp->nombre != nombre) {
            prev =temp;
            temp =temp->siguiente;
        }
        if (temp) {
            if (prev) {
                prev->siguiente =temp->siguiente;
            } else {
                cabeza =temp->siguiente;
            }
            delete temp;
        }
    }
    void mostrarHabilidades() {
        Habilidad* temp = cabeza;
        while (temp) {
            cout << "Habilidad: " << temp->nombre << " (Nivel " << temp->nivel << ")" << endl;
            temp = temp->siguiente;
        }
    }
};

// Clase base
class Personaje {
protected:
    string nombre;
    int nivel;
    int agilidad;
    int puntos_vida;
    ListaHabilidades habilidades;
public:
    Personaje(string n, int agi, int pv, int lvl) : nombre(n), agilidad(agi), puntos_vida(pv), nivel(lvl) {}
    virtual ~Personaje() {}
    virtual void atacar()const =0;
    virtual void mostrar() const{
        cout << nombre <<" - Nivel:" <<nivel <<", Agilidad: "<<agilidad<< ", Vida: " <<puntos_vida << endl;
    }
    void agregarHabilidad(string nombre, int nivel) {
        habilidades.agregarHabilidad(nombre, nivel);
    }
    void eliminarHabilidad(string nombre) {
        habilidades.eliminarHabilidad(nombre);
    }
    void mostrarHabilidades() {
        cout << "Habilidades de " << nombre << ":" << endl;
        habilidades.mostrarHabilidades();
    }
};

// Clases derivadas
class Guerrero : public Personaje {
public:
    Guerrero(string n) : Personaje(n, 5, 100, 10) {}
    void atacar() const override {
        cout <<nombre<<"ataca con una espada, causando 40 de daño."<<endl;
    }
};

class Mago : public Personaje {
public:
    Mago(string n) : Personaje(n, 7, 80, 10) {}
    void atacar() const override {
        cout <<nombre<<"lanza un hechizo de fuego, causando 30 de daño."<<endl;
    }
};

class Arquero : public Personaje {
public:
    Arquero(string n) : Personaje(n, 10, 90, 10) {}
    void atacar() const override {
        cout << nombre <<"dispara una flecha, causando 25 de dano."<<endl;
    }
};

int main() {
    vector<Personaje*> personajes = {
        new Guerrero("Thor"),
        new Mago("Merlin"),
        new Arquero("Legolas")
    };
    
    int personajeIndex;
    cout << "Seleccione un personaje:\n";
    for (size_t i = 0; i < personajes.size(); ++i) {
        cout << i << ". ";
        personajes[i]->mostrar();
    }
    cout << "Ingrese el numero del personaje: ";
    cin >> personajeIndex;
    
    if (personajeIndex < 0 || personajeIndex >= personajes.size()) {
        cout <<"Seleccion no valida."<<endl;
        return 1;
    }
    
    Personaje* personajeSeleccionado = personajes[personajeIndex];
    cout << "Has seleccionado a:" << endl;
    personajeSeleccionado->mostrar();
    
    int opcion;
    do {
        cout <<"\nSeleccione una accion:" <<endl;
        cout <<"1. Atacar" <<endl;
        cout <<"2. Mostrar habilidades" <<endl;
        cout <<"3. Agregar habilidad" <<endl;
        cout <<"4. Eliminar habilidad" <<endl;
        cout <<"5. Salir" <<endl;
        cout <<"Opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                personajeSeleccionado->atacar();
                break;
            case 2:
                personajeSeleccionado->mostrarHabilidades();
                break;
            case 3: {
                string nombreHab;
                int nivelHab;
                cout <<"Ingrese el nombre de la nueva habilidad: ";
                cin >> nombreHab;
                cout <<"Ingrese el nivel de la habilidad: ";
                cin >> nivelHab;
                personajeSeleccionado->agregarHabilidad(nombreHab, nivelHab);
                break;
            }
            case 4: {
                string nombreHab;
                cout <<"Ingrese el nombre de la habilidad a eliminar: ";
                cin >> nombreHab;
                personajeSeleccionado->eliminarHabilidad(nombreHab);
                break;
            }
        }
    } while (opcion != 5);
    
    for (auto& personaje : personajes) {
        delete personaje;
    }
    return 0;
}