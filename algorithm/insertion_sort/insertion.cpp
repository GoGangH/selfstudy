#include <iostream>
#include <algorithm>
using namespace std;
void insert();
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        insert();
    }
}
void insert(){
    int n, t[1001], a=0, b=0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>t[i];

    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            a++;
            if(t[j]<t[j-1]){
                swap(t[j], t[j-1]);
                b++;
            }
            else break;
        }
    }
    cout<<a<<" "<<b<<endl;
}