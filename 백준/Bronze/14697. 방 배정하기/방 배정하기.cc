#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int a, b, c, n, flag = 0;
  cin >> a >> b >> c >> n;

  for (int i = 0; n - a * i >= 0; i++) {
    if (n - a * i == 0) {
      flag = 1;
      break;
    }
    for (int j = 0; n - a * i - b * j >= 0; j++) {
      if (n - a * i - b * j == 0 || (n - a * i - b * j) % c == 0) {
        flag = 1;
        break;
      }
    }
  }
  if (flag)
    cout << 1;
  else
    cout << 0;
  return 0;
}