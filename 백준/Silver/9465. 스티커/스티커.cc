#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<vector<int>> v(2, vector<int>(n));
        vector<vector<int>> dp(2, vector<int>(n));

        for (int j = 0; j < 2; j++)
            for (int k = 0; k < n; k++) cin >> v[j][k];
            
            dp[0][0] = v[0][0];
            dp[1][0] = v[1][0];
            dp[0][1] = dp[1][0] + v[0][1];
            dp[1][1] = dp[0][0] + v[1][1];
            for (int j = 2; j < n; j++) {
                dp[0][j] = max(dp[1][j - 1] + v[0][j], max(dp[0][j - 2], dp[1][j - 2]) + v[0][j]);
                dp[1][j] = max(dp[0][j - 1] + v[1][j], max(dp[0][j - 2], dp[1][j - 2]) + v[1][j]);
            }

            cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
        }
}