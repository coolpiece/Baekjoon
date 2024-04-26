#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int c;
        cin >> c;
        int q = 0, d = 0, n = 0, p = 0;
        if (c >= 25) {
            q = c / 25;
            c %= 25;
        }
        if (c >= 10) {
            d = c / 10;
            c %= 10;
        }
        if (c >= 5) {
            n = c / 5;
            c %= 5;
        }
        if (c >= 1) {
            p = c / 1;
            c %= 1;
        }
        cout << q << " " << d << " " << n << " " << p << '\n';
    }
}