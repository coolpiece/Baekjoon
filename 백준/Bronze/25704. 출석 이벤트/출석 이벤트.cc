#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n, p, m;
    cin >> n >> p;
    m = p;
    if (n >= 5) m = p - 500;
    if (n >= 10) m = min(m, p * 0.9);
    if (n >= 15) m = min(m, p - 2000);
    if (n >= 20) m = min(m, p * 0.75);

    if (m < 0) m = 0;
    cout << m;
}