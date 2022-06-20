#include <iostream>
using namespace std;
int arr[9999999];
int find(int x) {
    if (arr[x] == x) return x;
    else return find(arr[x]);
}
int main(){
    int n, m, x, y, result=0;
    cin>>n>>m;
    for(int i=0;i<n;i++) arr[i]=i;

    for(int i=0;i<m;i++){
        cin>>x>>y;

        x=find(x);
        y=find(y);
        
        if(x==y){
            result=i+1;
            break;
        }
        else arr[y] = x;
    }
    cout<<result;
}