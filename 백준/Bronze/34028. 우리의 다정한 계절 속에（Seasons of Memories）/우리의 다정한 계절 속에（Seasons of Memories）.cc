#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    a -= 2015;
    if (b == 12)
        b = 5;
    else if (b >= 1 && b <= 2)
        b = 1;
    else if (b >= 3 && b <= 5)
        b = 2;
    else if (b >= 6 && b <= 8)
        b = 3;
    else if (b >= 9 && b <= 11)
        b = 4;

    cout << a * 4 + b;
    return 0;
}