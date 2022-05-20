#include <iostream>
#include <vector>
using namespace std;
vector<int> job[1005];
bool chk_way[1005];
int chk_work[1005];
bool dfs(int x){
    for(int i=0;i<job[x].size();i++){
        int tmp=job[x][i];
        if(chk_way[tmp]) continue;
        chk_way[tmp]=true;

        if(chk_work[tmp]==0 || dfs(chk_work[tmp])){
            chk_work[tmp]=x;
            return true;
        }
    }
    return false;
}
int main(){
    int n, m, k, x, y, result=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>x;
        for(int j=0;j<x;j++){
            cin>>y;
            job[i].push_back(y);
        }
    }

    for(int i=1;i<=n;i++){
        fill(chk_way, chk_way+m+1, false);
        if(dfs(i)) result++;
    }
    for(int i=1;i<=n;i++){
        fill(chk_way, chk_way+m+1, false);
        if(dfs(i)){
            result++;
            k--;
            if(k==0) break;
        }
    }
    cout<<result;
}