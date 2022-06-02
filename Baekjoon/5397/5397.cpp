#include <iostream>
#include <deque>
#include <string>
using namespace std;
string findS(string s){
    string result = "";
    int pos=0;
    deque<char> words;

    for(int i=0;i<s.size();i++){
        if(s[i]=='<'){
            if(pos>0) pos--;
        }
        else if(s[i]=='>'){
            if(pos<words.size()) pos++;
        }
        else if(s[i]=='-'){
            if(pos<=words.size()){
                if(pos>0){
                    pos--;
                    words.erase(words.begin()+pos);
                }
            }
        }
        else{
            words.insert(words.begin()+pos, s[i]);
            pos++;
        }
    }
    for(int i=0;i<words.size();i++) result+=words[i];
    return result;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string t;
        cin>>t;
        cout<<findS(t)<<endl;
    }
}