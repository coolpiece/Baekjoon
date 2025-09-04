#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;
    int len1 = str1.size(), len2 = str2.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string lcs = "";
    int idx1 = len1, idx2 = len2;
    while (dp[idx1][idx2]) {
        if (str1[idx1 - 1] == str2[idx2 - 1]) {
            lcs = str1[idx1 - 1] + lcs;
            idx1--, idx2--;
        } else {
            if (dp[idx1 - 1][idx2] > dp[idx1][idx2 - 1])
                idx1--;
            else
                idx2--;
        }
    }
    cout << dp[len1][len2] << '\n'<< lcs;
}