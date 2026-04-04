#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a.begin(), a.end());

  vector<int> c(m);
  for (int i = 0; i < m; i++)
    c[i] = upper_bound(a.begin(), a.end(), b[i]) - a.begin();

  for (int i = 0; i < m; i++) {
    cout << max(0, (3 + (int)sqrt(12 * c[i] - 3)) / 6) << " ";
  }
}