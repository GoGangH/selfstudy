#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string a;
    int m=0, k=0, n=0, cnt[26]={0};
    cin>>a;
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    for(int i=0;i<a.size();i++){
        cnt[a[i]-97]++;
        if(m<cnt[a[i]-97]) m=cnt[a[i]-97];
    }
    for(int i=0;i<26;i++){
        if(m==cnt[i]){
            k++;
            n=i;
        }
    }
    if(k>1) cout<<"?";
    else cout<<char(n+65);
}