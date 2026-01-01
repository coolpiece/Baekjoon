#include <bits/stdc++.h>
using namespace std;
int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    double h, m, s;
    cin >> h >> m >> s;
    h = 30 * h + m / 2 + s / 120;
    m = 6 * m + s / 10;
    s = 6 * s;
    vector<double> v;
    v.push_back(abs(h - m));
    v.push_back(abs(h - s));
    v.push_back(abs(m - s));
    v.push_back(360 - abs(h - m));
    v.push_back(360 - abs(h - s));
    v.push_back(360 - abs(m - s));
    sort(v.begin(), v.end());
    cout << fixed;
    cout.precision(6);
    cout << v[0] << '\n';
  }
}