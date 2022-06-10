#include <iostream>
#include <queue>
#include <functional> 
using namespace std;
struct cmp {
    bool operator()(int x, int y) {
        return x < y;
    }
};
int main(){
    priority_queue<int, vector<int>, cmp> box;
    int n, x, y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x==0){
            if(!box.empty()){
                cout<<box.top()<<endl;
                box.pop();
            }
            else cout<<-1<<endl;
            continue;
        }
        else{
            for(int j=0;j<x;j++){
                cin>>y;
                box.push(y);
            }
        }
    }
}