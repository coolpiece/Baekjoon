#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int m, n, x, y, rst = -1;
        cin >> m >> n >> x >> y;

        for (int j = 0; j < n; j++) {
            int idx = x + m * j, tmp = idx;
            tmp %= n;
            if (tmp == 0) tmp = n;

            if (tmp == y) {
                rst = idx;
                break;
            }
        }
        cout << rst << '\n';
    }
}