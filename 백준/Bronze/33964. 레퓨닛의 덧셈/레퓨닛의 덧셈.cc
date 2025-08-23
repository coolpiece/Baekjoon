#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;
    if (x < y) swap(x, y);  // x > y.
    for (int i = 0; i < x - y; i++) cout << 1;
    for (int i = 0; i < y; i++) cout << 2;
}