#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n, m, w, h, dap=0;
    cin>>n>>m>>w>>h;
    dap=min(n, m);
    dap=min(dap, w-n);
    dap=min(dap, h-m);
    cout<<dap;
}