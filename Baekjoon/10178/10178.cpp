#include <iostream>
using namespace std;
int main(){
    int n, x, y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        printf("You get %d piece(s) and your dad gets %d piece(s).\n", x/y, x%y);
    }
}