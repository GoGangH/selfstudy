#include <iostream>
using namespace std;
int main(){
    int x, y, z, cnt=0, mx=0;
    cin>>x>>y>>z;
    if(x==y && y==z) cout<<10000+z*1000;
    else if(x==y) cout<<1000+x*100;
    else if(y==z) cout<<1000+y*100;
    else if(x==z) cout<<1000+x*100;
    else{
        if(mx<x) mx=x;
        if(mx<y) mx=y;
        if(mx<z) mx=z;
        cout<<mx*100;
    }
}