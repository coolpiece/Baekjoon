#include <bits/stdc++.h>
using namespace std;

int get_idx(int i, int j) {
  return i * (i + 1) / 2 + j;
}  // 등차수열 합 공식 활용.

int main() {
  int n;
  cin >> n;
  int size = n * (n + 1) / 2;
  vector<int> a(size), b(size);
  for (int i = 0; i < size; i++) cin >> a[i];
  for (int i = 0; i < size; i++) cin >> b[i];

  int minVal = size;
  for (int type = 0; type < 6; type++) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        int ni, nj;
        switch (type) {
          case 0:  // 원본.
            ni = i, nj = j;
            break;

          case 1:  // 뒤집기.
            ni = i, nj = i - j;
            break;

          case 2:  // 시계 방향 회전.
            ni = n - 1 - (i - j), nj = n - 1 - i;
            break;

          case 3:  // 반시계 방향 회전.
            ni = n - 1 - j, nj = i - j;
            break;

          case 4:  // 뒤집기 + 시계 방향 회전.
            ni = n - 1 - (i - j), nj = j;
            break;

          case 5:  // 뒤집기 + 반시계 방향 회전.
            ni = n - 1 - j, nj = n - 1 - i;
            break;
        }
        if (a[get_idx(ni, nj)] != b[get_idx(i, j)]) cnt++;
      }
    }
    minVal = min(minVal, cnt);
  }
  cout << minVal;
  return 0;
}