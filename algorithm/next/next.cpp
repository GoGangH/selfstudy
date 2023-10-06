#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool next(string& s, int n);
int main() {
    int n, m;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> m >> s;

        if (next(s, m)) cout<<s<<endl;
        else{
            sort(s.begin(), s.end());
            cout<<s<<endl;
        }
    }

    return 0;
}
bool next(string& s, int n) {
    int i = n - 2;

    while (i >= 0 && s[i] >= s[i + 1]) {
        i--;
    }

    if (i == -1) {
        return false;
    }

    int j = n - 1;
    while (s[j] <= s[i]) {
        j--;
    }

    swap(s[i], s[j]);
    reverse(s.begin() + i + 1, s.end());

    return true;
}