#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i<n; i++) {
        float a, b, c, x1, x2;
        cin >> a >> b >> c;

        x1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        x2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        cout << fixed;  // 소수점 자리수 설정.
        cout.precision(3);
        cout << x1 << ", " << x2 << '\n';
    }
}