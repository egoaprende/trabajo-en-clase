#include <iostream>
#include <thread>
using namespace std;

class Auto{
    public:

    void operator() (int x) {
        for(int i=0;i<x;i++){
            cout<<"usando el objeto"<<this<<endl;
        }
    }
};

int main()
{
    cout<<"vamos a arrancar los carros\n";
    //thread th1(Auto(),4);
    //thread th2(Auto(),3);


    //th1.join();
    //th2.join();
    return 0;
}