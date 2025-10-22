#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> v(1001);
vector<vector<int>> d(1001, vector<int>(1001));

void dfs(int i, int j) {
    if (v[i][j] == '0' && d[i][j]==0) {  // 전류가 통하는 흰색.
        d[i][j] = 1;
        if (i > 0) dfs(i - 1, j);
        if (i + 1 < n) dfs(i + 1, j);
        if (j > 0) dfs(i, j -1);
        if (j + 1 < m) dfs(i, j + 1);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        v[i] = str;
    }
    for (int i = 0; i < m; i++) dfs(0, i);
    int flag = 0;
    for (int i = 0; i < m; i++) {
        if (d[n - 1][i] == 1) {
            flag = 1;
            break;
        }
    }
    if (flag)
        cout << "YES";
    else
        cout << "NO";
}