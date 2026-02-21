#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, maxVal = 0;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) maxVal = max(maxVal, v[i] * (n - i));
  cout << maxVal;
}