#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int len;
    string str, rvs;
    cin >> len >> str;
    rvs = str;
    reverse(rvs.begin(), rvs.end());
    vector<vector<int>> dp(len + 1, vector<int>(len + 1));

    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            if (str[i - 1] == rvs[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << len - dp[len][len];
}