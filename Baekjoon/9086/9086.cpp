#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    string text;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> text;
        cout << text.front() << text.back() << '\n';
    }
}