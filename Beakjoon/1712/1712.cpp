#include <iostream>
using namespace std;
int son(int a,int b,int c){
    int hap=a;
    if(b>=c) return -1;
    return (a/(c-b))+1;
}
int main(){
    int a, b, c;
    cin>>a>>b>>c;
    cout<<son(a, b, c);
}