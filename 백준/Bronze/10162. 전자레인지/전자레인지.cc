#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, a = 0, b = 0, c = 0;
    cin >> t;
    if (t % 10) { // 10으로 나누어 떨어지지 않으면 불가능.
        cout << -1;
        return 0;
    }

    if(t >= 300) {
        a = t / 300;
        t %= 300;
    }
    if(t >= 60) {
        b = t / 60;
        t %= 60;
    }
    if(t >= 10) {
        c = t / 10;
        t %= 10;
    }
    cout << a << " " << b << " " << c;
}