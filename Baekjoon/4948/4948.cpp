#include <iostream>
using namespace std;
int main(){
    int n, chk[246914]={0}, cnt=0;
    chk[1]=1;
    for(int i=2;i<=246912;i++){
        if(chk[i]==1) continue;
        for(int j=i*2;j<=246912;j+=i){
            if(chk[j]==1) continue;
            chk[j]=1;
        }
    }
    while(true){
        cin>>n;
        if(n==0) break;
        cnt=0;
        for(int i=n+1;i<=n*2;i++){
            if(chk[i]==0) cnt++;
        }
        cout<<cnt<<'\n';
    }
}