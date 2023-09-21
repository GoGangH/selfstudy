#include <iostream>
using namespace std;
int expon(int, int);
int main(){
    int n, a, b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        cout<<expon(a, b)<<endl;
    }
}
int expon(int x, int n){
    if(n==0) return 1;
    if(n%2==1){
        int k = expon(x, (n-1)/2);
        return (x*(k*k))%1000;
    }
    else{
        int k = expon(x, n/2);
        return (k*k)%1000;
    }
}