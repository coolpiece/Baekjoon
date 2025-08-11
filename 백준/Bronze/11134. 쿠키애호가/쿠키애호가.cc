#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n, c;
        cin >> n >> c;
        if (n % c)
            cout << n / c + 1 << '\n';
        else
            cout << n / c << '\n';
    }
}