#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;
    int l1 = str1.size(), l2 = str2.size(), l3 = str3.size();
    vector<vector<vector<int>>> dp(l1 + 1, vector<vector<int>>(l2 + 1, vector<int>(l3 + 1)));

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            for (int k = 1; k <= l3; k++) {
                if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1])
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else {
                    dp[i][j][k] = max(dp[i][j - 1][k], dp[i][j][k - 1]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                }
            }
        }
    }
    cout << dp[l1][l2][l3];
}