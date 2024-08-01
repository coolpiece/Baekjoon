#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            v[i][j] = c - '0';
        }
    }

    queue<pair<int, int>> q;
    bool visited[n][m];
    fill(&visited[0][0], &visited[n - 1][m], false);
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty()) {  // (1, 1) -> (n, m)
        int x = q.front().first, y = q.front().second;
        q.pop();

        if (x > 0 && v[x - 1][y] && !visited[x - 1][y]) {  // 좌
            q.push({x - 1, y});
            v[x - 1][y] = v[x][y] + 1;
            visited[x - 1][y] = true;
            if (x == n && y == m - 1) break;
        }
        if (x < n - 1 && v[x + 1][y] && !visited[x + 1][y]) {  // 우
            q.push({x + 1, y});
            v[x + 1][y] = v[x][y] + 1;
            visited[x + 1][y] = true;
            if (x == n - 2 && y == m - 1) break;
        }
        if (y > 0 && v[x][y - 1] && !visited[x][y - 1]) {  // 상
            q.push({x, y - 1});
            v[x][y - 1] = v[x][y] + 1;
            visited[x][y - 1] = true;
            if (x == n - 1 && y == m) break;
        }
        if (y < m - 1 && v[x][y + 1] && !visited[x][y + 1]) {  // 하
            q.push({x, y + 1});
            v[x][y + 1] = v[x][y] + 1;
            visited[x][y + 1] = true;
            if (x == n - 1 && y == m - 2) break;
        }
    }
    cout << v[n - 1][m - 1];
}