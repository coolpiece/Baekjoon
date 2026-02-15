#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, cnt = 0;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int last = n - 1; last > 0; last--) {
    int maxVal = 0, idx;
    for (int i = 0; i <= last; i++)
      if (maxVal < a[i]) maxVal = a[i], idx = i;
    if (last != idx) {
      swap(a[idx], a[last]);
      cnt++;
    }
    if (cnt == k) {
      for (int i = 0; i < n; i++) cout << a[i] << ' ';
      return 0;
    }
  }
  if (cnt < k) cout << -1;
}