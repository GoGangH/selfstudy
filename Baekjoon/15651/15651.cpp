#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> k;
void bak(int a){
    if(a==m){
        for(int i=0;i<k.size();i++){
            printf("%d ", k[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        k.push_back(i);
        bak(a+1);
        k.pop_back();
    }
    return;
}
int main(){
    cin>>n>>m;
    bak(0);
}