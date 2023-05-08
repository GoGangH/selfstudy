#include <iostream>
#include <string>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    string k[51];
    cin>>n;
    for(int i=0;i<n;i++) cin>>k[i];

    for(int i=0;i<k[0].length();i++){
        int num=1;
        for(int j=1;j<n;j++){
            if(k[j][i]!=k[0][i]){
                cout<<"?";
                break;
            }
            num++;
        }
        if(num==n) cout<<k[0][i];
    }
}