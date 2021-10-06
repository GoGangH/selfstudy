#include <iostream>
using namespace std;
int main(){
    int n, num=0, cnt=0, x=1, y=1, k=0, p=0;
    cin>>n;
    while(cnt<n-1){
        if(num==0){
            k++;
            num=k;
            if(p==0){
                p=1;
                y++;
            }
            else{
                p=0;
                x++;
            }
            cnt++;
            continue;
        }
        if(p==1){
            x++;
            y--;
        }
        else{
            x--;
            y++;
        }
        cnt++;
        num--;
    }
    cout<<x<<"/"<<y;
}