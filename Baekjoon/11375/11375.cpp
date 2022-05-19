/* 이분 탐색 */
#include <iostream>
#include <vector>
using namespace std;
vector<int> people[1005]; // 경로 저장
bool chk_work[1005];
int arr[1005];
bool dfs(int x){
    for(int i=0;i<people[x].size();i++){
        int tmp = people[x][i]; //x가 갈 수 있는 곳
        if(chk_work[tmp]) continue; //x가 이미 이동한적 있으면 건너뛰기
        chk_work[tmp] = true; //이동 가능한지 체크 해보았다는 것을 체크

        if(arr[tmp]==0 || dfs(arr[tmp])){ //이동할 node가 비어 있거나 이동할 node에 다른 사람이 있다면 다른사람이 다른 곳으로 옮길수 있는지를 체크
            arr[tmp]=x; //해당 node에 x가 이동했다고 저장
            return true; //이동에 성공했다는 것을 return
        }
    }
    return false; //x는 이동하지 못했음
}
int main(){
    int n, m, work, work_num, result=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>work;
        for(int j=0;j<work;j++){
            cin>>work_num;
            people[i].push_back(work_num);
        }
    }

    for(int i=1;i<=n;i++){
        fill(chk_work, chk_work+m+1, false); // 매번 i가 이동했는지 안했는지를 체크해주기위해 false로 초기화
        if(dfs(i)) result++; // return이 true일때 최대 사용자수 +1
    }
    cout<<result;
}