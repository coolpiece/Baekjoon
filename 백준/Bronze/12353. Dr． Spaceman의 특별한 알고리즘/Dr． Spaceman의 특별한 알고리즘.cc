#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int T = 0; T < t; T++) {
    char c;
    string mom, dad;
    cin >> c >> mom >> dad;
    double inch = 0;
    inch = (mom[0] - '0') + (dad[0] - '0');
    inch *= 12;
    if (mom[3] == '\"')
      inch += mom[2] - '0';
    else
      inch += (mom[2] - '0') * 10 + (mom[3] - '0');
    if (dad[3] == '\"')
      inch += dad[2] - '0';
    else
      inch += (dad[2] - '0') * 10 + (dad[3] - '0');

    if (c == 'B')
      inch += 5;
    else
      inch -= 5;
    inch /= 2;
    double minus = inch - 4, plus = inch + 4;
    int minsize, maxsize;
    // cout << inch << ' '<<minus<<' '<<plus<<'\n';
    if (minus != (int)minus)
      minsize = (int)(minus + 1);
    else
      minsize = (int)minus;
    maxsize = (int)plus;
    // cout << minsize << ' ' << maxsize << '\n';
    cout << "Case #" << T + 1 << ": " << minsize / 12 << '\'' << minsize % 12
         << '\"' << " to " << maxsize / 12 << '\'' << maxsize % 12 << "\"\n";
  }
}