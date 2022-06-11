#include <iostream>
#include <vector>
using namespace std;
int way[51][51]={0,};
int n;
int fin(int x){
    int t, chk[100]={0,}, result=0;
    vector<int> a;
    a.push_back(x);
    while(!a.empty()){
        t = a.back();
        a.pop_back();
        if(chk[t]==1) continue;
        chk[t]=1;
        for(int i=0;i<n;i++){
            if(way[t][i]==1 && chk[i]==0){
                a.push_back(i);
                way[t][i]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        int cnt=0;
        if(chk[i]==0){
            for(int j=0;j<n;j++){
                if(way[i][j]==1){
                    if(chk[j]==0) cnt++;
                }
            }
            if(cnt==0) result++;
        }
    }
    return result;
}
int main(){
    int x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x!=-1)
            way[x][i]=1;
    }
    cin>>x;
    cout<<fin(x);
}