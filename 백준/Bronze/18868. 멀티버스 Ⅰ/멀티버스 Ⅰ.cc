#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int m, n, cnt = 0;
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) cin >> v[i][j];

    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            int flag = 0;
            for (int k = 0; k < n - 1; k++) {
                for (int l = k + 1; l < n; l++) {
                    if (v[i][k] == v[i][l] && v[j][k] == v[j][l])
                        continue;
                    else if (v[i][k] < v[i][l] && v[j][k] < v[j][l])
                        continue;
                    else if (v[i][k] > v[i][l] && v[j][k] > v[j][l])
                        continue;
                    else {
                        flag = 1;
                        break;
                    }
                }
                if (flag) break;
                if (k == n - 2) cnt++;
            }
        }
    }
    cout << cnt;
}