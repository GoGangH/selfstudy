#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    int k[100]={0};
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(k[a[i]-97]==0){
            k[a[i]-97]=i+1;
        }
    }
    for(int i=0;i<26;i++){
        cout<<k[i]-1<<" ";
    }
}