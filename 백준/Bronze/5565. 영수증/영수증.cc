#include <bits/stdc++.h>
using namespace std;
int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int price;
  cin >> price;
  for (int i = 0; i < 9; i++) {
    int tmp;
    cin >> tmp;
    price -= tmp;
  }
  cout << price;
}