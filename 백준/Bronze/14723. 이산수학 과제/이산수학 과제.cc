#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, cur = 1, s = 2;
  cin >> n;
  while (cur < n) {
    cur += s;
    s++;
  }
  for (int i = 1; i < s; i++) {
    if (cur == n) {
      cout << i << ' ' << s - i;
      break;
    } else
      cur--;
  }
}