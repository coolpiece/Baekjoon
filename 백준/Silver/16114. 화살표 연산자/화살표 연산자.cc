#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int x, n, cnt = 0;
  cin >> x >> n;

  if (n > 1 && n % 2) {
    cout << "ERROR";
    return 0;
  }
  if (n == 0 && x > 0) {
    cout << "INFINITE";
    return 0;
  }

  if (n == 1 && x < 0) {
    cout << "INFINITE";
    return 0;
  }

  if (n > 1 && x > n / 2) cnt = 2 * (x - 1) / n;

  cout << cnt;
}