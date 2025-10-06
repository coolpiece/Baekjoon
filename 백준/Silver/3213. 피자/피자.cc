#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p1 = 0, p2 = 0, p3 = 0, total = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b, c;
        cin >> a >> c >> b;
        if (a == '1' && b == '4')
            p1++;
        else if (a == '1' && b == '2')
            p2++;
        else
            p3++;
    }

    total += p3;
    if (p1 >= p3) p1 -= p3;
    else p1 = 0;
    if ((p1 + 1) / 2 >= p2) {
        total += p2;
        p1 -= p2 * 2;
        total += (p1 + 3) / 4;
    } else {
        total += (p1 + 1) / 2;
        p2 -= (p1 + 1) / 2;
        total += (p2 + 1) / 2;
    }
    cout << total;
}