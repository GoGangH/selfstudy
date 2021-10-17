#include <iostream>
using namespace std;
int main(){
    int t, n, k, flow[15][15]={0};
    cin>>t;
    for(int i=0;i<15;i++){
        flow[i][1]=1;
        flow[0][i]=i;
    }
    for(int i=1;i<15;i++){
        for(int j=1;j<15;j++){
            flow[i][j]=flow[i-1][j]+flow[i][j-1];
        }
    }
    for(int i=0;i<t;i++){
        cin>>k>>n;
        cout<<flow[k][n]<<endl;
    }
}