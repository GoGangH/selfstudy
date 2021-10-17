#include <iostream>
using namespace std;
int main(){
    int a, b, clock=0;
    cin>>a>>b;
    clock+=a*60+b-45;
    if(clock<0) clock=1380+(60+clock);
    cout<<clock/60<<" "<<clock%60;
}