#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, check = 1, cnt = 0;
    queue<pair<int, int>> q;
    cin >> m >> n;
    int v[n][m];                   // 초기에는 -1, 0, 1로 표시. 이후에는 며칠 후에 익는지 기록.
    for (int i = 0; i < n; i++) {  // 토마토 정보 입력 받기.
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (!v[i][j]) check = 0;  // 안 익은 토마토가 있으면 check 표시.
            if (v[i][j] == 1) q.push({i, j});
        }
    }
    if (check) {
        cout << 0;  // 모두 익은 경우.
        return 0;
    }
    else {
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            if (x > 0 && !v[x - 1][y]) {  // 상
                v[x - 1][y] = v[x][y] + 1;
                q.push({x - 1, y});
            }
            if (x < n - 1 && !v[x + 1][y]) {  // 하
                v[x + 1][y] = v[x][y] + 1;
                q.push({x + 1, y});
            }
            if (y > 0 && !v[x][y - 1]) {  // 좌
                v[x][y - 1] = v[x][y] + 1;
                q.push({x, y - 1});
            }
            if (y < m - 1 && !v[x][y + 1]) {  // 우
                v[x][y + 1] = v[x][y] + 1;
                q.push({x, y + 1});
            }
        }
    }

    for (int i = 0; i < n; i++) {  // 모두 익었는지 확인.
        for (int j = 0; j < m; j++) {
            if (!v[i][j]) {
                cout << -1;
                return 0;
            }
            if (v[i][j] > cnt) cnt = v[i][j];
        }
    }
    cout << cnt - 1;
}