#include <iostream>
using namespace std;
int main(){
    int h, w, n, a;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>h>>w>>n;
        if(n%h!=0)
            cout<<((n%h)*100)+n/h+1<<endl;
        else{
            cout<<h*100+n/h<<endl;
        }
    }
}