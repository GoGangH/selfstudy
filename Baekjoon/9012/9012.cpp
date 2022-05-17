#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool chk_brac(string brac){
    vector<int> chk_bracket;
    for(int i=0;i<brac.size();i++){
        if(brac[i]==')'){
            if(chk_bracket.empty()) return false;
            chk_bracket.pop_back();
        }
        else{
            chk_bracket.push_back(1);
        }
    }
    if(!chk_bracket.empty()) return false;
    return true;
}
int main(){
    int n;
    string brac;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>brac;
        bool result = chk_brac(brac);
        if(result) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}