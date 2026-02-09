#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    long long rst = 1;
    for (int i = 1; i <= n; i++) {
      rst *= i;
      while (rst % 10 == 0) rst /= 10;
      rst %= 100000000;
    }
    cout << setw(5) << right << n << " -> " << rst % 10 << '\n';
  }
  return 0;
}