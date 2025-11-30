/*
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cout << "SHH";
}
*/

#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, cnt = 0;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      string str1 = v[i], str2 = v[j];
      vector<char> alpha(
          26);              // 두 번째 문자열을 첫 번째 문자열로 변환하는 해시.
      vector<int> use(26);  // 첫 번째 문자열에서의 사용 여부 저장.

      for (int k = 0; k < v[i].size(); k++) {
        int a = str1[k] - 'a', b = str2[k] - 'a';  // 알파벳을 숫자로 변환.
        if (alpha[b] == '\0') {  // 아직 변환하지 않은 알파벳인 경우.
          if (use[a] == 0) {
            alpha[b] = str1[k];  // 변환.
            use[a] = 1;
          }
        }
        if (alpha[b] != str1[k]) break;  // 변환 결과가 일치하지 않으면.

        if (k == v[i].size() - 1) {
          // cout << str1 << ' ' << str2 << '\n';
          cnt++;
        }
      }
    }
  }
  cout << cnt;
  return 0;
}