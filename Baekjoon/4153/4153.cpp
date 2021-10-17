#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int a, b, c, hap, m=0;
    while(true){
        cin>>a>>b>>c;
        hap=0;
        if(a==0 && b==0 && c==0) break;
        m=max(a, b);
        m=max(m, c);
        hap=pow(a, 2)+pow(b, 2)+pow(c, 2)-pow(m, 2);
        if(hap==pow(m, 2)) cout<<"right"<<endl;
        else cout<<"wrong"<<endl;
    }
}