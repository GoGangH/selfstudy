#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int d[101];
int divide_conquer(int s, int e);
int main(){
    int n, m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        for(int j=0;j<m;j++) cin>>d[j];
        int result = divide_conquer(0, m-1);
        if(result < 0) cout<<0<<endl;
        else cout<<result<<endl;
    }
}
int divide_conquer(int s, int e){
    int l_max = INT_MIN, r_max = INT_MIN, sum=0, m = (s+e)/2;

    if(s==e) return d[s];

    for(int i=m;i>=s;i--){
        sum += d[i];
        l_max = max(l_max, sum);
    }

    sum = 0;
    for(int i=m+1;i<=e;i++){
        sum+=d[i];
        r_max = max(r_max, sum);
    }

    return max(l_max + r_max, max(divide_conquer(s, m), divide_conquer(m+1, e)));
}