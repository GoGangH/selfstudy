#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(){
    int n, m, num = 1;
    stack<int> b;
    vector<string> result;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        while(num <= m){
            b.push(num);
            result.push_back("+");
            num+=1;
        }
        if(b.top() == m){
            b.pop();
            result.push_back("-");
        }
        else{
            cout<<"NO";
            return 0;
        }
    }

    for(int i=0;i<result.size();i++) cout<<result[i]<<"\n";
}