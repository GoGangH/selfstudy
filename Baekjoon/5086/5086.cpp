#include <iostream>
using namespace std;
int main(){
    int n, m;
    while(1){
        cin>>n>>m;
        if(n+m==0) break;
        if(m%n==0 && m>n){
            cout<<"factor"<<endl;
        }
        else if(n%m==0 && n>m){
            cout<<"multiple"<<endl;
        }
        else{
            cout<<"neither"<<endl;
        }
    }
}
