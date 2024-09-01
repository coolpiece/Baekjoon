#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    double h1, h2, rst;
    cin >> a >> b >> c;

    h1 = sqrt(pow(a, 2) - pow(b, 2));
    h2 = sqrt(pow(a, 2) - pow(c, 2));

    rst = (h1 * h2 - b * c) / a;
    d = round(rst);

    if (d > 0 && fabs(a * d + b * c - h1 * h2) < 1e-9)
        cout << d;  // 양수이고, 정수여야 함.
    else
        cout << -1;
}