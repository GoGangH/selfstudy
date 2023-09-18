#include <iostream>
#include <algorithm>
using namespace std;
void select();
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        select();
    }
}
void select(){
    int n, t[1001], a=0, b=0;
    cin>>n;
    for(int i=0;i<n;i++)cin>>t[i];

    for(int i=0;i<n-1;i++){
        int k=i;
        for(int j=i+1;j<n;j++){
            a++;
            if(t[j]<t[k]){
                k = j;
            }
        }
        if(k != i){
            swap(t[i], t[k]);
            b++;
        }
    }
    cout<<a<<" "<<b<<endl;
}