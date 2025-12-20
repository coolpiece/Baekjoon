#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int T = 0; T < t; T++) {
    long long n, s=0;
    int day = 1;
    cin >> n;
    vector<long long> v(6);
    for (int i = 0; i < 6; i++) {
      cin >> v[i];
      s += v[i];
    }

    while (1) {
      if (s > n) {
        cout << day << '\n';
        break;
      }
      day++;
      s *= 4;
    }
  }
}