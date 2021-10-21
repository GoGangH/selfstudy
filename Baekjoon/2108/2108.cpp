#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
    int n, mx=-4001, mn=5000, t=0, k=0, cnt=0, da[500000], num[8001]={0,};
    double hap=0.0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>da[i];
        num[da[i]+4000]++;
        if(mx<da[i]) mx=da[i];
        if(mn>da[i]) mn=da[i];
        if(num[da[i]+4000]>t){
            t=num[da[i]+4000];
            k=da[i];
        }
        hap+=da[i];
    }
    sort(da, da+n);
    for(int i=0;i<n;i++){
        if(num[da[i]+4000]==t && da[i-1]!=da[i]){
            cnt++;
            if(cnt==2){
                k=da[i];
                break;
            }
        }
    }
    cout<<round(hap/n)<<endl;
    cout<<da[n/2]<<endl;
    cout<<k<<endl;
    cout<<mx-mn;
}