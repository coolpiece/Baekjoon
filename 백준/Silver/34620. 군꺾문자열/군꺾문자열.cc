#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, k = 0;
    cin >> a >> b;
    int tmpb = b;
    string str = "";

    while (tmpb % 2 == 0) tmpb /= 2;

    if (tmpb != 1) {
        cout << -1;
        return 0;
    }

    while (a > 0) {
        if (a >= b) {
            a -= b;
            str += "G";
        } else {
            b /= 2;
            str += "K";
        }
    }
    reverse(str.begin(), str.end());
    cout << str;
}