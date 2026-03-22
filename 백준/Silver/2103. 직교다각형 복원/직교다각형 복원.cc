#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, total = 0;
  cin >> n;
  vector<pair<int, int>> point(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    point[i] = make_pair(x, y);
  }
  sort(point.begin(), point.end(),
       [](pair<int, int> p1, pair<int, int> p2) -> bool {
         if (p1.first == p2.first) return p1.second < p2.second;
         return p1.first < p2.first;
       });

  for (int i = 0; i < n; i += 2) total += point[i + 1].second - point[i].second;

  sort(point.begin(), point.end(),
       [](pair<int, int> p1, pair<int, int> p2) -> bool {
         if (p1.second == p2.second) return p1.first < p2.first;
         return p1.second < p2.second;
       });

  for (int i = 0; i < n; i += 2) total += point[i + 1].first - point[i].first;
  cout << total;
}