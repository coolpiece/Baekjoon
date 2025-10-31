#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, m, x, y;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(n));
  vector<int> cmd(4);  // W:0, A:1, S:2, D:3.

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
      if (v[i][j] == 2) {
        x = i, y = j;
      }
    }
  for (int i = 0; i < 4; i++) {
    string str;
    cin >> str;
    if (!str.compare("Down")) cmd[i] = 0;
    if (!str.compare("Stay")) cmd[i] = 1;
    if (!str.compare("Up")) cmd[i] = 2;
  }

  string move;
  cin >> move;
  int key = -1;  // W:0, A:1, S:2, D:3.
  for (int i = 0; i < m; i++) {
    char cur = move[i];
    if (cmd[0] == 0 && key != 0 && cur == 'W' && x - 1 >= 0 && v[x - 1][y] != 1)
      x--;  // W가 Down.
    else if (cmd[0] == 1 && key == 0 && cur == 'W' && x - 1 >= 0 &&
             v[x - 1][y] != 1)
      x--;  // W가 Stay.
    else if (cmd[0] == 2 && key == 0 && cur != 'W' && x - 1 >= 0 &&
             v[x - 1][y] != 1)
      x--;  // W가 Up.

    if (cmd[1] == 0 && key != 1 && cur == 'A' && y - 1 >= 0 && v[x][y - 1] != 1)
      y--;  // A가 Down.
    else if (cmd[1] == 1 && key == 1 && cur == 'A' && y - 1 >= 0 &&
             v[x][y - 1] != 1)
      y--;  // A가 Stay.
    else if (cmd[1] == 2 && key == 1 && cur != 'A' && y - 1 >= 0 &&
             v[x][y - 1] != 1)
      y--;  // A가 Up.

    if (cmd[2] == 0 && key != 2 && cur == 'S' && x + 1 < n && v[x + 1][y] != 1)
      x++;  // S가 Down.
    else if (cmd[2] == 1 && key == 2 && cur == 'S' && x + 1 < n &&
             v[x + 1][y] != 1)
      x++;  // S가 Stay.
    else if (cmd[2] == 2 && key == 2 && cur != 'S' && x + 1 < n &&
             v[x + 1][y] != 1)
      x++;  // S가 Up.

    if (cmd[3] == 0 && key != 3 && cur == 'D' && y + 1 < n && v[x][y + 1] != 1)
      y++;  // D가 Down.
    else if (cmd[3] == 1 && key == 3 && cur == 'D' && y + 1 < n &&
             v[x][y + 1] != 1)
      y++;  // D가 Stay.
    else if (cmd[3] == 2 && key == 3 && cur != 'D' && y + 1 < n &&
             v[x][y + 1] != 1)
      y++;  // D가 Up.

    if (cur == 'W') key = 0;
    if (cur == 'A') key = 1;
    if (cur == 'S') key = 2;
    if (cur == 'D') key = 3;
    // cout << "key:" << key << ", x:" << x + 1 << ", y:" << y + 1 << '\n';
  }
  cout << x + 1 << ' ' << y + 1;
}