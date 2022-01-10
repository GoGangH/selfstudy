#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> k;
void bak(int a, int b){
    if(b==m){
        for(int i=0;i<k.size();i++){
            cout<<k[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=a;i<=n;i++){
        k.push_back(i);
        bak(i, b+1);
        k.pop_back();
    }
    return;
}
int main(){
    cin>>n>>m;
    bak(1, 0);
}