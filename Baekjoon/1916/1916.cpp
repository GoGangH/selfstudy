#include <iostream>
using namespace std;
int n, p, way[1001][1001]={-1,};
int dijkstra(int x){
    int now, min=99999999, chk[1001]={0,}, wayR[1001]={-1,};
    for(int i=0;i<=n;i++) wayR[i]=-1;
    wayR[x]=0;
    now = x;
    while(1){
        chk[now]=1;
        for(int i=1;i<=n;i++){
            if(chk[i]==0 && way[now][i]!=-1){
                if(wayR[i]==-1 || wayR[i]>wayR[now]+way[now][i]){
                    wayR[i]=wayR[now]+way[now][i];
                }
            }
        }
        int min=999999999;
        for(int i=1;i<=n;i++){
            if(chk[i]==0 && min>wayR[i] && wayR[i]!=-1){
                min=wayR[i];
                now=i;
            }
        }
        if(min==999999999) break;
    }
    return wayR[p];
}
int main(){
    int m, s;
    cin>>n>>m;

    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) way[i][j]=-1;

    for(int i=0;i<m;i++){
        int x, y, z;
        cin>>x>>y>>z;
        if(way[x][y]>z || way[x][y]==-1) way[x][y]=z;
    }
    cin>>s>>p;
    cout<<dijkstra(s);
}