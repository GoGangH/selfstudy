#include <iostream>
#include <string>
using namespace std;
void reverse(int);
string a;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        reverse(a.length()-1);
        cout<<endl;
    }
}
void reverse(int n){
    cout<<a[n];
    if(n>0) reverse(n-1);
}