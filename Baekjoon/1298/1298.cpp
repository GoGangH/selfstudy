#include <iostream>
#include <vector>
using namespace std;
vector<int> notebook[5002];
bool chk[5002];
int chk_book[5002];
bool dfs(int x){

    for(int i=0;i<notebook[x].size();i++){
        int tmp = notebook[x][i];
        if(chk[tmp]) continue;
        chk[tmp]= true;

        if(chk_book[tmp]==0 || dfs(chk_book[tmp])){
            chk_book[tmp]=x;
            return true;
        }
    }
    return false;
}
int main(){
    int n, m, x, y, result=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        notebook[x].push_back(y);
    }

    for(int i=1;i<=n;i++){
        fill(chk, chk+n+1, false);
        if(dfs(i)) result++;
    }
    cout<<result;
}