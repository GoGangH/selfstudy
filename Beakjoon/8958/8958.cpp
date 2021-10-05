#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    int n, sc=0, hap=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        sc=0;
        hap=0;
        for(int j=0;j<a.size();j++){
            if(a[j]=='O'){
                sc++;
                hap+=sc;
            }
            else sc=0;
        }
        cout<<hap<<endl;
    }
}