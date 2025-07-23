#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, cnt = 0;
    cin >> n >> m;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 1; i < n; i++) {
        if (abs(v[i] - v[i - 1]) < m) {
            v[i] = 10000000000000;
            cnt++;
        }
    }
    cout << cnt;
}