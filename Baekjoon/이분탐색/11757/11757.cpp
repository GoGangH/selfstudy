#include <iostream>
#include <string>
using namespace std;
int n, stone[100];
int game(int player)
{
    int result = 0, stoneNum = n, low = 0, height = n - 1;
    while (stoneNum > 2)
    {
        stoneNum--;
        if (player)
        {
        }
        else
        {
        }
    }
    return result;
}
int main()
{
    string name;
    cin >> n >> name;
    for (int i = 0; i < n; i++)
    {
        cin >> stone[i];
    }
    if (name == "Alice")
        cout << game(1);
    else
        cout << game(0);
}