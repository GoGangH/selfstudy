#include <iostream>
#include <vector>
using namespace std;
vector<int> fish[100];
bool chk[100];
int chk_fish1[100];
int chk_fish2[100];
bool dfs(int x){
    for(int i=0;i<fish[x].size();i++){
        int tmp = fish[x][i];
        if(chk[tmp]) continue;
        chk[tmp]=true;

        if(chk_fish1[tmp]==0 || dfs(chk_fish1[tmp])){
            chk_fish1[tmp]=x;
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int tmp[n+1][3];
    for(int i=1;i<=n;i++){
        cin>>tmp[i][0]>>tmp[i][1]>>tmp[i][2];
    }

    for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (tmp[i][0] == tmp[j][0] && tmp[i][1] == tmp[j][1] && tmp[i][2] == tmp[j][2]) { //현재와 다음 상어의 스탯이 다 동일하면
				fish[i].push_back(j); //i가 j 잡아먹음의 관계
			}
			else if (tmp[i][0] >= tmp[j][0] && tmp[i][1] >= tmp[j][1] && tmp[i][2] >= tmp[j][2]){
			    fish[i].push_back(j); //i가 j잡아먹은거
			}
			else if (tmp[i][0] <= tmp[j][0] && tmp[i][1] <= tmp[j][1] && tmp[i][2] <= tmp[j][2]){
			    fish[j].push_back(i); //j가 i잡아먹은거
			}
		}
	}

    int result=0;
    for(int j=0;j<2;j++){
        for(int i=1;i<=n;i++){
            fill(chk, chk+n+1, false);
            if(dfs(i)) result++;
        }
    }
    cout<<n-result;
}