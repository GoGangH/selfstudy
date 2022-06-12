#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int n, m, arr[101][101]={0,}, answer[100]={0,}, cnt=0;
void fin(int x, int y){
    int way[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
    int x1, y1;
    vector<pair<int, int> > pos;

    pos.push_back(make_pair(x, y));

    while(!pos.empty()){
        x1=pos.back().first;
        y1=pos.back().second;
        pos.pop_back();
        arr[x1][y1]=1;
        answer[cnt]++;

        for(int i=0;i<4;i++){
            int tmpx = x1+way[i][0];
            int tmpy = y1+way[i][1];
            if(tmpx<n && tmpx>=0 && tmpy<m && tmpy>=0 && arr[tmpx][tmpy]==0){
                arr[tmpx][tmpy]=1;
                pos.push_back(make_pair(tmpx, tmpy));
            }
        }
    }
}
int main(){
    int k, x1, y1, x2, y2;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        cin>>x1>>y1>>x2>>y2;
        for(int j=y1;j<y2;++j){
            for(int p=x1;p<x2;++p){
                arr[j][p]=1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                fin(i, j);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    sort(answer, answer+cnt);
    for(int i=0;i<cnt;i++) cout<< answer[i]<<" ";
}