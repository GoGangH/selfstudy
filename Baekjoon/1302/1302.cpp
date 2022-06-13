#include <iostream>
#include <map>
using namespace std;
int main(){
    int n, max=-1;
    string s, maxS;
    map<string, int> book;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        if(book.find(s)!=book.end()){
            book[s]++;
        }
        else book[s]=0;

        if(max<=book[s]){
            if(max<book[s]){
                max=book[s];
                maxS=s;
            }
            else if(maxS>s && max==book[s]){
                max=book[s];
                maxS=s;
            }
        }
    }

    cout<<maxS;
}