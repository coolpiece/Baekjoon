#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
    cout << 30;
  else
    cout << 29;
}