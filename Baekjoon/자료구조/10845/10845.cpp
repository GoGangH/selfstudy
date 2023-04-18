#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    queue<int> que;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        string text;
        cin >> text;
        if (text == "push")
        {
            cin >> k;
            que.push(k);
        }
        else if (text == "front")
        {
            if (que.empty())
                cout << -1 << '\n';
            else
                cout << que.front() << '\n';
        }
        else if (text == "pop")
        {
            if (!que.empty())
            {
                cout << que.front() << '\n';
                que.pop();
            }
            else
                cout << -1 << '\n';
        }
        else if (text == "size")
            cout << que.size() << '\n';
        else if (text == "empty")
            cout << que.empty() << '\n';
        else if (text == "back")
        {
            if (que.empty())
                cout << -1 << '\n';
            else
                cout << que.back() << '\n';
        }
    }
}