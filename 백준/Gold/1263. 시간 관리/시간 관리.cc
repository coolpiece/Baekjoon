#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<pair<int, int>> task;
  for (int i = 0; i < n; i++) {
    int t, s;
    cin >> t >> s;
    task.push_back(make_pair(s, t));
  }
  sort(task.begin(), task.end(), greater<>());
  int time = task[0].first;
  for (int i = 0; i < n; i++) {
    if (task[i].first >= time)
      time -= task[i].second;
    else
      time = task[i].first - task[i].second;
  }
  if (time >= 0)
    cout << time;
  else
    cout << -1;
}