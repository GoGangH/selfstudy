#include <iostream>
#include <utility>
using namespace std;
pair<int, int> alpa[26];
void pre(int x);
void in(int x);
void post(int x);
int main(){
	int n;
	char x, y, z;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y>>z;
        alpa[x-65] = make_pair(y-65, z-65);
	}
	pre(0);
    cout<<endl;
	in(0);
    cout<<endl;
	post(0);
    cout<<endl;
}
void pre(int x){
	if(x<0) return;
	cout<<char(x+65);
	pre(alpa[x].first);
	pre(alpa[x].second);
}
void in(int x){
	if(x<0) return;
	in(alpa[x].first);
	cout<<char(x+65);
	in(alpa[x].second);
	return;
}
void post(int x){
	if(x<0) return;
    post(alpa[x].first);
	post(alpa[x].second);
	cout<<char(x+65);
}