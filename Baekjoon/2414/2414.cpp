#include <iostream>
#include <vector>
using namespace std;
vector<int> holl[100];
bool match[100];
int waychk[100];
bool dfs(int x){
    for(int i=0;i<holl[x].size();i++){
        int tmp = holl[x][i];
        if(match[tmp]) continue;
        match[tmp]=true;

        if(waychk[tmp]==0 || dfs(waychk[tmp])){
            waychk[tmp]= true;
            return true;
        }
    }
    return false;
}
int main(){
    int n, m;
    char x;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>x;
            if(x=='*') holl[i].push_back(j); 
        }
    }

    int result =0;
    for(int i=1;i<=n;i++){
        fill(match, match+n+1, false);
        if(dfs(x)) result++;
    }
    cout<<result;
}