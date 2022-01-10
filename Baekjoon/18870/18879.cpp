#include <iostream>
#include <set>
using namespace std;
int main(){
    set<int> s;
    int n, p, ka[1000000], ba[1000000]={0,};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p;
        s.insert(p);
        ba[i]=p;
    }
    for(int i=0;i<n;i++){
        int cnt=0;
        for(auto it = s.begin(); it != s.end(); it++){
            if(ba[i]==*it) break;
            cnt++;
        }
        cout<<cnt<<" ";
    }
}