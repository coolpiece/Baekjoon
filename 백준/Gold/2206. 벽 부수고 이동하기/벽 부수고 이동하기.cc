#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> v(1001);
vector<vector<vector<int>>> dis(1001, vector<vector<int>>(1001, vector<int>(2)));
struct info {
    int x, y, k;
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        v[i] = str;
    }

    vector<int> xpos = {-1, 1, 0, 0};
    vector<int> ypos = {0, 0, -1, 1};
    queue<info> q;

    q.push({0, 0, 0});
    dis[0][0][0] = dis[0][0][1] = 1;

    while (!q.empty()) {
        info i = q.front();
        q.pop();
        int x = i.x, y = i.y, k = i.k;
        for (int t = 0; t < 4; t++) {
            int nx = x + xpos[t], ny = y + ypos[t];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (v[nx][ny] == '1' && k == 1) continue;                 // 진행 불가.
                if (v[nx][ny] == '1' && k == 0 && dis[nx][ny][0] == 0) {  // 벽 부수기.
                    dis[nx][ny][1] = dis[x][y][0] + 1;
                    q.push({nx, ny, 1});
                } else if (dis[nx][ny][k] == 0) {
                    dis[nx][ny][k] = dis[x][y][k] + 1;
                    q.push({nx, ny, k});
                }
            }
        }
    }
    
    if (dis[n - 1][m - 1][0] == 0 && dis[n - 1][m - 1][1] == 0)  // 둘 다 불가능한 경우.
        cout << -1;
    else if (dis[n - 1][m - 1][0] == 0 || dis[n - 1][m - 1][1] == 0)  // 하나만 가능한 경우.
        cout << max(dis[n - 1][m - 1][0], dis[n - 1][m - 1][1]);
    else
        cout << min(dis[n - 1][m - 1][0], dis[n - 1][m - 1][1]);
}