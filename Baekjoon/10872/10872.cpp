#include <iostream>
using namespace std;
int pec(int n, int hap){
    if(n<=1) return hap;
    return pec(n-1, hap*=n);
}
int main(){
    int n;
    cin>>n;
    cout<<pec(n, 1);
}