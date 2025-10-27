#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2, h, m;
    cin >> n1 >> n2;
    h = n1 / 30;
    m = (n1 % 30) * 2;
    if (m * 6 == n2) cout << 'O';
    else cout << 'X';
}