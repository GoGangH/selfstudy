#include <iostream>
using namespace std;
int main()
{
    int n, m, np = 1, mp = 1, ndm, ndmp = 1;
    cin >> n >> m;
    for (int i = n; i > 1; i--)
        np *= i;
    for (int i = m; i > 1; i--)
        mp *= i;
    ndm = n - m;
    for (int i = ndm; i > 1; i--)
        ndmp *= i;
    cout << np / (mp * ndmp);
}