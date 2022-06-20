#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long int n, result=0, k=1;
    cin>>n;
    for(int i=0;i<n;i++){
        char x;
        cin>>x;
        result+=int(x-96)*k;
        result%=1234567891;
        k*=31;
        k%=1234567891;
    }
    cout<<result;
}