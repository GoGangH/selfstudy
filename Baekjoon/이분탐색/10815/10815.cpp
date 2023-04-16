#include <iostream>
#include <algorithm>
using namespace std;
int num[500001], n;
bool binSearch(int target)
{
    int low = 0, height = n;
    while (low < height)
    {
        int midle = (low + height) / 2;
        // cout << low << " " << midle << " " << height << " " << num[midle] << endl;
        if (num[midle] < target)
            low = midle + 1;
        else if (num[midle] > target)
            height = midle;
        else
            return true;
    }
    return false;
}
int main()
{
    /* cin cout이 반복되면서 시간이 더 오래걸리는 문제였음 아래 코드를 작성해서 풀음*/
    ios::sync_with_stdio(false);
    cin.tie(0);
    int target, m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> target;

        cout << binSearch(target) << " ";
    }
}