#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, water = 0;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int t, r;
        cin >> t >> r;
        water += r;
        if (water > k) {
            cout << i + 1 << ' ' << 1;
            return 0;
        }
    }
    cout << "-1";
}