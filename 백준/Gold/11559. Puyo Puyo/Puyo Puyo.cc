#include <bits/stdc++.h>
using namespace std;

bool pung();
vector<int> findStart(vector<vector<bool>>);
void down();
void printBoard();

int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
vector<string> board(12);

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  for (int i = 0; i < 12; i++) cin >> board[i];
  int cnt = 0;
  while (pung()) {
    cnt++;
    down();
    // printBoard();
  }
  cout << cnt;
}

bool pung() {
  queue<vector<int>> q;
  vector<vector<bool>> visited(12, vector<bool>(6));
  bool flag = false;

  while (true) {
    vector<vector<int>> removeList;
    vector<int> start = findStart(visited);
    if (start[0] == -1) break;  // 다 탐색한 경우.

    visited[start[0]][start[1]] = true;
    q.push({start[0], start[1]});
    removeList.push_back({start[0], start[1]});
    int cnt = 1;
    while (!q.empty()) {
      int r = q.front()[0], c = q.front()[1];
      q.pop();
      char color = board[r][c];
      for (int i = 0; i < 4; i++) {  // 상하좌우 탐색.
        int nr = r + dr[i], nc = c + dc[i];
        if (nr < 0 || nr >= 12 || nc < 0 || nc >= 6) continue;
        if (!visited[nr][nc] && board[nr][nc] == color) {
          visited[nr][nc] = true;
          q.push({nr, nc});
          removeList.push_back({nr, nc});
          cnt++;
        }
      }
    }
    if (cnt >= 4) {  // 4개 이상이면 터짐.
      flag = true;
      for (vector<int> cur : removeList) {
        board[cur[0]][cur[1]] = '.';
      }
    }
    removeList.clear();
  }
  return flag;
}

vector<int> findStart(vector<vector<bool>> visited) {
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 6; j++) {
      if (board[i][j] != '.' && !visited[i][j]) return {i, j};
    }
  }
  return {-1, -1};
}

void down() {
  for (int i = 0; i < 6; i++) {
    vector<char> update(12, '.');
    int idx = 0;
    for (int j = 11; j >= 0; j--)
      if (board[j][i] != '.') update[idx++] = board[j][i];
    for (int j = 0; j < 12; j++) board[11 - j][i] = update[j];
  }
}

void printBoard() {
  for (int i = 0; i < 12; i++) cout << board[i] << '\n';
  cout << '\n';
}