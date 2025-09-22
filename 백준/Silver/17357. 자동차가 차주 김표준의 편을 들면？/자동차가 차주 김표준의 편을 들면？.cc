#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> v(n + 1);   // 누적합.
    vector<long long> v2(n + 1);  // 제곱의 누적합.
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v2[i] = v[i] * v[i];
        v2[i] += v2[i - 1];
        v[i] += v[i - 1];
    }

    for (int k = 1; k <= n; k++) {
        int idx = -1;
        long long mx = -1;
        for (int i = 1; i <= n - k + 1; i++) {
            long long ex, m;
            m = v[i + k - 1] - v[i - 1];
            m = pow(m, 2);
            ex = v2[i + k - 1] - v2[i - 1];
            if (mx < k * ex - m) {
                mx = k * ex - m;
                idx = i;
            }
        }
        cout << idx << '\n';
    }
}