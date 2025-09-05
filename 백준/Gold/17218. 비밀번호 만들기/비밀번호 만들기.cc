#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.size(), l2 = s2.size();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i1 = l1, i2 = l2;
    string ans = "";
    while (dp[i1][i2]) {
        if (s1[i1 - 1] == s2[i2 - 1]) {
            ans = s1[i1 - 1] + ans;
            i1--, i2--;
        } else {
            if (dp[i1 - 1][i2] > dp[i1][i2 - 1])
                i1--;
            else
                i2--;
        }
    }
    cout << ans;
}