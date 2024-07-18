#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, s;
    cin >> t >> s;

    if (t >= 12 && t <= 16 && !s) cout << 320;
    else
        cout << 280;
}