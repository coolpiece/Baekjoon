#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<pair<int, double>> v(n);
  for (int i = 0; i < n; i++) {
    int w, h;
    cin >> w >> h;
    double ppi = sqrt(pow(w, 2) + pow(h, 2)) / 24;
    v[i].first = i + 1, v[i].second = ppi;
  }
  sort(v.begin(), v.end(),
       [](const pair<int, double>& a, const pair<int, double>& b) {
         if (a.second == b.second) return a.first < b.first;
         return a.second > b.second;
       });
  for (int i = 0; i < n; i++) cout << v[i].first << "\n";
}