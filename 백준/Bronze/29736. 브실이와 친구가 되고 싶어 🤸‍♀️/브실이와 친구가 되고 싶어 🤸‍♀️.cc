#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, k, x;
    cin >> a >> b >> k >> x;

    if(k-x>=a && k-x<=b) {
        if (k + x <= b) cout << 2 * x + 1;
        else
            cout << b - k + x + 1;
    }
    else if (k-x<a) {
        if (k + x < a) cout << "IMPOSSIBLE";
        else if(k+x>=a && k+x<=b)
            cout << k + x - a + 1;
        else
            cout << b - a + 1;
    }
    else
        cout << "IMPOSSIBLE";
}