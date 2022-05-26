#include <iostream>
#include <vector>
using namespace std;
vector<int> job[1005];
bool visit[1005];
int work[1005];
bool dfs(int x){
    for(int i=0;i<job[x].size();i++){
        int tmp = job[x][i];
        if(visit[tmp]) continue;
        visit[tmp]=true;

        if(work[tmp]==0 || dfs(work[tmp])){
            work[tmp]=x;
            return true;
        }
    }
    return false;
}
int main(){
    int n, m, s, x, y;
    bool findjob = true;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>x;
        for(int j=0;j<x;j++){
            cin>>y;
            job[i].push_back(y);
        }
    }
    int result=0;
    for(int i=1;i<=n;i++){
        fill(visit, visit + m+1, false);
        if(dfs(i)) result++;
    }
    while(s>0){
        findjob = false;
        for(int i=1;i<=n;i++){
            if(s==0) break;
            fill(visit, visit + m+1, false);
            if(dfs(i)){
                result++;
                s--;
                findjob=true;
            }
        }
        if(findjob == false) break;
    }
    cout<<result;
}