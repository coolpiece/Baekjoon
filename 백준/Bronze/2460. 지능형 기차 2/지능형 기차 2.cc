#include <bits/stdc++.h>
using namespace std;

int main() {
  int total = 0, maxVal = 0;
  for (int i = 0; i < 10; i++) {
    int out, in;
    cin >> out >> in;
    total += -out + in;
    maxVal = max(maxVal, total);
  }
  cout << maxVal;
}