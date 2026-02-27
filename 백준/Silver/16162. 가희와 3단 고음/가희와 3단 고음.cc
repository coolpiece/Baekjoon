#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a, d, x = 0;
  cin >> n >> a >> d;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i++) {
    if (v[i] == a) {
      a += d;
      x++;
    }
  }
  cout << x;
}