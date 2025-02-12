#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m, cnt = 0;
        cin >> n >> m;
        for (int b = 1; b < n; b++) {
            for (int a = 1; a < b; a++) {
                if ((a * a + b * b + m) % (a * b) == 0) cnt++;
            }
        }
        cout << cnt << '\n';
    }
}