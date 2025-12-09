#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, k;
  string mascot;
  cin >> n >> mascot >> k;
  if (!mascot.compare("annyong")) {
    if (k % 2 == 1)
      cout << k;
    else if (k - 1 > 0)
      cout << k - 1;
    else
      cout << k + 1;
  } else {
    if (k % 2 == 0)
      cout << k;
    else if (k - 1 > 0)
      cout << k - 1;
    else
      cout << k + 1;
  }
  return 0;
}