#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool compare(string a, string b){
    if(a.size()==b.size()) return a<b;
    return a.size()<b.size();
}
int main(){
    string a[20001];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a, a+n, compare);
    cout<<a[0]<<'\n';
    for(int i=0;i<n;i++){
        if(a[i]!=a[i-1] && i!=0) cout<<a[i]<<'\n';
    }
}