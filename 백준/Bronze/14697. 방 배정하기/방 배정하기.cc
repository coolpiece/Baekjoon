#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int a, b, c, n, cnt, flag = 0;
  cin >> a >> b >> c >> n;
  cnt = n - n / a * a;
  for (int i = 0; i < n / a; i++) {
    for (int j = 0; j < cnt / b; j++) {
      cnt = cnt - cnt / b * b;
      if (cnt == 0 || cnt % c == 0) {
        flag = 1;
        break;
      } else
        cnt += b;
    }
    if (cnt == 0) {
      flag = 1;
      break;
    }
    cnt += a;
  }
  if (flag)
    cout << 1;
  else
    cout << 0;
  return 0;
}