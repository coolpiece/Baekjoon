#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            v[i][j] = c - '0';
        }
    }

    queue<pair<int, int>> q;
    bool visited[n][n];  // 방문 여부 저장.
    vector<int> dz;      // 각 단지내 집의 수 저장.
    fill(&visited[0][0], &visited[n - 1][n], false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!v[i][j] || visited[i][j])  // 집이 없거나 방문한 집이면 패스.
                continue;
            else {
                q.push({i, j});
                visited[i][j] = true;
                int cnt = 0, num = 1;
                while (!q.empty()) {  // (i, j)와 연결된 집.
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    cnt = v[x][y];

                    if (x > 0 && v[x - 1][y] && !visited[x - 1][y]) {  // 좌
                        q.push({x - 1, y});
                        v[x - 1][y] = ++num;
                        visited[x - 1][y] = true;
                    }
                    if (x < n - 1 && v[x + 1][y] && !visited[x + 1][y]) {  // 우
                        q.push({x + 1, y});
                        v[x + 1][y] = ++num;
                        visited[x + 1][y] = true;
                    }
                    if (y > 0 && v[x][y - 1] && !visited[x][y - 1]) {  // 상
                        q.push({x, y - 1});
                        v[x][y - 1] = ++num;
                        visited[x][y - 1] = true;
                    }
                    if (y < n - 1 && v[x][y + 1] && !visited[x][y + 1]) {  // 하
                        q.push({x, y + 1});
                        v[x][y + 1] = ++num;
                        visited[x][y + 1] = true;
                    }
                }
                dz.push_back(cnt);
            }
        }
    }
    sort(dz.begin(), dz.end());
    cout << dz.size() << '\n';
    for (int i = 0; i < dz.size(); i++) cout << dz[i] << '\n';
}