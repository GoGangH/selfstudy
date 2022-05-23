#include <iostream>
using namespace std;
int main(){
    int n, x, min=9999999, hap=0;
    for(int i=0;i<7;i++){
        cin>>x;
        if(x%2==1){
            hap+=x;
            if(min>x) min=x;
        }
    }
    if(hap==0){
        cout<<-1;
        return 0;
    }
    cout<<hap<<endl;
    cout<<min;
}