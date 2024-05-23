#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i = 1;
    while (1) {
        int l, p, v;
        cin >> l >> p >> v;
        if (!l && !p && !v) break;  // 0 0 0 인 경우.

        int d = l * (v / p);
        if ((v % p) >= l) d += l;
        else
            d += v % p;
        cout << "Case " << i << ": " << d << '\n';
        i++;
    }
}