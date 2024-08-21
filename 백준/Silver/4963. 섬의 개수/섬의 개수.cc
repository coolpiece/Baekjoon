#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    while (1) {
        int w, h, cnt = 0;
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        vector<vector<int>> v(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> v[i][j];
            }
        }

        queue<pair<int, int>> q;
        bool visited[h][w];
        fill(&visited[0][0], &visited[h - 1][w], false);

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (v[i][j] == 1 && !visited[i][j]) {  // 방문하지 않은 섬 찾기.
                    q.push({i, j});
                    visited[i][j] = true;
                    cnt++;
                } else
                    continue;
                while (!q.empty()) {  // 연결된 섬 모두 방문.
                    int curx = q.front().first, cury = q.front().second;
                    q.pop();
                    for (int k = 0; k < 8; k++) {
                        int x = curx + dx[k], y = cury + dy[k];
                        if (x >= 0 && x <= h - 1 && y >= 0 && y <= w - 1 && v[x][y] == 1 && !visited[x][y]) {
                            q.push({x, y});
                            visited[x][y] = true;
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}