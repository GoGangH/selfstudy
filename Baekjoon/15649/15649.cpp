#include <iostream>
#include <vector>
using namespace std;
int m, n, chk[10]={0,};
vector<int> k;
void bak(int a){
    if(a==m){
        for(int i=0;i<k.size();i++){
            printf("%d ", k[i]);
        }
        printf("\n");
    }
    for(int i=1;i<=n;i++){
        if(chk[i]==0){
            chk[i]=1;
            k.push_back(i);
            bak(a+1);
            chk[i]=0;
            k.pop_back();
        }
    }
    return;
}
int main(){
    cin>>n>>m;
    bak(0);
}