#include <iostream>
using namespace std;
int fibo(int n){
    int a=0, b=1, c=0, cnt=2;
    if(n<2) return 1;
    while(cnt<=n){
        c=a+b;
        a=b;
        b=c;
        cnt++;
    }
    return c;
}
int main(){
    int n;
    cin>>n;
    cout<<fibo(n);
}