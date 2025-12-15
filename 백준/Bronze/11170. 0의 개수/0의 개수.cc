#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int T = 0; T < t; T++) {
        int n, m, cnt = 0;
        cin >> n >> m;
        if (n == 0) cnt++;
        for (int i = n; i <= m; i++) {
            int tmp = i;
            while (tmp) {
                if (tmp % 10 == 0) cnt++;
                tmp /= 10;
            }
        }
        cout << cnt << '\n';
    }
}