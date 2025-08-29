#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.size(), l2 = s2.size(), len = 0;
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                len = max(len, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    cout << len;
}