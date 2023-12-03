#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a[1001];
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int first = 0;
    int cnt = 1, result = 1;
    for(int i=1;i<n;i++){
        if(a[i]<a[first]){
            first = i;
            cnt = 0;
        }
        cnt++;
        result = max(result, cnt);
    }
    cout<<result<<endl;
  }
}