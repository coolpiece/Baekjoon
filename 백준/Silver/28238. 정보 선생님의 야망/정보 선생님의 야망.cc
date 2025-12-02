#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, m = 0, idx = 0;
  cin >> n;
  vector<vector<int>> w = {{1, 1, 0, 0, 0}, {1, 0, 1, 0, 0}, {1, 0, 0, 1, 0},
                           {1, 0, 0, 0, 1}, {0, 1, 1, 0, 0}, {0, 1, 0, 1, 0},
                           {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 0, 1, 0, 1},
                           {0, 0, 0, 1, 1}};
  vector<vector<int>> std(n, vector<int>(5));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 5; j++) cin >> std[i][j];

  for (int i = 0; i < 10; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      int pos = 0;
      for (int k = 0; k < 5; k++) {
        if (w[i][k] && std[j][k]) pos++;
      }
      if (pos == 2) cnt++;
    }
    if (m < cnt) {
      m = cnt;
      idx = i;
    }
  }
  cout << m << '\n';
  for (int i = 0; i < 5; i++) cout << w[idx][i] << ' ';
  return 0;
}