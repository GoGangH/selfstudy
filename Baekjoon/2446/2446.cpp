#include <iostream>
using namespace std;
int main(){
    int n, k=1;
    cin>>n;
    k+=n*2-2;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<i;j++) cout<<" ";
        for(int j=k;j>0;j--) cout<<"*";
        cout<<endl;
        k-=2;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=0;j--) cout<<" ";
        for(int j=0;j<k;j++) cout<<"*";
        cout<<endl;
        k+=2;
    }
}