#include<bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
    cin >> n;
    vector<long long> len(n - 1), oil(n), dp(n);
    for (int i = 0; i < n - 1; i++) cin >> len[i];
    for (int i = 0; i < n; i++) cin >> oil[i];
    long long price = oil[0];
    for (int i = 0; i < n; i++) {
        price = min(price, oil[i]);
        dp[i] = len[i] * price;
        if (i > 0) dp[i] += dp[i - 1];
    }
    cout << dp[n - 2];
}