#include <iostream>
#include <string>
using namespace std;
int main(){
    int n, cnt=0, c=0;
    string a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        c=0;
        int check[26]={0};
        check[a[0]-97]++;
        for(int j=1;j<a.size();j++){
            if(a[j]!=a[j-1]){
                if(check[a[j]-97]!=0){
                    c++;
                    break;
                }
                check[a[j]-97]++;
            }
        }
        if(c==0) cnt++;
    }
    cout<<cnt;
}