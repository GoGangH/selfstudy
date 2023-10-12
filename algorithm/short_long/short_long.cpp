#include <iostream>
using namespace std;
int m, d[101];
int short_long();
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) cin >> d[i];
        cout << short_long << endl;
    }
}
int short_long() {
    int s = 0, e = 0,
        t[101] =
            {
                0,
            },
        leng[101] =
            {
                0,
            },
        result = d[0];
    t[0] = d[0];
    for (int i = 1; i < m; i++) {
        t[i] = max(t[i - 1] + d[i], d[i]);
        if (t[i - 1] + d[i] > d[i])
            leng[i] = leng[i - 1] + 1;
        else
            leng[i] = 1;

        if (result < t[i]) {
            result = t[i];
            s = idx[i];
            e = i;
        }
    }

    if (result <= 0) {
        result = 0;
        s = -1;
        e = -1;
    }
    cout << result << " " << s << " " << e << endl;
}