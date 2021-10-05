#include <iostream>
using namespace std;
int main(){
    int n, m, k[1000]={0};
    double a, b, hap=0.0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        a=0.0;
        for(int j=0;j<m;j++){
            cin>>k[j];
            a+=k[j];
        }
        a/=m;
        hap=0.0;
        for(int j=0;j<m;j++){
            if(a<k[j]){
                hap++;
            }
        }
        b=hap/m;
        cout<<fixed;
        cout.precision(3);
        cout<<b*100<<"%"<<endl;
    }
}