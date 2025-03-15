#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct Contacto {
    string nombre;
    string telefono;
    string correo;
};

void listarContactos() {
    ifstream archivo("contactos.txt");
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}

void crearContacto() {
    Contacto nuevo;
    cout << "Nombre: "; cin >> nuevo.nombre;
    cout << "Telefono: "; cin >> nuevo.telefono;
    cout << "Correo: "; cin >> nuevo.correo;

    ofstream archivo("contactos.txt", ios::app);
    archivo << nuevo.nombre << "," << nuevo.telefono << "," << nuevo.correo << endl;
    archivo.close();
}

void editarContacto() {
    vector<Contacto> contactos;
    ifstream archivo("contactos.txt");
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Contacto c;
        getline(ss, c.nombre, ',');
        getline(ss, c.telefono, ',');
        getline(ss, c.correo, ',');
        contactos.push_back(c);
    }
    archivo.close();

    string nombre;
    cout << "Ingrese el nombre del contacto a editar: "; cin >> nombre;
    for (auto &c : contactos) {
        if (c.nombre == nombre) {
            cout << "Nuevo telefono: "; cin >> c.telefono;
            cout << "Nuevo correo: "; cin >> c.correo;
        }
    }

    ofstream archivoOut("contactos.txt");
    for (const auto &c : contactos) {
        archivoOut << c.nombre << "," << c.telefono << "," << c.correo << endl;
    }
    archivoOut.close();
}

void eliminarContacto() {
    vector<Contacto> contactos;
    ifstream archivo("contactos.txt");
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Contacto c;
        getline(ss, c.nombre, ',');
        getline(ss, c.telefono, ',');
        getline(ss, c.correo, ',');
        contactos.push_back(c);
    }
    archivo.close();

    string nombre;
    cout << "Ingrese el nombre del contacto a eliminar: "; cin >> nombre;
    ofstream archivoOut("contactos.txt");
    for (const auto &c : contactos) {
        if (c.nombre != nombre) {
            archivoOut << c.nombre << "," << c.telefono << "," << c.correo << endl;
        }
    }
    archivoOut.close();
}

int main() {
    int opcion;
    do {
        cout << "\nDirectorio Telefonico" << endl;
        cout << "1. Listar contactos" << endl;
        cout << "2. Crear contacto" << endl;
        cout << "3. Editar contacto" << endl;
        cout << "4. Eliminar contacto" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: listarContactos(); break;
            case 2: crearContacto(); break;
            case 3: editarContacto(); break;
            case 4: eliminarContacto(); break;
            case 5: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion no valida" << endl;
        }
    } while (opcion != 5);

    return 0;
}