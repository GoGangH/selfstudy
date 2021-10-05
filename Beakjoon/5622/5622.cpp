#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    int hap=0, num[26]={3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
    cin>>a;
    for(int i=0;i<a.size();i++) hap+=num[a[i]-65];
    cout<<hap;
}