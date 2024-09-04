#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b, cnt;
        cin >> a >> b;
        cnt = pow(a, 2) / pow(b, 2);
        cout <<cnt << '\n';

    }
}