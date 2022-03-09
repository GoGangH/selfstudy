#include <iostream>
using namespace std;
int main(){
    int n,k=1;
    cin>>n;
    for(int i=n-1;i>=0;i--){
        for(int j=i;j>0;j--) cout<<" ";
        for(int j=0;j<k;j++) cout<<"*";
        cout<<endl;
        k+=2;
    }
}