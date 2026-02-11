#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int cnt = 0, rst = 0;
  for (int i = 1; i < str.size(); i++) {
    if (str[i] - str[i - 1] == 1)
      cnt++;
    else {
      if (cnt == 2) rst++;
      cnt = 0;
    }
  }
  if (cnt == 2) rst++;
  cout << rst << '\n';
}