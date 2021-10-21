#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, k[1000000];
    cin>>n;
    for(int i=0;i<n;i++) cin>>k[i];
    sort(k, k+n);
    for(int i=0;i<n;i++) cout<<k[i]<<'\n';
}