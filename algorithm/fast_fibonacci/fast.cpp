#include <iostream>
#include <math.h>
using namespace std;
void fast_fibo(int, int []);
int main(){
    int n, m;
    cin>>n;
    for(int i=0;i<n;i++){
        int t[2]={0, 1};
        cin>>m;
        fast_fibo(m, t);
        cout<<t[0]<<endl;
    }
}

void fast_fibo(int n, int t[]){
    if(n==0) return;

    fast_fibo(n/2, t);

    int x = (t[0]*(2*t[1] - t[0])) % 1000;
    int y = (t[0]*t[0] + t[1]*t[1]) % 1000;

    if (n%2==0){
        t[0] = x;
        t[1] = y;
    }
    else{
        t[0] = y;
        t[1] = x + y;
    }
}