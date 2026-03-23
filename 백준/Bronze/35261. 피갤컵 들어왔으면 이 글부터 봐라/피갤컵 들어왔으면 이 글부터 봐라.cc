#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, maxVal = 0;
  string input;
  cin >> n >> input;
  vector<char> eagle = {'e', 'a', 'g', 'l', 'e'};
  for (int i = 0; i <= n - 5; i++) {
    int cnt = 0;
    for (int j = 0; j < 5; j++)
      if (input[i + j] == eagle[j]) cnt++;
    maxVal = max(maxVal, cnt);
  }
  cout << 5 - maxVal;
}