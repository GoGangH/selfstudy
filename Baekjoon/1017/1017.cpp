#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool eratos[5000];
vector<int> era[100];
vector<int> eratmp[100];
bool chk[5000];
int chk_so[5000];
bool dfs(int n){
    for(int i=0;i<eratmp[n].size();i++){
        int tmp= eratmp[n][i];
        if(chk[tmp]) continue;
        chk[tmp]=true;

        if(chk_so[tmp]==0 || dfs(chk_so[tmp])){
            chk_so[tmp]=n;
            return true;
        }
    }
    return false;
}
int main(){
    int n, arr[100] ,arr1[100], arr2[100], cnt1=1, cnt2=1, k=0;
    bool chkhol=false;
    fill(eratos, eratos+2000, true);
    for(int i=2;i<=2000;i++){
		if(eratos[i]==false) continue;
		for(int j=i+i;j<=2000;j+=i){
			if(eratos[j] == false) continue;
			else eratos[j]=false;
		} 
	}
    cin>> n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(arr[0]%2==1) chkhol=true;
    for(int i=0;i<n;i++){
        int x = arr[i];
        if(chkhol==true){
            if(x%2==0) arr2[cnt2++]=x;
            else arr1[cnt1++]=x;
        }
        else{
            if(x%2==0) arr1[cnt1++]=x;
            else arr2[cnt2++]=x;
        }
    }
    if(cnt1!=cnt2){
        cout<<-1;
        return 0;
    }
    for(int i=1;i<cnt1;i++){
        for(int j=1;j<cnt2;j++){
            if(eratos[arr1[i]+arr2[j]]){
                era[i].push_back(j);
                eratmp[i].push_back(j);
            }
        }
    }
    while(!eratmp[1].empty()){
        eratmp[1].pop_back();
    }
    vector<int> answer;
    for(int i=0;i<era[1].size();i++){
        eratmp[1].push_back(era[1][i]);
        int result = 1;
        fill(chk_so, chk_so+n+1, 0);
        for(int j=1;j<cnt1;j++){
            fill(chk, chk+n+1, false);
            if(dfs(j)) result++;
        }
        if(result==cnt1){
            answer.push_back(arr2[era[1][i]]);
            k=true;
        }
        eratmp[1].pop_back();
    }
    if(answer.empty()){
        cout<<-1;
        return 0;
    }
    sort(answer.begin(), answer.end());
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
}