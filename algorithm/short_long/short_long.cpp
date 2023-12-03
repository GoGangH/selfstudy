#include <iostream>
using namespace std;
int m, d[1001];
int short_long(int x);
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int result = 0;
        cin >> m;
        for (int j=0;j<m;j++) cin>>d[j];
        for (int j=0;j<m;j++) result = max(result, short_long(j));
        cout<<result<<endl;
    }
}
int short_long(int x) {
    int first = d[x], result = 1;
    while(x<m){
        x++;
        if(d[x]<first || x>=m) return result;
        result++;
    }
    return result;
}