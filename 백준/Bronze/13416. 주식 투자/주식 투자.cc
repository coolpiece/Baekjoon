#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int T = 0; T < t; T++) {
    long long n, a, b, c, s = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a >> b >> c;
      if (a <= 0 && b <= 0 && c <= 0) continue;
      if (a >= b && a >= c)
        s += a;
      else if (b >= a && b >= c)
        s += b;
      else if (c >= a && c >= b)
        s += c;
    }
    cout << s << '\n';
  }
}