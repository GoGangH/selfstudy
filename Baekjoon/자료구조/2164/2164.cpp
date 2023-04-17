#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n;
    queue<int> card;
    cin >> n;
    for (int i = 1; i <= n; i++)
        card.push(i);

    while (card.size() > 1)
    {
        card.pop();
        if (card.size() == 1)
            break;
        int tmp = card.front();
        card.pop();
        card.push(tmp);
    }
    cout << card.front();
}