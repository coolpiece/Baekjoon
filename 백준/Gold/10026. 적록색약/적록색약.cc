#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt1 = 0, cnt2 = 0;
    cin >> n;
    char rgb[n][n], rrb[n][n];  // rgb: 정상, rrb: 적록색약.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> rgb[i][j];
            rrb[i][j] = rgb[i][j];
            if (rrb[i][j] == 'G') rrb[i][j] = 'R';
        }
    }
    bool visited[n][n];
    queue<pair<int, int>> q;
    fill(&visited[0][0], &visited[n - 1][n], false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                q.push({i, j});
                visited[i][j] = true;
                char color = rgb[i][j];
                while (!q.empty()) {
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    if (x > 0 && !visited[x - 1][y] && color == rgb[x - 1][y]) {
                        visited[x - 1][y] = true;
                        q.push({x - 1, y});
                    }
                    if (x < n - 1 && !visited[x + 1][y] && color == rgb[x + 1][y]) {
                        visited[x + 1][y] = true;
                        q.push({x + 1, y});
                    }
                    if (y > 0 && !visited[x][y - 1] && color == rgb[x][y - 1]) {
                        visited[x][y - 1] = true;
                        q.push({x, y - 1});
                    }
                    if (y < n - 1 && !visited[x][y + 1] && color == rgb[x][y + 1]) {
                        visited[x][y + 1] = true;
                        q.push({x, y + 1});
                    }
                }
                cnt1++;
            }
        }
    }
    cout << cnt1 << " ";

    q = queue<pair<int, int>>();  // 큐를 비우기 위해 재선언.
    fill(&visited[0][0], &visited[n - 1][n], false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                q.push({i, j});
                visited[i][j] = true;
                char color = rrb[i][j];
                while (!q.empty()) {
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    if (x > 0 && !visited[x - 1][y] && color == rrb[x - 1][y]) {
                        visited[x - 1][y] = true;
                        q.push({x - 1, y});
                    }
                    if (x < n - 1 && !visited[x + 1][y] && color == rrb[x + 1][y]) {
                        visited[x + 1][y] = true;
                        q.push({x + 1, y});
                    }
                    if (y > 0 && !visited[x][y - 1] && color == rrb[x][y - 1]) {
                        visited[x][y - 1] = true;
                        q.push({x, y - 1});
                    }
                    if (y < n - 1 && !visited[x][y + 1] && color == rrb[x][y + 1]) {
                        visited[x][y + 1] = true;
                        q.push({x, y + 1});
                    }
                }
                cnt2++;
            }
        }
    }
    cout << cnt2;
}