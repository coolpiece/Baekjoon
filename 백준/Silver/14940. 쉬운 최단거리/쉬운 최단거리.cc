#include <bits/stdc++.h>
using namespace std;

bool visited[1001][1001];
int input[1001][1001], dist[1001][1001];
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = -1;
            cin >> input[i][j];
            if (input[i][j] == 2) {
                dist[i][j] = 0;
                q.push({i, j}); // 목표 지점 좌표에서 시작.
                visited[i][j] = true;
            } 
        }
    }

    while(!q.empty()) {
        auto cx = q.front().first, cy = q.front().second;
        q.pop();
        if (cx > 0) { // 상
            if (input[cx - 1][cy] && !visited[cx - 1][cy]) {
                dist[cx - 1][cy] = dist[cx][cy] + 1;
                q.push({cx - 1, cy});
                visited[cx - 1][cy] = true;
            }
        }
        if (cx < n) { // 하
            if (input[cx + 1][cy] && !visited[cx + 1][cy]) {
                dist[cx + 1][cy] = dist[cx][cy] + 1;
                q.push({cx + 1, cy});
                visited[cx + 1][cy] = true;
            }
        }
        if (cy > 0) { // 좌
            if (input[cx][cy - 1] && !visited[cx][cy - 1]) {
                dist[cx][cy - 1] = dist[cx][cy] + 1;
                q.push({cx, cy - 1});
                visited[cx][cy - 1] = true;
            }
        }
        if (cy < m) { // 우
            if (input[cx][cy + 1] && !visited[cx][cy + 1]) {
                dist[cx][cy + 1] = dist[cx][cy] + 1;
                q.push({cx, cy + 1});
                visited[cx][cy + 1] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (input[i][j] == 0) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
}