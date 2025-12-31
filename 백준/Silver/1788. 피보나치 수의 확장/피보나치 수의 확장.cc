#include <bits/stdc++.h>
using namespace std;
int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<long long> f(1000001);
  f[1] = 1;
  for (int i = 2; i <= 1000000; i++)
    f[i] = ((f[i - 1] % 1000000000) + (f[i - 2] % 1000000000)) % 1000000000;

  if (n >= 0) {
    if (f[n] == 0)
      cout << 0 << '\n' << 0;
    else if (f[n] > 0)
      cout << 1 << '\n' << f[n];
  } else {
    if ((-n) % 2)
      cout << 1 << '\n' << f[-n];
    else
      cout << -1 << '\n' << f[-n];
  }
}