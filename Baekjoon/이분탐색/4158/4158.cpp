#include <iostream>
using namespace std;
int n=-1, num[1000001];
bool binSearch(int target){
    int low=0, height=n;
    while(low<height){
        int middle = (low+height)/2;
        if(num[middle] < target) low = middle+1;
        else if(num[middle] > target) height = middle;
        else return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    int m=-1, target;
    while(1){
        int result=0;
        cin>>n>>m;
        if(n==0 && m==0) break;
        for(int i=0;i<n;i++) cin>>num[i];

        for(int i=0;i<m;i++){
            cin>>target;
            if(binSearch(target)) result++;
        }

        cout<<result<<endl;
    }
}