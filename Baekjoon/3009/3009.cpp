#include <iostream>
using namespace std;
int main(){
    int a[3], b[3];
    for(int i=0;i<3;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(a[i]==a[j]){
                a[i]=-1;
                a[j]=-1;
                break;
            }
        }
        for(int j=i+1;j<3;j++){
            if(b[i]==b[j]){
                b[i]=-1;
                b[j]=-1;
                break;
            }
        }
    }
    for(int i=0;i<3;i++){
        if(a[i]!=-1) cout<<a[i]<<" ";
    }
    for(int i=0;i<3;i++){
        if(b[i]!=-1) cout<<b[i];
    }
}