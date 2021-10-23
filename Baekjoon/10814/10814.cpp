#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(pair<int, string>a, pair<int, string>b){
    return a.first<b.first;
}
int main(){
    vector<pair<int, string> > a;
    int n, m;
    string t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m>>t;
        a.push_back(pair<int, string>(m, t));
    }
    stable_sort(a.begin(), a.end(), compare);
    for(int i=0;i<n;i++) cout<<a[i].first<<" "<<a[i].second<<'\n';
}