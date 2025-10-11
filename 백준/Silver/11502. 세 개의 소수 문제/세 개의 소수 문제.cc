#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  vector<int> v(1001);
  for (int i = 2; i < 1001; i++) v[i] = 1;
  for (int i = 2; i < 1001; i++) {
    if (!v[i]) continue;
    for (int j = 2; i * j < 1001; j++) v[i * j] = 0;
  }

  int t;
  cin >> t;

  for (int T = 0; T < t; T++) {
    int flag = 0, k;
    cin >> k;
    for (int i = 2; i < 1001; i++) {
      if (v[i]) {
        for (int j = i; j < 1001; j++) {
          if (v[j] && k - i - j >= 2 && v[k - i - j]) {
            cout << i << ' ' << j << ' ' << k - i - j << '\n';
            flag = 1;
            break;
          }
        }
        if (flag) break;
      }
    }
  }
}