#include <iostream>
using namespace std;
int k;
void aaa(int a, int b){
    if(a%b==0) k=b;
    else aaa(b, a%b);
}
int main(){
    int a, b;
    cin>>a>>b;
    aaa(a, b);
    cout<<k<<endl;
    cout<<a*b/k;
}