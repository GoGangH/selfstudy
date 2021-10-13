#include <iostream>
using namespace std;
int fibo(int t){
    if(t<=1) return t;
    return fibo(t-1)+fibo(t-2);
}
int main(){
    int n;
    cin>>n;
    cout<<fibo(n);
}
