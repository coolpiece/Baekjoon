#include <bits/stdc++.h>
using namespace std;

int main() {
  long long w, h, n;
  long double rst = 0;
  cin >> w >> h >> n;
  if(n%2) { // 홀수 등분.
    rst= (n - 1) / 2;
    rst = rst * rst / n * h * 2;
  }
  else {  // 짝수 등분.
    n /= 2;
    for (int i = 1; i < n; i++) rst += i;
    rst = rst / n * h * 2;
  }
  cout << fixed;
  cout.precision(6);
  cout << rst;
  return 0;
}