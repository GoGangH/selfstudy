#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    int a=0, b=0, k=1;
    string n, m;
    cin>>n>>m;
    for(int i=0;i<n.size();i++){
        a+=k*(n[i]-48);
        k*=10;
    }
    k=1;
    for(int i=0;i<m.size();i++){
        b+=k*(m[i]-48);
        k*=10;
    }
    cout<<max(a, b);
}