#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n;  i++) {
        int c, p;
        cin >> c >> p;

        int price = c * p;
        int discount = (c - 1) * 2;
        price -= discount;
        // int price = p;
        // if (c > 2) {
        //     price += (p - 2) * (c - 1);
        // }
        cout << c << " " << p << '\n' << price << '\n';
    }
}