#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long n, m;
    cin >> n;
    vector<long long> v(n + 1);
    vector<long long> psum(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    long long left = v[0], right = v[n], cnt = n;

    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) psum[i] = v[i] + psum[i - 1];
    cin >> m;

    if (psum[n] <= m)
        cout << v[n];
    else {
        for (int i = 1; i <= n; i++) {
            cnt = n - i + 1;
            if (psum[i - 1] + v[i] * cnt >= m) {
                left = v[i - 1];
                right = v[i];
                m -= psum[i - 1];
                break;
            }
        }
        long long rst;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (mid * cnt == m) {
                cout << mid;
                return 0;
            } else if (mid * cnt < m) {
                rst = mid;
                left = mid + 1;
            } else
                right = mid - 1;
        }
        cout << rst;
    }
}