#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = -1, pall[6];
    for (;;)
    {
        int i = 0, pos = 0, pre = 0;
        cin >> n;
        if (!n)
            break;
        pos = n;
        while (n != 0)
        {
            pall[i++] = n % 10;
            n /= 10;
        }
        int k = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            pre += pall[j] * k;
            k *= 10;
        }
        if (pos == pre)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
}