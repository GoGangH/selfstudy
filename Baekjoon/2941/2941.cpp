#include <iostream>
#include <string>
using namespace std;
int main(){
    string a, b[8]={"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    int n=0, k, cnt=0;;
    cin>>a;
    while(n<a.size()){
        cnt++;
        if(a[n]!='c' && a[n]!='d' && a[n]!='l' && a[n]!='n' && a[n]!='s' && a[n]!='z'){
            n++;
            continue;
        }
        for(int i=0;i<8;i++){
            if(a[n]!=b[i][0]) continue;
            k=0;
            for(int j=0;j<b[i].size();j++){
                if(a[n+j]!=b[i][j]){
                    k=1;
                    break;
                }
            }
            if(k==0){
                n+=b[i].size();
                break;
            }
        }
        if(k==1) n++;
    }
    cout<<cnt;
}