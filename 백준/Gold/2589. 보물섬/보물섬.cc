#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> v(n, vector<char>(m));
  vector<pair<int, int>> list;  // 육지 저장.
  int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
      if (v[i][j] == 'L') list.push_back(make_pair(i, j));
    }
  }

  int maxDis = 0;
  for (pair<int, int> i : list) {
    queue<tuple<int, int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m));
    q.push(make_tuple(i.first, i.second, 0));
    visited[i.first][i.second] = true;
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      int r, c, dis;
      tie(r, c, dis) = t;
      maxDis = max(maxDis, dis);
      for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if (v[nr][nc] == 'L' && !visited[nr][nc]) {
          visited[nr][nc] = true;
          q.push(make_tuple(nr, nc, dis + 1));
        }
      }
    }
  }
  cout << maxDis << '\n';
  return 0;
}