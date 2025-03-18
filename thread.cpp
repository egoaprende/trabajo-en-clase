#include <iostream>
#include <thread>
using namespace std;

void foo(int z){
    for(int i = 0; i<0;i++) {
        cout<<"soy foo"<<endl;
    }
}

void bar(){
    cout<<"soy bar"<<endl;
}


int main(){
    /*thread th1(foo,3);
    thread th2(bar);
 cout<<"main, foo and bar now corren de forma concurrente.....\n";

 th1.join();
 th2.join();
 cout<<"foo and bar completo\n";*/
 return 0;
}