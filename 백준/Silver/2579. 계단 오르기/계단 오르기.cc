#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n + 1), dp(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        dp[i] = v[i];
    }
    dp[2] = v[1] + v[2];

    for (int i = 3; i <= n; i++) { // 바닥부터 시작.
        dp[i] = max(dp[i-2] + v[i], dp[i-3] + v[i - 1] + v[i]); // 한 칸 - 두 칸 올라가기, 두 칸 올라가기.
    }
    cout << dp[n];
}