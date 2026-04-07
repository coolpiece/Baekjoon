#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int k;
  cin >> k;
  vector<int> a(46), b(46);
  a[0] = 1;
  for (int i = 1; i <= k; i++) {
    a[i] = b[i - 1];
    b[i] = b[i - 1] + a[i - 1];
  }
  cout << a[k] << " " << b[k];
}