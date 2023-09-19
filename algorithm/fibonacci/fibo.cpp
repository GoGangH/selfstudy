#include <iostream>
using namespace std;
int fibonacci(int);
int main(){
    int n, m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        cout<<fibonacci(m)<<endl;
    }
}
int fibonacci(int a){
    if(a <= 1) return a;
    return fibonacci(a-1) + fibonacci(a-2);
}