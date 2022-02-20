#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a, data[100000];
    cin>>a;
    for(int i=0;i<a;i++) cin>>data[i];
    sort(data, data+a);
    cout<<data[0]*data[a-1];
}