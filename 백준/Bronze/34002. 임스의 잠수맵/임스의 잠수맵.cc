#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, s, v, l, exp, time = 0;
    cin >> a >> b >> c >> s >> v >> l;
    exp = (250 - l) * 100;
    for (int i = 0; i < 30 * v; i++) {
        exp -= c;
        time++;
        if (exp <= 0) {
            cout << time;
            return 0;
        }
    }
    for (int i = 0; i < 30 * s; i++) {
        exp -= b;
        time++;
        if (exp <= 0) {
            cout << time;
            return 0;
        }
    }
    while (1) {
        exp -= a;
        time++;
        if (exp <= 0) {
            cout << time;
            return 0;
        }
    }
}