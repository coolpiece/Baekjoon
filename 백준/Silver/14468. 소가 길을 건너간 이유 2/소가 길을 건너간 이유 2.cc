#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string str;
  cin >> str;
  bool visited[26];
  for (int i = 0; i < 26; i++) visited[i] = false;
  int cnt = 0;
  for (int i = 0; i < str.size() - 1; i++) {
    if (!visited[str[i] - 'A']) {  // 아직 나오지 않은 소.
      visited[str[i] - 'A'] = true;
      set<char> s;
      for (int j = i + 1; j < str.size(); j++) {
        if (str[i] == str[j]) break;  // 같은 알파벳이 나올 때까지 순회.
        if (s.find(str[j]) !=
            s.end())  // 범위 내에 같은 알파벳이 2개 있는 경우.
          s.erase(str[j]);
        else  // 없는 경우 목록에 추가.
          if (!visited[str[j] - 'A']) s.insert(str[j]);
      }
      // cout << (char)i + 'A' << ": " << s.size() << '\n';
      cnt += s.size();
    }
  }
  cout << cnt;
}