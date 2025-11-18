#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  vector<int> v(101);
  vector<pair<int, int>> rvs;
  int n, cnt = 0;
  cin >> n;

  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int cur = n; cur >= 1; cur--) {
    int start;  // 뒤집기를 시작할 인덱스. start부터 cur까지 뒤집기.
    if (v[cur] == cur) continue;  // 제자리에 있는 경우.
    for (int i = 1; i <= cur; i++) {
      if (v[i] == cur) {
        start = i;
        reverse(v.begin() + start, v.begin() + cur + 1);
        rvs.push_back(make_pair(start, cur));
        cnt++;
        break;
      }
    }
  }
  if (cnt > 100)
    cout << -1;
  else {
    cout << cnt << '\n';
    for (int i = 0; i < rvs.size(); i++)
      cout << rvs[i].first << ' ' << rvs[i].second << '\n';
  }
}