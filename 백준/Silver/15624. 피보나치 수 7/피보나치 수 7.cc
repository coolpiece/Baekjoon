#include <bits/stdc++.h>
using namespace std;
int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  vector<int> v;
  v.push_back(0);
  v.push_back(1);
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    v.push_back(((v[i - 2] % 1000000007) + (v[i - 1]) % 1000000007) %
                1000000007);
  }
  cout << v[n];
}