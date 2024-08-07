#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> dp(500002);

    for (int i = 1; i < 223; i++) {
        dp[i * i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (dp[i] != 1) {
            int sq = floor(sqrt(i)), m = 4;  // 제곱근.
            for (int j = 1; j <= sq; j++) {
                m = min(m, dp[i - j * j] + 1);
            }
            dp[i] = m;
        }
    }
    cout << dp[n];
}