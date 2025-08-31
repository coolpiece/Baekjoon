#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;
    int l1 = str1.size(), l2 = str2.size();
    vector<vector<int>> dp(l1+1, vector<int>(l2+1));

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        } }
    cout << l1 + l2 - dp[l1][l2];
}