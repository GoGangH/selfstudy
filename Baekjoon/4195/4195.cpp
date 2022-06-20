#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
map<string, int> name;
int arr[200005], num[200005];
int find(int x) {
    if (arr[x] == x) return x;
    return arr[x] = find(arr[x]);
}
void uni(int x, int y) {
	x = find(x);
	y = find(y);

	if(x!=y){
        if(num[x] < num[y]){
            int tmp = x;
            x=y;
            y=tmp;
        }
		arr[y]=x;
		num[x]+=num[y];
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    string F1, F2;
    cin>>n;
    while(n--){
        int cnt=1;
        cin>>m;
        name.clear();

        for(int i=0;i<200005;i++){
            arr[i]=i;
            num[i]=1;
        }
        
        for(int i=0;i<m;i++){
            cin>>F1>>F2;

            if(!name.count(F1)) name[F1] = cnt++;
            if(!name.count(F2)) name[F2] = cnt++;

            uni(name[F1], name[F2]);
            cout<<max(num[find(name[F1])], num[find(name[F2])])<<"\n";
        }
    }
}