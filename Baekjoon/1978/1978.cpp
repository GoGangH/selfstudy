#include <iostream>
using namespace std;
bool math(int n){
    bool a=true;
    if(n<=1) return false;
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            a=false;
            break;
        }
    }
    return a;
}
int main(){
    int n, a, cnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(math(a)) cnt++;
    }
    cout<<cnt;
}