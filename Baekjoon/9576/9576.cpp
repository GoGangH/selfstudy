#include <iostream>
#include <vector>
using namespace std;
vector<int> book[1005];
bool chk_book[1005];
int chk_student[1005];
void clearV(int n){
    for(int i=1;i<=n;i++){
        while(!book[i].empty()) book[i].pop_back();
    }
}
bool dfs(int x){
    for(int i=0;i<book[x].size();i++){
        int tmp = book[x][i];
        if(chk_book[tmp]) continue;
        chk_book[tmp]=true;

        if(chk_student[tmp]==0 || dfs(chk_student[tmp])){
            chk_student[tmp]=x;
            return true;
        }
    }
    return false;
}
int main(){
    int t, n, m;
    cin>>t;
    for(int i=0;i<t;i++){
        int front, back;
        cin>>n>>m;
        clearV(m);
        fill(chk_student, chk_student+n+1, 0);
        for(int j=1;j<=m;j++){
            cin>>front>>back;
            for(int k=front;k<=back;k++){
                book[j].push_back(k);
            }
        }
        int result=0;
        for(int j=1;j<=m;j++){
            fill(chk_book, chk_book+n+1, false);
            if(dfs(j)) result++;
        }
        cout<<result<<endl;
    }
}