#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, a, b;
    vector<pair<int, int> > da;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        da.push_back(pair<int, int>(b, a));
    }
    sort(da.begin(), da.end());
    for(int i=0;i<n;i++){
        cout<<da[i].second<<" "<<da[i].first<<endl;
    }
}