#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int n, fact = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      fact *= i;
      while (fact % 10 == 0) fact /= 10;
      fact %= 100000;
    }
    cout << fact % 10 << '\n';
  }
}