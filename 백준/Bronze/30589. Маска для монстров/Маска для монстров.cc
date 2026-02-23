#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    double sum = 0, maxVal = LONG_MIN;
    cin >> n;
    vector<vector<long long>> v(n, vector<long long>(2));
    for (int i = 0; i < n; i++) cin >> v[i][0] >> v[i][1];
    for (int i = 1; i <= n; i++) {
        long long x = v[i % n][0] - v[i - 1][0], y = v[i % n][1] - v[i - 1][1];
        long long len = x * x + y * y;
        maxVal = max(maxVal, sqrt(len));
        sum += sqrt(len);
    }
    cout.precision(6);
    cout << fixed;
    cout << sum - maxVal;
}