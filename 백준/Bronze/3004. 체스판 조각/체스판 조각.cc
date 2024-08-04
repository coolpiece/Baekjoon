#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y;
    cin >> n;
    x = n / 2;
    y = n - x;
    x++, y++;
    cout << x * y;
}