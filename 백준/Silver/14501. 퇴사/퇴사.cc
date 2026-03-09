#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> dp(N + 6);
    for (int i = 1; i <= N; i++) {
        int T, P;
        cin >> T >> P;
        dp[i - 1 + T] = max(dp[i - 1 + T], dp[i - 1] + P);
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[N];
}