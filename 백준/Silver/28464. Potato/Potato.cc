#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int sw = 0, park = 0, front = 0, back = n - 1;
  while (front <= back) {
    park += a[back--];
    if (front > back) break;
    sw += a[front++];
  }
  cout << sw << " " << park;
}