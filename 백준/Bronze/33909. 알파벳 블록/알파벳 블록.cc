#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s = 0, c = 0, o = 0, n = 0, b1, b2;
    cin >> s >> c >> o >> n;
    s += n;
    c += o * 2;
    b1 = s / 3;
    b2 = c / 6;
    cout << min(b1, b2);
}