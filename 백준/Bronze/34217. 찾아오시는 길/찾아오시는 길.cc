#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a + c == b + d)
    cout << "Either";
  else if (a + c < b + d)
    cout << "Hanyang Univ.";
  else
    cout << "Yongdap";
  return 0;
}