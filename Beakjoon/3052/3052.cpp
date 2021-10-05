#include <iostream>
using namespace std;
int main(){
    int a, n=0, cnt[42]={0};
    for(int i=0;i<10;i++){
        cin>>a;
        if(cnt[a%42]==0){
            n++;
            cnt[a%42]++;
        }
    }
    cout<<n;
}