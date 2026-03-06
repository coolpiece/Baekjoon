#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int m;
    cin >> m;
    m = 6 + m / 50 * 12;
    if (m > 1086) {
      cout << -1;
      continue;
    }
    int h = m / 60;
    m %= 60;
    if (h < 4)
      cout << '0' << 6 + h;
    else
      cout << 6 + h;
    if (m < 10)
      cout << ":0" << m << '\n';
    else
      cout << ':' << m << '\n';
  }
  return 0;
}