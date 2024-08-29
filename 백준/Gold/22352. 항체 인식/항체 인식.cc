#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, check = 1, a, b, data, ndata;
    cin >> n >> m;
    vector<vector<int>> v1(n, vector<int>(m));
    vector<vector<int>> v2(n, vector<int>(m));
    bool visited[n][m];
    fill(&visited[0][0], &visited[n - 1][m], false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v1[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v2[i][j];
            if (v1[i][j] != v2[i][j]) {  // 데이터 값이 서로 다르면 표시.
                if (check) {
                    check = 0;
                    data = v1[i][j];  // 백신을 놓은 조직의 원래 데이터 저장.
                    ndata = v2[i][j];
                    a = i;  // 처음으로 다른 좌표 저장.
                    b = j;
                }
            }
        }
    }

    if (check) {  // 완전히 일치하는 경우.
        cout << "YES";
        return 0;
    } else {
        queue<pair<int, int>> q;
        v1[a][b] = ndata;
        q.push({a, b});
        visited[a][b] = true;
        int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
        while (!q.empty()) {
            int curx = q.front().first, cury = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = curx + dx[i], y = cury + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && v1[x][y] == data) {
                    v1[x][y] = ndata;
                    q.push({x, y});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {  // 두 결과가 다르면 NO.
        for (int j = 0; j < m; j++) {
            if (v1[i][j] != v2[i][j]) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}