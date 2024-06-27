#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b;
    cin >> a >> b;
    double d = a * (100 - b) / 100;
    // cout << d << '\n';
    if (d >= 100) cout << 0;
    else
        cout << 1;
}