#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  string a, b;
  cin >> a >> b;
  long long rst = 0;
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      rst += (a[i] - '0') * (b[j] - '0');
    }
  }
  cout << rst;
}