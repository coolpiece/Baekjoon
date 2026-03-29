#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;
  int next = (m + k - 4) % n;
  while (next < 0) next += n;
  cout << next + 1;
}