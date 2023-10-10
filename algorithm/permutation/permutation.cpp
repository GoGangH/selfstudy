#include <iostream>
#include <string>
using namespace std;
void permutation(int n, string k);
string s;
int result = 0, chk[10] = {
                    0,
};
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string k;
        cin >> s;
        result = 0;
        permutation(0, k);
        cout << result << endl;
    }
}
void permutation(int n, string k) {
    if (n == s.size()) {
        int s_hap = 0;
        for (int i = 0; i < n; i++) {
            int num = int(k[i] - 97);
            if (i % 2 == 0)
                s_hap += num;
            else
                s_hap -= num;
        }
        if (s_hap > 0) result++;
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (chk[i] == 0) {
            chk[i] = 1;
            k += s[i];
            permutation(n + 1, k);
            k.erase(n);
            chk[i] = 0;
        }
    }
}