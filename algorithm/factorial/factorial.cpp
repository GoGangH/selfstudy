#include <iostream>
using namespace std;
int factorial(int);
int main() {
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        int result = factorial(m);
        while (1) {
            if (result % 10 != 0) break;
            result /= 10;
        }
        cout << result % 1000 << endl;
    }
}
int factorial(int m) {
    if (m == 0) return 1;

    int k = m;
    while (1) {
        if (k % 10 != 0) break;
        k /= 10;
    }
    int p = factorial(m - 1);
    while (1) {
        if (p % 10 != 0) break;
        p /= 10;
    }

    return (k % 10000) * (p % 10000);
}