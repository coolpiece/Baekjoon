#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int k, n = 0;
  string str;
  cin >> k >> str;
  int l = str.size() / k;
  vector<vector<char>> v(l, vector<char>(k));
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < k; j++) {
      v[i][j] = str[n];
      n++;
    }
    i++;
    if (i >= l) break;
    for (int j = k - 1; j >= 0; j--) {
      v[i][j] = str[n];
      n++;
    }
  }

  for (int i = 0; i < k; i++)
    for (int j = 0; j < l; j++) cout << v[j][i];
  cout << '\n';
}