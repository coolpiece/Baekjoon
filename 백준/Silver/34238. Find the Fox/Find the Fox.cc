#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, cnt = 0;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> v[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'F') {
                if (i + 2 < n && v[i + 1][j] == 'O' && v[i + 2][j] == 'X') cnt++;
                if (j + 2 < m && v[i][j + 1] == 'O' && v[i][j + 2] == 'X') cnt++;
                if (i + 2 < n && j + 2 < m && v[i + 1][j + 1] == 'O' && v[i + 2][j + 2] == 'X') cnt++;
                if (i - 2 >= 0 && v[i - 1][j] == 'O' && v[i - 2][j] == 'X') cnt++;
                if (j - 2 >= 0 && v[i][j - 1] == 'O' && v[i][j - 2] == 'X') cnt++;
                if (i - 2 >= 0 && j - 2 >= 0 && v[i - 1][j - 1] == 'O' && v[i - 2][j - 2] == 'X') cnt++;
                if (i - 2 >= 0 && j + 2 < m && v[i - 1][j + 1] == 'O' && v[i - 2][j + 2] == 'X') cnt++;
                if (i + 2 < n && j - 2 >= 0 && v[i + 1][j - 1] == 'O' && v[i + 2][j - 2] == 'X') cnt++;
            }
        }
    }
    cout << cnt;
}