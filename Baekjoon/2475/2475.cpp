#include <iostream>
using namespace std;
int main(){
    int a, hap=0;
    for(int i=0;i<5;i++){
        cin>>a;
        hap+=a*a;
    }
    cout<<hap%10;
}