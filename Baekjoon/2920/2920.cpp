#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    string a = "";
    for (int i = 1; i <= 8; i++)
    {
        cin >> n;
        a.append(to_string(n));
    }

    if (a == "12345678")
        cout << "ascending";
    else if (a == "87654321")
        cout << "descending";
    else
        cout << "mixed";
}