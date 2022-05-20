#include <iostream>
#include <vector>
using namespace std;
vector<int> job[1005];
bool chk_way[1005];
int chk_node[1005];
int dfs(int x){
    for(int i=0;i<job[x].size();i++){
        int tmp = job[x][i];
        if(chk_way[tmp]) continue;
        chk_way[tmp]=true;

        if(chk_node[tmp]==0 || dfs(chk_node[tmp])){
            chk_node[tmp]=x;
            return true;
        }
    }
    return false;
}
int main(){
    int n, m, x, y, result=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        for(int j=0;j<x;j++){
            cin>>y;
            job[i].push_back(y);
        }
    }

    for(int i=1;i<=n;i++){
        if(job[i].size()!=0){
            fill(chk_way, chk_way+m+1, false);
            result+= dfs(i);
            fill(chk_way, chk_way+m+1, false);
            result+= dfs(i);
        }
    }
    cout<<result;
}