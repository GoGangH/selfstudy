#include <iostream>
//#include <utility>
//#include <vector>
//#include <algorithm>
using namespace std;
int main(){
    int n, cnt=0, body[50][2], chk[50];
    //int ck=-1, nm=1, dap[50]={0};
    //vector<pair<int, int> > chk;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>body[i][0]>>body[i][1];
    }
    for(int i=0;i<n;i++){
        cnt=0;
        for(int j=0;j<n;j++){
            if(body[i][0]<body[j][0] && body[i][1]<body[j][1] && i!=j) cnt++;
        }
        //chk.push_back(pair<int,int>(cnt, i));
        chk[i]=cnt+1;
    }
    for(int i=0;i<n-1;i++) cout<<chk[i]<<" ";
    cout<<chk[n-1];
}
    /* 등수 게산 착오
    vector<pair<int, int> >::iterator iter;

    sort(chk.begin(), chk.end());
    cnt=0;
    for(iter = chk.begin();iter != chk.end();iter++){
        if(iter->first!=ck){
            cnt+=nm;
            ck=iter->first;
            nm=1;
            dap[iter->second]=cnt;
        }
        else{
            nm++;
            dap[iter->second]=cnt;
        }
    }
    for(int i=0;i<n-1;i++) cout<<dap[i]<<" ";
    cout<<dap[n-1];
}*/