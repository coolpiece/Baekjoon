#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, plus, minus;
    cin >> plus >> minus;
    if ((plus + minus) % 2 == 0) {
        a = (plus + minus) / 2;
        b = plus - a;
        if (a < 0 || b < 0 || a - b != minus)
            cout << -1;
        else
            cout << a << " " << b;
    }
    else
        cout << -1;
}