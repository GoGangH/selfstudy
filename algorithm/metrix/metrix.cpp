#include <iostream>
using namespace std;
int matrix(int n);
int d[101], mm[101][101]={0,}, pp[101][101]={0,};
void order(int i, int j);
int main(){
    int n, m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        for(int j=0;j<=m;j++)
            for(int k=0;k<=m;k++){
                mm[j][k]= 0;
                pp[j][k]=0;
            }

        for(int j=0;j<=m;j++) cin>>d[j];
        cout<<matrix(m+1)<<endl;
    }
}

int matrix(int n){
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            int k = i + j - 1;
            mm[j][k] = 0xfffffff;
            for(int p=j;p<k;p++){
                int tmp = mm[j][k];
                mm[j][k] = min(mm[j][k], mm[j][p] + mm[p+1][k] + d[j-1]*d[p]*d[k]);
                if(mm[j][k]!=tmp)
                    pp[j][k] = p;
            }
        }
    }
    order(1, n-1);
    cout<<endl;
    return mm[1][n-1];
}
void order(int i, int j){
    if(i==j) cout<<"M"<<i;
    else{
        int k = pp[i][j];
        cout<<"(";
        order(i, k);
        order(k+1, j);
        cout<<")";
    }
}