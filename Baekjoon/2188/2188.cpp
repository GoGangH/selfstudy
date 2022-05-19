#include <iostream>
#include <vector>
using namespace std;
vector<int> cow[1005];
int arr[1005]={0,};
bool chk_barn[1005];
bool dfs(int x){
    for(int i=0;i<cow[x].size();i++){
        int tmp= cow[x][i];
        if(chk_barn[tmp]) continue;
        chk_barn[tmp]= true;

        if(arr[tmp]==0 || dfs(arr[tmp])){
            arr[tmp] = x;
            return true;
        }
    }
    return false;
}
int main(){
    int n, m, result=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int barn;
        cin>>barn;
        for(int j=0;j<barn;j++){
            int way;
            cin>>way;
            cow[i].push_back(way);
        }
    }

    for(int i=1;i<=n;i++){
        fill(chk_barn, chk_barn+m+1, false);
        if(dfs(i)) result++;
    }
    cout<< result<<endl;
}