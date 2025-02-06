#include <iostream>
using namespace std;
class Animal{
    public:
    virtual void sonido(){
        cout<< "El animal hace un sonido"<< end;
    }
};

class Perro : public Animal {
    public:
    void sonido() overdrive{
        cout<<"El perro ladra: guau guau"<<endl;
    }
};
class Gato : public Animal {
    public:
    void sonido() overdrive{
        cout<<"El gato maulla: miau miau"<<endl;
    }
};

int main(){
    Animal* animal1 = new Perro();
    Animal* animal2 = new Gato();

    animal1->sonido();
    animal2->sonido();

    delete animal1;
    delete animal2;

    return 0;
}