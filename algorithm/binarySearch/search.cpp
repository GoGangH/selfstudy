#include <iostream>
using namespace std;
int t[1000];
int search(int s, int e, int find_num);
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m, find_num;
        cin>>m>>find_num;
        for(int j=0;j<m;j++) cin>>t[j];
        cout<<search(0, m-1, find_num)<<endl;
    }
}
int search(int s, int e, int find_num){
    if(e<s) return -1;

    int m = (s + e)/2;

    if(t[m]==find_num) return m;
    else if(t[m]>find_num) return search(s, m-1, find_num);
    else return search(m+1, e, find_num);
}