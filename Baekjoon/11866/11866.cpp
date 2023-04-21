#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, k, sz, pos = 1, num[10000] = {
                               0,
                           };
    cin >> n >> k;
    sz = n;
    cout << "<";
    while (sz > 0)
    {
        int cnt = 0;
        while (1)
        {
            if (num[pos] == 0)
            {
                cnt++;
                if (cnt == k)
                    break;
            }
            pos++;
            if (pos == n + 1)
                pos = 1;
        }
        num[pos] = 1;
        if (sz - 1 == 0)
            cout << pos << ">";
        else
            cout << pos << ", ";
        sz--;
    }
}