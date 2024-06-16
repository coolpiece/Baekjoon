#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p;
    cin >> p;

    for (int i = 0; i < p; i++) {
        int k, n, s1, s2, s3;
        cin >> k >> n;

        s1 = (1 + n) * n / 2;
        s2 = n * n;
        s3 = n * (n + 1);
        cout << k << " " << s1 << " " << s2 << " " << s3 << '\n';
    }
}