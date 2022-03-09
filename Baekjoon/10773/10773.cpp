#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> k;
    int n, a, hap=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a==0) k.pop_back();
        else k.push_back(a);
    }
    for(int i=0;i<k.size();i++){
        hap+=k[i];
    }
    cout<<hap;
}