#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, a, b, c, d, m, k;
    cin >> l >> a >> b >> c >> d;
    k = a / c;
    if (a % c) k++;
    m = b / d;
    if (b % d) m++;
    if (k > m)
        cout << l - k;
    else
        cout << l - m;
}