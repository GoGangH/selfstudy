#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, x, now = 0;
    vector<int> yo;

    cin>>n>>x;
    if(n == 1){
        cout<<"<1>";
        return 0;
    }

    for(int i=1;i<=n;i++){
        yo.push_back(i);
    }

    for(int i=0;i<n;i++){
        now+=x-1;
        now %= yo.size();
        if(i==0) cout<<"<"<<yo[now]<<", ";
        else cout<<yo[now]<<", "; 
        yo.erase(yo.begin()+now);

        if(yo.size()<=now) now = 0;
        if(yo.size()==1){
            cout<<yo[0]<<">";
            break;
        }
    }
}