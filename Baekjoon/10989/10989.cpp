#include <iostream>
using namespace std;
int main(){
    int n, a, mx=0, cnt[10001]={0,};
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a);
        cnt[a]++;
        if(mx<a){
            mx=a;
        }
    }
    for(int i=0;i<=mx;i++){
        if(cnt[i]==0) continue;
        for(int j=0;j<cnt[i];j++){
            printf("%d\n", i);
        }
    }
}