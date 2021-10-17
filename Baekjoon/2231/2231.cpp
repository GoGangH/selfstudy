#include <iostream>
using namespace std;
int main(){
    int n, t, cnt=0, k;
    cin>>n;
    t=n;
    while(t!=0){
        t/=10;
        cnt++;
    }
    t=n-9*cnt;
    for(int i=t;i<=n;i++){
        k=i;
        cnt=0;
        while(k!=0){
            cnt+=k%10;
            k/=10;
        }
        if(i+cnt==n){
            cout<<i;
            break;
        }
        if(i==n) cout<<"0";
    }
}