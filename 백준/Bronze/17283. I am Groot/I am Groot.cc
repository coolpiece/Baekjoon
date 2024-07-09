#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r, sum = 0, cnt = 1;
    cin >> l >> r;
    while (1) {
        l = l * r / 100;
        if (l > 5) {
            int branch = pow(2, cnt++);
            sum += l * branch;
        }
        else
            break;
    }
    cout << sum;
}