#include <iostream>
#include <algorithm>
using namespace std;
int find(int n);
int t[1001];
int main(){
    int n, m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        for(int j=0;j<m;j++) cin>>t[j];
        cout<<find(m-1)<<endl;
    }
}
int find(int n){
    if(n==-0) return t[n];
    return max(t[n], find(n-1));
}