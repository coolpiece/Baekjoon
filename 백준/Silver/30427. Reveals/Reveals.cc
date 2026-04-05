#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  string tmp;
  getline(cin, tmp);
  int n, m;
  cin >> n;
  vector<string> name(n);
  for (int i = 0; i < n; i++) cin >> name[i];
  name.push_back("swi");
  sort(name.begin(), name.end());
  cin >> m;
  set<string> seen;
  for (int i = 0; i < m; i++) {
    cin >> tmp;
    seen.insert(tmp);
  }
  if (find(name.begin(), name.end(), "dongho") != name.end()) {
    cout << "dongho";
    return 0;
  }
  string suspect;
  int cnt = 0;
  for (int i = 0; i < n + 1; i++) {
    if (seen.find(name[i]) != seen.end())
      cnt++;
    else
      suspect = name[i];
  }
  if (name.size() - cnt == 1) {
    cout << suspect;
    return 0;
  }
  if (find(name.begin(), name.end(), "bumin") != name.end() &&
      seen.find("bumin") == seen.end()) {
    cout << "bumin";
    return 0;
  }
  if (find(name.begin(), name.end(), "cake") != name.end() &&
      seen.find("cake") == seen.end()) {
    cout << "cake";
    return 0;
  }
  if (find(name.begin(), name.end(), "lawyer") != name.end() &&
      seen.find("lawyer") == seen.end()) {
    cout << "lawyer";
    return 0;
  }
  for (int i = 0; i < n + 1; i++) {
    if (name[i] != "swi" && seen.find(name[i]) == seen.end()) {
      cout << name[i];
      return 0;
    }
  }
}