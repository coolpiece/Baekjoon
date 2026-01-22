#include <bits/stdc++.h>
using namespace std;
int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, time = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    time += tmp;
  }
  time += 8 * (n - 1);
  cout << time / 24 << ' ' << time % 24;
}