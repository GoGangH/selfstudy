#include <iostream>
using namespace std;
int m, n,
    chk[11][11] = {
        0,
};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
bool tour(int x, int y, int count);
int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> m >> n >> x >> y;
        for (int t = 1; t <= m; t++) {
            for (int j = 1; j <= n; j++) {
                chk[t][j] = 0;
            }
        }
        if (tour(x, y, 1)) {
            cout << "1" << endl;
            for (int t = 1; t <= m; t++) {
                for (int j = 1; j <= n; j++) {
                    cout << chk[t][j] << " ";
                }
                cout << endl;
            }
        } else
            cout << "0" << endl;
    }
}
bool tour(int x, int y, int count) {
    chk[x][y] = count;
    if (count == n * m) {
        return true;
    }

    for (int i = 0; i < 8; i++) {
        int xx = x + dy[i];
        int yy = y + dx[i];
        if (xx > 0 && yy > 0 && xx <= m && yy <= n && chk[xx][yy] == 0) {
            if (tour(xx, yy, count + 1)) {
                return true;
            }
        }
    }
    chk[x][y] = 0;
    return false;
}