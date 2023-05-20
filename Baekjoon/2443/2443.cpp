#include <iostream>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, t;
    cin>>n;
    t=n*2-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int j=t;j>0;j--){
            cout<<"*";
        }
        cout<<"\n";
        t-=2;
    }
}