#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s = 0;
    cin >> n;
    s += n / 5;
    n %= 5;
    for (int i = s; i > 0; i--) {
        if (n % 2) {
            n += 5;
            s--;
        } else {
            s += n / 2;
            cout << s;
            return 0;
        }
    }
    if (n % 2)
        cout << -1;
    else {
        s += n / 2;
        cout << s;
    }
}