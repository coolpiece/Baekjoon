#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> hp(n + 1);          // 잃는 체력 저장.
    vector<int> happy(n + 1);       // 얻는 기쁨 저장.
    vector<vector<int>> dp(n+1, vector<int>(100));  // dp[사람][체력] = 기쁨.
    for (int i = 1; i <= n; i++) cin >> hp[i];
    for (int i = 1; i <= n; i++) cin >> happy[i];

    for (int i = 1; i <= n; i++) {        // 사람 번호.
        for (int j = 1; j < 100; j++) {  // 체력.
            dp[i][j] = dp[i - 1][j];
            if (hp[i] <= j)
            dp[i][j] = max(dp[i][j], dp[i-1][j - hp[i]] + happy[i]);
        }
    }
    cout << dp[n][99];
}