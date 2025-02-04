#include <iostream>
using namespace std;

class operacion{
    protected:
    int valor1;
    int valor2;
    int resultado;

    public:
     void cargar1(){
        cout<< "ingrese el peimer valor:";
        cin>> valor1;
     };
     void cargar2(){
        cout<<" ingrese el segundo valor:";
        cin>> valor2;
     };
     void mostrarResultado(){
        cout<<resultado<<"\n";
     };
};

class Suma: public operacion{
 public:
 void operar(){
    resultado=valor1+valor2;

 };
};
class Resta: public operacion{
 public:
 void operar(){
    resultado=valor1-valor2;

 };
};
class Multi: public operacion{
 public:
 void operar(){
    resultado=valor1*valor2;

 };
};
int main(){
    Suma objsuma;
    objsuma.cargar1();
    objsuma.cargar2();
    objsuma.operar();
    cout<< "la suma de los dos valores es:";
    objsuma.mostrarResultado();
    cout<< "========================================"<<"\n";

    Resta objresta;
    objresta.cargar1();
    objresta.cargar2();
    objresta.operar();
    cout<<"La resta de los dos numeros es:";
    objresta.mostrarResultado();
    cout<< "========================================"<<"\n";

    Multi objmulti;
    objmulti.cargar1();
    objmulti.cargar2();
    objmulti.operar();
    cout<<"La resta de los dos numeros es:";
    objmulti.mostrarResultado();
    cout<< "========================================"<<"\n";

}