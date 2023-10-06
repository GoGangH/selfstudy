#include <iostream>
using namespace std;
int factorial(unsigned long long int a);
int main(){
    int n, m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        cout<<factorial(m)<<endl;
    }
}
int factorial(unsigned long long int a){
    if(a==0) return 1;
    return a * factorial(a-1);
}