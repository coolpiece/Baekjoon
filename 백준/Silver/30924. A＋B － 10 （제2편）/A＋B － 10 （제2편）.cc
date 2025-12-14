#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  vector<int> v(10000);
  vector<int> vv(2);
  srand(time(0));
  for (int i = 0; i < 10000; i++) v[i] = i + 1;
  random_shuffle(v.begin(), v.end());
  int resp;
  for (int a = 0; a < 9998; a++) {
    cout << "? A " << v[a] << endl;
    cin >> resp;
    if (resp == 1) {
      for (int b = 0; b < 9999; b++) {
        cout << "? B " << v[b] << endl;
        cin >> resp;
        if (resp == 1) {
          cout << "! " << v[a] + v[b];
          return 0;
        }
      }
    }
  }
  vv[0] = v[9998] + v[9999];
  vv[1] = v[9999] + v[9999];
  random_shuffle(vv.begin(), vv.end());
  cout << vv[0];
}