#include <iostream>
using namespace std;
int main(){
    int n, m, cmt=0, cnt=0, chk=0, t=0, min=999999; 
    char til[50][50];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>til[i][j];
    }

    for(int i=0;i<=n-8;i++){
        for(int j=0;j<=m-8;j++){
            cmt=0;
            cnt=0;
            chk=0;
            t=0;
            for(int k=i;k<i+8;k++){
                t++;
                for(int p=j;p<j+8;p++){
                    if(p==j){
                        if(t%2==0) chk=1;
                        else chk=0;
                    }
                    if(chk==0){
                        chk=1;
                        if(til[k][p]=='W') cnt++;
                        if(til[k][p]=='B') cmt++;
                    }
                    else{
                        chk=0;
                        if(til[k][p]=='W') cmt++;
                        else cnt++;
                    }
                }
            }
            if(min>cnt) min=cnt;
            if(min>cmt) min=cmt;
        }
    }
    cout<<min;
}