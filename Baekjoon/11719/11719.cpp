#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    string ans;
    for(int i=0;i<100 && !cin.eof();i++){//eof 즉 데이터가 안들어올때 까지 입력받기
        getline(cin, a);//입력이 NULL문자가 들어올때 까지 한줄 입력
        cout<<a<<endl;
    }
}