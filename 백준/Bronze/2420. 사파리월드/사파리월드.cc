#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    long long n, m;
    cin >> n >> m;
    if (n > m) {
        cout << n - m;
    } else
        cout << m - n;
}