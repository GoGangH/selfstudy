#include <iostream>
using namespace std;
int main(){
    int max=-9999999, n=0, a;
    for(int i=1;i<=9;i++){
        cin>>a;
        if(max<a){
            max=a;
            n=i;
        }
    }
    cout<<max<<endl<<n;
}