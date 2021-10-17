#include <iostream>
using namespace std;
int main(){
    int n, m, chk[10001]={0};
    cin>>n;
    chk[1]=1;
    for(int i=2;i<10001;i++){
        if(chk[i]==1) continue;
        for(int j=i*2;j<10001;j+=i){
            if(chk[j]==1) continue;
            chk[j]=1;
        }
    }
    for(int i=0;i<n;i++){
        cin>>m;
        for(int j=m/2;j<=m;j++){
            if(chk[j]==1) continue;
            if(chk[m-j]==0){
                cout<<m-j<<" "<<j<<'\n';
                break;
            }
        }
    }
}