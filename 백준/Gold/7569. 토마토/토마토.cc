#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, h, check = 1, cnt = 0;
    queue<tuple<int, int, int>> q;
    cin >> m >> n >> h;
    int v[h][n][m];                // 초기에는 -1, 0, 1로 표시. 이후에는 며칠 후에 익는지 기록.
    for (int i = 0; i < h; i++) {  // 토마토 정보 입력 받기.
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> v[i][j][k];
                if (!v[i][j][k]) check = 0;  // 안 익은 토마토가 있으면 check 표시.
                if (v[i][j][k] == 1) q.push({i, j, k});
            }
        }
    }
    if (check) {
        cout << 0;  // 모두 익은 경우.
        return 0;
    } else {
        while (!q.empty()) {
            int x = get<0>(q.front()), y = get<1>(q.front()), z = get<2>(q.front());
            q.pop();

            if (x > 0 && !v[x - 1][y][z]) {  // 상
                v[x - 1][y][z] = v[x][y][z] + 1;
                q.push({x - 1, y, z});
            }
            if (x < h - 1 && !v[x + 1][y][z]) {  // 하
                v[x + 1][y][z] = v[x][y][z] + 1;
                q.push({x + 1, y, z});
            }
            if (y < n - 1 && !v[x][y + 1][z]) {  // 앞
                v[x][y + 1][z] = v[x][y][z] + 1;
                q.push({x, y + 1, z});
            }
            if (y > 0 && !v[x][y - 1][z]) {  // 뒤
                v[x][y - 1][z] = v[x][y][z] + 1;
                q.push({x, y - 1, z});
            }
            if (z > 0 && !v[x][y][z - 1]) {  // 좌
                v[x][y][z - 1] = v[x][y][z] + 1;
                q.push({x, y, z - 1});
            }
            if (z < m - 1 && !v[x][y][z + 1]) {  // 우
                v[x][y][z + 1] = v[x][y][z] + 1;
                q.push({x, y, z + 1});
            }
        }
    }

    for (int i = 0; i < h; i++) {  // 모두 익었는지 확인.
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (!v[i][j][k]) {
                    cout << -1;
                    return 0;
                }
                if (v[i][j][k] > cnt) cnt = v[i][j][k];
                // cout << v[i][j][k] << " ";
            }
        }
    }
    cout << cnt - 1;
}