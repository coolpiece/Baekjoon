#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (a == b)
        cout << 0;
    else
        cout << b - a - 1 << '\n';
    if (b - a >= 2) {
        for (long long i = 1; i <= b - a - 1; i++) {
            cout << a + i << " ";
        }
    }
}