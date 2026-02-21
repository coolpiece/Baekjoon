#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, rst = 0;
  cin >> n;
  string cur, target;
  cin >> cur >> target;
  for (int i = 0; i < cur.length(); i++)
    rst += min(abs(cur[i] - target[i]), 26 - abs(cur[i] - target[i]));
  cout << rst;
}