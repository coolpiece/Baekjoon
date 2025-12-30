#include <bits/stdc++.h>
using namespace std;
int rst = 0, n, m;
vector<int> v;

void back(int size, int idx, int time) {
  if (time == m) {
    rst = max(rst, size);
    return;
  }
  if (idx == n - 1) {
    rst = max(rst, size);
    return;
  }
  if (idx + 1 < n) back(size + v[idx + 1], idx + 1, time + 1);
  if (idx + 2 < n) back(size / 2 + v[idx + 2], idx + 2, time + 1);
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  back(1, -1, 0);
  cout << rst;
}