#include <iostream>
#include <queue>
using namespace std;
queue<int> xx;
queue<int> yy;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int arr[60][60] = {
    0,
};
void findWorm(int n, int m)
{
    while (!xx.empty())
    {
        int xa = xx.front();
        int ya = yy.front();
        arr[xa][ya] = 0;
        xx.pop();
        yy.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = xa + dx[i];
            int y1 = ya + dy[i];
            if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= n)
                continue;
            if (arr[x1][y1] == 1)
            {
                xx.push(x1);
                yy.push(y1);
                arr[x1][y1] = 0;
            }
        }
    }
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t, n, m;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x, y, k, cnt = 0;
        cin >> n >> m >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> x >> y;
            arr[x][y] = 1;
        }
        for (int j = 0; j < n; j++)
        {
            for (int p = 0; p < m; p++)
            {
                if (arr[j][p] == 1)
                {
                    xx.push(j);
                    yy.push(p);
                    findWorm(n, m);
                    cnt++;
                }
            }
        }
        for (int j = 0; j < 60; j++)
        {
            for (int p = 0; p < 60; p++)
                arr[j][p] = 0;
        }
        cout << cnt << '\n';
    }
}