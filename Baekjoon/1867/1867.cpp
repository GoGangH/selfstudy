#include <iostream>
#include <vector>
using namespace std;
vector<int> stone[10005];
bool doll[10000];
int joop[10000];
bool dfs(int x){
    if(doll[x]) return false;
    doll[x]=true;

    for(int i=0;i<stone[x].size();i++){
        int tmp = stone[x][i];
        if(joop[tmp]==0 || dfs(joop[tmp])){
            joop[tmp]=x;
            return true;
        }
    }
    return false;
}
int main(){
    int n, m, x, y;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        stone[x].push_back(y);
    }
    int result=0;
    for(int i=1;i<=n;i++){
        fill(doll, doll+n+1, false);
        if(dfs(i)) result++;
    }
    cout<<result;
}