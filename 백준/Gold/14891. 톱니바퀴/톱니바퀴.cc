// 비트 마스킹으로 해결.

#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  string str;
  int gear[4];
  for (int i = 0; i < 4; i++) {
    cin >> str;
    gear[i] = stoi(str, nullptr, 2);
  }
  int k;
  cin >> k;
  vector<int> dir(4);
  for (int i = 0; i < k; i++) {
    int num, turn;
    cin >> num >> turn;
    fill(dir.begin(), dir.end(), 0);
    dir[num - 1] = turn;
    for (int j = num - 1; j < 3; j++) {  // 오른쪽 회전 확인.
      if (((gear[j] >> 5) & 1) != ((gear[j + 1] >> 1) & 1))
        dir[j + 1] = dir[j] * -1;
    }
    for (int j = num - 1; j > 0; j--) {  // 왼쪽 회전 확인.
      if (((gear[j] >> 1) & 1) != ((gear[j - 1] >> 5) & 1))
        dir[j - 1] = dir[j] * -1;
    }
    for (int i = 0; i < 4; i++) {
      if (dir[i] == 1)  // 시계 방향 회전.
        gear[i] = ((gear[i] & 1) << 7) | (gear[i] >> 1);
      else if (dir[i] == -1)  // 반시계 방향 회전.
        gear[i] = (gear[i] >> 7) | ((gear[i] & 127) << 1);
    }
  }
  cout << (gear[0] >> 7) * 1 + (gear[1] >> 7) * 2 + (gear[2] >> 7) * 4 +
              (gear[3] >> 7) * 8;
}