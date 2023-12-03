#include <iostream>
#include <string>
using namespace std;
int L[101][101], S[101][101];
string a, b;
int lengthLCS(int m, int n);
void printLCS(int m, int n);
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        cout << lengthLCS(a.size(), b.size())<<" ";
        printLCS(a.size(), b.size());
        cout<<endl;
    }
}
int lengthLCS(int m, int n){
    for(int i=0;i<=m;i++) L[i][0] = 0;
    for(int i=0;i<=n;i++) L[0][i] = 0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1] == b[j-1]){
                L[i][j] = L[i-1][j-1] + 1;
                S[i][j] = 0;
            }
            else{
                L[i][j] = max(L[i][j-1], L[i-1][j]);
                if(L[i][j] == L[i][j-1]) S[i][j] = 1;
                else S[i][j] = 2;
            }
        }
    }

    return L[m][n];
}
void printLCS(int m, int n){
    if(m==0 || n==0) return;
    if(S[m][n] == 0){
        printLCS(m-1, n-1);
        cout<<a[m-1];
    }
    else if(S[m][n] == 1)
        printLCS(m, n-1);
    else if(S[m][n] == 2)
        printLCS(m-1, n);
}