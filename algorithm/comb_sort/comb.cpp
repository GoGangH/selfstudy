#include <iostream>
#include <algorithm>
using namespace std;
void comb();
int main(){
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        comb();
    }
}

void comb(){
    int n, t[1001], gap, a=0, b=0;
    bool chk = false;

    cin >> n;
    gap = n;

    for(int i=0;i<n;i++) cin>>t[i];

    while(!chk){
        gap /= 1.3;
        if(gap < 2){
            gap = 1;
            chk = true;
        }
        int i=0;
        while(i+gap < n){
            a++;
            if(t[i]>t[i+gap]){
                b++;
                swap(t[i], t[i+gap]);
                chk = false;
            }
            i++;
        }
    }
    cout<< a << " "<< b<<endl;
}