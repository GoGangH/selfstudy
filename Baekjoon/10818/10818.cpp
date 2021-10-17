#include <iostream>
using namespace std;
int main(){
    int n, a, min=1000000, max=-1000000;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a<min) min=a;
        if(max<a) max=a;
    }
    cout<<min<<" "<<max;
}