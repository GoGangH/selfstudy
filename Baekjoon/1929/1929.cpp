#include <iostream>
#include <math.h>
using namespace std;
bool decimal(int n){
    if(n<=1) return false;
    for(int i=2;i<=int(sqrt(n));i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    int n, m;
    cin>>n>>m;
    for(int i=n;i<=m;i++){
        if(decimal(i)) cout<<i<<'\n';
    }
}