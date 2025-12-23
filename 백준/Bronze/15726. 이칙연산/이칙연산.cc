#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long double a, b, c, m = 0;
    cin >> a >> b >> c;
    m = max(a / b * c, a * b / c);
    cout << (int)m;
}