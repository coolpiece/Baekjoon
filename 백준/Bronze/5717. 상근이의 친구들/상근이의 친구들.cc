#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1) {
        int m, f;
        cin >> m >> f;
        if (m == 0 && f == 0) break;
        cout << m + f << '\n';
    }
}