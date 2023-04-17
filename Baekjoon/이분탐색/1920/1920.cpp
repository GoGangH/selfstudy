#include <iostream>
#include <algorithm>
using namespace std;
int n, num[100001];
int binSearch(int target)
{
    int low = 0, height = n - 1;
    while (low <= height)
    {
        int middle = (low + height) / 2;
        if (num[middle] < target)
            low = middle + 1;
        else if (num[middle] > target)
            height = middle - 1;
        else
        {
            cout << "1" << '\n';
            return 1;
        }
    }
    cout << "0" << '\n';
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, target;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    sort(num, num + n);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> target;
        binSearch(target);
    }
}