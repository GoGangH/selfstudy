#include <iostream>
#include <map>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    map<int, int> num;
    int n, m, t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        num[t]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        if (num.find(t) != num.end())
            cout << num.find(t)->second << " ";
        else
            cout << 0 << " ";
    }
}