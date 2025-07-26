#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    for (int i = 1; i <= n; i++) {  // 첫번째 물건부터 n번째 물건까지.
        int w, v;
        cin >> w >> v;
        for (int j = 1; j <= k; j++) {
            if (w <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);  // 안 넣는 경우와 넣는 경우 중 가치가 큰 값 선택.
            else                                                     // 용량을 초과해서 배낭에 넣을 수 없는 경우.
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][k];
}