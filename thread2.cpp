#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
using namespace std;

void sumRange(const vector<int>& arr, int start, int end, long long result){
    result = accumulate(arr.begin()+start,arr.begin()+ end,0LL);
}

int main(){
   /* conts int size = 1000000;
    vector<int> ar(size, 1);
    long long sum1 =0, sum2 =0;

    thread t1(sumRange, cref(arr), 0, size / 2, ref(sum1));
    thread t2(sumRange, cref(arr), size / 2, size, ref(sum2));

    t1.join();
    t2.join();

    long long totalSum = sum1 + sum2;
    cout<<"Suma total: "<<totalSum<<endl;
*/
    return 0;
}