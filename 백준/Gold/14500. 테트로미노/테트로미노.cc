#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, mx = 0;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> v[i][j];

    for (int i = 0; i < n; i++)  // 가로4 * 세로1.
        for (int j = 0; j < m - 3; j++) mx = max(mx, v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i][j + 3]);

    for (int i = 0; i < n - 3; i++)  // 가로1 * 세로4.
        for (int j = 0; j < m; j++) mx = max(mx, v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 3][j]);

    for (int i = 0; i < n - 1; i++)  // 정사각형. 가로2 * 세로2.
        for (int j = 0; j < m - 1; j++) mx = max(mx, v[i][j] + v[i][j + 1] + v[i + 1][j] + v[i + 1][j + 1]);

    for (int i = 0; i < n - 2; i++) {  // 가로2 * 세로3.
        for (int j = 0; j < m - 1; j++) {
            mx = max(mx, v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i][j + 1]);
            mx = max(mx, v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 1][j + 1]);
            mx = max(mx, v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 2][j + 1]);
            mx = max(mx, v[i][j + 1] + v[i + 1][j + 1] + v[i + 2][j + 1] + v[i][j]);
            mx = max(mx, v[i][j + 1] + v[i + 1][j + 1] + v[i + 2][j + 1] + v[i + 1][j]);
            mx = max(mx, v[i][j + 1] + v[i + 1][j + 1] + v[i + 2][j + 1] + v[i + 2][j]);
            mx = max(mx, v[i][j] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 2][j + 1]);
            mx = max(mx, v[i][j + 1] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 2][j]);
        }
    }

    for (int i = 0; i < n - 1; i++) {  // 가로3 * 세로2.
        for (int j = 0; j < m - 2; j++) {
            mx = max(mx, v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j]);
            mx = max(mx, v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 1]);
            mx = max(mx, v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 2]);
            mx = max(mx, v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2] + v[i][j]);
            mx = max(mx, v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2] + v[i][j + 1]);
            mx = max(mx, v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2] + v[i][j + 2]);
            mx = max(mx, v[i][j] + v[i][j + 1] + v[i + 1][j + 1] + v[i + 1][j + 2]);
            mx = max(mx, v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 1] + v[i + 1][j]);
        }
    }
    cout << mx;
}