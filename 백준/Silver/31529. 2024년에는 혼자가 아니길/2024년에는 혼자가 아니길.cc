#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, w;
    cin >> x >> y;
    w = (2 * x - y);
    if (w < 0 || x>y) cout << -1;
    else
        cout << 2024 * w / 4;
}