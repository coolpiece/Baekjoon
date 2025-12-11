#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  map<string, int> cnt;
  for (int i = 0; i < n; i++) {
    int s, t;
    cin >> s >> t;
    for (int j = 0; j < t; j++) {
      string tag;
      cin >> tag;
      cnt[tag]++;
    }
  }
  int m = 0, flag = 0;
  string rst;
  for (auto i = cnt.begin(); i != cnt.end(); i++) m = max(m, i->second);
  for (auto i = cnt.begin(); i != cnt.end(); i++) {
    if (m == i->second) {
      rst = i->first;
      if (flag == 0)
        flag = 1;
      else {
        flag = 2;
        break;
      }
    }
  }
  if (flag == 2)
    cout << -1;
  else
    cout << rst;
  return 0;
}