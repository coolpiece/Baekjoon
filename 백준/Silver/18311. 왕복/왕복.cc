#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k, sum = 0;
    cin >> n >> k;
    vector<long long> v(2 * n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
        v[2 * n - i + 1] = v[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        v[i] += v[i - 1];  // 누적합
    }

    for (int i = 1; i <= 2 * n; i++) {
        if (k >= v[i - 1] && k < v[i]) {
            if (i > n) cout << 2 * n - i + 1;
            else cout << i;
        }
    }
}