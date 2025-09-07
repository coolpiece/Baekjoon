#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double min;
    cin >> min;
    cout << fixed;
    cout.precision(1);

    if (min >= 0 && min <= 30)
        min /= 2;
    else
        min = (min - 30) * 1.5 + 15;
    cout << min;
}