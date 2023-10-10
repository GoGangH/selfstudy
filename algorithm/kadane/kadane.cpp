#include <iostream>
#include <algorithm>
using namespace std;
void kadane();
int m, d[101];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        for(int j=0;j<m;j++) cin>>d[j];
        kadane();
    }
}
void kadane(){
    int s=0, e=0, t[101] = {0,}, idx[101] = {0,}, result = d[0];
    t[0] = d[0];
    for(int i=1;i<m;i++){
        t[i] = max(t[i-1] + d[i], d[i]);
        if(t[i-1] + d[i] > d[i]) idx[i] = idx[i-1];
        else idx[i] = i;

        if(result < t[i]){
            result = t[i];
            s=idx[i];
            e=i;
        }
    }

    if(result <= 0){
        result = 0;
        s = -1;
        e = -1;
    }
    cout<<result<<" "<<s<<" "<<e<<endl;
}