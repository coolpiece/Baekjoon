#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int resp;
  for (int a = 1; a <= 9; a++) {
    cout << "? A " << a << endl;
    cin >> resp;
    if (resp == 1) {
      int b = 0;
      for (int b = 1; b <= 9; b++) {
        cout << "? B " << b << endl;
        cin >> resp;
        if (resp == 1) {
          cout << "! " << a + b;
          break;
        }
      }
      break;
    }
  }
  return 0;
}