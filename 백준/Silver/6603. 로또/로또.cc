#include <bits/stdc++.h>
using namespace std;
int pick[6], v[49], k;
void combi(int start, int cnt) {
  if (cnt == 6) {  // 다 뽑은 경우.
    for (int i = 0; i < 6; i++) cout << pick[i] << ' ';
    cout << '\n';
    return;
  }
  for (int i = start; i < k; i++) {
    pick[cnt] = v[i];
    combi(i + 1, cnt + 1);
  }
}

int main() {
  while (cin >> k) {
    if (k == 0) break;
    for (int i = 0; i < k; i++) cin >> v[i];
    combi(0, 0);
    cout << '\n';
  }
}