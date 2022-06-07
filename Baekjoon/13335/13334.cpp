#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int main(){
    int n, w, l, x=0, hp=0, tim=0;
    queue<pair<int, int> > way;
    queue<int> bus;
    cin>>n>>w>>l;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        bus.push(k);
    }
    while(!bus.empty()){
        if(!way.empty()){
            if(tim-way.front().second==w){
                hp-=way.front().first;
                way.pop();
            }
        }
        if(hp+bus.front()<=l){
            hp+=bus.front();
            way.push(make_pair(bus.front(), tim));
            bus.pop();
        }
        tim++;
    }
    while(!way.empty()){
        if(tim-way.front().second==w){
            hp-=way.front().first;
            way.pop();
        }
        tim++;
    }
    cout<<tim;
}