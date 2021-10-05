#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    int cnt=0, n=0;
    getline(cin, a);
    for(int i=0;i<a.size();i++){
        if(i!=0){
            if(a[i]!=' '){
                if(n==0){
                    n++;
                    cnt++;
                }
            }
            else n=0;
        }
        else{
            if(a[i]!=' '){
                n++;
                cnt++;
            }
        }
    }
    cout<<cnt;
}