#include <iostream>
#include <algorithm>
using namespace std;
void shell();
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        shell();
    }
}

void shell(){
    int n, t[1001], a=0, b=0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>t[i];

    int gap = n/2;

    while(gap > 0){
        for(int i=gap;i<n;i++){
            int tmp = t[i];
            int j;
            for(j=i;j>=gap;j-=gap){
                a++;
                if(t[j-gap]>tmp){
                    b++;
                    t[j] = t[j-gap];
                }
                else break;
            }
            t[j] = tmp;
        }
        gap /= 2;
    }
    cout<<a<<" "<<b<<endl;
}