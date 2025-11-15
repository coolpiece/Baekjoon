#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];

  long long a = 1, b = v[n - 1], p;
  for (int i = n - 2; i >= 0; i--) {
    p = b * v[i];
    a += p;
    swap(a, b);
  }
  p = b;
  a = p - a;
  cout << a << ' ' << b;
}