#include <iostream>
using namespace std;
int main()
{
    int n, hap = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        hap += n;
    }
    cout << hap;
}