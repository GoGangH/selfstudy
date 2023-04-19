#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, x;
    string text;
    deque<int> dque;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> text;
        if (text == "push_front")
        {
            cin >> x;
            dque.push_front(x);
        }
        else if (text == "push_back")
        {
            cin >> x;
            dque.push_back(x);
        }
        else if (text == "pop_front")
        {
            if (!dque.empty())
            {
                cout << dque.front() << '\n';
                dque.pop_front();
            }
            else
                cout << -1 << '\n';
        }
        else if (text == "pop_back")
        {
            if (!dque.empty())
            {
                cout << dque.back() << '\n';
                dque.pop_back();
            }
            else
                cout << -1 << '\n';
        }
        else if (text == "size")
        {
            cout << dque.size() << '\n';
        }
        else if (text == "empty")
        {
            cout << dque.empty() << '\n';
        }
        else if (text == "front")
        {
            if (!dque.empty())
            {
                cout << dque.front() << '\n';
            }
            else
                cout << -1 << '\n';
        }
        else if (text == "back")
        {
            if (!dque.empty())
            {
                cout << dque.back() << '\n';
            }
            else
                cout << -1 << '\n';
        }
    }
}