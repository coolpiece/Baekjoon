#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int a, b, n;
  string str = "aba";
  cin >> a >> b;
  if (a <= b)
    cout << "NO";
  else {
    n = a - b;
    a -= n, b -= n;
    if (a < 0 || b < 0)
      cout << "NO";
    else {
      cout << "YES\n" << n << '\n';
      for (int i = 0; i < n - 1; i++) cout << str << '\n';
      for (int i = 0; i < b; i++) str.append("ba");
      cout << str;
    }
  }
}