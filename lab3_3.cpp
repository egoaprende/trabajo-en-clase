#include <iostream>
using namespace std;

int main(){
    int array[5] = {1, 2, 3, 4, 5};
    int* punteroin =&array[0];
    int* punterofin=&array[4];

    for(int i =0;i < 5;++i){
        cout<<"direccion del array:("<<i<<")"<<&array[i]<<endl;
    }
    cout <<"tamano del array en bytes:"<<sizeof(array)<< "bytes" <<endl;
    cout<< "diferencias entre los punteros inicio y fin    "<< (punteroin - punterofin)<<endl;
    punteroin++;
    cout<<"comprobacion"<<punteroin<<endl;
    return 0;


}