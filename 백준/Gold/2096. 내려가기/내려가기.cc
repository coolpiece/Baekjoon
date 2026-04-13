#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int n, maxA, maxB, maxC, minA, minB, minC, tmpA, tmpB, tmpC;
  cin >> n;
  vector<int> v(3);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) cin >> v[j];
    if (i == 0)
      maxA = minA = v[0], maxB = minB = v[1], maxC = minC = v[2];
    else {
      // 최댓값 계산.
      tmpA = max(maxA, maxB) + v[0];
      tmpB = max(max(maxA, maxB), maxC) + v[1];
      tmpC = max(maxB, maxC) + v[2];
      maxA = tmpA, maxB = tmpB, maxC = tmpC;

      // 최솟값 계산.
      tmpA = min(minA, minB) + v[0];
      tmpB = min(min(minA, minB), minC) + v[1];
      tmpC = min(minB, minC) + v[2];
      minA = tmpA, minB = tmpB, minC = tmpC;
    }
  }
  cout << max(max(maxA, maxB), maxC) << " " << min(min(minA, minB), minC);
}