#include <iostream>
using namespace std;
int main(){
    int h, m, s, x;
    cin>>h>>m>>s;
    cin>>x;
    s+=x%60;
    x/=60;
    m+=s/60;
    s%=60;

    m+=x%60;
    x/=60;
    h+=m/60;
    m%=60;
    
    h+=x;
    h%=24;

    cout<<h<<" "<<m<<" "<<s;

}