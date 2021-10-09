#include <iostream>
#include <string>
using namespace std;
int main(){
    string a, b, d="";
    int x, y, other=0, aa, bb;
    cin>>a>>b;
    x=a.size()-1;
    y=b.size()-1;
    while(x!=-1 || y!=-1){
        if(x==-1){
            aa=0;
            bb=b[y]-48;
        }
        else if(y==-1){
            aa=a[x]-48;
            bb=0;
        }
        else{
            aa=a[x]-48;
            bb=b[y]-48;
        }
        aa+=bb+other;
        other=aa/10;
        d+=char((aa%10)+48);
        if(x>=0) x--;
        if(y>=0) y--;
    }
    if(other!=0) d+='1';
    for(int i=d.size()-1;i>=0;i--) cout<<d[i];
}