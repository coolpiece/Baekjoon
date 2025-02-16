#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, pack = 1000, piece = 1000, price = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int pa, pi;
        cin >> pa >> pi;
        pack = min(pack, pa);
        piece = min(piece, pi);
    }
    if (pack > piece * 6) pack = piece * 6;
    price = (n / 6) * pack + (n % 6) * piece;
    price = min(price, (n / 6 + 1) * pack);
    cout << price;
}