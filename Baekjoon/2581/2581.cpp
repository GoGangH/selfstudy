#include <iostream>
using namespace std;
bool decimal(int n){
    if(n<=1) return false;
    for(int i=2;i<=n/2;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    int n, m, hap=0, mi=-1;
    cin>>n>>m;
    for(int i=n;i<=m;i++){
        if(decimal(i)){
            if(mi==-1) mi=i;
            hap+=i;
        }
    }
    if(mi!=-1) cout<<hap<<endl;
    cout<<mi;
}