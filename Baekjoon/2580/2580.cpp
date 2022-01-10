#include <iostream>
#include <vector>
using namespace std;
int doku[10][10]={0,};
int main(){
    int a;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>a;
            if(a==0) cout<<i<<" "<<j<<endl;
            doku[i][j]=a;
        }
    }
}