#include <iostream>
#include <math.h>
using namespace std;
void hanoi(int n, int a, int b, int c, unsigned long long int m);
int main() {
    int n, num_disks;
    unsigned long long int m;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>num_disks>>m;
        hanoi(num_disks,1,2,3, m);
    }
}
void hanoi(int n, int a, int b, int c, unsigned long long int m)
{
    if(n==1){
        cout<<a<<" "<<c<<endl;
        return;
    }
    else{
        unsigned long long int p = pow(2, n-1);
        if(p == m){
            cout<<a<<" "<<c<<endl;
            return;
        }
        else if(p > m){
            hanoi(n-1, a, c, b, m);
        }
        else{
            hanoi(n-1, b, a, c, m-p);
        }
    }
}