#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int, int);
int main(){
    int n, a, b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a<b) swap(a, b);
        cout<<gcd(a, b)<<endl;
    }
}
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}