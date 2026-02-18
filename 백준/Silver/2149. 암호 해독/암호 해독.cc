#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string key, str, sortkey;
  cin >> key >> str;
  sortkey = key;
  sort(sortkey.begin(), sortkey.end());
  int keylen = key.length(), line = str.length() / keylen;
  char v[line][keylen];
  for (int i = 0; i < keylen; i++)
    v[0][i] = sortkey[i];  // 입력 받아서 행렬로 저장.
  int idx = 0;
  for (int i = 0; i < keylen; i++)
    for (int j = 1; j <= line; j++) v[j][i] = str[idx++];

  vector<int> order(keylen);
  for (int i = 0; i < keylen; i++) {
    for (int j = 0; j < keylen; j++) {
      if (key[i] == sortkey[j]) {  // 정렬된 키가 원래 키의 몇 번째로 변환되는지 미리 저장.
        order[i] = j;
        sortkey[j] = 0;  // 선택 표시.
        break;
      }
    }
  }
  for (int i = 1; i <= line; i++) {
    for (int j = 0; j < keylen; j++) {
      cout << v[i][order[j]];
    }
  }
}