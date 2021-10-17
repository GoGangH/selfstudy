#include <iostream>
using namespace std;
int main(){
    int n, m, nm[100], mi=9999999, hap, dap;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>nm[i];

    for(int i=0;i<n-2;i++){
        if(nm[i]>m) continue;
        for(int j=i+1;j<n-1;j++){
            if(nm[i]+nm[j]>m) continue;
            for(int k=j+1;k<n;k++){
                hap=nm[i]+nm[j]+nm[k];
                if(hap<=m){
                    if(mi>m-hap){
                        mi=m-hap;
                        dap=hap;
                    }
                }
            }
        }
    }
    cout<<dap;
}