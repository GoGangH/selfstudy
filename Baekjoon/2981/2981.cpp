#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, chk=0, ka[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>ka[i];
    sort(ka, ka+n);
    for(int i=2;i<=ka[0];i++){
        chk=0;
        for(int j=1;j<n;j++){
            if(ka[j]%i!=ka[0]%i){
                chk++;
                break;
            }
        }
        if(chk==0) cout<<i<<" ";
    }
}