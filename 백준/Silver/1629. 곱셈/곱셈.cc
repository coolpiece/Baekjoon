#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c, ans = 1;
    cin >> a >> b >> c;
    a %= c;
    if (b == 1) ans = a % c;
    else {

    while (b > 1) {
        if (b % 2) {  // 홀수 번 나눌 때.
            ans = ans * a % c;
        }
        a = a * a % c;
        b /= 2;
    }
    ans = ans * a % c;
    }
    cout << ans;
}