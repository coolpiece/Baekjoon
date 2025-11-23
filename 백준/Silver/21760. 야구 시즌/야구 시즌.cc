#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    long long n, m, k, d, b, tmp, total;
    cin >> n >> m >> k >> d;
    tmp = m * n * ((m - 1) * k + m * (n - 1)) / 2;
    b = d / tmp;
    if (b < 1)
      cout << -1 << '\n';
    else
      cout << b * tmp << '\n';
  }
  return 0;
}