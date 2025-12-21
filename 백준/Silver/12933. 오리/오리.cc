#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;
  vector<int> duck(5);
  int cnt = 0;
  if (str.size() % 5) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'q') {
      duck[0]++;
      duck[4]++;
      cnt = max(cnt, duck[4]);
    }
    else if (str[i] == 'u') {
      if (duck[0] > 0) {
        duck[0]--;
        duck[1]++;
      } else {
        cout << -1;
        return 0;
      }
    }
    else if (str[i] == 'a') {
      if (duck[1] > 0) {
        duck[1]--;
        duck[2]++;
      } else {
        cout << -1;
        return 0;
      }
    }
    else if (str[i] == 'c') {
      if (duck[2] > 0) {
        duck[2]--;
        duck[3]++;
      } else {
        cout << -1;
        return 0;
      }
    }
    else if (str[i] == 'k') {
      if (duck[3] > 0) {
        duck[3]--;
        duck[4]--;
      } else {
        cout << -1;
        return 0;
      }
    }
  }
  if (duck[4] == 0) cout << cnt;
  else
    cout << -1;
}