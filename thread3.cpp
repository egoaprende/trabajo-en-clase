#include <iostream>
#include <thread>
using namespace std;

void foo(int z){
    for (int i=0;i<z;i++){
        cout<<"usando la funcion\n";
    }
}
class thread_obj {
    public:
    void operator()(int x){
        for (int i=0;i<x;i++){
            cout<<"usando el objeto\n";
        }
    }
};

int main(){
   /* cout<<"Thread 1 and 2 and 3 operan independientemente"<<endl;
    thread th1(foo,3);

    thread th2(thread_obj(),3);

    auto f =[](int x){
        for (int i=0;i<x;i++)
        cout<<"thread usando lambda expression\n";
    };

    thread th3(f,3);
    th1.join();
    th2.join();
    th3.join(); */
    return 0;
}
